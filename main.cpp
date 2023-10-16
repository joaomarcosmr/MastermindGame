#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    // VARIAVEIS

    int tentativasSelecionada = 10, sequencia=4, sequenciaSelecionada[sequencia], dificuldade, recorde, pontos=0, escolha, igual, i=0, j, t, s, r, n[sequencia], posicaoCerta=0, numeroCerto=0, tentativasSelecionadaFacil = 8, tentativasSelecionadaDificil = 12;
    int sequenciaTamanho = sizeof(sequenciaSelecionada);
    string dificuldadeTexto = "Média (Padrão)", erro, erro2, voltar;
    bool saoIguais = false;


    // MENU COMEÇO DO JOGO:

    while(escolha != 4){

    system("cls");
    cout << "--------------------------------" << endl << endl;
    cout << "Seja bem-vindo(a) ao MasterMind!" << endl << endl << "Você deverá descobrir a senha que o sistema irá codificar," << endl << "possuindo algumas tentativas. Caso acerte você ganhará 100 pontos, mas se errar, perde 100 pontos!" << endl << "Tente bater seu recorde!" << endl << endl;

    if (pontos > 0){
        cout << "--------------------------------" << endl << endl;
        cout << "Sua pontuação é: " << pontos << endl << endl;
    };

    cout << "--------------------------------" << endl << endl;
    cout << "Dificuldade selecionada: " << dificuldadeTexto << endl << erro << endl;
    cout << "--------------------------------" << endl << endl;
    cout << "Selecione uma opção (digite o número correspondente para selecionar):" << endl << endl << "1. Jogar" << endl << "2. Dificuldade" << endl <<  "3. Sobre" << endl << "4. Fim" << endl << endl;
    cout << "Sua Resposta >> "; cin >> escolha;

    switch(escolha) {
        case 1:

            // JOGO

            system("cls");
            erro = "";
            cout << "--------------------------------" << endl << endl;
            cout << "DESCUBRA A SENHA!" << endl << "Válidos números apenas de 0 à 9." << endl << endl;
            cout << "--------------------------------" << endl << endl;

            // GERAR SENHA ALEATÓRIA

            i=0;
            if(dificuldade == 1){
                tentativasSelecionada = tentativasSelecionadaFacil;
            } else if (dificuldade == 2){
                tentativasSelecionada = 10;
            } else if (dificuldade == 3){
                tentativasSelecionada = tentativasSelecionadaDificil;
            } else {
                tentativasSelecionada = 10;
            }

            do{
                r = rand() % 10;
                sequenciaSelecionada[i] = r;
                igual = 0;
                for(j=0;j<i;j++){
                    if(sequenciaSelecionada[j] == sequenciaSelecionada[i]){
                        igual = 1;
                    };
                };
                if(igual == 0){
                    i++;
                };
            }while(i < sequencia);

            for(i=0;i<sequencia;i++){
                cout << sequenciaSelecionada[i];
            }
            cout << "SENHA DE " << sequencia << " DÍGITOS GERADA, TENTE ADIVINHAR:" << endl << endl;

            // TENTATIVAS USUARIO

            i=0;
            saoIguais=false;
            erro = "";
            posicaoCerta = 0;
            numeroCerto = 0;

            do{
                for(j=1;j<=sequencia;j++){
                    cout << "Digite o número " << j << " >> ";
                    cin >> n[i];
                    cout << endl;
                    i++;
                };

                // CHECA SE OS NÚMEROS DIGITADOS ESTÃO NO VETOR
                i=0;
                while(i<sequencia){
                    for(s=0;s<sequencia;s++){
                            if(n[i] == sequenciaSelecionada[s]){
                            numeroCerto += 1;
                        }
                    }
                    i++;
                }

                // CHECA SE ESTÃO NA POSIÇÃO CERTA

                for(t=0;t<sequencia;t++){
                    if(n[t] == sequenciaSelecionada[t]){
                        posicaoCerta += 1;
                    }
                }

                if(sequencia == 5) posicaoCerta+=1;

                // Errors

                for(i=0;i<sequencia;i++){
                    for(j=i+1;j<sequencia;j++){
                        if(n[i] == n[j]){
                            erro = "Não pode repetir números \n";
                        }
                    }
                }

                for(i=0;i<sequencia;i++){
                    if(n[i] > 9 || n[i] < 0){
                        erro2 = "Não pode números maiores que 9 e menores que 0 \n";
                    }
                }
                // CONDICAO DE VITORIA

                if (posicaoCerta == sequencia){
                    saoIguais = true;
                }

                // SAÍDA DE INFORMAÇÕES
                tentativasSelecionada -= 1;

                if(tentativasSelecionada < 0){
                    i=0;
                    cout << endl << "Acabou suas tentativas, você não adivinhou a senha!" << endl << endl;
                    if(pontos > 0){
                        cout << "Você perdeu 100 pontos, tente novamente! =/";
                        pontos -= 100;
                    }
                    cout << endl;
                    break;
                }

                if(erro == "" && erro2 == ""){
                    cout << "Possui " << numeroCerto << " números corretos" << endl;
                    cout << "Possui " << posicaoCerta << " números da posição certa" << endl;
                    if (!saoIguais){
                        cout << "Você possui ainda " << tentativasSelecionada << " tentativas restantes..." << endl << endl;
                    } else {
                        cout << endl << "Você acertou a senha, parabéns!" << endl << endl;
                        cout << "Você ganhou 100 pontos!";
                        cout << endl;
                        pontos += 100;
                        break;
                    }
                    cout << "--------------------------------" << endl << endl;
                } else {
                    cout << "--------------------------------" << endl << endl;
                    cout << erro << erro2 << endl << endl;
                    cout << "--------------------------------" << endl << endl;
                }
                i = 0;
                erro = "";
                erro2 = "";
                posicaoCerta = 0;
                numeroCerto = 0;
            } while (!saoIguais);

            cout << "Aperte qualquer tecla para voltar ao menu inicial: >> "; cin >> voltar;
            break;
        case 2:

            // DIFICULDADE

            system("cls");
                cout << "--------------------------------" << endl << endl;
                cout << "Selecione uma opção de dificuldade (digite o número correspondente para selecionar):" << endl << endl << "1. Fácil - acertar uma sequência de 3 dígitos e terá 08 tentativas" << endl << "2. Média - acertar uma sequência de 4 dígitos e terá 10 tentativas" << endl <<  "3. Difícil - acertar uma sequência de 5 dígitos e terá 12 tentativas" << endl << endl;
                cout << "Sua Resposta >> "; cin >> dificuldade;
                    if (dificuldade == 1){
                        sequencia = 3;
                        tentativasSelecionada = tentativasSelecionadaFacil;
                        dificuldadeTexto = "Fácil";
                    } else if (dificuldade == 2){
                        sequencia = 4;
                        tentativasSelecionada = 10;
                        dificuldadeTexto = "Média(Padrão)";
                    } else if (dificuldade == 3){
                        sequencia = 5;
                        tentativasSelecionada = tentativasSelecionadaDificil;
                        dificuldadeTexto = "Difícil";
                    } else {
                        erro = "";
                        erro = "Digite um número de 1 a 3, dificuldade alterada pra Média(Padrão)";
                    };
            break;
        case 3:

            // SOBRE

            system("cls");
            cout << "--------------------------------" << endl << endl;
            cout << "Equipe de desenvolvimento: João Marcos Martins Rosa, Bernardo Gonçalves Seubert." << endl << "Mês/Ano: Outubro de 2023." << endl << "Nome do professor/Disciplina: Alex Rese, Algoritmos e Programação." << endl << endl;
            cout << "--------------------------------" << endl << endl;
            cout << "Digite '1' para voltar ao menu anterior >> "; cin >> escolha;
            break;
        case 4:

            // FIM

            break;
        default:
            cout << "Opção inválida." << endl;
            cout << "Digite '1' para voltar ao menu anterior >> "; cin >> escolha;
            break;
    }

    };
}
