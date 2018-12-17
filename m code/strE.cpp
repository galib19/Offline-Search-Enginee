#include<bits/stdc++.h>

using namespace std;

struct trie
{
       char key;
       trie *next,*children;
};

struct fileName
{
	char name[100];
	char path[500];
};

trie *newnode(char s)
{
     trie *t= new trie[100] ;
     t->key=s;
     t->next=NULL;
     t->children=NULL;
}


void insert(trie **t,char *s,int start)
{if(s[start]=='\0')
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
      fileName myFile;
      double i = 0; 
      
      cin >> myFile.path;// >> myFile.name;
      //cout << myFile.name << myFile.path << endl;
      
    
     //while (cin >> str1 >> str2) {
     do{
		 gets (myFile.name);
		i++;
              insert(&t,myFile.name,0);
               cout << myFile.path << " \t\t\t" << myFile.name << endl;
        
      }while(cin >> myFile.path);
      
      cout << i << endl;
      
      do{
		 gets (myFile.name);
		i++;
              insert(&t,myFile.name,0);
              cout << myFile.path << " \t\t\t" << myFile.name << endl;
        
      }while(cin >> myFile.path);
      
      cout << i << endl;
      
     /* ch= 'y';
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
*/
return 0;
}
