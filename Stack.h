#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template<typename T>	//탬플릿 클래스로 확장
class Stack : public LinkedList<T>{	//LinkedList는 T type template class
	public:
		virtual bool Delete (T &element){	//virtual. type은 T
			//first가 0이면 false반환
			if(this->first == 0)	//first는 class의 멤버 변수이므로 this 포인터 사용
				return false;

			Node<T> *current = this->first;	//제거할 current Node 생성
			this->first = this->first->link;	// 제거 이후의 first지정
			element = current->data;	//element는 data를 가리킴
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			delete current;	//current 삭제
			this->current_size--;	//size 줄이기

			return true;
			}
};
