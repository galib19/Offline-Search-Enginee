 #include<bits/stdc++.h>

using namespace std;

struct trie
{
       char key;
       trie *next,*children;
       set<int> mySet;
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
     //t->mySet.clear();
}
int i;
void insert(trie **t,char *s,int start,int i)
    {
        if(s[start]=='\0')
        {
            *t=newnode('#');
            (*t)->mySet.insert(i);
            return;
        }
        else if(*t==NULL)
        {
            *t=newnode(s[start]);
            (*t)->mySet.insert(i);
            insert(&(*t)->children,s,start+1,i);
        }
        else if ((*t)->key==s[start])
        {
            (*t)->mySet.insert(i);
            insert(&(*t)->children,s,start+1,i);
        }

        else
        {
            (*t)->mySet.insert(i);
            insert(&(*t)->next,s,start,i);
        }
 
        set<int>::iterator it;
        cout << "myset contains of file:"<<i<<":";
  for ( it=(*t)->mySet.begin() ; it != (*t)->mySet.end(); it++ )
    cout << " " << *it;

  cout << endl;
         


}


bool search(trie *t ,char *s,int start)
{


     if(t==NULL)
     cout<<"ERROR NOT FOUND"<<endl;

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
      fileName myFile;
      long int i = 0;

      cin >> myFile.path;// >> myFile.name;
      //cout << myFile.name << myFile.path << endl;

      do
      {
		 gets(myFile.name);
		 i++;
         insert(&t,myFile.name,0,i);
         //cout << myFile.path << " " << myFile.name << endl;

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
