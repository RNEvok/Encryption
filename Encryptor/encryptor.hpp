#ifndef Encryptor_H
  #define Encryptor_H

  #include "./../AsymmetricEncryption/asymmetricEncryption.hpp"
  #include "./../Caesar/caesar.hpp"
  #include "./../ShannonFano/shannonFano.hpp"

  class Encryptor {
    private:
      Encryption* encryption;
    public:

      Encryptor();

      Encryptor(Encryption* encryption);

      ~Encryptor();

      void setStrategy(Encryption* encryption);
      
      Message encode(Message m);

      Message decode(Message m);
  };

#endif