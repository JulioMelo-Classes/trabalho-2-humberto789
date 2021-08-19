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

    if(comando[0] == '#' || comando.size() == 0){ //debug apenas
      cout<<comando<<endl;
      continue;
    }
    
    vector<string> dadosComando = servicos.separador_linha_comando(comando);
    
    // Etapa: Fim do programa
    if(comando == "quit"){
      cout << "Saindo do Concordo" << endl;
      break;
    }
    // Etapa: Criação de um novo Usuario
    else if(dadosComando[0] == "create-user"){
      
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
    else if (dadosComando[0] == "login"){
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
    else if (dadosComando[0] == "disconnect"){

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
    else if (dadosComando[0] == "create-server"){
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
    else if (dadosComando[0] == "set-server-desc"){
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
                cout << "Descrição do servidor '" << servidorDescricao.get_nome() << "' modificada!" << endl;
              }else{
                cout << "Você não pode alterar a descrição de um servidor que não foi criado por você" << endl;
              }
            }else {
              cout << "Servidor '" << servidorDescricao.get_nome() <<"' não existe" << endl;
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
    else if(dadosComando[0] == "set-server-invite-code"){
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
                  cout << "Código de convite do servidor '" << servidorCodigo.get_nome() << "' removido!" << endl;
                }else {
                  cout << "Código de convite do servidor '" << servidorCodigo.get_nome() << "' modificado!" << endl;
                }
              }else{
                cout << "Você não pode alterar o codigo de convite de um servidor que não foi criado por você" << endl;
              }
            }else {
              cout << "Servidor '" << servidorCodigo.get_nome() <<"' não existe" << endl;
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
    else if(dadosComando[0] == "list-servers"){
      if(dadosComando.size()<2){
        cout << "Informe os campos que restam" << endl;
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
    else if(dadosComando[0] == "remove-server"){
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
                cout << "Servidor '" << servidorRemovido.get_nome() << "' removido" << endl;
              }else{
                cout << "Você não é o dono do servidor '" << servidorRemovido.get_nome() << "'" << endl;
              }
            }else {
              cout << "Servidor '" << servidorRemovido.get_nome() <<"' não existe" << endl;
            }
          }else{
            cout << "Você não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Entrar em um servidor
    else if(dadosComando[0] == "enter-server"){
      if(dadosComando.size()<3){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          Servidor servidor;
          servidor.set_nome(dadosComando[2]);

          if(dadosComando[3].empty() || dadosComando.size()==3){
            servidor.set_codigoConvite("");
          }else{
            servidor.set_codigoConvite(dadosComando[3]);
          }

          if(sistema.verificar_usuario_logado(usuarioDono)){
            if(sistema.verificar_servidor_existe(servidor.get_nome())){
              if(sistema.entrar_servidor(idUsuario, servidor)){

                cout << "Entrou no servidor com sucesso" << endl;
              }else{
                cout << "Servidor requer código de convite" << endl;
              }
            }else {
              cout << "Servidor '" << servidor.get_nome() <<"' não existe" << endl;
            }
          }else{
            cout << "Você não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Sair do servidor
    else if(dadosComando[0] == "leave-server"){
      if(dadosComando.size()<3){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          Servidor servidor;
          servidor.set_nome(dadosComando[2]);

          if(sistema.verificar_usuario_logado(usuarioDono)){
            if(sistema.verificar_servidor_existe(servidor.get_nome())){
              if(sistema.sair_servidor(idUsuario, servidor)){

                cout << "Saindo do servidor '"<< servidor.get_nome() << "'" << endl;
              }else{
                cout << "Você não está conectado nesse servidor" << endl;
              }
            }else {
              cout << "Servidor '" << servidor.get_nome() <<"' não existe" << endl;
            }
          }else{
            cout << "Você não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Listar pessoas no servidor
    else if(dadosComando[0] == "list-participants"){
      if(dadosComando.size()<2){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          if(sistema.verificar_usuario_logado(usuarioDono)){

            sistema.listar_usuarios_no_servidor (idUsuario);
          }else{
            cout << "Você não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Listar canais do servidor
    else if(dadosComando[0] == "list-channels"){
      if(dadosComando.size()<2){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          if(sistema.verificar_usuario_logado(usuarioDono)){

            sistema.listar_canais_no_servidor (idUsuario);
          }else{
            cout << "Você não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Criar um canal do servidor
    else if(dadosComando[0] == "create-channel"){
      if(dadosComando.size()<3){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          if(sistema.verificar_usuario_logado(usuarioDono)){
            
            Servidor servidor = sistema.recuperar_servidor_visualizado(idUsuario);

            if(!servidor.get_nome().empty()){

              if(sistema.criar_canal_texto(idUsuario, dadosComando[2])){
                cout << "Canal de texto '" << dadosComando[2] <<"' criado" << endl;
              }else{
                cout << "Canal de texto '" << dadosComando[2] <<"' já existe" << endl;
              }

            }else{
              cout << "Usuario não está visualizando nenhum servidor" << endl;
            }
          }else{
            cout << "Você não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Entrar em um canal
    else if(dadosComando[0] == "enter-channel"){
      if(dadosComando.size()<3){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          if(sistema.verificar_usuario_logado(usuarioDono)){
            
            Servidor servidor = sistema.recuperar_servidor_visualizado(idUsuario);

            if(!servidor.get_nome().empty()){

              if(sistema.entrar_canal_texto(idUsuario, dadosComando[2])){
                cout << "Entrou no canal '" << dadosComando[2] <<"'" << endl;
              }else{
                cout << "Canal '" << dadosComando[2] <<"' não existe" << endl;
              }

            }else{
              cout << "Usuario não está visualizando nenhum servidor" << endl;
            }
          }else{
            cout << "Você não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Sair de um canal
    else if(dadosComando[0] == "leave-channel"){
      if(dadosComando.size()<2){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          if(sistema.verificar_usuario_logado(usuarioDono)){
            
            Servidor servidor = sistema.recuperar_servidor_visualizado(idUsuario);

            if(!servidor.get_nome().empty()){

              if(sistema.sair_canal_texto(idUsuario)){
                cout << "Saindo do canal" << endl;
              }else{
                cout << "Você já não está visualizando nenhum canal" << endl;
              }

            }else{
              cout << "Usuario não está visualizando nenhum servidor" << endl;
            }
          }else{
            cout << "Você não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Enviar mensagem para o canal
    else if(dadosComando[0] == "send-message"){
      if(dadosComando.size()<2){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        string mensagem;

        for(int i = 2; i<dadosComando.size(); i++){
          mensagem = mensagem + dadosComando[i];
          if(i!=dadosComando.size()-1){
            mensagem = mensagem + " ";
          }
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          if(sistema.verificar_usuario_logado(usuarioDono)){
            
            Servidor servidor = sistema.recuperar_servidor_visualizado(idUsuario);

            if(!servidor.get_nome().empty()){

              if(sistema.enviar_mensagem(idUsuario, mensagem)){
                cout << "Mensagem enviada" << endl;
              }else{
                cout << "Você já não está visualizando nenhum canal" << endl;
              }

            }else{
              cout << "Usuario não está visualizando nenhum servidor" << endl;
            }
          }else{
            cout << "Você não está conectado" << endl;
          }

        }else {
          cout << "Este usuario não existe" << endl;
        }
      }
    }
    //Etapa: Visualizar mensagens do canal
    else if(dadosComando[0] == "list-messages"){
      if(dadosComando.size()<2){
        cout << "Informe os campos" << endl;
      }else{
        int idUsuario = -1;

        if(servicos.stringIsInteger(dadosComando[1])){
          idUsuario = stoi(dadosComando[1]);
        }

        Usuario usuarioDono = sistema.buscar_usuario_por_id(idUsuario);

        if(!usuarioDono.get_email().empty()){
          
          if(sistema.verificar_usuario_logado(usuarioDono)){
            
            Servidor servidor = sistema.recuperar_servidor_visualizado(idUsuario);

            if(!servidor.get_nome().empty()){

              if(sistema.listar_mensagens(idUsuario)){
              }else{
                cout << "Você já não está visualizando nenhum canal" << endl;
              }

            }else{
              cout << "Usuario não está visualizando nenhum servidor" << endl;
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
