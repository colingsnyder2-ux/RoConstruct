// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
union any_pointer { void* obj_ptr; const void* const_obj_ptr; void (*func_ptr)(); char data[1]; };
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };
struct vtable_base {
    void (*manager)(const any_pointer& in, any_pointer& out, functor_manager_operation_type op);
    void clear(any_pointer& functor) {
        if (manager) manager(functor, functor, destroy_functor_tag);
    }
};
class function0 {
public:
    vtable_base* vtable;
    int pad;
    any_pointer functor;
    ~function0() { clear(); }
    void clear() {
        if (vtable) {
            vtable->clear(functor);
            vtable = 0;
        }
    }
};
struct Item {
    int a, b;
    function0 f;
};
struct Node {
    Node* _Next;
    Node* _Prev;
    Item _Myval;
};
class List {
public:
    char pad[0x14];
    Node* _Myhead;
    unsigned _Mysize;
    void clear();
};
void List::clear()
{
    Node* _Pnode = _Myhead->_Next;
    _Myhead->_Next = _Myhead;
    _Myhead->_Prev = _Myhead;
    _Mysize = 0;
    for (Node* _Pnext; _Pnode != _Myhead; _Pnode = _Pnext) {
        _Pnext = _Pnode->_Next;
        _Pnode->_Myval.~Item();
        operator delete(_Pnode);
    }
}
