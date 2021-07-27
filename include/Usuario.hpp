#ifndef Usuario_hpp
#define Usuario_hpp

#include <vector>
#include <iostream>

using namespace std;

class Usuario{
  private:
      int id;
      string nome;
      string email;
      string senha;
  public:

    /*! 
      @brief Define o id do usuario.
      @param id_ O id do usuario.
    */
    void set_id (int id_);

    /*! 
      @brief Define o nome do usuario.
      @param nome_ O nome do usuario.
    */
    void set_nome (string nome_);

    /*! 
      @brief Define o email do usuario.
      @param email_ O email do usuario.
    */
    void set_email (string email_);

    /*! 
      @brief Define a senha do usuario.
      @param senha_ A senha do usuario.
    */
    void set_senha (string senha_);

    /*! 
      @brief Recupera o id do usuario.
      @return Id do usuario. 
    */
    int get_id (void);

    /*! 
      @brief Recupera o nome do usuario.
      @return Nome do usuario. 
    */
    string get_nome (void) const;

    /*! 
      @brief Recupera o email do usuario.
      @return Email do usuario. 
    */
    string get_email (void) const;
    
    /*! 
      @brief Recupera o senha do usuario.
      @return Senha do usuario. 
    */
    string get_senha (void) const;
};

#endif