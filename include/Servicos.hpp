#ifndef Servicos_hpp
#define Servicos_hpp

#include <vector>
#include <iostream>
#include "Usuario.hpp"

using namespace std;

class Servicos{
  private:

  public:
    /*! 
      @brief transoforma uma string em um inteiro.
      @param str_ string que será convertida para inteiro. 
      @return returna true caso a conversão tenha funcionado e false caso a conversão tenha falhado.
    */
    bool stringIsInteger(const string& str);
    
    /*! 
      @brief Transforma uma linha de comando em um vetor de strings separando cada string pelo caractere " ".
      @param comando linha de comando que será transformada. 
      @return vetor de string separado.
    */
    std::vector<string> separador_linha_comando(string comando);

    /*! 
      @brief Captura a data e hora do sistema e a transforma em uma string. 
      @return string contendo a data e a hora atual.
    */
    string pegar_data_hora_do_sistema ( void );
};

#endif