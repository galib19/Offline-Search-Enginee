#include<bits/stdc++.h>

using namespace std;

struct trie
{
       char key;
       trie *next,*children;
};

trie *newnode(char s)
{
     trie *t= new trie[100] ;
     t->key=s;
     t->next=NULL;
     t->children=NULL;
}


void insert(trie **t,char *s,int start)
				   
				   {
				   if(s[start]=='\0')
                   {
                          *t=newnode('#');
                          return;
                   }
                   else if(*t==NULL)
                   {
                               *t=newnode(s[start]);
                               insert(&(*t)->children,s,start+1);
                   }
                   else if ((*t)->key==s[start])
                   insert(&(*t)->children,s,start+1);
                   else
                   insert(&(*t)->next,s,start);
}


bool search(trie *t ,char *s,int start)
{

	 //cout << s[start] << endl;
	//cout << t->key << endl;
     if(t==NULL)
     return false;

     if(t->key==  s[start] ) //if(t->key=='#' && s[start]=='\0')
     return true;

     if((t->key!='#' && s[start]=='\0') || (t->key=='#' && s[start]!='\0'))
     return false;

     if(t->key==s[start])
     return search(t->children,s,start+1);

     else
     return search(t->next,s,start);

     return false;
}

int main()
{      
      trie *t=NULL;
      char ch;
      
      do{
          	
			  if (ch=='n') break;
			  char str[20];
			  cout << "Insert String in Suffix Tree" << endl;
			  cin >> str;
      
              insert(&t,str,0);
          
              cout <<"Want More Insertion? y/n ::"<<endl; 
               
      }while(cin >> ch);
      
      ch= 'y';
      do{
          	
			  if (ch=='n') break;
			  char str[20];
			  cout << "Search String from suffix tree" << endl;
			  cin >> str;
      
              if(search(t,str,0))
			  cout<<"Found :)"<<endl;
              else
              cout<< "Not Found :( Wanna Try Again? y/n :: "<< endl;
              
              cout << "Search another?"<< endl; 
               
      }while(cin >> ch);

return 0;
}
