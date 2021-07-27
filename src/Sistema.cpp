#include "Sistema.hpp"
#include <stdio.h>
#include <string.h>
#include <map>

std::vector <Usuario> Sistema::get_usuarios (void){
  return usuarios;
}

int Sistema::get_qtdUsuarios (void) const{
  return usuarios.size();
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
    if(strcmp(usuarios[i].get_email().c_str(), email.c_str()) == 0){
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

      if(strcmp(usuarios[i].get_email().c_str(), usuario_.get_email().c_str()) == 0 && strcmp(usuarios[i].get_senha().c_str(), usuario_.get_senha().c_str()) == 0){
        
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
      if(strcmp(servidores[i].get_nome().c_str(), nome_.c_str()) == 0){
        return true;
      }
    }
    return false;
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
    if((servidores[i].get_usuarioDonoId() == servidor_.get_usuarioDonoId()) && (strcmp(servidores[i].get_nome().c_str(), servidor_.get_nome().c_str()) == 0)){
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
    if(servidores[i].get_usuarioDonoId() == usuarioId_){
      resultado.push_back(servidores[i]);
    }
  }

  return resultado;
}

bool Sistema::remover_servidor (Servidor servidor_) {
  bool resultado = false;
  for(int i = 0; i<servidores.size(); i++){
    if((servidores[i].get_usuarioDonoId() == servidor_.get_usuarioDonoId()) && (strcmp(servidores[i].get_nome().c_str(), servidor_.get_nome().c_str()) == 0)){

      servidores.erase(servidores.begin() + i);

      resultado = true;
    }
  }

  if(resultado){
    
    for(auto i = usuariosLogados.begin(); i != usuariosLogados.end();){

      if(strcmp(servidor_.get_nome().c_str(), i->second.first.c_str()) == 0){
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