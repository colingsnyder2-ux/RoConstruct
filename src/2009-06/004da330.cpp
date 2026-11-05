// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Node {
    Node* _Left;
    Node* _Parent;
    Node* _Right;
    char _Myval[0x154];
    char _Color;
    char _Isnil;
};
class Tree {
public:
    char pad[0x18];
    Node* _Myhead;
    static Node*& _Left(Node* p) { return p->_Left; }
    static Node*& _Right(Node* p) { return p->_Right; }
    static Node*& _Parent(Node* p) { return p->_Parent; }
    static char& _Isnil(Node* p) { return p->_Isnil; }
    Node*& _Root() { return _Parent(_Myhead); }
    void _Rrotate(Node* _Wherenode);
};
void Tree::_Rrotate(Node* _Wherenode)
{
    Node* _Pnode = _Left(_Wherenode);
    _Left(_Wherenode) = _Right(_Pnode);

    if (!_Isnil(_Right(_Pnode)))
        _Parent(_Right(_Pnode)) = _Wherenode;
    _Parent(_Pnode) = _Parent(_Wherenode);

    if (_Wherenode == _Root())
        _Root() = _Pnode;
    else if (_Wherenode == _Right(_Parent(_Wherenode)))
        _Right(_Parent(_Wherenode)) = _Pnode;
    else
        _Left(_Parent(_Wherenode)) = _Pnode;

    _Right(_Pnode) = _Wherenode;
    _Parent(_Wherenode) = _Pnode;
}
