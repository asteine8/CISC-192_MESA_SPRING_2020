/*-----------------------------------------------------------------
*	mainflip.cpp -	game program for students to do  maintenance 
*	programming on:  mainflip needs function: 
		bool flip (int weight) ;
*	(parm passed to flip() determines how many times in 100 
*	invocations flip() will return true.)
*	T.E. Harrisburg
*  Sun Dec  1 23:22:16 PST 2019

*   Edited by Alexandra Steiner (4/12/20)
*		- Added flip.h and flip.cpp for flip function
*		- Localized getchne.h
*		- Created src folder to hold dependancies
-----------------------------------------------------------------*/

#include <cstdio>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "./src/getchne.h"
#include "./src/flip.h"  // change to suit your installation

using namespace std;

int main (int argc, char *argv[], char **env)
{
	#ifdef __linux__ 
			puts("LINUX") ;
		//	cin.get() ;
		system("clear") ;
	#elif _WIN32
		// windows code goes here
			puts("WINDOZE") ;
	#else
			puts("O/S??") ;
		//cin.get() ;
		system("CLS") ;
	#endif

	bool ended = false ;
	char c ;
	int liklihood = 0 ;

	while (!ended)
	{
		printf("OPEN BLACKBEARD'S TREASURE CHEST.") ; 


		printf("|----------------------------------|\n") ;
		printf("|-----   ---         ----    --- --|\n") ;
		printf("|                                  |\n") ;
		printf("|   { PROPERTY OF EDWARD TEACH }   |\n") ;
		printf("|                                  |\n") ;
		printf("|--    ------- (  0  ) ------------|\n") ;
		printf(" |               (8)              |\n") ;       
		printf(" |                                |\n") ;       
		printf(" |       Press 8 to pick lock     |\n") ;       
		printf(" |                                |\n") ;       
		printf(" |                                |\n") ;       
		printf(" |--------------------------------|\n") ;       
		printf("\n\n\n") ;
		c = getchne() ;
		if ('8' != c)
		{
			puts("that's EIGHT, Twit!") ;
			puts("Like a Double-Round rake pick, capisch?") ;
			cin.get() ;
			continue ;
		}
		ended = flip(25) ;
		if (!ended) 
		{
			printf("sorry! Keep trying!  (Arrrrr.)\n") ;
			continue ;
		}
		else
		{
         printf("    =============================\n") ;
         printf("    :             0             :\n") ;
         printf("    =============================\n") ;
         printf("     \\                        /\n") ;
         printf("      \\                      /\n") ;
			printf("      /\\--------------------/\n") ;
			printf("     /O   --- ...00CCC---- * \\\n") ;
			printf("    /  0  *  ..  0 ** * 0CCC* \\\n") ;
			printf("   / O0 *0* ==---*   0   CCCCC \\\n") ;
			printf("  /  O*O  ==            CCCCCCO \\\n") ;
			printf(" /-------------------------------\\\n") ;
			printf(" |               (8)              |\n") ;
			printf(" |                                |\n") ;
			printf(" |            SPROING!!           |\n") ;
			printf(" |            YOU WON!            |\n") ;
			printf(" |                                |\n") ;
			printf(" |--------------------------------|\n") ;
			printf("\n\n\n") ;
			getchar() ;
			puts("   ") ;
			puts("XUKZ CNUUR-YTH'F IYOJG TETZEEGK") ;
			puts("SB BZ XUX WBWW HR ZAIF,") ;
			puts("TRQ HYOZ AUW FDMA YL'LY FMOR T PVVALR WDYZ.") ;
//			puts("	") ;
			puts("MS OGHT NL II SBVR JBMNG TINWW") ;
			puts("STVM PTZRBG EG QBR SHQW") ;
			puts("NGH FGA TUX EINL EYKNHG PUXU UPNBPNT KGQ.") ;
//			puts(" ") ;
			puts("V MVRCK A YNDGUBRT YVOQXZ HRVO,") ;
			puts("N TLEXBZK FTPQ-EHKRW TIYE.") ;
			puts("EAF FEG IQVUTTF") ;
			puts("PV WBKEI N PSENK TUTZ CBNVF.") ;
//			puts(" ") ;
			puts("YOEEX NMFASCU DAYD FLEHYTJ JHNKZIY-REEFZ") ;
			puts("WVMT TBFEAFLRF MA WZXPY,") ;
			puts("CUD IBXI ZXR GJYIIX") ;
			puts("MRQ ESIG NORL AR NEP SQBRF.") ;
//			puts(" ") ;
			puts("YDSZ \"PEGEOMRG\" NC NEEA OVOEX, 1980'E, HP.") ;
			/* celebrating the enchantment of Vigenere */

		}
		printf("Thanks for playing.  Now get a life!\n") ;
	} // while 

	return EXIT_SUCCESS ;
} // main ends