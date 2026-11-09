// from server: 43% by colin
struct Node {
    Node* next;
    Node* prev;
    int value;
};

struct List {
    Node* head;
};

struct Container {
    char pad[0x10];
    List list;
    int count;
};

struct Other {
    char pad[0x18];
    int count;
};

extern "C" void __stdcall _invalid_parameter_noinfo();

struct S {
    char pad[0x18];
    int count;
    int method(int a, int b, int c);
};

int S::method(int a, int b, int c)
{
    if (this->count == 0)
        return 0;

    Container* cont = (Container*)this;
    Other* other = (Other*)a;

    if (!((bool (__thiscall*)(void*))0x5ac5d0)((void*)b)) {
        Node* n = cont->list.head;
        if (n == (Node*)&cont->list) {
            _invalid_parameter_noinfo();
        }
        ((void (__thiscall*)(void*, int))0x5ac8f0)((void*)b, n->value);
    }

    ((void (__thiscall*)(void*, int))0x5ac8f0)((void*)b, 0);

    int idx = ((int (__thiscall*)(void*))0x4605a0)((void*)b);

    if (this->count > 0) {
        int i = 0;
        while (i < this->count) {
            Node* cur = *(Node**)(idx + 0x1c);
            Node* nxt = *(Node**)(idx + 0x20);
            i++;
            if (cur == 0) {
                _invalid_parameter_noinfo();
            }
            if (nxt == cur->next) {
                _invalid_parameter_noinfo();
            }
            if (cur != (Node*)&cont->list) {
                _invalid_parameter_noinfo();
            }
            nxt = nxt->next;
            Node* h = cont->list.head;
            if (nxt == h) {
                nxt = h->next;
            } else {
                if (nxt == cur->next) {
                    _invalid_parameter_noinfo();
                }
            }
            int val = nxt->value;
            if (idx != c) {
                if (!((bool (__thiscall*)(void*, int))0x4a9540)((void*)b, idx)) {
                    break;
                }
            }
            if (i >= other->count) {
                break;
            }
        }
    }

    ((void (__thiscall*)(void*, int))0x5ac8f0)((void*)b, idx);
    return 0;
}
