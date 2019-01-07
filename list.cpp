#include "list.h"
#include <assert.h>

List::List(const List& x)
    : _front(0), _back(0), _size(x._size)
{
    if(x._size == 0) return;
    Node* p = x._front;
    Node* q = _front = new Node(p->_data);
    for(int i=1; i<_size; i++){
        p = p->_next;
        q = q->_next = new Node(p->_data);
        assert(q);      //Checks that new operator was successful (fails if run out of memory)
    }
    _back = q;
}

List& List::operator=(const List &x)
{
    clear(); //Clear List at beginning of
    if(x._size == 0) return *this;
    _size = x._size;
    Node* p = x._front;
    Node* q = _front = new Node(p->_data);
    for(int i = 1; i<_size; i++){
        p = p->_next;
        q = q->_next = new Node(p->_data, q);
        assert(q);
    }
    _back = q;
    return *this; //return this after finishing copyiny
}

void List::push_front(const T& t)
{
    if(_size == 0) _front = _back = new Node(t);
    else _front = _front->_prev = new Node(t, 0, _front);
    ++_size;
}

void List::push_back(const T& t)
{
    if(_size == 0) _front = _back = new Node(t);
    else _back = _back->_next = new Node(t, _back);
    ++_size;
}

void List::pop_front()
{
    if(_size == 0) return;
    Node* p = _front;
    if (_size == 1) _front = _back = 0;
    else {
        _front = _front->_next;
        _front->_prev = 0;
    }
    delete p;
    --_size;
}
void List::pop_back()
{
    if(_size == 0) return;
    Node* p = _back;
    if(_size == 1) _front = _back = 0;
    else {
        _back = _back->_prev;
        _back->_next = 0;
    }
    delete p;
    --_size;
}

List::Iterator List::insert(Iterator& pos, const T& t)
{
    if(!pos) {    //null iterator means insert at end of list
        push_back(t);
        pos._p = _back;
    }
    else {
        Node* p = pos._p;
        if (p == _front) _front = p->_prev = new Node(t, p->_prev, p);
        else p->_prev = p->_prev->_next = new Node(t, p->_prev, p);
        ++_size;
        --pos;  //pos should point to newly inserted element
    }
    return pos;
}

void List::erase(Iterator &pos)
{
    if(!pos || _size == 0) return;
    Node* p = pos._p;
    pos._p = p->_next;
    p->_next->_prev = p->_next;
    delete p;
    --_size;
}

void List::remove(const T& t)
{
    if(_front == 0) return;
    Node* p_next = _front->_next;
    for(Node* p=_front; p; p = p_next, p_next = p->_next){
        if(p == _front) _front = p->_next;
        else p->_prev->_next = p->_next;
        if(p == _back) _back = p->_prev;
        else p->_next->_prev = p->_prev;
        delete p;
        --_size;
    }
}

void List::clear()
{
    Node* p=_front;
    while(p)
    {
        _front = p->_next;
        delete p;
        p = _front;
    }
    _back = 0;
    _size = 0;
}
