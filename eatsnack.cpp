#include<iostream>//Ã∞≥‘…ﬂ¿‡ 
#include<vector>
#include<windows.h>
#include <conio.h>
using namespace std;
void food(char*p);
class snack
{
	public:
		vector<char*> body;
		int size,toward;
		snack(char *p){size=0;body.push_back(p);toward=0;};
		void movewest(){toward=3;};
		void moveeast(){toward=2;};
		void movesouth(){toward=1;};
		void movenorth(){toward=0;};
		bool move(char *t);
};
bool snack::move(char *t)
{
	char *p;
	p=body[size];
	//*body[size]='\0';
	for(int i=size;i>0;i--)
	   body[i]=body[i-1];
	if(toward==0)
	   body[0]-=20;
	if(toward==1)
	   body[0]+=20;
	if(toward==2)
	   body[0]++;
	if(toward==3)
	   body[0]--;
	//if(*body[0]=='#')
	   //body.push_back(p); 
	*p='\0';
	if(*(body[0])=='@')
	{
		*p='*';
		body.push_back(p);
		size++;
		food(t);
	  }  
	if(*(body[0])=='#'||*(body[0])=='*')
	  return false;
	*body[0]='*';
	return true;
}
void food(char *p)
{
	int c;
	while(1)
	{
	c=rand()%400;
	if(*(p+c)=='\0')
	   break;
	   }
	*(p+c)='@';
}

int main()
{
    char game[20][20];
    char *t=&game[0][0];
    char *p = &game[10][10];
    for(int i=0;i!=20;i++)
       for(int j=0;j!=20;j++)
           game[i][j]='\0';
    for(int i=0;i!=20;i++)
       game[0][i]='#';
    for(int i=0;i!=20;i++)
       game[19][i]='#';
    for(int i=0;i!=20;i++)
       game[i][0]='#';
    for(int i=0;i!=20;i++)
       game[i][19]='#';
    game[10][10]='*';
    //game[2][4]='@';
    snack sk1(p);
    food(t);
    while(1)
      {
      	Sleep(4);
      	if(kbhit())
		  {
      	  int ch = _getch();
		  if(ch==97)
		     sk1.movewest();
		  if(ch==119)
		     sk1.movenorth();
		  if(ch==100)
		    sk1.moveeast();
		  if(ch==115)
		    sk1.movesouth(); 
		  //cout << ch;
	    }
	     bool flag=sk1.move(t);
		if(!flag)
		   break;
	    for(int i=0;i!=20;i++)
      	   {
			 for(int j=0;j!=20;j++)
      	      cout << game[i][j];
      	     cout << endl;
      	    }
      	cout << "’‚¿Ô «Ã∞≥‘…ﬂ”Œœ∑,wasd≤Ÿøÿ…œœ¬◊Û”“ by wei"<<endl;
		Sleep(300);
		system("cls");
}
        cout << "you lose"<<endl;
        system("pause");
 } 
