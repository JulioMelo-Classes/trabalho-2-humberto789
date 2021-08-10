#include "CanalTexto.hpp"

void CanalTexto::set_nome (string nome_){
  nome = nome_;
}

string CanalTexto::get_nome (void) const{
  return nome;
}

void CanalTexto::adicionar_mensagem (string mensagem_, int idUsuario_){

  Mensagem mensagem;
  mensagem.set_conteudo(mensagem_);
  mensagem.set_enviadaPor(idUsuario_);

  Servicos servicos;

  mensagem.set_dataHora(servicos.pegar_data_hora_do_sistema());

  mensagens.push_back(mensagem);

}

void CanalTexto::listar_mensagens_armazenadas(vector<Usuario> usuarios ){

  if(mensagens.size()!=0){

    for(int i = 0; i < mensagens.size(); i++){
      string texto;
      for(int j = 0; j < usuarios.size(); j++){
        if(mensagens[i].get_enviadaPor() == usuarios[j].get_id()){
          texto = usuarios[j].get_nome();
        }
      }
      texto = texto + "<" + mensagens[i].get_dataHora() + ">: " + mensagens[i].get_conteudo();

      cout << texto << endl;
    }

  }else{
    cout << "Sem mensagens para exibir" << endl;
  }
}