// from server: 34% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _invalid_parameter_noinfo();
extern "C" void __stdcall sub_417F10(void*, int, void*);
extern "C" void* __stdcall sub_4141A0(void*, void*);
extern "C" void* __cdecl sub_62FEF6(unsigned int);
extern "C" void __cdecl sub_62FC62(void*);
extern "C" void __stdcall sub_77E6D8();
extern "C" void __stdcall sub_77E6AC();

struct Vec {
    void* begin;
    void* end;
    void* cap;
};

struct Obj {
    void* vptr;
    long ref1;
    long ref2;
};

struct Creator {
    void* vptr;
    void* field4;
    void* field8;
};

struct S {
    void* field0;
    void method(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i);
};

void S::method(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i)
{
    Vec v;
    v.begin = 0;
    v.end = 0;
    v.cap = 0;

    sub_417F10(&v, 2, &v);

    void* p = v.begin;
    if (p != 0) {
        int n = ((char*)v.end - (char*)p) >> 2;
        if (n == 0) {
            sub_77E6D8();
            p = v.begin;
        }
    } else {
        sub_77E6D8();
        p = v.begin;
    }

    void* tmp = 0;
    sub_4141A0(&tmp, &tmp);
    void* q = *(void**)tmp;
    void* r = *(void**)p;
    *(void**)tmp = r;
    *(void**)p = q;

    if (v.begin != 0) {
        void* vt = *(void**)v.begin;
        void (*fn)(void*, int) = *(void (**)(void*, int))vt;
        fn(v.begin, 1);
    }

    if (v.begin != 0) {
        int n = ((char*)v.end - (char*)v.begin) >> 2;
        if (n <= 1) {
            sub_77E6D8();
        }
    } else {
        sub_77E6D8();
    }

    void* esi = (char*)v.begin + 4;
    void* mem = sub_62FEF6(0xc);
    if (mem != 0) {
        *(void**)mem = (void*)0x787840;
        *(void**)((char*)mem + 4) = i;
        *(void**)((char*)mem + 8) = h;
        if (h != 0) {
            _InterlockedExchangeAdd((volatile long*)((char*)h + 4), 1);
        }
    } else {
        mem = 0;
    }

    void* old = *(void**)esi;
    *(void**)esi = mem;
    if (old != 0) {
        void* vt = *(void**)old;
        void (*fn)(void*, int) = *(void (**)(void*, int))vt;
        fn(old, 1);
    }

    void* self = *(void**)this;
    void* vt2 = *(void**)self;
    void (*fn2)(void*, void*) = *(void (**)(void*, void*))(*(char**)vt2 + 4);
    fn2(self, &v);

    void* pb = v.begin;
    if (pb != 0) {
        void* pe = v.end;
        void* cur = pb;
        while (cur != pe) {
            void* o = *(void**)cur;
            if (o != 0) {
                void* vt3 = *(void**)o;
                void (*fn3)(void*, int) = *(void (**)(void*, int))vt3;
                fn3(o, 1);
            }
            cur = (char*)cur + 4;
        }
        sub_62FC62(pb);
    }

    v.begin = 0;
    v.end = 0;
    v.cap = 0;

    sub_77E6AC();

    if (h != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)h + 4), -1) == 1) {
            void* vt4 = *(void**)h;
            void (*fn4)(void*) = *(void (**)(void*))(*(char**)vt4 + 4);
            fn4(h);
            if (_InterlockedExchangeAdd((volatile long*)((char*)h + 8), -1) == 1) {
                void* vt5 = *(void**)h;
                void (*fn5)(void*) = *(void (**)(void*))(*(char**)vt5 + 8);
                fn5(h);
            }
        }
    }
}
