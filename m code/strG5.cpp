#include<bits/stdc++.h>

using namespace std;

struct trie
{
       char key;
       trie *next,*children;
       vector<int> myVec;
};
//trie *root;

struct fileName
{
	char name[100];
	char path[500];
};

trie *newnode(char s)
{
     trie *t= new trie[100] ;
     t->key=s;
     t->myVec.clear();
     t->next=NULL;
     t->children=NULL;
     //return t;
}

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
            //(*t)->myVec.push_back(i);
            insert(&(*t)->next,s,start,i);
        }

        for(int k=0; k< (*t)->myVec.size();k++)
        {
			cout<< (*t)-> myVec[k] << endl;
		}


}

trie search(trie *t ,char *s,int start)
{
	 //cout<<"in"<<endl;
	if (s[start]!='\0')
	{
		cout  <<"s[start]:\t"<<s[start] << endl;
		cout <<"key:\t"<< t->key << endl;
		//cout<<"vec size:"<< t->myVec.size()<<endl;

		/*if(t==NULL)
		{
			t->myVec.clear();
			cout<<"error building tree"<<endl;

		}*/
		//if(t->key==  s[start] ) //if(t->key=='#' && s[start]=='\0')
		//return true;
		//if((t->key=='#' && s[start]!='\0'))
			//t->myVec.clear();

		if(t->key==s[start])
			{
				//cout<<"sd1"<<endl;
				if (s[start+1]=='\0') goto k;
				search(t->children,s,start+1);
			}
		else
			{
				cout<<"sd  "<<endl;
				if (s[start+1]=='\0') goto k;
				search(t->next,s,start);
			}
	}
	k:

	for(int i=0; i< t->myVec.size();i++)
        {
			cout << t->myVec[i] << endl;
		}

		return  (*t);
}

int main()
{
      trie *t=NULL;
      fileName myFile;
      int i = 0;
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


      /*char ch= 'y';
      do{

			  if (ch=='n') break;*/

			  char str[20];
			  cout << "Search String from suffix tree" << endl;
			  cin>>str;


              trie fintrie = search(t,str,0);

			  /*int temp=0;
				  while(!fintrie.myVec.empty())
				  {
					temp=fintrie.myVec.back();
					fintrie.myVec.pop_back();
					cout<< temp << endl;
					temp=0;
				  }*/
      //}while(cin >> ch);


return 0;
}
