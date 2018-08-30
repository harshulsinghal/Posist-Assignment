#include <bits/stdc++.h>
using namespace std;
/*
struct timestamp {
int dd,mm,yyyy,hh,mn,ss,zhh,zmm;
char sign,zone[3];
};
*/
struct data{
int o_id;
float val;
string name;
};

struct Node{
    struct Node *left, *right, *parent;
string timestamp; //timestamp structure as 12.08.2019 12:12:55 GMT+5:30
string dat;
int nodeNumber;
string nodeId,referenceNodeId,childReferenceNodeId,genesisReferenceNodeId,HashValue;
};
string cipher(string original, int key){
for(int i=0;i<original.size();i++){
    original[i]+=key;
}
return original;
}
string computeDataHash(int o_id, float val, string name){
stringstream str1,str2;
str1 >> o_id;
str2 >> val;
string a1 = str1.str(), a2 = str2.str();
string toCompute = a1 + " " + a2 + " " + name;
toCompute = cipher(toCompute,3); // key=3 set by owner
return toCompute;
}

string computeHash(string timestamp, string hashe, int nodeNumber, string nodeId,string referenceNodeId,string childReferenceNodeId,string genesisReferenceNodeId) {
string hashString;
stringstream str1;
str1 >> nodeNumber;
string a1 = str1.str();
hashString = timestamp + hashe + a1 + nodeId + referenceNodeId + childReferenceNodeId + genesisReferenceNodeId;
return hashString;
}
struct Node *createNode(string timestamp,struct data *d, int nodeNumber, string nodeId,string referenceNodeId,string childReferenceNodeId,string genesisReferenceNodeId){
struct Node *n;
n->timestamp = timestamp;
n->dat = computeDataHash(d->o_id,d->val,d->name);
n->nodeNumber = nodeNumber;
n->referenceNodeId = referenceNodeId;
n->nodeId = nodeId;
n->childReferenceNodeId = childReferenceNodeId;
n->genesisReferenceNodeId = genesisReferenceNodeId;
n->HashValue = computeHash(timestamp,n->dat,nodeNumber,nodeId,referenceNodeId,childReferenceNodeId,genesisReferenceNodeId);
return n;
}
struct Node *createGenesis(){
struct Node *GenesisNode = new (struct Node);
struct data *d;
d->o_id = 1;
d->val = 12.23f;
//d->name = "Harshul";
GenesisNode->parent = NULL;
GenesisNode->left = NULL;
GenesisNode->right = NULL;
GenesisNode = createNode("30.08.2018 17:51:22 GMT+5:30",d,1,"0","0","0","ydyyfdyy");
return GenesisNode;
}
int main(){
struct Node *GenesisNode = createGenesis();
cout<<"End";
return 0;
}
