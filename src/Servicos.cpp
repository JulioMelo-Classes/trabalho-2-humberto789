#include "Servicos.hpp"
#include "Usuario.hpp"
#include <stdio.h>
#include <string.h>
#include <time.h>

//Verifica se uma string é um float
bool Servicos::stringIsInteger(const string& str){
  int contadorNumero = 0;
  int contadorPonto = 0;
  for (char const &c : str) {
      if (isdigit(c) == 0 ){
        return false;
      }
      else{
        contadorNumero++;
      }
  }
  if(contadorNumero>=1){
    return true;
  }
  return false;
}

std::vector<string> Servicos::separador_linha_comando(string comando){

  vector<string> resultado;

  if(comando.empty()){
    return resultado;
  }

  
  string auxiliar = "";
  int contador = 0;

  for(char const &c : comando){

    if(c == ' '){
      resultado.push_back(auxiliar);
      auxiliar = "";
    }
    else{
      auxiliar = auxiliar+c;
    }

    if (contador == comando.size()-1){
      resultado.push_back(auxiliar);
    }

    contador++;
  }
  return resultado;
}

string Servicos::pegar_data_hora_do_sistema ( void ){
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);

  string resultado = std::to_string(data_hora_atual->tm_mday) + " / " + std::to_string(data_hora_atual->tm_mon+1) + " / " + std::to_string(data_hora_atual->tm_year+1900) + " - " + std::to_string(data_hora_atual->tm_hour) + ":" + std::to_string(data_hora_atual->tm_min);

  return resultado;

}