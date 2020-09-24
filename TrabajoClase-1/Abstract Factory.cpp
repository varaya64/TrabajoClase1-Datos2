#include <iostream>

using namespace std;

class mascotaPequena{
 public:
  virtual ~mascotaPequena(){};
  virtual std::string tipoMascota() const = 0;
};

class Cobaya : public mascotaPequena{
 public:
  std::string tipoMascota() const override {
    return "Esto es una mascota Cobaya";
  }
};

class Hamster : public mascotaPequena {

  std::string tipoMascota() const override {
    return "Esto es un hamster";
  }
};

class mascotaMediana{
 public:
  virtual ~mascotaMediana(){};
  virtual std::string tipoMascotaMed() const = 0;
};


class Perro : public mascotaMediana {
 public:
  std::string tipoMascotaMed() const override {
    return "Esto es un perro";
  }
};


class Gato : public mascotaMediana {
 public:
  std::string tipoMascotaMed() const override {
    return "Esto es un gato";
  }
};


class AbstractFactory {
 public:
  virtual mascotaMediana *crearMascotaMed() const = 0;
  virtual mascotaPequena *crearMascotaPeq() const = 0;
};


class mascotaFactory : public AbstractFactory {
 public:
  mascotaPequena *crearMascotaPeq() const override {
    return new Cobaya();
  }
  mascotaMediana *crearMascotaMed() const override {
    return new Perro();
  }
};

class mascotaFactory2 : public AbstractFactory {
 public:
  mascotaPequena *crearMascotaPeq() const override {
    return new Hamster();
  }
  mascotaMediana *crearMascotaMed() const override {
    return new Gato();
  }
};


