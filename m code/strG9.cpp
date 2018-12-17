#include<bits/stdc++.h>

using namespace std;
void searchDeep(struct trie*);
struct trie
{
       char key;
       trie *next,*children;
       vector<string> myVec;
};
trie *root;

/*struct fileName
{
	char name[100];
	char path[500];

};*/

trie *newnode(char s)
{
     trie *t= new trie[100] ;
     t->key=s;
     //t->myVec.push_back("govire jao");
     t->next=NULL;
     t->children=NULL;

     return t;
}

void insert(trie **t,char *s,int start,string path)
    {

         if(s[start]=='\0')
        {
            *t=newnode('#');
            (*t)->myVec.push_back(path);
            for(int i = 0; i < (*t)->myVec.size(); i++) {
            cout << (*t)->myVec[i] << endl;}

            //for(int i = 0; i < myVec.size(); i++) {
            //cout << myVec[i] << endl;}
            return;
        }
        else if(*t==NULL)
        {
            *t=newnode(s[start]);
            //(*t)->myVec.push_back(i);

            insert(&(*t)->children,s,start+1,path);
        }
        else if ((*t)->key==s[start])
        {
            //(*t)->myVec.push_back(i);
            insert(&(*t)->children,s,start+1,path);
        }

        else
        {
            //(*t)->myVec.push_back(i);
            insert(&(*t)->next,s,start,path);
        }

        /*for(int i = 0; i < myVec.length(); i++) {
            cout << myVec[i] << endl;
        }*/

}


void search(trie *t ,char *s,int start)
{
	 //cout<<"in"<<endl;
	if (s[start]!='\0')
	{
		cout  <<"s[start]:\t"<<s[start] << endl;
		cout <<"key:\t"<< t->key << endl;
		//cout<<"vec size:"<< t->myVec.size()<<endl;

		if(t==NULL)
		{
			//t->myVec.clear();
			cout<<"error building tree"<<endl;

		}
		//if(t->key==  s[start] ) //if(t->key=='#' && s[start]=='\0')
		//return true;
		//if((t->key=='#' && s[start]!='\0'))
			//searchDeep(t);

		if(t->key==s[start])
			{
				//cout<<"sd1"<<endl;
				if (s[start+1]=='\0') {searchDeep(t->children);}
				search(t->children,s,start+1);
			}
		else
			{
				//cout<<"sd  "<<endl;
				if (s[start+1]=='\0') {searchDeep(t->children);}
				search(t->next,s,start);
			}
	}
}

void searchDeep(trie *t)
        {

            if(t->key!='#')
            {
                searchDeep(t->children);

            }
            else
            {
                for(int i = 0; i < t->myVec.size(); i++)
                {
                    cout << t->myVec[i] << endl;
                }
                searchDeep(t->next);
            }
            /*if(t->key==s[start])
			{
				//cout<<"sd1"<<endl;
				//if (s[start+1]=='\0') goto k;
				searchDeep(t->children);
			}
		else
			{
				cout<<"sd  "<<endl;
				if (s[start+1]=='\0') goto k;
				search(t->next,s,start);
			}
        }*/


}

int main()
{
      trie *t=NULL;
      //fileName myFile;
      int i = 0;
      char name[100];
      vector<string> fileName;
      vector<string> filePath;

	  string line;
      ifstream inFile;
      inFile.open ("list.txt");
      if (inFile.is_open())  // same as: if (myfile.good())
      {
		  //cout << "Begin" << endl;
          string path;
          inFile>>path;
          do  // same as: while (getline( myfile, line ).good())
          {
			  //cout << "Bgin" << endl;
			  //cout<<path<<endl;
			  string temp;
              getline(inFile ,temp);
              int k=0;
              while (k<temp.size()) {
				name[k] = temp[k];
				k++;
			  }
			   name[temp.size()] = '\0';
              //cout << "Bin" << endl;
              i++;
			  insert(&t,name,1, path);


              fileName.push_back( name);
              filePath.push_back(path);
              cout <<  name << " -> " << path << endl;
          }while(inFile>> path);

          inFile.close();
      }

		else {
			cout << "End" << endl;
		}


			  char str[20];
			  cout << "Search String from suffix tree" << endl;
			  cin>>str;
              search(t,str,0);
return 0;
}

