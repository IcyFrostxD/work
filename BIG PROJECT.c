//License TO SONGPON THONGBOR**************

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

//SET DELAY TO EACH CONVERSATION*
void delay(int time_seconds) 
{
    clock_t start_time = clock(); //clock_t from time.h
    while (clock() < start_time + time_seconds * CLOCKS_PER_SEC); // CLOCK PER SEC COME FROM TIME.H IN SCRIPT #DEFINE CLOCK_PER_SEC 1000
}

main()
{
	//START MENU
	delay(1); printf("Welcome To "); delay(2); printf("Field trip to the Unknow\n\n");
	delay(2); printf("Press ENTER to continue...");
	getchar();
	system("cls");
	// END OF START MENU
	
	//START PROLOGUE
	delay(1); printf("."); delay(1); printf("."); delay(1); printf(".\n"); system("cls");
	delay(1); printf("* IN YOUR MIND *\n"); 
	delay(2); printf("Tomorrow is field trip day\n"); delay(2); printf("I have to prepare myself for now.\n\n");
	delay(3); printf("Gameplay Tutorial: You can select a path for your fate.\n"); delay(2); printf("But remember, everything has its effect.\n"); 
	delay(2); printf("It's called the Butterfly Effect.\n"); 
	delay(2); printf("Press ENTER to continue...");
	getchar();
	system("cls");
	//END PROLOGUE
	
	//SELECTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	delay(2); printf("***After finishing preparation...**\n");
	delay(2); printf("Oh wait!"); delay(2); printf(" I still have one space left for my item.\n"); delay(2); printf("Uhh...."); delay(2); printf(" Flashlight or Tool kit\n\n");
	char TUTORIALSELECTION; // USE ONLY IN TUTORIAL
	while (1)
	{
		delay(2);printf("A. Flashlight\n");delay(1); printf("B. Tool kit\n");
		delay(1);printf("Answer : ");
		scanf(" %c", &TUTORIALSELECTION);
		if (TUTORIALSELECTION == 'A' || TUTORIALSELECTION == 'a')
		{
			delay(1); printf("It's a good choice, but I 'll take both\n");
			delay(2); printf("SYSTEM : You select both\n");
			break;
		}
		else if (TUTORIALSELECTION == 'B' || TUTORIALSELECTION == 'b')
		{
			delay(1); printf("Oh wait, Why do I need tools kit? for what?\n"); delay(2); printf("Nevermind I will take both\n");
			delay(2); printf("SYSTEM : You select both\n");
			break;
		}
		else 
		{
			delay(1); printf("You are not right, I SAID Flashlight OR Tools kit !!!\n");
		}
	}
	delay(5); system("cls");
	//END OF SELECTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//AT THE SCHOOL!!
	delay(2); printf("*At the school*\n");
	delay(2); printf("Teacher : OK Student this is our trip day have fun with your trip\n"); 
	delay(3); printf("But do not forget about the rules\n");
	delay(2); printf("Friend 1 : Hey Mark, what did you bring today?\n");
	
	char MAINROUTE, SADROUTE;
	delay(2); printf("Mark : Uh... I brought...\n");delay(1); printf("A. Truth\t"); delay(1); printf("B. Lie\t\t"); delay(1); printf("C. ...\n");
	delay(1); printf("Mark : ");
	scanf(" %c", &MAINROUTE);
	while (1)
	{
		if (MAINROUTE == 'A' || MAINROUTE == 'a') // truth
		{
			delay(2); printf("Mark : I brought a lot of thing, i have talcum powder, drinking water, some snacks, flashlight and a tools kit\n");
			delay(4); printf("Friend 1 : Oh wow!!"); 
			delay(2); printf(" but why did you bring a tools kit? What for?\n");
			delay(3); printf("Mark : I don't even know either HAHA.");
			delay(2); printf(" What about you Lucas\n");
			delay(3); printf("Lucas : I brought a lighte...\n"); 
			delay(2); printf("Mark : HUH?! Why did you bring a lighter? Are you going to burn the town? Hahaha!\n");
			delay(3); printf("Lucas : Hey! don't say that!\n"); 
			delay(3); printf("Mark : Broooo, I'm kidding. Okay, what else did you bring\n");
			delay(3); printf("Lucas : A Lighter and a rope\n");
			delay(2); printf("Mark : NONONO You are definitely going to burn the city\n");
			delay(3); printf("Lucas : YES!! HAHAHA"); 
			delay(2); printf(" just kidding. My mom just put it inside my bag, I don't know why. It might be useful\n");
			break;
		}
		else if (MAINROUTE == 'B' || MAINROUTE == 'b') // lie
		{
			delay(2); printf("Mark : I didn't bring anything special.");		
			delay(2); printf(" What about you Lucas\n");
			delay(3); printf("Lucas : I bring lighte...\n"); 
			delay(2); printf("Mark : HUH!! why did you bring lighter, are you going to burn the town? HAHAHA\n");
			delay(3); printf("Lucas : Hey! don't say that!\n"); 
			delay(3); printf("Mark : Broooo I'm kidding.. Ok what did you bring more\n");
			delay(3); printf("Lucas : Lighter and a rope\n");
			delay(2); printf("Mark : NONONO You are really going to burn the city\n");
			delay(3); printf("Lucas : YES!! HAHAHA"); 
			delay(2); printf(" just kidding, my mom just put it inside my bag, I don't know why. It may useful\n");
			break;
		}

		else if (MAINROUTE == 'C' || MAINROUTE == 'c') // nothing AND USE SAD ROUTE IF YOU SELECT THIS
		{
			delay(2); printf("Mark : **You said nothing**\n");
			delay(2); printf("Lucas : Why are you so quiet,"); delay(3); printf(" Are you okay?\n");

			delay(2); printf("Mark : Uh....\n");
			delay(2); printf("A. I'm okay\t"); delay(1); printf("B. ...\t\n");
			delay(1); printf("Mark : ");
			while (1)
			{
					scanf(" %c", &SADROUTE);
					
					if (SADROUTE == 'A' || SADROUTE == 'a') 
					{
						delay(2); printf("Mark : I'm okay\n");
						delay(2); printf("Lucas : You don't seem okay. Is something wrong? You can tell me\n");
						break;
					}
					else if (SADROUTE == 'B' || SADROUTE == 'b')
					{
						delay(2); printf("Mark : ...\n");
						break;
					}
					else
					{
						delay(2); printf("Please Select right answer\n");
						delay(2); printf("A. I'm okay\t"); delay(1); printf("B. ...\t\n");
						delay(1); printf("Mark : ");
						scanf(" %c", &SADROUTE);
					}
			}
			delay(2); printf("Lucas : By the way I brought a ligher and a rope");
			delay(2); printf(" my mom just put it inside my bag,\n");
			delay(3); printf("I don't know why. It might be useful\n");
			break;
		}
		else 
		{
		delay(2); printf("Please Select right answer\n");
		delay(2); printf("A. Truth\t"); delay(1); printf("B. Lie\t\t"); delay(1); printf("C. ...\n");
		delay(1); printf("Mark : ");
		scanf(" %c", &MAINROUTE);
		}
	}
		delay(3); printf("Teacher : Okay students, We are going on the bus now!\n");
		delay(2); printf("*** Student walks to the bus ***\n");
		delay(3); printf("Friend 2 : YO Lucas, Mark let me sit with you guys.\n");
		delay(3); printf("Lucas : There's no space for you, Bill.\n");
		delay(3); printf("Bill : Come on Lucas I got no friend to sit with\n");
		delay(3); printf("Lucas : Okay, fine, but it'll be uncomfortable to sit because we're already packed with three people.\n"); 
		delay(4); printf("Bill : Hooray!! I don't mind it\n\n");
		delay(2); printf("** Mark, Lucas, and Bill are on the bus... **\n");
		delay(3); printf("Lucas : Hey Bill, can you move a litle bit please\n"); 
		delay(3); printf("Bill : No !!! HAHA"); delay(2); printf(" just kidding, okay I will move a little\n");
		delay(4); printf("Lucas : Too little broooo"); delay(2); printf(" Move more please T_T\n"); delay(2); printf("Bill : Okay Haha no more pranking\n");
		delay(3); printf("Mark mind : Finally they finished it\n"); 
		delay(3); printf("Mark : Guys its too boring let's play a game\n");
		delay(3); printf("Bill : Sound great"); delay(2); printf(". What game is it?\n"); 
		delay(3); printf("Mark : It is Magic Number\n");
		delay(3); printf("Lucas : WHOAA I LOVE GUESSING\n"); 
	if (MAINROUTE == 'A'|| MAINROUTE == 'a')
	{
		delay(2); printf("Mark : It's like you're guessing about her"); delay(3); printf("—will she like you back or not, right? Haha\n");
		delay(3); printf("Lucas : OKAY!! MARK YOU START IT\n"); 
		delay(2); printf("Mark : Just kidding my friend"); delay(3); printf(", Btw let's play the game\n\n");
	}
	else if (MAINROUTE == 'B'|| MAINROUTE == 'b')
	{
		delay(2); printf("Mark : It's like you're guessing about her"); delay(3); printf("—will she like you back or not, right? Haha\n");
		delay(3); printf("Lucas : OKAY!! MARK YOU START IT\n"); 
		delay(2); printf("Mark : Just kidding my friend"); delay(3); printf(", Btw let's play the game\n\n");
	}
	else if (MAINROUTE == 'C' || MAINROUTE == 'c')
	{
		delay(2); printf("Mark : Ok Lucas, I am glad to hear that.\n");
		delay(2); printf("Lucas : What wrong with you today Mark?"); delay(3); printf(" You are a bit different.\n");
		delay(2); printf("Bill : OH NO! WE HAVE LOST MARK!!!!!"); delay(3); printf("Hey DEVIL BRING OUR MARK BACK!\n");
		delay(2); printf("Lucas : I don't think that will work Bill "); delay(3); printf("You ain't a kid anymore brooo\n");
		delay(2); printf("Bill : OK LUCAS! DO YOU WANNA FIGHT?\n"); 
		delay(3); printf("Lucas : What? I just said you are grown enough\n");
		delay(2); printf("Mark : Can you Two Stop? please\n");
		delay(2); printf("Louis and Bill : OK....\n");
		delay(2); printf("Mark : I will start the game now\n");
	}
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////game time
	delay(2); printf("Game Tutorial :"); delay(2); printf("\nMagic Number is a game where you guess the number between x to x.\n");
	delay(4); printf("How to play : First player choose a number \n"); delay(2); printf("and second player have to guess it,\n");
	delay(2); printf("Press ENTER to continue...");
	getchar();
	system("cls");{
	}
	
	int secretNumber, attempts = 1, n1, n2, guess = 0;
	char ch;
	delay(2); printf("RULES : Don't make the first number higher than 15\n");
	delay(2); printf("Don't make the second number higher than 20\n");
	delay(2); printf("The first number can not be a negative number\n");
	delay(2); printf("Both guessing must be more than 6 guesses\n");
	
    printf("Select number from X to X\n");
	printf("Pick first number : ");
    scanf(" %d", &n1);
    printf("Pick second number : ");
    scanf(" %d", &n2);
    while (1)
    {
    	if(scanf("%d", &n1) == 1)
    	{
    		break;
		}
		else if (scanf("%d", &n2) == 1)
		{
			break;
		}
		else
		printf("\nWhy did you input alphabet? Try number instead\n");
		while ((ch = getchar()) != '\n' && ch != EOF); // EOF Stdio.h = -1 FOR CLEAR BUFFER
		printf("Pick first number : ");
	    scanf(" %d", &n1);
	    printf("Pick second number : ");
	    scanf(" %d", &n2);
	}
	
	while (1)
	{
		if (n1 == n2)
		{
			printf("Don't make the same number\n");
		}
		else if (n1 > n2)
		{
			printf("First number can not be higher than second number\n");
		}
		else if (n1 > 15)
		{
			printf("First number can not be higher than 15\n");
		}
		else if (n2 > 20)
		{
			printf("Second number can not be higher than 20\n");
		}
		else if (n1 < 0)
		{
			printf("First number can not be negative number\n");
		}
		else if ((n2-n1) <= 5)
		{
			printf("Both numbers must be higher than 6 guessing\n");
		}
		else
		{
		break;
		}
		printf("Pick first number : ");
        scanf(" %d", &n1);
        printf("Pick second number : ");
        scanf(" %d", &n2);
	}

    while (1)
	{
	delay(2); printf("Pick Magic number : ");
    scanf("%d", &secretNumber);
    if (secretNumber > n2)
    {
    	printf("Dont too higher than the last number\n");
	}
	else if (secretNumber < n1)
	{
		printf("Don't too lower than the first number\n");
	}
	else
	break;
	}
	delay(2); system("cls");
	delay(2); printf("Magic Number will be %d - %d\n", n1, n2);
	while (guess != secretNumber) 
	{	
        delay(1); printf("Enter your magic number : ");
        delay(1); scanf("%d", &guess);

        if (guess == secretNumber) 
		{
            delay(1); printf("Congratulation, You WIN!!\n");
            delay(2); printf("Magic number is %d\n", secretNumber); break;
        } 
		else if (guess > secretNumber) 
		{
            delay(1); printf("Too high Try again little brother\n");
        } 
		else 
		{
            delay(1); printf("Too low Try again bro\n");
        }
        attempts++;
    }

    delay(2); printf("You found the magic number in %d attempts!\n", attempts);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////END OF GAME TIME!!
    
	if (attempts == 1)
	{
		delay(2); printf("Mark : Are you cheater? Did you read my mind?");
		delay(2); printf("\nLucas : You'd rather choose this to be so easy");
		delay(2); printf("\nBill : Yes, and call us cheater");
	}
	else if (attempts <= 4 )
	{
		delay(2); printf("Mark : Nice BRO!! you did well");
		delay(2); printf("\nLucas : I know already bro Hehe");
		delay(2); printf("\nBill : Anything easier?");
	}
	else if (attempts > 4)
    {
    	delay(2); printf("Mark : Nice try bro, even you hit more than 4 times");
    	delay(2); printf("\nLucas : Did you mocking me ?");
    	delay(2); printf("\nBill : Bro, he actually mocking us");
	}
	delay(5); system("cls");
		delay(2); printf("\nTeacher : Students.. We are arriving soon");
		delay(2); printf(" Don't forget your bagpack and about our rules");
		delay(2); printf("\nLets repeat the rules");
		delay(2); printf("\nTeacher : Rules number 1");
		delay(2); printf("\nStudents : Rules number 1");
		delay(2); printf("\nTeacher : Don't Screa......");
		delay(2); printf("\nStudents : Don't disturb people");
		delay(2); printf("\nTeacher : Rules number 2");
		delay(2); printf("\nStudents : Rules number 2");
		delay(2); printf("\nTeacher : Be a good k...."); delay(2); printf(" il"); delay(2); printf(" ler...");
		delay(2); printf("\nStudents : Be a good kid");
		delay(2); printf("\nTeacher : Okay students, we are getting off the bus. Line up and walk down like a train");
		delay(2); printf("\nStudents : Okay, Teacher!");
		delay(2); printf("\nMark : Did you guys notice something weird?");
		delay(2); printf("\nBill : No? What is it");
		delay(2); printf("\nA.TRUTH");delay(1); printf("\t\tB. LIE"); delay(1); printf("\t\tC. NOTHING");
		delay(2); printf("\nMark : ");
		scanf(" %c", &MAINROUTE);
	while (1)
	{
		if (MAINROUTE == 'A' || MAINROUTE == 'a') // THEY A BIT NOTICE ABOUT SOMETHING WRONG BUT NOT 100% BELIEVE
		{
			delay(2); printf("Mark : Teacher is weird she said something weird, Like Be a good killer, and don't scream\n");
			delay(2); printf("Louis : I think you have lost your mind\n");
			delay(2); printf("Bill : You haven't slept since yesterday?\n");
			break;
		}
		else if (MAINROUTE == 'B' || MAINROUTE == 'b') // THEY DON'T KNOW WHAT IS GOING ON
		{
			delay(2); printf("Mark : Um.. Nothing\n");
			delay(2); printf("Louis : It's okay you probably have a less rest since yesterday");
			delay(2); printf("Bill : Yes, Yes, Lets have some fun in ABANDONIA PARK!");
			break;
		}
		else if (MAINROUTE == 'C' || MAINROUTE == 'c') // THEY DON'T KNOW WHAT IS GOING ON
		{
			delay(2); printf("Mark : ...\n");
			delay(2); printf("Louis : This guy is quiet again\n");
			delay(2); printf("Bill : If you don't talk then I will not talk to you anymore, ");
			delay(2); printf("just this day");
			break;
		}
		else
			printf("Please select A B C :)\n");
			delay(2); printf("\nA.TRUTH");delay(2); printf("\t\tB. LIE"); delay(2); printf("\t\tC. NOTHING");
			delay(2); printf("\nMark : ");
			scanf(" %c", &MAINROUTE);
	}
}