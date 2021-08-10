#ifndef CanalTexto_hpp
#define CanalTexto_hpp

#include <vector>
#include <iostream>
#include "Mensagem.hpp"
#include "Servicos.hpp"
#include "Usuario.hpp"

using namespace std;

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

    /*! 
      @brief Adiciona uma nova mensagem no vetor mensagens.
      @param mensagem_ a mensagem que o usuario quer enviar.
      @param idUsuario_ o id do usuario que enviou a mensagem. 
    */
    void adicionar_mensagem (string mensagem_, int idUsuario_);

    /*! 
      @brief Mostra todas as mensagens que estão neste canal.
      @param usuarios vetor que representa todos os usuarios cadastrados.
    */
    void listar_mensagens_armazenadas(vector<Usuario> usuarios );

    
};

#endif