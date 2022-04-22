#include "./shannonFano.hpp"

ShannonFanoEncryption::ShannonFanoEncryption(Parameters params) {
  CharVector a = params.alphabet;
  DoubleVector p = params.probabilities;
  int blockSize = params.blockSize;

  this->alplabet = a;
  this->blockSize = blockSize;

  ProbabilitiesTable probabilitiesTable;
  Codes codes;

  {
    SymbolProbabilitiesTable symbolPr;
    for (int i = 0; i < a.size(); i++)
      symbolPr.insert(SymbolProbabilitiesTable::value_type(a[i], p[i]));

    this->symbolPr = symbolPr;
  }

  if (blockSize == 1) {
    // Заполнение таблицы вероятностей появления символов (слов)
    for (int i = 0; i < a.size(); i++) {
      string key(1, a[i]);
      probabilitiesTable.push_back({string(key), p[i]});
      codes.insert(Codes::value_type(key, ""));
    };

    this->entropy = calculateEntropy(p);
  } else if (blockSize <= a.size()) {
    CharMatrix blocksPlacements = placementsReiterations<char>(a, a.size(), blockSize);
    StringVector bKeys;
    for (auto p : blocksPlacements)
      bKeys.push_back(charVectorToString(&p));

    DoubleVector bKeysProbabilities;
    for (auto k : bKeys) {
      double p = 1;

      for (int i = 0; i < k.length(); i++)
        p *= symbolPr.at(k[i]);

      bKeysProbabilities.push_back(p);
    };

    // Заполнение таблицы вероятностей появления символов (слов) 
    for (int i = 0; i < bKeys.size(); i++) {
      probabilitiesTable.push_back({bKeys[i], bKeysProbabilities[i]});
      codes.insert(Codes::value_type(bKeys[i], ""));
    };

    this->entropy = calculateEntropy(bKeysProbabilities);

  } else throw (std::invalid_argument("Ошибка! Длина блока не может быть больше мощности алфавита!"));

  this->sortByProbability(&probabilitiesTable);
  this->probabilitiesTable = probabilitiesTable;

  cout << "\nТаблица вероятностей появления символов (слов):" << endl;
  for (auto el : this->probabilitiesTable)
    cout << el.symbol << " " << el.probability << endl;

  this->codes = codes;
  this->createCodes(0, probabilitiesTable.size() - 1);

  cout << "\nТаблица кодовых слов:" << endl;
  for (auto c : this->codes) {
    cout << c.first << " " << c.second << endl;
    codesInverse.insert(Codes::value_type(c.second, c.first));
  }

  Codes codesInverse;
  for (auto c : this->codes)
    codesInverse.insert(Codes::value_type(c.second, c.first));
  this->codesInverse = codesInverse;

  double avgLen = 0;
  for (auto el : this->probabilitiesTable)
    avgLen += this->codes.at(el.symbol).length() * el.probability;

  this->avgLen = avgLen / blockSize;
};

void ShannonFanoEncryption::sortByProbability(ProbabilitiesTable* t) {
  sort(t->begin(), t->end(), [](Symbol& a, Symbol& b) {return a.probability < b.probability;});
};

void ShannonFanoEncryption::createCodes(int start, int end) {
  if (start == end)
    return;
  else if (end - start == 1) {
    this->codes.at(this->probabilitiesTable[start].symbol) += '1';
    this->codes.at(this->probabilitiesTable[end].symbol) += '0';
  } else {
    int splitIndex = this->getSplitIndex(start, end);
    cout << "Best split index: " << splitIndex << endl;
    
    for (int i = start; i <= end; i++) {
      if (i >= splitIndex)
        this->codes.at(this->probabilitiesTable[i].symbol) += '0';
      else
        this->codes.at(this->probabilitiesTable[i].symbol) += '1';
    }

    this->createCodes(start, splitIndex - 1);
    this->createCodes(splitIndex, end);
  }
};

int ShannonFanoEncryption::getSplitIndex(int start, int end) {
  double min = INFINITY;
  int minIndex = -1;

  double sumLeft = 0;
  double sumRight = 0;

  for (int i = start; i <= end; i++)
    sumRight += this->probabilitiesTable[i].probability;

  int splitIndex = start;

  while (splitIndex <= end) {
    double dif = abs(sumRight - sumLeft);
    if (dif < min) {
      min = dif;
      minIndex = splitIndex;
    }

    sumLeft += this->probabilitiesTable[splitIndex].probability;
    sumRight -= this->probabilitiesTable[splitIndex].probability;

    splitIndex++;
  }
  
  return minIndex;
};

string ShannonFanoEncryption::savePunctuation(string plainMsg) {
  string withoutPunctuation = "";
  IntVector uppercasePositions;
  IntVector punctuationPositions;
  CharVector punctuation;
  
  for (int i = 0; i < plainMsg.length(); i++) {
    char upperChar = toupper(plainMsg[i]);

    if (this->symbolPr.find(upperChar) == this->symbolPr.end()) {
      punctuationPositions.push_back(i);
      punctuation.push_back(plainMsg[i]);
    } else {
      if (upperChar == plainMsg[i])
        uppercasePositions.push_back(i);
      withoutPunctuation += plainMsg[i];
    }
  }

  this->uppercasePositions = uppercasePositions;
  this->punctuationPositions = punctuationPositions;
  this->punctuation = punctuation;

  return withoutPunctuation;
};

string ShannonFanoEncryption::withPunctuation(string plainMsg) {
  string withPunctuation = "";

  int i = 0;
  int j = 0;
  int k = 0;

  for (int t = 0; t < plainMsg.length() + this->punctuationPositions.size(); t++) {
    if (find(this->punctuationPositions.begin(), this->punctuationPositions.end(), t) != this->punctuationPositions.end())
      withPunctuation += this->punctuation[j++];
    else {
      if (this->uppercasePositions[k] == t) {
        withPunctuation += plainMsg[i];
        k++;
      } else
        withPunctuation += tolower(plainMsg[i]);

      i++;
    }
  };

  return withPunctuation;
};

Message ShannonFanoEncryption::encode(Message m) {
  string plainMsg =this->savePunctuation(m.text);
  if (plainMsg.length() % this->blockSize != 0)
    throw (std::invalid_argument("Ошибка! Сообщение не разбить на блоки заданного размера!"));

  string cipherMsg = "";

  for (int i = 0; i < plainMsg.length(); i += this->blockSize) {
    string key = "";

    for (int j = 0; j < this->blockSize; j++)
      key += toupper(plainMsg[i + j]);

    cipherMsg += this->codes.at(key);
  }

  return Message(cipherMsg, true);
};

Message ShannonFanoEncryption::decode(Message m) {
  string cipherMsg = m.text;

  string plainMsg = "";

  int i = 0;
  
  while (i < cipherMsg.length()) {
    string code = "";

    int j = 0;
    while (this->codesInverse.find(code) == this->codesInverse.end()) {
      code += cipherMsg[i + j];
      j++;
    }

    plainMsg += this->codesInverse.at(code);

    i += j;
  }
// return Message(plainMsg, false);
  return Message(withPunctuation(plainMsg), false);
};