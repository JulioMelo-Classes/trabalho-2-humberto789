#ifndef Mensagem_hpp
#define Mensagem_hpp

#include <vector>
#include <iostream>

using namespace std;

class Mensagem{
  private:
      string dataHora;
      int enviadaPor;
      string conteudo;
  public:

    /*! 
      @brief Define a data e hora que a mensagem foi enviada.
      @param dataHora_ A data e a hora da mensagem.
    */
    void set_dataHora (string dataHora_);

    /*! 
      @brief Define o id do usuario que enviou a mensagem.
      @param nome_ O id do usuario que enviou a mensagem.
    */
    void set_enviadaPor (int enviadaPor_);

    /*! 
      @brief Define o conteudo da mensagem.
      @param email_ O conteudo da mensagem.
    */
    void set_conteudo (string conteudo_);

    /*! 
      @brief Recupera data e a hora do envio da mensagem.
      @return Data e hora do envio da mensagem. 
    */
    string get_dataHora (void);

    /*! 
      @brief Recupera o id do usuario que enviou a mensagem.
      @return Id do usuario que enviou a mensagem. 
    */
    int get_nome (void) const;

    /*! 
      @brief Recupera o conteudo da mensagem.
      @return Conteudo da mensagem. 
    */
    string get_conteudo (void) const;

};

#endif