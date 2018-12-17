#include<bits/stdc++.h>

using namespace std;

struct trie
{
       char key;
       trie *next,*children;
       vector<int> myVec;
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
     t->myVec.clear();
}
int i;
void insert(trie **t,char *s,int start,int i)
    {
        if(s[start]=='\0')
        {
            *t=newnode('#');
            return;
        }
        else if(*t==NULL)
        {
            *t=newnode(s[start]);
            (*t)->myVec.push_back(i);
            insert(&(*t)->children,s,start+1,i);
        }
        else if ((*t)->key==s[start])
        {
            (*t)->myVec.push_back(i);
            insert(&(*t)->children,s,start+1,i);
        }

        else
        {
            (*t)->myVec.push_back(i);
            insert(&(*t)->next,s,start+1,i);
        }
        /*int temp=0;
        while(!(*t)->myVec.empty())
		{
			temp=(*t)->myVec.back();
			(*t)->myVec.pop_back();
			cout<< temp << endl;
			temp=0;
		}*/

}


trie search(trie *t ,char *s,int start)
{
	 if(s[start]!='\0')
	{
		if(t==NULL)
		{
			t->myVec.clear();
			cout<<"error building tree"<<endl; 
		}
		//if(t->key==  s[start] ) //if(t->key=='#' && s[start]=='\0')
		//return true;
		if((t->key=='#' && s[start]!='\0'))
			t->myVec.clear();

		if(t->key==s[start])
			search(t->children,s,start+1);
		else
			search(t->next,s,start);
	}
		return (t->myVec);
}

int main()
{
      trie *t=NULL;
      trie *r=NULL;
      fileName myFile;
      long int i = 0;
      vector<string> name;
      vector<string> path;

	  string line;
      ifstream inFile;
      inFile.open ("list.txt");
      if (inFile.is_open())  // same as: if (myfile.good())
      {
		  //cout << "Begin" << endl;
          inFile>>myFile.path;
          do  // same as: while (getline( myfile, line ).good())
          {
			  //cout << "Bgin" << endl;
			  string temp;
              getline(inFile ,temp);
              int k=0;
              while (k<temp.size()) {
				myFile.name[k] = temp[k]; 
				k++;
			  }
			  myFile.name[temp.size()] = '\0';
              //cout << "Bin" << endl;
              i++;
			  insert(&t,myFile.name,1,i);
              name.push_back(myFile.name);
              path.push_back(myFile.path);
              cout << myFile.name << " -> " << myFile.path << endl;
          }while(inFile>>myFile.path);
          
          inFile.close();
      }
		
		else {
			cout << "End" << endl;
		}
      /*cin >> myFile.path;
      //cout << myFile.name << myFile.path << endl;
      do
      {
		 gets(myFile.name);
		 i++;
         insert(&t,myFile.name,1,i);
         name.push_back(myFile.name);
         path.push_back(myFile.path);
         
         //cout << myFile.path << " " << myFile.name << endl;

      }while(cin>>myFile.path);
      cout << i << endl;
      /*for (unsigned n=0; n<name.size(); ++n) {
        cout << name.at( n ) << " "<<path.at(n);
      }*/

      
      /*char ch= 'y';
      do{

			  if (ch=='n') break;*/
			  
			  char str[20];
			  cout << "Search String from suffix tree" << endl;		 
			  cout<<"ada2"; 
			  cin>>str;
			  
			  
              vector<int> finVec = search(t,str,0);
			  
			  /*int temp=0;
				  while(!r.myVec.empty())
				  {
					temp=r.myVec.back();
					r.myVec.pop_back();
					cout<< temp << endl;
					temp=0;
				  }*/
      //}while(cin >> ch);


return 0;
}
