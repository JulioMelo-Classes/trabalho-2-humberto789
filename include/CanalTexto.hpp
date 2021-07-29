#ifndef CanalTexto_hpp
#define CanalTexto_hpp

#include <vector>
#include <iostream>
#include "Mensagem.hpp"

using namespace std;

/*
CP1 classe CanalTexto ok!
*/
class CanalTexto{
  private:
      string nome;
      std::vector< Mensagem > mensagens;
  public:

    /*! 
      @brief Define o nome do canal de texto.
      @param nome_ O nome do canal de texto.
    */
    void set_nome (string nome_);

    /*! 
      @brief Recupera o nome do canal de texto.
      @return Nome do canal de texto. 
    */
    string get_nome (void) const;

    bool adicionar_mensagem (Mensagem mensagem_);

    int get_quantidadeMensagens (void) const;

    
};

#endif