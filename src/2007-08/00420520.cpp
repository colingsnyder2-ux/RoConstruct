// from server: 57% by colin
extern "C" void __stdcall _invalid_parameter_noinfo();

struct Node {
    Node* left;
    Node* right;
    int key;
};

struct CRobloxTreeCtrl {
    bool func_00420520(Node* first, Node* last, Node* target, Node* end);
};

bool CRobloxTreeCtrl::func_00420520(Node* first, Node* last, Node* target, Node* end)
{
    Node* cur = first;
    while (cur != last) {
        if (cur == 0 || cur == end)
            _invalid_parameter_noinfo();
        if (target == end)
            return true;
        if (cur == 0)
            _invalid_parameter_noinfo();
        if ((int)target < cur->key)
            _invalid_parameter_noinfo();
        Node* n = target->left;
        if (n != 0) {
            if (!((bool (__thiscall*)(Node*, Node*))0x53e2c0)(n, (Node*)this)) {
                if (n->right != (Node*)this) {
                    if (!((bool (__thiscall*)(Node*, Node*))((*(void***)this)[3]))((Node*)this, n)) {
                        if (!((bool (__thiscall*)(Node*, Node*))((*(void***)n)[4]))(n, (Node*)this))
                            return false;
                    }
                }
            }
        }
        if ((int)target < cur->key)
            _invalid_parameter_noinfo();
        target = (Node*)((char*)target + 8);
    }
    return true;
}
