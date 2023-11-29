#pragma once

#include <cassert>
#include <stdint.h>

template<typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node* next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList& list)
	{
		Node* current = list.first_;
		while (current)
		{
			PushBack(current->item);
			current = current->next;
		}
	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		while (first_)
			PopFront();
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;

		Node* current = first_;
		while (current)
		{
			current = current->next;
			size++;
		}

		return size;
	}

	T Front()
	{
		assert(first_);
		return first_->item; // TODO: 수정
	}

	T Back()
	{
		assert(first_);
		Node* current = first_;
		while (current->next)
		{
			current = current->next;
		}


		return current->item; // TODO: 수정
	}

	Node* Find(T item)
	{
		// TODO: item이 동일한 노드 포인터 반환
		Node* current = first_;
		while (current)
		{
			if (current->item == item)
			{
				return current;
			}
			current = current->next;
		}

		return nullptr;
	}

	void InsertBack(Node* node, T item)
	{
		Node* temp = new Node;
		temp->item = item;
		temp->next = node->next;
		node->next = temp;
	}

	void Remove(Node* n)
	{
		assert(first_);

		Node* prev = first_;
		while (prev->next)
		{
			if (prev->next == n)
			{
				break;
			}
			prev = prev->next;
		}
		prev->next = n->next;
		delete n;
		
		if(first_ == n)
		{
			first_ = first_->next;
			delete n;
			return;
		}
		
	
	}

	void PushFront(T item)
	{
		// first_가 nullptr인 경우와 아닌 경우 나눠서 생각해보기 (결국은 두 경우를 하나로 합칠 수 있음)

		// 새로운 노드 만들기
		Node* temp = new Node;

		temp->item = item;
		
		temp->next = first_;
		first_ = temp;
		
	}

	void PushBack(T item)
	{
		
		
		if (first_)
		{
			Node* current = first_;
			
			while (current->next)
			{
				current = current->next;
			}
			Node* temp = new Node;
			temp->item = item;
			temp->next = nullptr;

			current->next = temp;
		}
		else
		{
			PushFront(item);
		}
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);
		Node* temp = first_;
		first_ = first_->next;
		delete temp;

	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}
		
		if (first_->next == nullptr)
		{
			delete first_;
			first_ = nullptr;
			return;
		}
		assert(first_);

		Node* current = first_;
		if (current->next)
		{
			while (current->next->next)
			{
				current = current->next;
			}
			Node* temp = current->next; // 지울거
			current->next = current->next->next;
			delete temp;
		}
		

		else 
		{
			delete first_;
			first_ = nullptr;
		}
	}

	void Reverse()
	{
		Node* current = first_;
		Node* prev = nullptr;
		
		while (current)
		{
			Node* temp = prev;
			prev = current;
			current = current->next;
			prev->next = temp;
		}
		first_ = prev;
	}

	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					//cout << "[" << current << ", " << current->item << ", " << current->next << "]";

					// 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						<< current->item << ", "
						<< reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}

				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

protected:
	Node* first_ = nullptr;

	bool print_debug_ = false;
};