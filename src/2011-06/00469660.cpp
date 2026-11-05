// from server: 43% by atomic.potato
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

struct Inner {
    char pad[0x40];
    void ctor(Inner*);
    void dtor();
};

struct Outer {
    int first;
    Inner inner;
};

struct Holder {
    Outer* ptr;
};

struct type_info;

extern "C" bool __stdcall type_info_equal(const type_info*, const type_info*);

struct S {
    void __cdecl func(int, Holder*, Holder*);
};

void S::func(int op, Holder* a, Holder* b) {
    if (op == 0) {
        Outer* src = a->ptr;
        Outer* mem = (Outer*)operator_new(0x44);
        b->ptr = mem;
        if (mem) {
            mem->first = src->first;
            mem->inner.ctor(&src->inner);
        }
    } else if (op == 1) {
        b->ptr = a->ptr;
        a->ptr = 0;
    } else if (op == 2) {
        Outer* p = b->ptr;
        if (p) {
            p->inner.dtor();
            operator_delete(p);
        }
        b->ptr = 0;
    } else if (op == 3) {
        Outer* p = b->ptr;
        if (type_info_equal((const type_info*)0xc14ce0, (const type_info*)0xc14ce0)) {
            b->ptr = a->ptr;
        } else {
            b->ptr = 0;
        }
    } else {
        b->ptr = (Outer*)0xc14ce0;
        ((char*)b)[4] = 0;
        ((char*)b)[5] = 0;
    }
}
