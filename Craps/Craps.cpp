 // Simula��o do jogo de dados craps.
#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib> // cont�m prot�tipos para fun��es srand e rand
using std::rand;
using std::srand;

#include <ctime> // cont�m prot�tipo para a fun��o time
using std::time;

int rollDice(); // lan�a o dado, calcula e exibe a soma

int main()
{
   // enumera��o com constantes que representam o status do jogo
	 enum Status { CONTINUE, WON, LOST }; // todas as mai�sculas em constantes
	
	 int myPoint; // pontos se n�o ganhar ou perder na primeira rolagem
	 Status gameStatus; // pode conter CONTINUE, WON ou LOST
	
	    // torna aleat�rio o gerador de n�mero aleat�rio utilizando a hora atual
		srand(time(0));
	
	 int sumOfDice = rollDice(); // primeira rolagem dos dados
	
	 // determina status e pontua��o do jogo (se necess�rio) com base no primeiro lan�amento de dados
	
	switch (sumOfDice)
	{
	    case 7: // ganha com 7 no primeiro lan�amento
		case 11: // ganha com 11 no primeiro lan�amento
		gameStatus = WON;
		break;
		case 2: // perde com 2 no primeiro lan�amento
		case 3: // perde com 3 no primeiro lan�amento
		case 12: // perde com 12 no primeiro lan�amento
	    gameStatus = LOST;
		    break;
		    default: // n�o ganhou nem perdeu, portanto registra a pontua��o
		    gameStatus = CONTINUE; // jogo n�o terminou
			myPoint = sumOfDice; // informa a pontua��o
			cout << "Point is " << myPoint << endl;
		    break; // opcional no final do switch
			
	} // fim de switch
	
		 // enquanto o jogo n�o estiver completo
		 while (gameStatus == CONTINUE) // nem WON nem LOST
		 {
		  sumOfDice = rollDice(); // lan�a os dados novamente
		
			 // determina o status do jogo
			 if (sumOfDice == myPoint) // vit�ria por pontua��o
			 gameStatus = WON;
		     else
			 if (sumOfDice == 7) // perde obtendo 7 antes de atingir a pontua��o
			 gameStatus = LOST;
		 } // fim do while
	
		 // exibe uma mensagem ganhou ou perdeu
		 if (gameStatus == WON)
		  cout << "Player wins" << endl;
	     else
		 cout << "Player loses" << endl;
	
	 return 0; // indica termina��o bem-sucedida
	
} // fim de main

 // lan�a os dados, calcula a soma e exibe os resultados
int rollDice()
{
	 // seleciona valores aleat�rios do dado
		 int die1 = 1 + rand() % 6; // primeiro lan�amento do dado
	     int die2 = 1 + rand() % 6; // segundo lan�amento do dado
	
		 int sum = die1 + die2; // calcula a soma de valores do dado
	
	 // exibe os resultados desse lan�amento
		 cout << "Player rolled " << die1 << " + " << die2
		 << " = " << sum << endl;
  return sum; // fim da fun��o rollDice
} // fim da fun��o rollDice