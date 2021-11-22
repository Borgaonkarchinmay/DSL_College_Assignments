#include<iostream>
using namespace std;

// Node structure
struct Node{
	int data;
	Node *next;
};

// class declaration
class linkedList{
	private:
		Node *first;
	
	public:
		// Linked-list operations
		linkedList();
		~linkedList();
		void addNode(const int);
		bool checkElement(const int);
		void displinkedList();
		linkedList* operator =(const linkedList &list);
		
		// Set operations
		linkedList Intersection(const linkedList &list);
		linkedList Union(const linkedList &list);
		
			
};

// Implementation details
linkedList :: linkedList(){
	first = NULL;
}

linkedList* linkedList :: operator =(const linkedList &list){

	for(Node *ptr = list.first; ptr!=NULL; ptr = ptr ->next){
		addNode(ptr ->data);
	}	
	return this;
}

void linkedList :: addNode(const int m){
	// Create a temp pointer to point the new node
	// Allocate the node type memory to the pointer
	
	Node *temp = new Node;
	
	if(!checkElement(m)){
		temp-> data = m;
		temp-> next = first;
		first = temp;
	}
	else{
		int roll_no;
		cout<<"Student Roll no already stored!"<<endl;
		cout<<"Enter new Roll no: ";
		cin>>roll_no;
		cout<<endl;
		addNode(roll_no);
	}
	
}

void linkedList :: displinkedList(){
	cout<<"\nBelow is 'Roll-No' , 'address' of current node and address of next node"<<endl<<endl;
	
	int eleNo = 0;
	Node *ptr = first;
	while(ptr != NULL){
		eleNo++;
		cout<<"Node "<<eleNo<<"\tRoll-No -> "<<ptr ->data<<"\t,address -> "<<ptr<<"\t next pointer -> "<<ptr ->next<<endl;
		ptr = ptr ->next;
		
	}
}

bool linkedList :: checkElement(const int m){

	for(Node *ptr = first; ptr != NULL; ptr = ptr ->next){
		if(ptr ->data == m){
			return true;
		}
	}
	
	return false;
}

linkedList linkedList :: Intersection(const linkedList &list){
	linkedList result;
	for(Node *ptr1 = first; ptr1!=NULL; ptr1 = ptr1 ->next){
		for(Node *ptr2 = list.first; ptr2!=NULL; ptr2 = ptr2 ->next){
			if(ptr1 ->data == ptr2 ->data){
				result.addNode(ptr1 ->data);
			}
		}
	}
	return result;
}

linkedList linkedList :: Union(const linkedList &list){
	linkedList result;
	result = list;
	for(Node *ptr = first; ptr!=NULL; ptr = ptr ->next){
		if(!result.checkElement(ptr ->data))
		result.addNode(ptr ->data);			
	}
	
	return result;
}



linkedList :: ~linkedList(){
	
	// Create pointer ptr to traverse through linked list
	Node *ptr = first;
	
	// Create a temp pointer to release the memory of current node
	Node *temp = new Node;
	
	while(ptr != NULL){
		temp = ptr-> next;
		delete ptr;
		ptr = temp;
	}
	
	delete ptr;
	delete temp;
}


int main(){

	int stu_count,  opt;
	char choice = 'y';	
	cout<<"Enter number of students in class: ";
	cin>>stu_count;
	cout<<endl;
	
	linkedList Vanilla, Butterscotch;
	
	int vanCount, butCount;
	
	cout<<"Enter number of student's having Vanilla ice-cream: ";
	cin>>vanCount;
	cout<<endl;
	
	// Generate linked list to store these students
	for(int i =0; i<vanCount; i++){
		int rollNo;
		cout<<"Enter Roll No of "<<" student "<<i+1<<" : ";
		cin>>rollNo;
		Vanilla.addNode(rollNo);
	}

	cout<<"\nEnter number of student's having Butterscotch ice-cream: ";
	cin>>butCount;
	cout<<endl;
	
	// Generate linked list to store these students
	for(int i =0; i<butCount; i++){
		int rollNo;
		cout<<"Enter Roll No of "<<" student "<<i+1<<" : ";
		cin>>rollNo;
		Butterscotch.addNode(rollNo);
	}
	
	
	// Dispplay students eating Vanilla
	cout<<"\nStudents having Vanilla ice-cream"<<endl;
	Vanilla.displinkedList();
	
	// Dispplay students eating Butterscotch
	cout<<"\nStudents having Butterscotch ice-cream"<<endl;
	Butterscotch.displinkedList();
	
	cout<<endl<<endl;
	cout<<"****Menu*****\na) Press 1 -> Students who like both Vanilla and Butterscotch \nb) Press 2 -> Students who like either Vanilla or Butterscotch or not both\na) Press 3 -> Students who like neither Vanilla nor Butterscotch\n"<<endl;
	cout<<"-----------------------------------------------------------------------";
	
	while(choice == 'y'){
		
		cout<<endl;
		cout<<"\nEnter menu number: ";
		cin>>opt;
		
		if(opt == 1){
			linkedList result;
			result = Vanilla.Intersection(Butterscotch);
			cout<<endl;
			cout<<"Students who like both Vanilla and Butterscotch- "<<endl;
			result.displinkedList();
		}
		
		else if(opt == 2){
			linkedList inter, result;
			inter = Vanilla.Intersection(Butterscotch);
			
			for(int i =1; i <= stu_count; i++){
				if(!inter.checkElement(i)){
					result.addNode(i);
				}
			}
			
			cout<<endl;
			cout<<"Students who like either Vanilla or Butterscotch or nor both- "<<endl;
			result.displinkedList();
		}
		
		else if(opt == 3){
			linkedList Union, result;
			Union = Vanilla.Union(Butterscotch);
			int count = 0;
			
			for(int i =1; i <= stu_count; i++){
				if(!Union.checkElement(i)){
					count++;
				}
			}
			
			cout<<endl;
			cout<<"Number of students who neither like Vanilla not Butterscotch: "<<count<<endl;
		}
		
		else{
			cout<<"OOPs!, Invalid option, TRY Again"<<endl;
		}
		
		cout<<endl<<endl;
		cout<<"Enter choice-> Press 'y' to continue and 'n' to exit: ";
		cin>>choice;
		cout<<"................................................................."<<endl;	
	}
	

	return 0;
}

/*
....................................
OUTPUT: 

Enter number of students in class: 12

Enter number of student's having Vanilla ice-cream: 5

Enter Roll No of  student 1 : 1
Enter Roll No of  student 2 : 6
Enter Roll No of  student 3 : 7
Enter Roll No of  student 4 : 9
Enter Roll No of  student 5 : 11

Enter number of student's having Butterscotch ice-cream: 6

Enter Roll No of  student 1 : 1
Enter Roll No of  student 2 : 7
Enter Roll No of  student 3 : 8
Enter Roll No of  student 4 : 9
Enter Roll No of  student 5 : 11
Enter Roll No of  student 6 : 12

Students having Vanilla ice-cream

Below is 'Roll-No' , 'address' of current node and address of next node

Node 1  Roll-No -> 11   ,address -> 0xc95a70     next pointer -> 0xc95a50
Node 2  Roll-No -> 9    ,address -> 0xc95a50     next pointer -> 0xc91570
Node 3  Roll-No -> 7    ,address -> 0xc91570     next pointer -> 0xc91550
Node 4  Roll-No -> 6    ,address -> 0xc91550     next pointer -> 0xc91530
Node 5  Roll-No -> 1    ,address -> 0xc91530     next pointer -> 0

Students having Butterscotch ice-cream

Below is 'Roll-No' , 'address' of current node and address of next node

Node 1  Roll-No -> 12   ,address -> 0xc95b30     next pointer -> 0xc95b10
Node 2  Roll-No -> 11   ,address -> 0xc95b10     next pointer -> 0xc95af0
Node 3  Roll-No -> 9    ,address -> 0xc95af0     next pointer -> 0xc95ad0
Node 4  Roll-No -> 8    ,address -> 0xc95ad0     next pointer -> 0xc95ab0
Node 5  Roll-No -> 7    ,address -> 0xc95ab0     next pointer -> 0xc95a90
Node 6  Roll-No -> 1    ,address -> 0xc95a90     next pointer -> 0


****Menu*****
a) Press 1 -> Students who like both Vanilla and Butterscotch
b) Press 2 -> Students who like either Vanilla or Butterscotch or not both
a) Press 3 -> Students who like neither Vanilla nor Butterscotch

-----------------------------------------------------------------------

Enter menu number: 1

Students who like both Vanilla and Butterscotch-

Below is 'Roll-No' , 'address' of current node and address of next node

Node 1  Roll-No -> 11   ,address -> 0xc95ee0     next pointer -> 0xc95d80
Node 2  Roll-No -> 9    ,address -> 0xc95d80     next pointer -> 0xc95e80
Node 3  Roll-No -> 7    ,address -> 0xc95e80     next pointer -> 0xc95dc0
Node 4  Roll-No -> 1    ,address -> 0xc95dc0     next pointer -> 0


Enter choice-> Press 'y' to continue and 'n' to exit: y
.................................................................


Enter menu number: 2

Students who like either Vanilla or Butterscotch or nor both-

Below is 'Roll-No' , 'address' of current node and address of next node

Node 1  Roll-No -> 12   ,address -> 0xc95c80     next pointer -> 0xc95c60
Node 2  Roll-No -> 10   ,address -> 0xc95c60     next pointer -> 0xc95de0
Node 3  Roll-No -> 8    ,address -> 0xc95de0     next pointer -> 0xc95f40
Node 4  Roll-No -> 6    ,address -> 0xc95f40     next pointer -> 0xc95f60
Node 5  Roll-No -> 5    ,address -> 0xc95f60     next pointer -> 0xc95c40
Node 6  Roll-No -> 4    ,address -> 0xc95c40     next pointer -> 0xc95c20
Node 7  Roll-No -> 3    ,address -> 0xc95c20     next pointer -> 0xc95e60
Node 8  Roll-No -> 2    ,address -> 0xc95e60     next pointer -> 0


Enter choice-> Press 'y' to continue and 'n' to exit: y
.................................................................


Enter menu number: 3

Number of students who neither like Vanilla not Butterscotch: 5


Enter choice-> Press 'y' to continue and 'n' to exit: n
.................................................................

--------------------------------
Process exited after 37.6 seconds with return value 0
Press any key to continue . . .

*/


