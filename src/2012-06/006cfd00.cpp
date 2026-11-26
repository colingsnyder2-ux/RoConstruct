// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Node { Node* _Left; Node* _Parent; Node* _Right; char pad[0x15-12]; char _Isnil; };
static Node* Min(Node* p) { while (!p->_Left->_Isnil) p = p->_Left; return p; }
struct It { Node* _Ptr;
  void _Inc() {
    if (_Ptr->_Isnil) ;
    else if (!_Ptr->_Right->_Isnil) _Ptr = Min(_Ptr->_Right);
    else { Node* p; while (!(p = _Ptr->_Parent)->_Isnil && _Ptr == p->_Right) _Ptr = p; _Ptr = p; }
  } };
void g(It* i) { i->_Inc(); }
