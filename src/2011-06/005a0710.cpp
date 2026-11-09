// from server: 37% by atomic.potato
struct Node {
    Node* m_left;
    Node* m_parent;
    Node* m_right;
    char pad0[4];
    int m_key;
    char pad1[5];
    char m_isnil;
};

struct Tree {
    char pad0[4];
    Node* m_head;
};

struct Result {
    Node* m_node;
    char m_inserted;
};

struct S {
    Tree* m_tree;
    Result* f(Node* key, Result* out);
};

extern "C" void __cdecl func_0060db00();

Result* S::f(Node* key, Result* out)
{
    Node* header = m_tree->m_head;
    Node* cur = header->m_parent;
    char less = 1;
    while (cur->m_isnil == 0) {
        less = key->m_key < cur->m_key;
        header = cur;
        if (less)
            cur = cur->m_left;
        else
            cur = cur->m_right;
    }
    Node* pos = header;
    if (less) {
        if (header == m_tree->m_head->m_left) {
            Result* r = (Result*)0;
            r = (Result*)0;
            func_0060db00();
            out->m_inserted = 1;
            out->m_node = pos;
            return out;
        }
        func_0060db00();
    }
    if (pos->m_key < key->m_key) {
        out->m_node = pos;
        out->m_inserted = 1;
        return out;
    }
    out->m_node = pos;
    out->m_inserted = 0;
    return out;
}
