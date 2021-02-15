/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	/** TODO 
		Fix this method
	*/
	return m_size;
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	/** TODO
		Fix this method
	*/
	if( temp == nullptr)
    {
        return false;
    }
    if (m_front->getValue() == value)
    {
        isFound =true;
    }


	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	/** TODO
		Fix this method
	*/
	Node<T>* m_ptrNext = m_front;
	if(m_front == nullptr)
    {
        return false;
    }
    else if(m_size == 1)
    {
        delete m_front;
        m_front = nullptr;
        //shouldn't we have a m_back to set to nullprt?
        isRemoved = true;
    }
    else if( m_size == 2)
    {
        lastNode = m_front->getNext();
        delete lastNode;
		lastNode = nullptr;
		m_front->setNext(lastNode);
		isRemoved = true;
    }
    else
    {
        //m_ptrLast = m_ptrLast->m_ptrPrev;
        //delete m_ptrLast->m_ptrNext;
        //m_ptrLast->m_ptrNext = nullptr; This is how i would do it, trying to figure out this syntax
        for( int i = 0; i < (m_size - 2);i++)
        {
            m_ptrNext = m_ptrNext->getNext();
        }
        secondintoLast = m_ptrNext;
        delete lastNode;
        lastNode = nullptr;
        secondintoLast ->setNext(lastNode);
        isRemoved = true;
    }

    m_size--;
	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
