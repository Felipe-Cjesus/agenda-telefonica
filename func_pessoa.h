#include <string>
#include <iostream>

using namespace std;

//declara��o da classe pessoa
class pessoa{
   private:
      string nome;
      string sobrenome;
   
   public:
      pessoa();
      pessoa(string nome, string sobrenome);
      ~pessoa();
      string getnome();
      void setnome(string nome);
      string getsobrenome();
      void setsobrenome(string nome);
      void imprimir();
};

//implementa��o das fun��es da classe pessoa
pessoa::pessoa(){}

pessoa::pessoa(string nome, string sobrenome){
  this->nome = nome;
  this->sobrenome = sobrenome;
}
pessoa::~pessoa(){}

string pessoa::getnome(){
   return nome;
}
void pessoa::setnome(string nome){
   this->nome = nome;
}

string pessoa::getsobrenome(){
   return sobrenome;
}
void pessoa::setsobrenome(string sobrenome){
	this->sobrenome = sobrenome;
}

//apresenta os dados da pessoa no console
void pessoa::imprimir(){
  cout<<"Nome: "<< nome << sobrenome <<endl;
}
