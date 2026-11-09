// from server: 19% by atomic.potato
struct Node {
    Node* m_left;
    Node* m_right;
    Node* m_parent;
    int m_key;
    int m_val;
    char m_color;
    char pad[3];
};

struct Map {
    Node* m_head;
    int m_size;
};

struct List {
    Node* m_head;
    int m_size;
};

struct S {
    char pad0[0x138];
    List m_list1;
    char pad1[4];
    Map m_map1;
    char pad2[4];
    Map m_map2;
    void f(int a, int b);
};

extern "C" int __stdcall sub_4c6ba0(void*, void*);
extern "C" void __stdcall sub_5bf670(void*);
extern "C" void __stdcall sub_401740(void*, void*);
extern "C" void __stdcall sub_5aa3c0(void*, void*);
extern "C" void __stdcall sub_64bf00(void*, void*, void*);
extern "C" void __stdcall sub_5a86c0(void*, void*);

void S::f(int a, int b)
{
    if (!sub_4c6ba0(this, 0))
        return;

    Node* end1 = m_map1.m_head;
    Node* n = end1->m_left;
    while (n != end1) {
        if (n->m_key != a && n->m_val != a) {
            sub_5bf670(&n);
            continue;
        }
        Node* next;
        if (n->m_color == 0) {
            Node* r = n->m_right;
            if (r->m_color == 0) {
                n = r;
                while (n->m_left->m_color == 0)
                    n = n->m_left;
            } else {
                Node* p = n->m_parent;
                while (p->m_color == 0 && n == p->m_right) {
                    n = p;
                    p = p->m_parent;
                }
                n = p;
            }
        } else {
            next = n;
        }
        sub_401740(&m_map1, &next);
        n = next;
    }

    Node* end2 = m_list1.m_head;
    n = end2->m_left;
    while (n != end2) {
        if (n->m_key == a) {
            Node* next;
            if (n->m_color == 0) {
                Node* r = n->m_right;
                if (r->m_color == 0) {
                    n = r;
                    while (n->m_left->m_color == 0)
                        n = n->m_left;
                } else {
                    Node* p = n->m_parent;
                    while (p->m_color == 0 && n == p->m_right) {
                        n = p;
                        p = p->m_parent;
                    }
                    n = p;
                }
            } else {
                next = n;
            }
            sub_5aa3c0(&m_list1, &next);
            n = next;
        } else if (n->m_key < a) {
            Node* tmp;
            sub_64bf00(&n->m_val, &tmp, &a);
            if (tmp != n->m_parent)
                sub_401740(&n->m_val, &tmp);
            if (n->m_color == 0) {
                Node* r = n->m_right;
                if (r->m_color == 0) {
                    n = r;
                    while (n->m_left->m_color == 0)
                        n = n->m_left;
                } else {
                    Node* p = n->m_parent;
                    while (p->m_color == 0 && n == p->m_right) {
                        n = p;
                        p = p->m_parent;
                    }
                    n = p;
                }
            }
        } else {
            if (n->m_color == 0) {
                Node* r = n->m_right;
                if (r->m_color == 0) {
                    n = r;
                    while (n->m_left->m_color == 0)
                        n = n->m_left;
                } else {
                    Node* p = n->m_parent;
                    while (p->m_color == 0 && n == p->m_right) {
                        n = p;
                        p = p->m_parent;
                    }
                    n = p;
                }
            }
        }
    }

    sub_5a86c0(&m_map2, &a);
}
