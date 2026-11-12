// from server: 92% by EspClaude
// roc 2007-08 00728f90 124 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// Shape: VS2005 std::list<T>::_Buynode(_Next, _Prev, const T&) with
// _TRY_BEGIN/_CATCH_ALL; node allocation 0x1c (target push 0x1c) => value
// size 0x14 at node+8; value copy through non-inlined _Construct (0x728bb0).
#include <new>

struct Val14 { int w[5]; };
struct Node { Node* _Next; Node* _Prev; Val14 _Myval; };

void __cdecl Construct_Val14(Val14* p, const Val14& v);

struct ListVal14 {
    Node* _Buynode(Node* _Next, Node* _Prev, const Val14& _Val);
};

Node* ListVal14::_Buynode(Node* _Next, Node* _Prev, const Val14& _Val)
{
    Node* _Pnode = (Node*)::operator new(sizeof(Node));
    try {
        new ((void*)&_Pnode->_Next) Node*(_Next);
        new ((void*)&_Pnode->_Prev) Node*(_Prev);
        Construct_Val14(&_Pnode->_Myval, _Val);
    } catch (...) {
        ::operator delete(_Pnode);
        throw;
    }
    return _Pnode;
}
