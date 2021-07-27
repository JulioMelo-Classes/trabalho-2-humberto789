#include "CanalTexto.hpp"
#include "Mensagem.hpp"
#include "Usuario.hpp"
#include "Sistema.hpp"
#include "Servidor.hpp"
#include "Servicos.hpp"

#include <iostream>   // cout, endl
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int main( int argc, char *argv[] ){

  Sistema sistema;
  Servicos servicos;
  int incrementadorIdUsuario = 0;

  string comando;
  while(true){
    
    std::getline(std::cin, comando);

    vector<string> dadosComando = servicos.separador_linha_comando(comando);

    // Etapa: Fim do programa
    if(strcmp(comando.c_str(),"quit")==0){
      cout << "Saindo do Concordo" << endl;
      break;
    }
    // Etapa: Criação de um novo Usuario
    else if(strcmp(dadosComando[0].c_str(), "create-user")==0){
      
      Usuario usuarioCriado;

      usuarioCriado.set_id(incrementadorIdUsuario);
      usuarioCriado.set_email(dadosComando[1]);
      usuarioCriado.set_senha(dadosComando[2]);

      string aux = "";

      for(int i = 3; i<dadosComando.size(); i++){
        aux = aux + dadosComando[i];
        if(i!=dadosComando.size()-1){
          aux = aux + " ";
        }
      }

      usuarioCriado.set_nome(aux);

      cout << "Criando usuário " << usuarioCriado.get_nome() << endl;

      if(sistema.adicionar_usuario(usuarioCriado)){
        incrementadorIdUsuario++;
        cout << "Usuário criado" << endl;
      }else{
        cout << "Usuário já existe!" << endl;
      }
    }
    //Etapa: Login Usuario Sistema
    else if (strcmp(dadosComando[0].c_str(), "login")==0){
      Usuario usuarioLogin;

      usuarioLogin.set_email(dadosComando[1]);
      usuarioLogin.set_senha(dadosComando[2]);

      if(usuarioLogin.get_email().empty()){
        cout << "Senha ou usuário inválidos!" << endl;
      }
      else if(sistema.logar_sistema(usuarioLogin)){
        cout << "Logado como " << usuarioLogin.get_email() << endl;
      }else{
        cout << "Senha ou usuário inválidos!" << endl;
      }

    }
    //Etapa: Desconectar
    else if (strcmp(dadosComando[0].c_str(), "disconnect")==0){

      if(dadosComando.size()<2){
        cout << "Não está conectado" << endl;
      }
      else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDesconectado = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDesconectado.get_email().empty()){
          if(sistema.desconectar(usuarioDesconectado)){
            cout << "Desconectando usuário " << usuarioDesconectado.get_email() << endl;
          }
          else {
            cout << "Não está conectado" << endl;
          }
        }else{
          cout << "Não está conectado" << endl;
        }
      }
    }
    //Etapa: Criação do Servidor
    else if (strcmp(dadosComando[0].c_str(), "create-server")==0){
      if(dadosComando.size()<3){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          Servidor servidorCriado;
          servidorCriado.set_usuarioDonoId(idUsuario);
          servidorCriado.set_nome(dadosComando[2]);

          if(sistema.verificar_usuario_logado(usuarioDono)){
            if(sistema.adicionar_servidor(servidorCriado)){
              cout << "Servidor criado" << endl;
            }else {
              cout << "Servidor com esse nome já existe" << endl;
            }
          }else{
            cout << "Não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Mudar descricao do servidor
    else if (strcmp(dadosComando[0].c_str(), "set-server-desc")==0){
      if(dadosComando.size()<4){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          Servidor servidorDescricao;
          servidorDescricao.set_usuarioDonoId(idUsuario);
          servidorDescricao.set_nome(dadosComando[2]);

          string descricao;

          for(int i = 3; i<dadosComando.size(); i++){
            descricao = descricao + dadosComando[i];
            if(i!=dadosComando.size()-1){
              descricao = descricao + " ";
            }
          }

          servidorDescricao.set_descricao(descricao);

          if(sistema.verificar_usuario_logado(usuarioDono)){
            if(sistema.verificar_servidor_existe(servidorDescricao.get_nome())){
              if(sistema.modificar_descricao(servidorDescricao)){
                cout << "Descrição do servidor ‘" << servidorDescricao.get_nome() << "’ modificada!" << endl;
              }else{
                cout << "Você não pode alterar a descrição de um servidor que não foi criado por você" << endl;
              }
            }else {
              cout << "Servidor ‘" << servidorDescricao.get_nome() <<"’ não existe" << endl;
            }
          }else{
            cout << "Não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Setar codigo de convite do servidor
    else if(strcmp(dadosComando[0].c_str(), "set-server-invite-code")==0){
      if(dadosComando.size()<3){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          Servidor servidorCodigo;
          servidorCodigo.set_usuarioDonoId(idUsuario);
          servidorCodigo.set_nome(dadosComando[2]);
          if(dadosComando[3].empty() || dadosComando.size()==3){
            servidorCodigo.set_codigoConvite("");
          }else{
            servidorCodigo.set_codigoConvite(dadosComando[3]);
          }

          if(sistema.verificar_usuario_logado(usuarioDono)){
            if(sistema.verificar_servidor_existe(servidorCodigo.get_nome())){
              if(sistema.setar_codigo(servidorCodigo)){
                if(servidorCodigo.get_codigoConvite()==""){
                  cout << "Código de convite do servidor ‘" << servidorCodigo.get_nome() << "’ removido!" << endl;
                }else {
                  cout << "Código de convite do servidor ‘" << servidorCodigo.get_nome() << "’ modificado!" << endl;
                }
              }else{
                cout << "Você não pode alterar o codigo de convite de um servidor que não foi criado por você" << endl;
              }
            }else {
              cout << "Servidor ‘" << servidorCodigo.get_nome() <<"’ não existe" << endl;
            }
          }else{
            cout << "Não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Listar Servidores
    else if(strcmp(dadosComando[0].c_str(), "list-servers")==0){
      if(dadosComando.size()<2){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuario = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuario.get_email().empty()){
          if(sistema.verificar_usuario_logado(usuario)){
            
            vector<Servidor> listaServidores = sistema.listar_servidor_usuarios(idUsuario);

            for(int i = 0; i<listaServidores.size(); i++){
              cout << listaServidores[i].get_nome() << endl;
            }

          }else{
            cout << "Não está conectado" << endl;
          }
        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Remover servidor
    else if(strcmp(dadosComando[0].c_str(), "remove-server")==0){
      if(dadosComando.size()<3){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          Servidor servidorRemovido;
          servidorRemovido.set_usuarioDonoId(idUsuario);
          servidorRemovido.set_nome(dadosComando[2]);

          if(sistema.verificar_usuario_logado(usuarioDono)){
            if(sistema.verificar_servidor_existe(servidorRemovido.get_nome())){
              if(sistema.remover_servidor(servidorRemovido)){
                cout << "Servidor ‘" << servidorRemovido.get_nome() << "’ removido" << endl;
              }else{
                cout << "Você não é o dono do servidor ‘" << servidorRemovido.get_nome() << "’" << endl;
              }
            }else {
              cout << "Servidor ‘" << servidorRemovido.get_nome() <<"’ não existe" << endl;
            }
          }else{
            cout << "Você não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
  }

}