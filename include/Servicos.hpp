#ifndef Servicos_hpp
#define Servicos_hpp

#include <vector>
#include <iostream>
#include "Usuario.hpp"


using namespace std;

class Servicos{
  private:

  public:

    bool stringIsInteger(const string& str);
    
    std::vector<string> separador_linha_comando(string comando);
};

#endif