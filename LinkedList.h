#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template<typename T>
class Node{
	public:
		//데이터를 저장할 변수
		T data;	//type은 T
		//노드구조체 이용; 다음노드의 주소를 저장할 포인터
		Node *link;

		Node(T element){	//type은 T
		  data = element;
		  link = 0;
		}
	};

//LinkedList Class
template<typename T>
class LinkedList{
	protected:
		//첫번째 노드의 주소를 저장할 포인터
		Node<T> *first;	//type은 T
		int current_size;	//크기는 그대로 int
	public:
		//생성자, 초기화 
		LinkedList(){
			first = 0;
			current_size = 0;
		};

		//노드 개수를 리턴
		int GetSize(){
			return current_size;
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(T element);	//type에 무관하게 받음(T)
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(T &element);	//type에 무관하게 받음(T). element의 주소를 받아 함수 내에서 제거할 값을 해당 주소에 저장한다.

		//리스트 출력
		void Print();
};


//새 노드를 맨 앞에 붙이고 값을 넣음
template<typename T>
void LinkedList<T>::Insert(T element){	//type과 무관하게 T로
	//노드 생성
	Node<T> *newnode = new Node<T>(element);	//type은 T

	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first;
	first = newnode;
	current_size++;
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
template<typename T>
bool LinkedList<T>::Delete(T &element){	//type은 T

	if (first == 0)
		return false;
	
	Node<T> *current = first;	//Node type은 T
	Node<T> *previous = 0;		//Node type은 T
	
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == 0){  //마지막 노드를 찾는것
			if (previous)
				previous -> link = current -> link;
			else
				first = first -> link;
			break;
		}
		previous = current;
		current = current -> link;
	}
	element = current -> data;
	delete current;
	current_size--;

	return true;
}

//리스트를 출력하는 Print 함수
template<typename T>
void LinkedList<T>::Print(){	//type은 T
	Node<T> *i;	//Node type은 T
	int index = 1;

	if (current_size != 0){
		for( i = first; i != NULL; i=i->link){
			if (index == current_size){
				cout << "[" << index << "|";
				cout << i -> data <<"]";	//마지막일 때는 화살표 없이
			}
			
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}


#endif
