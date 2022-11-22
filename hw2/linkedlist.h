#include <iostream>

using namespace std;

template <class Type>
struct nodeType
{
	Type value;
   Type user;
   Type id;
   Type score;
   Type grade;
	nodeType<Type> *link;
};

template <class Type>
class linkedList {
private: 
	int count;
	nodeType<Type> *head;
	nodeType<Type> *tail;
public:
   linkedList();
   int length();
   void loadInput(string input);
   void loadCommand(string command);
   void sortLoad();
   void addAtLocation(string index, string cred);
   void removeWithAttribute(string attribute);
   void sortWithAttribute(string attribute);
   void insertTail(const Type& newItem);
   void insertHead(const Type& newItem);
   void deleteNode(const Type& deleteItem);
   void removeHead();
   void removeTail();
   void destroyList();
   void print(ofstream &out) const;
   void printInput() const;
   void printCommand() const;
   ~linkedList();
};	


template <class Type>
linkedList<Type>::linkedList() 
{
	head = NULL;
	tail = NULL;
	count = 0;
}

template <class Type>
int linkedList<Type>::length() 
{
	return count;
}

//this is the function help loading original info to the linked list
template <class Type>
void linkedList<Type>::loadInput(string str)
{
    str.erase(remove(str.begin(), str.end(), '['), str.end());
    str.erase(remove(str.begin(), str.end(), ']'), str.end());
    
    string small="";//result as final product, small as elements contain by vector section
    int n=str.length();// integer n to get string length
    char arr[n];// turn string into an array of char
    vector<string> section;//to contain and divide sections of the string

    for(int i=0;i<n;i++){
        arr[i]=str[i];
    }

    for(int i=0;i<n;i++){
        if(i==(n-1)){//to ensure last id line is included due to the loop's nature
            small+=arr[i];
            section.push_back(small);
        }
        else if(arr[i]!=';'){
            small+=arr[i];//add to string;
        }
        else if(arr[i]==';'){
            section.push_back(small);
            small="";//reset small to continue with the next section of vector;
        }
   }
   
   if(section.size()<4){
        return;
   }

   if(section[0][0]=='i' && section[1][0]=='u' && section[2][0]=='s' && section[3][0]=='g'){
      nodeType<Type> *newNode = new nodeType<Type>();
      newNode->id=section[0];
      newNode->user=section[1];
      newNode->score=section[2];
      newNode->grade=section[3];
      newNode->link=NULL;
   
      if (head == NULL) {
         head = tail = newNode;
      } else {
         tail->link = newNode;
         tail = newNode;
      }
      count++;
   }else{
      return;
   }
}

//sortLoad function allows tha program to load input and compare id to make sure there is always updated with same id.
template<typename Type>
void linkedList<Type>::sortLoad(){
   nodeType<Type> *temp3 = new nodeType<Type>();

   temp3=head;
   if(head == NULL){
      return;
   }
   while(temp3->link != NULL){
      nodeType<Type> *temp2 = new nodeType<Type>();
      temp2=temp3;
      while(temp2->link != NULL){// order is temp1 to temp2 to temp3
         if(temp2->link->id == temp3->id){
            temp3->user=temp2->link->user;
            temp3->grade=temp2->link->grade;
            temp3->score=temp2->link->score;

            nodeType<Type> *dlt = temp2->link;
            temp2->link=temp2->link->link;

            free(dlt);
            count--;
         }
         if(temp2->link->id !=temp3->id && temp2->link->user == temp3->user){
            nodeType<Type> *dlt = temp2->link;
            temp2->link=temp2->link->link;

            free(dlt);
            count--;
         }
         temp2=temp2->link;
      }
      temp3=temp3->link;
   }
}

//loadCommand function allow loading command and distinguish between different commands
template<typename Type>
void linkedList<Type>::loadCommand(string cmd){

   string small="";//result as final product, small as elements contain by vector section
   int n=cmd.length();// integer n to get string length
   char arr[n];// turn string into an array of char
   vector<string> section;//to contain and divide sections of the string

   string order="", index="", credential="";//to take parts of diseccting command order

   for(int i=0;i<n;i++){
      arr[i]=cmd[i];
   }

   for(int i=0;i<n;i++){
      if(i==(n-1)){//to ensure last id line is included due to the loop's nature
         small+=arr[i];
         section.push_back(small);
      }
      else if(arr[i]!=' '){
         small+=arr[i];//add to string;
      }
      else if(arr[i]==' '){
         section.push_back(small);
         small="";//reset small to continue with the next section of vector;
      }
   }

   //assigning order, index and credential, with sorting index and credential
   order=section[0];

   index=section[1];
   index.erase(remove(index.begin(), index.end(), '('), index.end());
   index.erase(remove(index.begin(), index.end(), ')'), index.end());

   if(section[0][0]=='A'){
      credential=section[2];
      credential.erase(remove(credential.begin(), credential.end(), '['), credential.end());
      credential.erase(remove(credential.begin(), credential.end(), ']'), credential.end());
   }

   if(order[0]=='A'){
      addAtLocation(index,credential);
   }
   if(order[0]=='R'){
      removeWithAttribute(index); 
   }
   if(order[0]=='S'){
      sortWithAttribute(index);
   }
}

template <class Type>
void linkedList<Type>::addAtLocation(string index, string credential)
{  
   int ind=stoi(index), pos=0;// turn index from string to integer, pos to count position
   string small="";//result as final product, small as elements contain by vector section
   int n=credential.length();// integer n to get string length
   char arr[n];// turn string into an array of char
   vector<string> section;//to contain and divide sections of the string


   for(int i=0;i<n;i++){
      arr[i]=credential[i];
   }

   for(int i=0;i<n;i++){
      if(i==(n-1)){//to ensure last id line is included due to the loop's nature
         small+=arr[i];
         section.push_back(small);
      }
      else if(arr[i]!=';'){
         small+=arr[i];//add to string;
      }
      else if(arr[i]==';'){
         section.push_back(small);
         small="";//reset small to continue with the next section of vector;
      }
   }

   if(section.size()<4){
      return;
   }

   if(section[0][0]=='i' && section[1][0]=='u' && section[2][0]=='s' && section[3][0]=='g'){
   }else{
      return;
   }
   nodeType<Type> *newNode = new nodeType<Type>();
   newNode->id=section[0];
   newNode->user=section[1];
   newNode->score=section[2];
   newNode->grade=section[3];
   newNode->link=NULL;

   //to detect same id but different user or same id to update the rest
   int found = 0;

   if(head!=NULL){
      nodeType<Type> *detect;
      detect = head;
      while(detect!=NULL){
         if(detect->id == newNode->id){
            detect->score=newNode->score;
            detect->grade=newNode->grade;
            found = 1;
            return;
         }
         if(detect->id!=newNode->id && detect->user==newNode->user){
            return;
         }
         detect = detect->link;
      }

   }

   if (found==0){

      nodeType<Type> *temp= head;
      nodeType<Type> *prev= NULL;

      if(ind > count){
         return;
      }
      else if( ind==0){
         head=newNode;
         newNode->link=temp;
      }
      else{
         for(int i=0;i<ind;i++){
            prev = temp;
            temp=temp->link;
         }
         prev->link=newNode;
         newNode->link=temp;
      }
      count++;
   }
}

template <class Type>
void linkedList<Type>::removeWithAttribute(string index)
{
   if(index[0]=='u'){//remove user
      nodeType<Type> *temp = new nodeType<Type>();
      temp=head;
      while(temp->link!=NULL){
         if(temp->link->user ==  index){
            nodeType<Type> *dlt = temp->link;
            temp->link=temp->link->link;

            free(dlt);
            count--;
         }
         temp=temp->link;
      }
   }
   if(index[0]=='i'){//remove id
      nodeType<Type> *temp = new nodeType<Type>();
      temp=head;
      while(temp->link!=NULL){
         if(temp->link->id ==  index){
            nodeType<Type> *dlt = temp->link;
            temp->link=temp->link->link;

            free(dlt);
            count--;
         }
         temp=temp->link;
      }
   }
   if(index[0]=='s'){//remove score
      nodeType<Type> *temp = new nodeType<Type>();
      temp=head;
      while(temp->link!=NULL){
         if(temp->link->score ==  index){
            nodeType<Type> *dlt = temp->link;
            temp->link=temp->link->link;

            free(dlt);
            count--;
         }
         temp=temp->link;
      }
   }
   if(index[0]=='g'){//remove grade
      nodeType<Type> *temp = new nodeType<Type>();
      temp=head;
      while(temp->link!=NULL){
         if(temp->link->grade == index && temp->link->link==NULL){
            nodeType<Type> *dlt = temp->link;
            temp->link=temp->link->link;

            free(dlt);
            count--;
            return;
         }
         if(temp->link->grade == index){
            nodeType<Type> *dlt = temp->link;
            temp->link=temp->link->link;

            free(dlt);
            count--;
         }
         temp=temp->link;
      }
   }
}

template <class Type>
void linkedList<Type>::sortWithAttribute(string index)
{
   if(index[0]=='i'){//sort id
      bool isSorted = false;
         nodeType<Type> *cu;
         nodeType<Type> *nxt;
         while(!isSorted){ //while false, list is still unsorted
         isSorted = true;
         cu = head;
         nxt = cu->link;
         while(cu->link != nullptr){
            if(cu->id > cu->link->id){
               string tempData = cu->id;
               cu->id = nxt->id;
               nxt->id = tempData;

               string tempDatachar = cu->grade;
               cu->grade = nxt->grade;
               nxt->grade = tempDatachar;

               string tempDatauser = cu->user;
               cu->user = nxt->user;
               nxt->user = tempDatauser;

               string tempDatascore = cu->score;
               cu->score = nxt->score;
               nxt->score = tempDatascore;

               isSorted = false;
            }
            cu = cu->link;
            nxt = cu->link;
         }
      }
   }
   if(index[0]=='u'){//sort user
      bool isSorted = false;
         nodeType<Type> *cu;
         nodeType<Type> *nxt;
         while(!isSorted){ //while false, list is still unsorted
         isSorted = true;
         cu = head;
         nxt = cu->link;
         while(cu->link != nullptr){
            if(cu->user > cu->link->user){
               string tempData = cu->id;
               cu->id = nxt->id;
               nxt->id = tempData;

               string tempDatachar = cu->grade;
               cu->grade = nxt->grade;
               nxt->grade = tempDatachar;

               string tempDatauser = cu->user;
               cu->user = nxt->user;
               nxt->user = tempDatauser;

               string tempDatascore = cu->score;
               cu->score = nxt->score;
               nxt->score = tempDatascore;

               isSorted = false;
            }
            cu = cu->link;
            nxt = cu->link;
         }
      }
   }
   if(index[0]=='s'){//sort score
      bool isSorted = false;
         nodeType<Type> *cu;
         nodeType<Type> *nxt;
         while(!isSorted){ //while false, list is still unsorted
         isSorted = true;
         cu = head;
         nxt = cu->link;
         while(cu->link != nullptr){
            if(cu->score < cu->link->score){
               string tempData = cu->id;
               cu->id = nxt->id;
               nxt->id = tempData;

               string tempDatachar = cu->grade;
               cu->grade = nxt->grade;
               nxt->grade = tempDatachar;

               string tempDatauser = cu->user;
               cu->user = nxt->user;
               nxt->user = tempDatauser;

               string tempDatascore = cu->score;
               cu->score = nxt->score;
               nxt->score = tempDatascore;

               isSorted = false;
            }
            cu = cu->link;
            nxt = cu->link;
         }
      }
   }
   if(index[0]=='g'){//sort grade
      bool isSorted = false;
         nodeType<Type> *cu;
         nodeType<Type> *nxt;
         while(!isSorted){ //while false, list is still unsorted
         isSorted = true;
         cu = head;
         nxt = cu->link;
         while(cu->link != nullptr){
            if(cu->grade > cu->link->grade){
               string tempData = cu->id;
               cu->id = nxt->id;
               nxt->id = tempData;

               string tempDatachar = cu->grade;
               cu->grade = nxt->grade;
               nxt->grade = tempDatachar;

               string tempDatauser = cu->user;
               cu->user = nxt->user;
               nxt->user = tempDatauser;

               string tempDatascore = cu->score;
               cu->score = nxt->score;
               nxt->score = tempDatascore;

               isSorted = false;
            }
            cu = cu->link;
            nxt = cu->link;
         }
      }
   }
}

template <class Type>
void linkedList<Type>::insertTail(const Type& newItem)
{
	//complete
	nodeType<Type> *newNode = new nodeType<Type>();
	newNode->value = newItem;
	newNode->link = NULL;
	
	if (head == NULL) {
	   head = tail = newNode;
	} else {
	   tail->link = newNode;
	   tail = newNode;
	}
	count++;
}

template <class Type>
void linkedList<Type>::insertHead(const Type& newItem)
{
   //complete
   nodeType<Type> *newNode = new nodeType<Type>();
   newNode->value = newItem;
   newNode->link = NULL;
   
   if(head == NULL){
      head = tail = newNode;
   }
   else {
      newNode->link = head;
      head=newNode;
   }
   count++;
}

template <class Type>
void linkedList<Type>::print(ofstream &out) const
{
   nodeType<Type> *current; //pointer to traverse the list
   current = head; //set current point to the head node
   while (current != NULL ) //while more data to print
   {
      if(current->id!=""){
         out <<"["<< current->id << ";" <<current->user << ";" << current->score << ";" << current->grade <<"]"<< endl;
         current = current->link;
      }
      else{
         current = current->link;
      }
   }
}

template <class Type>
void linkedList<Type>::printInput() const
{
   nodeType<Type> *current; //pointer to traverse the list
   current = head; //set current point to the head node
   while (current != NULL) //while more data to print
   {
      cout << current->id << " " <<current->user << " " << current->score << " " << current->grade << endl;
      current = current->link;
   }
}

template <class Type>
void linkedList<Type>::printCommand() const
{

}

template <class Type>
void linkedList<Type>::destroyList()
{
   nodeType<Type> *temp; //pointer to deallocate the memory occupied by the node
   while (head != NULL) //while there are nodes in the list
   {
      temp = head; //set temp to the current node
      head = head->link; //advance head to the next node
      delete temp; //deallocate the memory occupied by temp
   }
   tail = NULL; //initialize tail to NULL; head has already been set to NULL by the while loop
   count = 0;
}

template <class Type>
linkedList<Type>::~linkedList()
{
    destroyList();
}

template <class Type>
void linkedList<Type>::removeHead() {
    nodeType<Type> *temp;
    temp = head;
    if (head == NULL) {
        head = NULL;
    }
    else if (head != NULL) {
        temp = head->link;
        delete head;
        head = temp;
    }
    count--;

}

template <class Type>
void linkedList<Type>::removeTail() {
    nodeType<Type> *temp;
    nodeType<Type> *temp2;

    temp = head;
    if (temp == NULL) {
        head =  tail = NULL;
    }
    else if(temp->link==NULL) {
        head=tail=NULL;
    }
    else{
        while (temp->link!=NULL) {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        delete temp;
        tail = temp2;
        tail->link = NULL;
    }
    count--;
}