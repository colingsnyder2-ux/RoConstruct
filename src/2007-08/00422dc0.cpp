// from server: 13% by colin
extern "C" {
    __declspec(dllimport) void __stdcall SendMessageA(void*, unsigned int, unsigned int, long);
    void __cdecl _invalid_parameter_noinfo(void);
}

struct Node {
    Node* next;
    Node* prev;
};

struct List {
    Node* head;
    unsigned int size;
};

struct Inner {
    char pad[0x20];
    void* hwnd;
};

struct Outer {
    char pad[0x20];
    List list;
    char pad2[0x0c];
    Inner* inner;
};

struct CRobloxTreeCtrlNode {
    void func();
};

void CRobloxTreeCtrlNode::func()
{
    Outer* self = (Outer*)this;
    Inner* inner = self->inner;
    void* hwnd = inner->hwnd;

    List* lst = &self->list;
    Node* sentinel = lst->head;

    Node* cur = sentinel->next;
    while (cur != sentinel) {
        SendMessageA(hwnd, 0x1101, 0, *(long*)((char*)cur + 0x44));
        cur = cur->next;
    }

    lst->head->next = lst->head;
    lst->head->prev = lst->head;
    lst->size = 0;
}
