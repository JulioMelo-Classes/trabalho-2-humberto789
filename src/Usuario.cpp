#include "Usuario.hpp"

void Usuario::set_id (int id_){
  id = id_;
}

void Usuario::set_nome (string nome_){
  nome = nome_;
}

void Usuario::set_email (string email_){
  email = email_;
}

void Usuario::set_senha (string senha_){
  senha = senha_;
}

int Usuario::get_id (void){
  return id;
}

string Usuario::get_nome (void) const{
  return nome;
}

string Usuario::get_email (void) const{
  return email;
}

string Usuario::get_senha (void) const{
  return senha;
}