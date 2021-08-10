#include "Servidor.hpp"
#include <stdio.h>
#include <string.h>

void Servidor::set_usuarioDonoId (int usuarioDonoId_){
  usuarioDonoId = usuarioDonoId_;
}

void Servidor::set_nome (string nome_){
  nome = nome_;
}

void Servidor::set_descricao (string descricao_){
  descricao = descricao_;
}

void Servidor::set_codigoConvite (string codigoConvite_){
  codigoConvite = codigoConvite_;
}

int Servidor::get_usuarioDonoId (void){
  return usuarioDonoId;
}

string Servidor::get_nome (void) const{
  return nome;
}

string Servidor::get_descricao (void) const{
  return descricao;
}

string Servidor::get_codigoConvite (void) const{
  return codigoConvite;
}

bool Servidor::verificar_participante_existe(int id_participante_){
  
  for(int i = 0; i < participantesIDs.size(); i++){
    if(participantesIDs[i] == id_participante_){
      return true;
    }
  }
  return false;
}

bool Servidor::adicionar_participante (int id_participante_){

  if(!verificar_participante_existe(id_participante_)){
    participantesIDs.push_back(id_participante_);
    return true;
  }
  return false;
}

bool Servidor::adicionar_canal (CanalTexto canal_){
  if(!canal_.get_nome().empty()){
    canaisTexto.push_back(canal_);
    return true;
  }
  return false;
}

bool Servidor::remover_participante(int id_participante_) {
  
  for(int i = 0; i<participantesIDs.size(); i++){
    if(participantesIDs[i] == id_participante_){

      participantesIDs.erase(participantesIDs.begin() + i);

      return true;
    }
  }

  return false;
}

void Servidor::listar_nome_participantes (vector<Usuario> usuarios){
  for(int i = 0; i<participantesIDs.size(); i++){
    
    for(int j = 0; j<usuarios.size(); j++){
      if(participantesIDs[i] == usuarios[j].get_id()){
        cout << usuarios[j].get_nome() << endl;
        j = usuarios.size();
      }
    }
  }
}

void Servidor::listar_nome_canais (void) {

  for(int i = 0; i < canaisTexto.size(); i++){
    cout << "#" << canaisTexto[i].get_nome() << endl;
  }

};

bool Servidor::verificar_canal_existe (string nomeCanal_){
  
  for(int i = 0; i < canaisTexto.size(); i++){

    if(canaisTexto[i].get_nome() == nomeCanal_){
      return true;
    }
  }
  return false;
}

bool Servidor::adicionar_mensagem_no_canal(string nomeCanal_, string mensagem_, int idUsuario_){

  for(int i = 0; i < canaisTexto.size(); i++){
    if(canaisTexto[i].get_nome() == nomeCanal_){
      canaisTexto[i].adicionar_mensagem(mensagem_, idUsuario_);
      return true;
    }
  }
  return false;
}

void Servidor::listar_mensagens_do_canal(string nomeCanal_, vector<Usuario> usuarios_){
  for(int i = 0; i < canaisTexto.size(); i++){
    if(canaisTexto[i].get_nome() == nomeCanal_){
      canaisTexto[i].listar_mensagens_armazenadas(usuarios_);
    }
  }
}