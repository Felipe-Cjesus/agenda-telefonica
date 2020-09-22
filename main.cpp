/*	Estrutura de Dados II
*
*	Projeto: Agenda de contatos
*
*	Função: Entrar com dados de contato para inserir em uma agenda utilizando estrutura MAP
*
*****************************************************
*
*	Autor: Felipe Costa de Jesus, Pedro Ventura
*	Email: felipe.costa.10@hotmail.com
*****************************************************
*
*	Alteração
*
*	Data: 22/09/2020
*
*****************************************************
*/
#include <cstdlib>
#include <iostream>
#include <map>
#include "func_pessoa.h"
#include <string>

using namespace std;

void menu(){
    system("cls");//limpa os dados do console
    cout << "---- Implementacao da Agenda com Map ----" << endl;
    cout << "1 - Limpar agenda" << endl;//
    cout << "2 - Inserir numero" << endl;//
    cout << "3 - Remover pelo numero" << endl;
    cout << "4 - Remover pelo nome da pessoa" << endl;
    cout << "5 - Localizar pelo numero" << endl;
    cout << "6 - Localizar pelo nome" << endl;
    cout << "7 - Listar contatos" << endl;
//  cout << "8 - Realizar chamada" << endl;
    cout << "0 - Sair" << endl;
}


int main(){
	
    int opcao,subst;
    bool nr_localizado;
    string nome,sobrenome;
    int num;
    map<int,pessoa> map_agenda;
    map<int, pessoa>::iterator it;
    //o laço de repetição serve para manter a comunicação com o usuário através do menu a a opção escolhida pelo usuário
    while(true){
	   	menu();
    	cout << "Opcao - ";
       	cin >> opcao;
       
       //define a escolha do usuário
       if(opcao == 0){
           break;
       }else if(opcao == 1){
           if(!map_agenda.empty()){
           		map_agenda.clear();
           		cout<<"Contatos apagados com sucesso"<<endl;
		   }else{
		   		cout<<"Nao existe contatos a serem apagados"<<endl;
		   }
        system("pause");
       }else if(opcao == 2){
           system("cls");
           //solicita ao usuários os dados
           cout << "Nome: ";
           cin >> nome;
           cout << "Sobrenome: ";
           cin >> sobrenome;
           cout << "Nr: ";
           cin >> num;
		   	   
           //verifica se o número do telefone já existe no mapa
           it = map_agenda.find(num);
           if(it != map_agenda.end()){
	           	cout<<"O numero informado ja existe"<<endl;
	           	cout<<"1 - Para Substituir ou 2 - Para Cancelar"<<endl;cout<<"Opcao: ";
	           	cin>>subst;
	           	if(subst!=1){
	           		continue;
				}else{
			   		//Se o elemento já existir, será alterado, caso contrário será inserido
			  	 	map_agenda[num] = pessoa(nome,sobrenome);
			  	 	cout<<"Contato alterado com sucesso!!"<<endl;
			  	 	system("pause");
					continue;
			   }
			}
       		//insere o dado no mapa, se existir, irá substituir
       		map_agenda.insert(make_pair(num, pessoa(nome, sobrenome)));
       		cout<<"Contato adicionado com sucesso!!"<<endl;
       		
		system("pause");
       }else if(opcao == 3){
           cout << "Nr excluir: ";
           cin >> num;
           int numDelet = map_agenda.erase(num);
           if(numDelet>0){
           		cout<<"Numero deletado: "<<numDelet<<endl;
			}else{
				cout<<"O numero nao existe"<<endl;
			}
       system("pause");
	   }else if(opcao == 4){
           cout << "Nome a excluir: ";
           cin >> nome;
           if(!map_agenda.empty()){
           	nr_localizado = false;
           	for(it = map_agenda.begin(); it != map_agenda.end(); it++){
           		if(nome == it->second.getnome()){
           			it->second.imprimir();
           			cout<<"Apagando . . ."<<endl;
           			map_agenda.erase(it->first);
           			nr_localizado = true;
           			break;
				   }
			   }
			   if(!nr_localizado){
			   	cout<<"O "<< nome << " nao foi localizado" << endl;
			   }
		   }else{
		   	cout<<"A agenda nao possui contatos"<<endl;
		   }
		system("pause");
       }else if(opcao == 5){
           cout << "Nr localizar: ";
           cin >> num;
           it = map_agenda.find(num);
           if(it != map_agenda.end()){
           	cout<<"Dados do contato"<<endl;
           	it->second.imprimir();
		   }else{
		   	cout<<"Numero nao encontrado"<<endl;
		   }
		system("pause");
       }else if(opcao == 6){
           cout << "Nome: ";
           cin >> nome;
			if(!map_agenda.empty()){
				nr_localizado = false;
				for(it = map_agenda.begin(); it != map_agenda.end();it++){
					if(nome == it->second.getnome()){
						cout<<"Dados do contato"<<endl;
						it->second.imprimir();
						nr_localizado = true;
						break;
					}
				}
				if(!nr_localizado){
					cout<<"O "<<nome<<" nao foi localizado"<<endl;
				}else{
					cout<<"A agenda nao possui contatos"<<endl;
				}
			}
			system("pause");
       }else if(opcao == 7){
           if(!map_agenda.empty()){
           	for(it = map_agenda.begin(); it != map_agenda.end(); it++){
           		cout<<"----------------------"<<endl;
           		cout<<"Telefone: "<< it->first <<endl;
           		it->second.imprimir();
           		cout<<""<<endl;
			   }
		   }else{
		   	cout<<"A agenda nao possui contatos"<<endl;
		   }
		system("pause");
       }/*else if(opcao == 8){
           cout << "Nr: ";
           cin >> num;
       }*/
       
       else if(opcao == 9){
       	if(!map_agenda.empty()){
           	for(it = map_agenda.begin(); it != map_agenda.end(); it++){
	           		cout<<"----------------------"<<endl;
	           		cout<<"Numero: "<< it->first <<endl;
					it->second.imprimir();
       			}
	   		}	
	   	system("pause");
	  	}
	}//#end while
    return 0;
}
 
