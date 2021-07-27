#ifndef Sistema_hpp
#define Sistema_hpp

#include <vector>
#include <iostream>
#include <map>
#include "Usuario.hpp"
#include "Servidor.hpp"

using namespace std;

class Sistema{
  private:
    std::vector< Usuario > usuarios;
    std::vector< Servidor > servidores;
    map<int, std::pair<string, string> > usuariosLogados;

  public:

    bool adicionar_usuario (Usuario usuario_);

    bool adicionar_servidor (Servidor servidor);

    bool logar_sistema (Usuario usuario);

    bool desconectar (Usuario usuario_);

    bool verificar_servidor_existe(string nome_);

    bool verificar_usuario_logado(Usuario usuario_);

    bool modificar_descricao (Servidor servidor_);

    bool setar_codigo(Servidor servidor_);

    bool remover_servidor (Servidor servidor_);

    Usuario buscar_usuario_por_id (int id_);

    Usuario buscar_usuario_por_email (string email);

    std::vector <Usuario> get_usuarios (void);

    std::vector <Servidor> get_servidor (void);

    std::vector<Servidor> listar_servidor_usuarios(int usuarioId_);

    int get_qtdUsuarios (void) const;

    int get_qtdUsuariosLogados (void) const;

    int get_qtdServidores (void) const;    
};

#endif