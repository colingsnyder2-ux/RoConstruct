// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is std::_Tree::_Rrotate (MSVC 2008 std::map/set red-black tree).
// The node layout and the tree object layout below are local stand-ins, not taken from a header.
struct RbNode {
    RbNode* _Left;     // +0
    RbNode* _Parent;   // +4
    RbNode* _Right;    // +8
    char    _pad[0x2C];
    char    _Color;    // +0x38
    char    _Isnil;    // +0x39
};

struct RbTree {
    char    _pad[0x18];
    RbNode* _Myhead;   // +0x18
};

extern "C" void __fastcall fn_0068d140(RbTree* self, int unusedEdx, RbNode* _Wherenode)
{
    RbNode* _Pnode = _Wherenode->_Left;
    _Wherenode->_Left = _Pnode->_Right;
    if (!_Pnode->_Right->_Isnil)
        _Pnode->_Right->_Parent = _Wherenode;
    _Pnode->_Parent = _Wherenode->_Parent;

    RbNode* head = self->_Myhead;
    if (_Wherenode == head->_Parent)
        head->_Parent = _Pnode;
    else if (_Wherenode == _Wherenode->_Parent->_Right)
        _Wherenode->_Parent->_Right = _Pnode;
    else
        _Wherenode->_Parent->_Left = _Pnode;

    _Pnode->_Right = _Wherenode;
    _Wherenode->_Parent = _Pnode;
}
