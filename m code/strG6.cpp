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
     //t->myVec.clear();
}

void insert(trie **t,char *s,int start,int i)
    {
        if(s[start]=='\0')
        {
            //*t=newnode('#');
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
        int temp=0;
        while(!(*t)->myVec.empty())
		{
			temp=(*t)->myVec.back();
			(*t)->myVec.pop_back();
			cout<< temp << endl;
			temp=0;
		}

}


trie search(trie *t ,char *s,int start)
{
	 cout << s[start] << endl;
	 cout << t->key << endl;
     
     if(t==NULL)
     {
		t->myVec.clear();
		return (*t);
	 }

     if((t->key=='#' && s[start]!='\0'))
	 { 
		t->myVec.clear();
		return (*t);
	 }

     if(t->key==s[start])
	 {
				// cout<<"sd1"<<endl;
		return search(t->children,s,start+1);
	 }
	 else
	 {
				//cout<<"sd  "<<endl;
		return search(t->next,s,start);
	 }
     return  (*t);
	 //cout<<"in"<<endl;
	/*while ()
	{
		cout  <<"s[start]:\t"<<s[start] << endl;
		cout <<"key:\t"<< t->key << endl;
		
		if(t==NULL)
		{
			t->myVec.clear();
			cout<<"error building tree"<<endl; 
			
		}
		//if(t->key==  s[start] ) //if(t->key=='#' && s[start]=='\0')
		//return true;
		if((t->key=='#' && s[start]!='\0'))
		{
			t->myVec.clear();
			break;
		}

		if(t->key==s[start])
		{
				// cout<<"sd1"<<endl;
			search(t->children,s,start+1);
		}
		else
			{
				//cout<<"sd  "<<endl;
				search(t->next,s,start);
			}
	}*/
		
}

int main()
{
      trie *t=NULL;
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
  
      
      /*char ch= 'y';
      do{

			  if (ch=='n') break;*/
			  
			  char str[20];
			  cout << "Search String from suffix tree" << endl;		  
			  cin>>str;
			  
			  
              trie fintrie = search(t,str,0);
			  
			  int temp=0;
				  while(!fintrie.myVec.empty())
				  {
					temp=fintrie.myVec.back();
					fintrie.myVec.pop_back();
					cout<< temp << endl;
					temp=0;
				  }
      //}while(cin >> ch);


return 0;
}
