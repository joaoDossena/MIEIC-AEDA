# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
private: 
	stack<T> elemStack;
	stack<T> minStack;
public:
	StackExt() {};
	bool empty() const; 
	T &top();
	void pop();
	void push(const T & val);
	T &findMin();
};

template <class T> 
bool StackExt<T>::empty() const
{
	return elemStack.empty() && minStack.empty();
}

template <class T> 
T& StackExt<T>::top()
{
    T *novo = new T();
    if(this->empty())
    	novo = NULL;
    else
    	novo = &elemStack.top();
    return *novo;
}

template <class T> 
void StackExt<T>::pop()
{
	if(this->empty())
		return;
	else
	{
		minStack.pop();
		elemStack.pop();
	}
}

template <class T> 
void StackExt<T>::push(const T & val)
{
	if(this->empty())
		minStack.push(val);
	else if(val < minStack.top())
		minStack.push(val);
	else
		minStack.push(minStack.top());
	elemStack.push(val);
}

template <class T> 
T& StackExt<T>::findMin()
{
    T *novo = new T();
    if(this->empty())
    	novo = NULL;
    else
    	novo = &minStack.top();
    return *novo;
}

