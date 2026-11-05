// from server: 61% by atomic.potato
struct Inner {
    char pad0[4];
    void* field4;
    void* field8;
    char padC[9];
    char field15;
};

struct List {
    void* head;
    void* field4;
    void* field8;
};

struct S {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    List list10;
    void* field1C;
    List list20;
    S(void* a, void* b);
};

extern "C" void* __cdecl func_80a05e(unsigned int size);
extern "C" void* __cdecl func_74bcf0(void* self, void* arg);
extern "C" void* __cdecl func_62d880(void* self);

S::S(void* a, void* b)
{
    Inner* p = (Inner*)func_80a05e(0x30);
    if (p != 0)
        p = (Inner*)func_74bcf0(p, this);
    else
        p = 0;
    field4 = a;
    field8 = p;
    fieldC = b;
    field0 = (void*)0xabf080;
    List* lst = &list10;
    void* n = func_62d880(lst);
    lst->field4 = n;
    ((char*)n)[0x15] = 1;
    void* x = lst->field4;
    *(void**)((char*)x + 4) = x;
    x = lst->field4;
    *(void**)x = x;
    x = lst->field4;
    *(void**)((char*)x + 8) = x;
    lst->field8 = 0;
    field1C = 0;
    List* l2 = &list20;
    l2->head = l2;
    l2->field4 = l2;
}
