#ifndef LIST_H
#define LIST_H
typedef int T;      //Typedef allows us to easy change the data type of the list

class List
{
private:
    struct Node
    {
        /*Node Structure to hold data of each node n double linked list*/
        friend class Iterator;
        Node(T data, Node* prev=0, Node* next = 0) : _data(data), _prev(prev), _next(next) {}
        T _data;            //Holds data element of Node
        Node* _prev;        //Points to memory location of previous Node
        Node* _next;        //points to memory location of next Node
    };
public:
    class Iterator
    {
        friend class List;
    public:
        Iterator(Node* p) : _p(p) { }
        bool operator!() const { return ( _p ? false : true ); }
        T& operator*() const { return _p->_data; }
        Iterator& operator++() { _p = _p->_next; return *this; }
        Iterator& operator--() { _p = _p->_prev; return *this; }
        Iterator& operator=(const Iterator& it)
            { _p = it._p; return *this; }
        friend bool operator==(const Iterator it, const Iterator jt)
            { return bool(it._p == jt._p); }
        friend bool operator!=(const Iterator it, const Iterator jt)
            { return bool(it._p != jt._p); }
    private:
        Node* _p;   //points to list Node
    };
public:
    List() : _front(0), _back(0), _size(0) { }
    List(const List&);
    ~List() { clear(); }
    List& operator=(const List&);
    int size() { return _size; }
    bool empty() const { return bool(_size == 0); }
    T& front() const { return _front->_data; }
    T& back() const { return _back->_data; }
    void push_front(const T&);        //Inserts the element t to the front of the list
    void push_back(const T&);
    void pop_front();
    void pop_back();
    Iterator begin() { return Iterator(_front); }
    Iterator end() { return Iterator(0); }
    Iterator insert(Iterator&, const T&);
    void erase(Iterator&);
    void remove(const T&);
    void clear();
private:
    Node* _front;
    Node* _back;
    int _size;
};



#endif // LIST_H
