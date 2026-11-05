// from server: 31% by atomic.potato
struct Inner {
    void* vt;
    int val;
};

struct Outer {
    void* vt;
    void (__thiscall *set)(void*, Inner*);

    void method(Inner* p);
};

extern "C" void __stdcall _invalid_parameter_noinfo();
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl op_delete(void*);

struct Vec {
    Inner* begin;
    Inner* end;
    Inner* cap;
    void Vec_ctor(int);
    void Vec_dtor();
};

void Vec::Vec_ctor(int) {}
void Vec::Vec_dtor() {}

void Outer::method(Inner* p) {
    Vec v;
    v.Vec_ctor(1);
    int n = (int)((char*)v.end - (char*)v.begin) >> 2;
    if (n <= 0) {
        _invalid_parameter_noinfo();
    }
    Inner* old = v.begin;
    Inner* ni = 0;
    void* mem = operator_new(8);
    if (mem) {
        *(void**)mem = (void*)0x9cbe4c;
        *((Inner**)mem + 1) = p;
        ni = (Inner*)mem;
    }
    Inner* tmp = old;
    if (&v.begin != &old) {
        tmp = v.begin;
        v.begin = ni;
    }
    if (tmp) {
        void** vt = *(void***)tmp;
        void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
        fn(tmp, 1);
    }
    void** ovt = *(void***)this;
    void (*setfn)(void*, Inner*) = (void (*)(void*, Inner*))ovt[1];
    setfn(this, v.begin);
    v.Vec_dtor();
}
