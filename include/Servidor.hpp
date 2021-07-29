#ifndef Servidor_hpp
#define Servidor_hpp

#include <vector>
#include <iostream>
#include "CanalTexto.hpp"

using namespace std;

/*
CP1 classe servidor ok!
*/
class Servidor{
  private:
      int usuarioDonoId;
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

    bool adicionar_canalTexto (CanalTexto canalTexto_);

    bool adicionar_participante (int id_participante);

    int get_qtdParticipantes (void) const;

    int get_qtdCanaisTexto (void) const;    
};

#endif