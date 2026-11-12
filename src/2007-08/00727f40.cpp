// from server: 92% by EspClaude
// roc 2007-08 00727f40 124 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// Shape: VS2005 std::list<T>::_Buynode(_Next, _Prev, const T&) with
// _TRY_BEGIN/_CATCH_ALL; node allocation 0x18 (target push 0x18) => value
// size 0x10 at node+8; value copy through non-inlined _Construct (0x4a5be0).
#include <new>

struct Val10 { int w[4]; };
struct Node { Node* _Next; Node* _Prev; Val10 _Myval; };

void __cdecl Construct_Val10(Val10* p, const Val10& v);

struct ListVal10 {
    Node* _Buynode(Node* _Next, Node* _Prev, const Val10& _Val);
};

Node* ListVal10::_Buynode(Node* _Next, Node* _Prev, const Val10& _Val)
{
    Node* _Pnode = (Node*)::operator new(sizeof(Node));
    try {
        new ((void*)&_Pnode->_Next) Node*(_Next);
        new ((void*)&_Pnode->_Prev) Node*(_Prev);
        Construct_Val10(&_Pnode->_Myval, _Val);
    } catch (...) {
        ::operator delete(_Pnode);
        throw;
    }
    return _Pnode;
}
