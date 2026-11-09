// from server: 48% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct String {
    void* data[4];
    String();
    ~String();
};

struct RefCounted {
    virtual void destroy();
    virtual void release();
    volatile long ref1;
    volatile long ref2;
};

extern "C" void __stdcall sub_b22654(void*);
extern "C" void __stdcall sub_b2263c(void*);
extern "C" void __cdecl sub_56c700(void*, void*);
extern "C" int __cdecl sub_67f4a0(void*);
extern "C" void __cdecl sub_56c2f0(void*, void*);
extern "C" void __cdecl sub_544d30(void*, void*, void*);

struct Target {
    void func(void* arg);
};

void Target::func(void* arg) {
    String s;
    void* local1 = 0;
    void* local2 = 0;
    void* local3 = 0;
    sub_b22654(&s);
    sub_56c700(this, &s);
    int r = sub_67f4a0(&local1);
    local2 = (void*)r;
    sub_56c2f0(this, &local2);
    sub_544d30(&local3, &local1, arg);
    sub_b2263c(&s);
    RefCounted* p = (RefCounted*)arg;
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref1, -1) == 1) {
            p->destroy();
            if (_InterlockedExchangeAdd(&p->ref2, -1) == 1) {
                p->release();
            }
        }
    }
}
