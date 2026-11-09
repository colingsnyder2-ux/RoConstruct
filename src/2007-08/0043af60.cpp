// from server: 39% by colin
struct CSelectionPropGrid;

struct Inner {
    char pad[0x28];
    int count;
};

struct Holder {
    char pad[0xb8];
    Inner* inner;
};

struct Other {
    char pad[0x120];
    void* ptr;
};

struct CSelectionPropGrid {
    char pad[0x18c];
    char field18c[0x10];
    char field19c[0x10];
    void func(void*);
};

extern "C" void* __stdcall sub_699000(int);
extern "C" void __stdcall sub_699320(void*, int, void*);
extern "C" void __stdcall sub_4339d0(void*, void*);
extern "C" void __stdcall sub_464ec0(void*, void*);
extern "C" void* __stdcall sub_4397d0(void*, int);
extern "C" void* __stdcall sub_438e10(void*, void*);

extern "C" {
    typedef int (__stdcall *Fn1)();
    typedef int (__stdcall *Fn2)(void*, void*);
    typedef void (__stdcall *Fn3)(void*);
    extern Fn1 imp_77dd98;
    extern Fn2 imp_77dcb8;
    extern Fn3 imp_77ddbc;
}

void CSelectionPropGrid::func(void* arg)
{
    Other* other = (Other*)arg;
    Holder* h = (Holder*)sub_4397d0(this, *(int*)((char*)other->ptr + 8));
    int i = 0;
    if (h->inner->count > 0) {
        do {
            void* a = sub_699000(i);
            void* b = sub_438e10(a, (char*)this + 0x18c);
            void* c = sub_438e10(other, (char*)this + 0x18c);
            int r = imp_77dcb8(c, (void*)imp_77dd98());
            bool less = r < 0;
            imp_77ddbc((char*)this + 0x18c);
            imp_77ddbc((char*)this + 0x19c);
            if (less)
                break;
            i++;
        } while (i < h->inner->count);
    }
    sub_699320(h, i, other);
    void* p = other->ptr;
    sub_4339d0((char*)this + 0x19c, &p);
    *(void**)((char*)this + 0x19c) = (char*)other + 0x108;
    sub_464ec0((char*)this + 0x18c, &p);
}
