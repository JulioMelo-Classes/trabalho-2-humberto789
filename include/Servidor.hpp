#ifndef Servidor_hpp
#define Servidor_hpp

#include <vector>
#include <iostream>
#include "CanalTexto.hpp"
#include "Usuario.hpp"

using namespace std;

/*
CP2 ok

Documentação 0.8, faltou documentar os atributos
*/
class Servidor{
  private:
      int usuarioDonoId; //<! documentação restante!
      string nome;
      string descricao;
      string codigoConvite;
      std::vector< CanalTexto > canaisTexto;
      std::vector< int > participantesIDs;

  public:

    /*! 
      @brief Define o id do usuario que criou o servidor.
      @param usuarioDonoId_ O id do usuario que criou o servidor.
    */
    void set_usuarioDonoId (int usuarioDonoId_);

    /*! 
      @brief Define o nome do servidor.
      @param nome_ O nome do servidor.
    */
    void set_nome (string nome_);

    /*! 
      @brief Define a descricao do servidor.
      @param descricao_ A descricao do servidor.
    */
    void set_descricao (string descricao_);

    /*! 
      @brief Define o codigo de convite do servidor.
      @param codigoConvite_ O codigo de convite do servidor.
    */
    void set_codigoConvite (string codigoConvite_);

    /*! 
      @brief Recupera o id do usuario que criou o servidor.
      @return  Id do usuario que criou o servidor. 
    */
    int get_usuarioDonoId (void);

    /*! 
      @brief Recupera o nome do servidor.
      @return Nome do servidor. 
    */
    string get_nome (void) const;

    /*! 
      @brief Recupera a descricao do servidor.
      @return Descricao do servidor. 
    */
    string get_descricao (void) const;

    /*! 
      @brief Recupera o codigo de convite do servidor.
      @return Codigo de convite do servidor. 
    */
    string get_codigoConvite (void) const;

    /*! 
      @brief Adiciona um novo canal no vetor de canais.
      @param canal O canal que será adicionado. 
      @return returna true caso tenha conseguido adicionar o canal e false caso esse canal já esteja adicionado no vetor.
    */
    bool adicionar_canal (CanalTexto canal);

    /*! 
      @brief Adiciona o id do novo participante do servidor.
      @param id_participante_ O id do usuario que será adicionado. 
      @return returna true caso tenha conseguido adicionar o participante e false caso esse participando já esteja cadastrado.
    */
    bool adicionar_participante (int id_participante_);

    /*! 
      @brief Verifica se o usuario está cadastrado nesse servidor.
      @param id_participante_ O id do usuario que será verificado. 
      @return returna true caso o participante esteja cadastrado no servidor e false caso nao esteja cadastrado.
    */
    bool verificar_participante_existe(int id_participante_);

    /*! 
      @brief Verifica se o canal está cadastrado nesse servidor.
      @param nomeCanal_ O nome do canal que será verificado. 
      @return returna true caso o canal esteja cadastrado no servidor e false caso nao esteja cadastrado.
    */
    bool verificar_canal_existe (string nomeCanal_);

    /*! 
      @brief Remove o usuario do servidor pelo id.
      @param id_participante_ O id do usuario que será removido do servidor. 
      @return returna true a remoção tenha funcionado e false caso o usuario já tenha sido removido.
    */
    bool remover_participante(int id_participante_);

    /*! 
      @brief Adiciona uma nome mensagem em um determinado canal do servidor.
      @param nomeCanal_ O nome do canal que tera a nova mensagem cadastrada. 
      @param mensagem_ A mensagem que será cadastrada. 
      @param idUsuario_ O id do usuario que enviou a mensagem. 
      @return returna true caso a mensagem tenha sido adicionada com sucesso e false caso o canal informado não exista.
    */
    bool adicionar_mensagem_no_canal(string nomeCanal_, string mensagem_, int idUsuario_);
   
    /*! 
      @brief Lista o nome de todos os usuarios que estão cadastrados nesse servidor.
      @param usuarios O vetor contendo as informações pessoais dos usuarios.
    */
    void listar_nome_participantes (vector<Usuario> usuarios);

    /*! 
      @brief Lista o nome de todos os canais que estão cadastrados nesse servidor.
    */
    void listar_nome_canais (void);

    /*! 
      @brief Lista todas as mensagens de um determinado canal.
      @param nomeCanal_ O nome do canal que terá as mensagens exibidas
      @param usuarios_ O vetor contendo as informações pessoais dos usuarios.
    */
    void listar_mensagens_do_canal(string nomeCanal_, vector<Usuario> usuarios_);
};

#endif