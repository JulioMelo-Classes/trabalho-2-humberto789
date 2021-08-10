#ifndef Sistema_hpp
#define Sistema_hpp

#include <vector>
#include <iostream>
#include <map>
#include "Usuario.hpp"
#include "Servidor.hpp"
#include "CanalTexto.hpp"

using namespace std;

class Sistema{
  private:
    std::vector< Usuario > usuarios;
    std::vector< Servidor > servidores;
    map<int, std::pair<string, string> > usuariosLogados;

  public:

    /*! 
      @brief Adiciona um novo usuario ao sistema.
      @param usuario_ Usuario que será cadastrado. 
      @return retorna true caso tenha conseguido efetuar o cadastro do usuario e false caso esse usuario já esteja cadastrado.
    */
    bool adicionar_usuario (Usuario usuario_);

    /*! 
      @brief Adiciona um novo servidor ao sistema.
      @param servidor Servidor que será cadastrado. 
      @return retorna true caso tenha conseguido efetuar o cadastro do servidor e false caso esse servidor já tenha sido cadastrado.
    */
    bool adicionar_servidor (Servidor servidor);

    /*! 
      @brief Loga o usuario no sistema e salva suas informações.
      @param usuario Usuario que será logado. 
      @return retorna true caso o usuario tenha conseguido logar no sistema e false caso a senha e/ou o email estejam errados.
    */
    bool logar_sistema (Usuario usuario);

    /*! 
      @brief Desconectar o usuario do sistema.
      @param usuario Usuario que será desconectado. 
      @return retorna true caso o usuario tenha conseguido desconectar do sistema e false caso esse usuario já esteja desconectado.
    */
    bool desconectar (Usuario usuario_);

    /*! 
      @brief Verfica pelo nome se um determinado servidor está cadastrado no sistema .
      @param nome_ O nome do servidor. 
      @return retorna true caso o servidor exista e false caso o servidor não exista.
    */
    bool verificar_servidor_existe(string nome_);

    /*! 
      @brief Verifica se o usuario está logado no sistema.
      @param usuario_ O usuario que será verificado. 
      @return retorna true caso o usuario esteja logado false caso o usuario esteja deslogado.
    */
    bool verificar_usuario_logado(Usuario usuario_);

    /*! 
      @brief Modifica a descricao de um determinado servidor.
      @param servidor_ Servidor já com a descrição modificada. 
      @return retorna true caso a modificação foi realizada com sucesso e false caso o servidor não exista.
    */
    bool modificar_descricao (Servidor servidor_);

    /*! 
      @brief Adiciona um codigo de convite em um determinado servidor.
      @param servidor_ Servidor já com o codigo de convite novo. 
      @return retorna true caso a modificação foi realizada com sucesso e false caso o servidor não exista.
    */
    bool setar_codigo(Servidor servidor_);

    /*! 
      @brief Remove um determinado servidor do sistema.
      @param servidor_ Servidor que será removido. 
      @return retorna true caso a remoção foi realizada com sucesso e false caso o servidor não exista.
    */
    bool remover_servidor (Servidor servidor_);

    /*! 
      @brief Realiza a conexão do usuario a um servidor.
      @param idUsuario_ Id do usuario que vai se conectar ao servidor.
      @param servidor_ Servidor que o usuario vai se conectar. 
      @return retorna true caso a conexão tenha sido realizada com sucesso e false caso o servidor não exista.
    */
    bool entrar_servidor (int idUsuario_, Servidor servidor_);

    /*! 
      @brief Realiza a saida do usuario de um servidor.
      @param idUsuario_ Id do usuario que vai sair do servidor.
      @param servidor_ Servidor que o usuario vai sair. 
      @return retorna true caso a saida tenha sido realizada com sucesso e false caso o servidor não exista.
    */
    bool sair_servidor(int idUsuario_, Servidor servidor_);

    /*! 
      @brief Cadastra um novo canal de texto no servidor visualizado pelo usuario.
      @param idUsuario_ Id do usuario.
      @param nomeCanal_ Nome do novo canal de texto. 
      @return retorna true caso o canal tenha sido cadastrado com sucesso e false caso o canal já tenha sido cadastrado no servidor.
    */
    bool criar_canal_texto(int idUsuario_, string nomeCanal_);

    /*! 
      @brief Realiza a entrada do usuario a um canal de texto do servidor visualizado por ele.
      @param idUsuario_ Id do usuario.
      @param nomeCanal_ Nome do novo canal de texto. 
      @return retorna true caso o usuario tenha consigo entrar no canal de texto e false caso o usuario já esteja no canal de texto.
    */
    bool entrar_canal_texto(int idUsuario_, string nomeCanal_);

    /*! 
      @brief Realiza a saida do usuario do canal de texto do servidor visualizado por ele.
      @param idUsuario_ Id do usuario.
      @return retorna true caso o usuario tenha consigo sair no canal de texto e false caso o usuario não esteja visualizado nenhum servidor.
    */
    bool sair_canal_texto(int idUsuario_);

    /*! 
      @brief Cadastra uma nova mensagem no canal de texto visualizado pelo usuario
      @param idUsuario_ Id do usuario.
      @param mensagem_ Mensagem que será cadastrada. 
      @return retorna true caso a mensagem tenha sido cadastrada com sucesso false cado o canal não exista.
    */
    bool enviar_mensagem(int idUsuario_, string mensagem_);

    /*! 
      @brief Lista todas as mensagem que estão no canal de texto visualizado pelo usuario
      @param idUsuario_ Id do usuario.
      @return retorna true caso a listagem tenha acontecido com sucesso false caso o canal não exista.
    */
    bool listar_mensagens(int idUsuario_);

    /*! 
      @brief Recupera do sistema um Usuario pelo id dele.
      @param id_ Id do usuario.
      @return retorna o usuario recuperado.
    */
    Usuario buscar_usuario_por_id (int id_);

    /*! 
      @brief Recupera do sistema um Usuario pelo email dele.
      @param email Email do usuario.
      @return retorna o usuario recuperado.
    */
    Usuario buscar_usuario_por_email (string email);

    /*! 
      @brief Recupera do sistema um Servidor pelo seu nome.
      @param nome_ Nome do servidor.
      @return retorna o servidor recuperado.
    */
    Servidor buscar_servidor_por_nome(string nome_);

    /*! 
      @brief Recupera o servidor que está sendo visualizado pelo usuario.
      @param idUsuario_ Id do usuario.
      @return retorna o servidor visualizado.
    */
    Servidor recuperar_servidor_visualizado(int idUsuario_);

    /*! 
      @brief Recupera todos os usuarios cadastrados no sistema.
      @return retorna um vetor com todos os usuarios cadastrados no sistema.
    */
    std::vector <Usuario> get_usuarios (void);

    /*! 
      @brief Exibe os nomes dos servidores no sistema.
      @return retorna um vetor como todos os servidores cadastrados.
    */
    std::vector<Servidor> listar_servidor_usuarios (int usuarioId_);

    /*! 
      @brief Lista todos os servidores do sistema, somente se o usuario estiver logado.
      @param idUsuario_ Id do usuario.
    */
    void listar_usuarios_no_servidor (int idUsuario_);

    /*! 
      @brief Lista todos os canais que estão cadastrados no servidor que está sendo visualizado pelo usuario.
      @paramm idUsuario_ Id do usuario.
    */
    void listar_canais_no_servidor (int idUsuario_); 
};

#endif