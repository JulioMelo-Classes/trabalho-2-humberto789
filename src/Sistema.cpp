#include "Sistema.hpp"
#include <stdio.h>
#include <string.h>
#include <map>

std::vector <Usuario> Sistema::get_usuarios (void){
  return usuarios;
}

bool Sistema::adicionar_usuario (Usuario usuario_){
  if(buscar_usuario_por_email(usuario_.get_email()).get_email().empty()){
    usuarios.push_back(usuario_);
    return true;
  }
  return false;
}

Usuario Sistema::buscar_usuario_por_email (string email){
  
  Usuario resultado;
  
  for(int i = 0; i<usuarios.size(); i++){
    if(usuarios[i].get_email() == email){
      resultado = usuarios[i];
    }
  }

  return resultado;
}

bool Sistema::logar_sistema (Usuario usuario_){
  if(usuarios.empty()){
    return false;
  }
  else{
    for(int i = 0; i<usuarios.size(); i++){

      if(usuarios[i].get_email() == usuario_.get_email() && usuarios[i].get_senha() == usuario_.get_senha()){
        
        usuario_ = buscar_usuario_por_email(usuario_.get_email());

        usuariosLogados[usuario_.get_id()] = make_pair("", "");
        return true;
      }
    }
    return false;
  }
}

bool Sistema::desconectar (Usuario usuario_) {
  if(usuariosLogados.empty()){
    return false;
  }
  else {
    for(auto i = usuariosLogados.begin(); i != usuariosLogados.end();){
      if(i->first == usuario_.get_id()){
        i = usuariosLogados.erase(i);
        return true;
      }
      else{
        i++;
      }
    }
    return false;
  }
}

Usuario Sistema::buscar_usuario_por_id(int id_){

  Usuario resultado;
  
  for(int i = 0; i<usuarios.size(); i++){
    if(usuarios[i].get_id() == id_){
      resultado = usuarios[i];
      
    }
  }
  return resultado;
}

bool Sistema::verificar_usuario_logado(Usuario usuario_){
  if(usuariosLogados.empty()){
    return false;
  }
  else {
    for(auto i = usuariosLogados.begin(); i != usuariosLogados.end();){
      if(i->first == usuario_.get_id()){
        return true;
      }
      else{
        i++;
      }
    }
    return false;
  }
}

bool Sistema::verificar_servidor_existe(string nome_){
  if(servidores.empty()){
    return false;
  }else{
    for(int i = 0; i<servidores.size(); i++){
      if(servidores[i].get_nome() == nome_){
        return true;
      }
    }
    return false;
  }
}

Servidor Sistema::buscar_servidor_por_nome(string nome_){
  
  Servidor resultado;
  
  if(servidores.empty()){
    return resultado;
  }else{
    for(int i = 0; i<servidores.size(); i++){
      if(servidores[i].get_nome() == nome_){
        resultado = servidores[i];
      }
    }
    return resultado;
  }
}

bool Sistema::adicionar_servidor (Servidor servidor_){
  if(!verificar_servidor_existe(servidor_.get_nome())){
    servidores.push_back(servidor_);
    return true;
  }
  return false;
}

bool Sistema::modificar_descricao (Servidor servidor_){
  for(int i = 0; i<servidores.size(); i++){
    if(servidores[i].get_usuarioDonoId() == servidor_.get_usuarioDonoId() && servidores[i].get_nome() == servidor_.get_nome()){
      servidores[i].set_descricao(servidor_.get_descricao());
      return true;
    }
  }
  return false;
}

bool Sistema::setar_codigo(Servidor servidor_){
  for(int i = 0; i<servidores.size(); i++){
    if(servidores[i].get_usuarioDonoId() == servidor_.get_usuarioDonoId()){
      servidores[i].set_codigoConvite(servidor_.get_codigoConvite());
      return true;
    }
  }
  return false;
}

std::vector<Servidor> Sistema::listar_servidor_usuarios(int usuarioId_){
  std::vector<Servidor> resultado;

  for(int i = 0; i<servidores.size(); i++){
    resultado.push_back(servidores[i]);
  }

  return resultado;
}

bool Sistema::remover_servidor (Servidor servidor_) {
  bool resultado = false;
  for(int i = 0; i<servidores.size(); i++){
    if((servidores[i].get_usuarioDonoId() == servidor_.get_usuarioDonoId()) && servidores[i].get_nome() == servidor_.get_nome()){

      servidores.erase(servidores.begin() + i);

      resultado = true;
    }
  }

  if(resultado){
    
    for(auto i = usuariosLogados.begin(); i != usuariosLogados.end();){

      if(servidor_.get_nome() == i->second.first){
        i->second.first = "";
        i->second.second = "";
      }
      else{
        i++;
      }
    }
  }

  return resultado;
}

bool Sistema::entrar_servidor (int idUsuario_, Servidor servidor_) {

  bool resultado = false;

  for(int i = 0; i<servidores.size(); i++){
    if(servidores[i].get_nome() == servidor_.get_nome()){

      if((idUsuario_ == servidores[i].get_usuarioDonoId()) || servidor_.get_codigoConvite() == servidores[i].get_codigoConvite()){
        if(servidores[i].adicionar_participante(idUsuario_) || servidores[i].verificar_participante_existe(idUsuario_)){

          for(auto j = usuariosLogados.begin(); j != usuariosLogados.end();){
            
            if(j->first == idUsuario_){
              j->second.first = servidores[i].get_nome();
              j = usuariosLogados.end();
            }else{
              j++;
            }
          }

          resultado = true;
        }
      }
    }
  }
  return resultado;
}

bool Sistema::sair_servidor(int idUsuario_, Servidor servidor_){
  for(int i = 0; i<servidores.size(); i++){
    if(servidores[i].get_nome() == servidor_.get_nome()){
      if(servidores[i].remover_participante(idUsuario_)){

        for(auto j = usuariosLogados.begin(); j != usuariosLogados.end();){
          
          if(j->first == idUsuario_ && servidores[i].get_nome() == j->second.first){

            j->second.first = "";
            j->second.second = "";
            j = usuariosLogados.end();
          }else{
            j++;
          }
        }

        return true;
      }
    }
  }
  return false;
}

void  Sistema::listar_usuarios_no_servidor (int idUsuario_) {

  string nomeServidor;

  for(auto i = usuariosLogados.begin(); i != usuariosLogados.end();){
            
    if(i->first == idUsuario_){
      nomeServidor = i->second.first;
      i = usuariosLogados.end();
    }else{
      i++;
    }
  }

  if(!nomeServidor.empty()){

    Servidor servidor = buscar_servidor_por_nome(nomeServidor);

    servidor.listar_nome_participantes(usuarios);
  }
}

void Sistema::listar_canais_no_servidor (int idUsuario_){
  string nomeServidor;

  for(auto i = usuariosLogados.begin(); i != usuariosLogados.end();){
            
    if(i->first == idUsuario_){
      nomeServidor = i->second.first;
      i = usuariosLogados.end();
    }else{
      i++;
    }
  }

  if(!nomeServidor.empty()){

    Servidor servidor = buscar_servidor_por_nome(nomeServidor);

    servidor.listar_nome_canais();
  }
}

Servidor Sistema::recuperar_servidor_visualizado(int idUsuario_){
  
  Servidor servidorVisualizado;
  string nomeServidor;

  for(auto i = usuariosLogados.begin(); i != usuariosLogados.end();){
            
    if(i->first == idUsuario_){
      nomeServidor = i->second.first;
      i = usuariosLogados.end();
    }else{
      i++;
    }
  }

  if(!nomeServidor.empty()){
    servidorVisualizado = buscar_servidor_por_nome(nomeServidor);
  }
  return servidorVisualizado;
}

bool Sistema::criar_canal_texto(int idUsuario_, string nomeCanal_){
  
  Servidor servidorVisualizado = recuperar_servidor_visualizado(idUsuario_);

  if(!servidorVisualizado.get_nome().empty()){

    for(int i = 0;  i<servidores.size(); i++){

      if(servidores[i].get_nome() == servidorVisualizado.get_nome()){

        if(!servidores[i].verificar_canal_existe(nomeCanal_)){

          CanalTexto canal;
          canal.set_nome(nomeCanal_);

          servidores[i].adicionar_canal(canal);
          return true;
        }
      }
    }
  }
  return false;
}

bool Sistema::entrar_canal_texto(int idUsuario_, string nomeCanal_){

  Servidor servidorVisualizado = recuperar_servidor_visualizado(idUsuario_);

  if(!servidorVisualizado.get_nome().empty()){

    for(int i = 0;  i<servidores.size(); i++){

      if(servidores[i].get_nome() == servidorVisualizado.get_nome()){

        if(servidores[i].verificar_canal_existe(nomeCanal_)){

          for(auto j = usuariosLogados.begin(); j != usuariosLogados.end();){
            
            if(j->first == idUsuario_ && servidores[i].get_nome() == j->second.first){

              j->second.second = nomeCanal_;

              return true;
            }else{
              j++;
            }
          }
        }
      }
    }
  }
  return false;
}

bool Sistema::sair_canal_texto(int idUsuario_){
  Servidor servidorVisualizado = recuperar_servidor_visualizado(idUsuario_);

  if(!servidorVisualizado.get_nome().empty()){

    for(auto i = usuariosLogados.begin(); i != usuariosLogados.end();){
      
      if(i->first == idUsuario_ && servidorVisualizado.get_nome() == i->second.first){
        
        if(i->second.second != ""){
          i->second.second = "";
          return true;
        }
        return false;

      }else{
        i++;
      }
    }
  }
  return false;
}

bool Sistema::enviar_mensagem(int idUsuario_, string mensagem_){

  Servidor servidorVisualizado = recuperar_servidor_visualizado(idUsuario_);

  if(!servidorVisualizado.get_nome().empty()){

    for(int i = 0;  i<servidores.size(); i++){

      if(servidores[i].get_nome() == servidorVisualizado.get_nome()){

        for(auto j = usuariosLogados.begin(); j != usuariosLogados.end();){
          
          if(j->first == idUsuario_ && servidores[i].get_nome() == j->second.first){

            if(j->second.second != ""){
              string nomeCanal = j->second.second;
              servidores[i].adicionar_mensagem_no_canal(nomeCanal, mensagem_, idUsuario_);

              return true;
            }
            return false;

          }else{
            j++;
          }
        }
        
      }
    }
  }
  return false;
}

bool Sistema::listar_mensagens(int idUsuario_){

  Servidor servidorVisualizado = recuperar_servidor_visualizado(idUsuario_);

  if(!servidorVisualizado.get_nome().empty()){

    for(int i = 0;  i<servidores.size(); i++){

      if(servidores[i].get_nome() == servidorVisualizado.get_nome()){

        for(auto j = usuariosLogados.begin(); j != usuariosLogados.end();){
          
          if(j->first == idUsuario_ && servidores[i].get_nome() == j->second.first){

            if(j->second.second != ""){
              string nomeCanal = j->second.second;
              servidores[i].listar_mensagens_do_canal(nomeCanal, usuarios);

              return true;
            }
            return false;

          }else{
            j++;
          }
        }
        
      }
    }
  }
  return false;
} 