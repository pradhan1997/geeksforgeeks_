#include<bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE=26;

//TRIE NODE
struct TrieNode{
	struct TrieNode *children[ALPHABET_SIZE];
	//TO CHECK IF IT IS END OF A WORD
	bool isEndOfWord;
};

//returns a new trie node
struct TrieNode *getNode(void){
	struct TrieNode *pNode=new TrieNode;
	pNode->isEndOfWord=false;
	for(int i=0;i<ALPHABET_SIZE;i++)
	pNode->children[i]=NULL;
	return pNode;
}

//if the key is not present, inserts key into trie
//if the key is prefix of the trie node, mark it as a leaf node
void insert(struct TrieNode *root,string key){
     
     struct TrieNode *pCrawl=root;
     for(int i =0;i<key.length();i++){
     	int index=key[i]-'a';
     	if(!pCrawl->children[index])
     	pCrawl->children[index]=getNode();
     	pCrawl=pCrawl->children[index];
     }	
     //mark the last node as leaf
     pCrawl->isEndOfWord=true;
}

//returns true if key is present in trie
//somewhat same logic as insert
bool search(struct TrieNode *root, string key){
	struct TrieNode *pCrawl=root;
	for(int i=0;i<key.length();i++){
		int index=key[i]-'a';
		if(!pCrawl->children[index])
		return false;
		
		pCrawl=pCrawl->children[index];
	}
	return (pCrawl!=NULL && pCrawl->isEndOfWord);
}


//main method
int main(){
	string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
        int n = sizeof(keys)/sizeof(keys[0]); 
        struct TrieNode *root=getNode();
        //create a trie 
        for(int i=0;i<n;i++)
        insert(root,keys[i]);
        //search for keys
        search(root,"the")?cout<<"the is present":cout<<"nopes not present";
        cout<<"\n";
        search(root,"these")?cout<<"these is present":cout<<"nopes not present";
	return 0;
}



