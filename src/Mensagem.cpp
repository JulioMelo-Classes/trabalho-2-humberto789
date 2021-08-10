#include "Mensagem.hpp"

void Mensagem::set_dataHora (string dataHora_){
  dataHora = dataHora_;
}


void Mensagem::set_enviadaPor (int enviadaPor_){
  enviadaPor = enviadaPor_;
}

void Mensagem::set_conteudo (string conteudo_){
  conteudo = conteudo_;
}

string Mensagem::get_dataHora (void){
  return dataHora;
}

int Mensagem::get_enviadaPor (void) const{
  return enviadaPor;
}

string Mensagem::get_conteudo (void) const{
  return conteudo;
}