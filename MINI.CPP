#include<conio.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>
#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
int score = 0;
void print_score()
{
	cout<<"\n\n\n\n\n\n\tYour score is:\n";
	gotoxy(41,12);
	cout<<score<<"/25";
	getch();
	exit(0);
}

// #######################  ClearScreen  ##################################

void ClearScreen()
{
	clrscr();
	cout<<"\t\t\t\tWELCOME TO QUIZ\n\n";
}


// #######################  Instructions Page  #########################
char instructions()
{
    char ch;
    ClearScreen();

    cout<<"\n\n\t\t\t\t INSTRUCTIONS";
    cout<<"\n\t 1. Quiz contains total 5 Questions";
    cout<<"\n\t 2. Each Question has 4 options in which one is correct.";
    cout<<"\n\t 3. Each question has a associated rating which tells its difficulty level.";
    cout<<"\n\t 4. Each correct answer is rewarded with +5 and wrong answer with -1.";
    cout<<"\n\n\n\n\t\t\tWant to Play the Quiz(Y/N).\n";
    cin>>ch;
    //fflush(stdin);
    return ch;
}

//#########################  STRUCTURE DEFINITION  #######################
class Node
{ public:
  struct Node *left;
  struct Node *right;
  char Quest[100];      //The Question
  char option1[80];
  char option2[80];
  char option3[80];
  char option4[80];
  int rating;           //The difficulty of the question
  char key;              //Index of the correct answer
};


//######################### CREATING THE NODE ###############################

class Node *create( char Ques[], char key ,char option1[],char option2[],char option3[],char option4[], int rating)
{

   // struct Node *ptr= (struct Node*)malloc(sizeof( struct Node ));
    Node* ptr = NULL;
    ptr = new Node();
    ptr->key=key;
    strcpy(ptr->Quest,Ques);
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->rating = rating;
    strcpy(ptr->option1,option1);
    strcpy(ptr->option2,option2);
    strcpy(ptr->option3,option3);
    strcpy(ptr->option4,option4);

 return ptr;

}

//#########################  INSERTING A NODE  #############################

class Node *insert( struct Node *root, struct Node *ptr)
{
    if(!root)
	root = ptr;
    else if(ptr->rating < root->rating)
	root->left = insert(root->left , ptr);
    else
	root->right = insert(root->right, ptr);
    return root;
}

// #######################   DRIVER FUNCTION   ############################
void run(struct Node *root)
{
    char ans;
    if(root)
    {
	ClearScreen();             // Clear Screen for every NEW Question.
	cout<<"\n\n\t\t\t"<<root->Quest<<"\n\n";
	delay(1000);
	cout<<"\t\t"<<root->option1;
	delay(1000);
	cout<<"\t\t\t"<<root->option2;
	delay(1000);
	cout<<"\n\n\t\t"<<root->option3;
	delay(1000);
	cout<<"\t\t\t"<<root->option4<<"\n\n";
	cin>>ans;
	//fflush(stdin);
	if(toupper(ans)==root->key)
	{
	    score+=5;
	    cout<<"Right answer!   :)";
	    getch();
	    run(root->right);
	}
	else
	{
	    score--;
	    cout<<"Wrong answer    :(";
	    cout<<"\n\nThe right answer was option "<<root->key;
	    getch();
	    run(root->left);
	}
    }
}



// #######################   MAIN FUNCTION   ###############################

int main()
{
  int rating;
  char ans;
  char ch,ques[100],option1[80],option2[80],option3[80],option4[80];
  Node *root = NULL;
  Node *ptr = NULL;
  root = new Node();
  ptr = new Node();
  root = ptr = NULL;
    strcpy(ques,"What is the boiling point of water in F?");
    strcpy(option1,"A.  198");
    strcpy(option2,"B.  206");
    strcpy(option3,"C.  212");
    strcpy(option4,"D.  219");
root = create(ques,'C',option1,option2,option3,option4,10);

    strcpy(ques,"How many players are in a cricket team?");
    strcpy(option1,"A.  10");
    strcpy(option2,"B.  11");
    strcpy(option3,"C.  12");
    strcpy(option4,"D.  9");
    ptr = create(ques,'B',option1,option2,option3,option4,5);
root = insert( root, ptr );

    strcpy(ques,"How many planets are in our solar system?");
    strcpy(option1,"A.  9");
    strcpy(option2,"B.  8");
    strcpy(option3,"C.  10");
    strcpy(option4,"D.  7");
    ptr = create(ques,'A',option1,option2,option3,option4,15);
root = insert( root, ptr );

    strcpy(ques,"In which of the following decades did Hiroshima and Nagasaki bombing\n\t\t  incident happen?");
    strcpy(option1,"A) 1930s");
    strcpy(option2,"B) 1940s");
    strcpy(option3,"C) 1950s");
    strcpy(option4,"D) 1960s");
    ptr = create(ques,'B',option1,option2,option3,option4,3);
root = insert( root, ptr );

    strcpy(ques,"Which of the following european countries did NOT participate\n\t\t  in World War 2?");
    strcpy(option1,"A) Romania");
    strcpy(option2,"B) Hungary");
    strcpy(option3,"C) Sweden");
    strcpy(option4,"D) Bulgaria");
    ptr = create(ques,'C',option1,option2,option3,option4,7);
root = insert( root, ptr );

    strcpy(ques,"In which of the following countries, Google Maps is NOT banned?");
    strcpy(option1,"A) Iran");
    strcpy(option2,"B) North Korea");
    strcpy(option3,"C) Syria");
    strcpy(option4,"D) Ireland");
    ptr = create(ques,'D',option1,option2,option3,option4,13);
root = insert( root, ptr );

    strcpy(ques,"Which one of following Indians was never elected to become\n\t\t  India's Prime Minister?");
    strcpy(option1,"A) Atal Bihari Vajpayee");
    strcpy(option2,"B) Rajiv Gandhi");
    strcpy(option3,"C) A.P.J. Abdul Kalam");
    strcpy(option4,"D) Indira Gandhi");
    ptr = create(ques,'C',option1,option2,option3,option4,17);
root = insert( root, ptr );

    strcpy(ques,"Name the CEO of Intel company.");
    strcpy(option1,"A) Bob Swan");
    strcpy(option2,"B) Tim Cook");
    strcpy(option3,"C) Michael Scott");
    strcpy(option4,"D) John Browett");
    ptr = create(ques,'A',option1,option2,option3,option4,1);
root = insert( root, ptr );

    strcpy(ques,"Who discovered oxygen?");
    strcpy(option1,"A) Joseph Priestley");
    strcpy(option2,"B) Gil Amelio");
    strcpy(option3,"C) Michael Spindler");
    strcpy(option4,"D) Jerry York");
    ptr = create(ques,'A',option1,option2,option3,option4,4);
root = insert( root, ptr );

    strcpy(ques,"In which year was the popular english rock band named\n\t\t  Pink Floyd formed?");
    strcpy(option1,"A) 1955");
    strcpy(option2,"B) 1965");
    strcpy(option3,"C) 1975");
    strcpy(option4,"D) 1985");
    ptr = create(ques,'B',option1,option2,option3,option4,6);
root = insert( root, ptr );

    strcpy(ques,"In which year did the popular Indian singer Arijit Singh\n\t\t  start his music career?");
    strcpy(option1,"A) 2004");
    strcpy(option2,"B) 2007");
    strcpy(option3,"C) 2010");
    strcpy(option4,"D) 2013");
    ptr = create(ques,'B',option1,option2,option3,option4,8);
root = insert( root, ptr );

    strcpy(ques,"In which decade did the classic music composer named\n\t\t  Ludwig van Beethoven die?");
    strcpy(option1,"A) 1800s");
    strcpy(option2,"B) 1810s");
    strcpy(option3,"C) 1820s");
    strcpy(option4,"D) 1830s");
    ptr = create(ques,'C',option1,option2,option3,option4,11);
root = insert( root, ptr );

    strcpy(ques,"Which one of the following countries have NOT landed\n\t\t humans on moon yet?");
    strcpy(option1,"A) China");
    strcpy(option2,"B) United States");
    strcpy(option3,"C) Russia");
    strcpy(option4,"D) India");
    ptr = create(ques,'D',option1,option2,option3,option4,14);
root = insert( root, ptr );

    strcpy(ques,"Which one of the countries has the largest population?");
    strcpy(option1,"A) Bangladesh");
    strcpy(option2,"B) Brazil");
    strcpy(option3,"C) Nigeria");
    strcpy(option4,"D) Russia");
    ptr = create(ques,'B',option1,option2,option3,option4,16);
root = insert( root, ptr );

    strcpy(ques,"Which one of the countries has the largest area covered?");
    strcpy(option1,"A) Canada");
    strcpy(option2,"B) United States");
    strcpy(option3,"C) Australia");
    strcpy(option4,"D) India");
    ptr = create(ques,'A',option1,option2,option3,option4,18);
root = insert( root, ptr );

    strcpy(ques,"Which one of the countries has the smallest\n\t\t Gross Domestic Product(GDP)?");
    strcpy(option1,"A) India");
    strcpy(option2,"B) China");
    strcpy(option3,"C) United Kingdom");
    strcpy(option4,"D) Japan");
    ptr = create(ques,'C',option1,option2,option3,option4,0);
root = insert( root, ptr );

    strcpy(ques,"Which one of the following countries is the most Biodiversed?");
    strcpy(option1,"A) China");
    strcpy(option2,"B) Brazil");
    strcpy(option3,"C) South Africa");
    strcpy(option4,"D) Thailand");
    ptr = create(ques,'B',option1,option2,option3,option4,1);
root = insert( root, ptr );

    strcpy(ques,"Which one of the countries is the most densely populated?");
    strcpy(option1,"A) Singapore");
    strcpy(option2,"B) Bangladesh");
    strcpy(option3,"C) Vatican City");
    strcpy(option4,"D) Hong Kong");
    ptr = create(ques,'A',option1,option2,option3,option4,3);
root = insert( root, ptr );

    strcpy(ques,"Which one of the following languages is the most spoken?");
    strcpy(option1,"A) Spanish");
    strcpy(option2,"B) Russian");
    strcpy(option3,"C) Arabic");
    strcpy(option4,"D) Mandarin");
    ptr = create(ques,'D',option1,option2,option3,option4,4);
root = insert( root, ptr );

    strcpy(ques,"Which one of the following countries is the most advanced in\n\t\t terms of technology?");
    strcpy(option1,"A) Canada");
    strcpy(option2,"B) India");
    strcpy(option3,"C) Germany");
    strcpy(option4,"D) Finland");
    ptr = create(ques,'C',option1,option2,option3,option4,5);
root = insert( root, ptr );

    strcpy(ques,"Which one of the following animals is the largest in\n\t\t size?");
    strcpy(option1,"A) Colossal Squid");
    strcpy(option2,"B) Giraffe");
    strcpy(option3,"C) African Elephant");
    strcpy(option4,"D) Brown Bear");
    ptr = create(ques,'A',option1,option2,option3,option4,6);
root = insert( root, ptr );

    strcpy(ques,"Which one of the following planets is the biggest in size?");
    strcpy(option1,"A) Uranus");
    strcpy(option2,"B) Neptune");
    strcpy(option3,"C) Saturn");
    strcpy(option4,"D) Earth");
    ptr = create(ques,'C',option1,option2,option3,option4,7);
root = insert( root, ptr );

    strcpy(ques,"Who invented telephone?");
    strcpy(option1,"A) Joseph Swan ");
    strcpy(option2,"B) Alexander Graham Bell");
    strcpy(option3,"C) Hans Lippershey");
    strcpy(option4,"D) Jacob Metius");
    ptr = create(ques,'B',option1,option2,option3,option4,9);
root = insert( root, ptr );

    strcpy(ques,"Who invented telescope?");
    strcpy(option1,"A) Joseph Swan ");
    strcpy(option2,"B) Alexander Graham Bell");
    strcpy(option3,"C) Hans Lippershey");
    strcpy(option4,"D) Jacob Metius");
    ptr = create(ques,'C',option1,option2,option3,option4,10);
root = insert( root, ptr );

    strcpy(ques,"Who invented Computer?");
    strcpy(option1,"A) Joseph Swan");
    strcpy(option2,"B) Zacharias Janssen");
    strcpy(option3,"C) Robert Hooke");
    strcpy(option4,"D) Charles Babbage");
    ptr = create(ques,'D',option1,option2,option3,option4,11);
root = insert( root, ptr );

    strcpy(ques,"Who invented Dynamite?");
    strcpy(option1,"A) Alfred Nobel");
    strcpy(option2,"B) Marie Curie");
    strcpy(option3,"C) Thomas Edison");
    strcpy(option4,"D) Albert Einstein");
    ptr = create(ques,'A',option1,option2,option3,option4,13);
root = insert( root, ptr );

    strcpy(ques,"Which one of the following cities in India is the most polluted?");
    strcpy(option1,"A) Delhi");
    strcpy(option2,"B) Kanpur");
    strcpy(option3,"C) Faridabad");
    strcpy(option4,"D) Lucknow");
    ptr = create(ques,'B',option1,option2,option3,option4,14);
root = insert( root, ptr );

    strcpy(ques,"Which one of the cities is the most expensive in the world?");
    strcpy(option1,"A) Los Angeles");
    strcpy(option2,"B) New York");
    strcpy(option3,"C) Osaka");
    strcpy(option4,"D) Singapore");
    ptr = create(ques,'D',option1,option2,option3,option4,15);
root = insert( root, ptr );

    strcpy(ques,"Which one of the countries is the most educated in the world?");
    strcpy(option1,"A) Korea");
    strcpy(option2,"B) United States");
    strcpy(option3,"C) Canada");
    strcpy(option4,"D) Australia");
    ptr = create(ques,'C',option1,option2,option3,option4,16);
root = insert( root, ptr );

    strcpy(ques,"Which one of the following animal species is the\n\t\t  deadliest to humans?");
    strcpy(option1,"A) Snakes");
    strcpy(option2,"B) Tapeworms");
    strcpy(option3,"C) Humans themselves");
    strcpy(option4,"D) Assassin bugs");
    ptr = create(ques,'C',option1,option2,option3,option4,17);
root = insert( root, ptr );

    strcpy(ques,"Which one of the following religions in India is the\n\t\t  LEAST populated?");
    strcpy(option1,"A) Sikhs");
    strcpy(option2,"B) Jains");
    strcpy(option3,"C) Christians");
    strcpy(option4,"D) Hindus");
    ptr = create(ques,'B',option1,option2,option3,option4,19);
root = insert( root, ptr );

    ch = instructions();
    if(ch=='Y'|| ch=='y')
    {
	run(root);
	clrscr();
	print_score();
	getch();
    }

    else
    {
	cout<<"\n\t\t\t\t Thanks for coming Here!";
	getch();
	exit(0);
    }
return 0;
}
