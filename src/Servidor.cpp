#include "Servidor.hpp"

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