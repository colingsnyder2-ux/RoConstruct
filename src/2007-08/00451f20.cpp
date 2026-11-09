// from server: 1% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sprintf(char*, const char*, ...);

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Inner {
    char pad[0x78];
    void* field78;
};

struct Obj {
    char pad[0x150];
    int field150;
};

struct Arg {
    void* vptr;
    void* ptr;
};

struct Str {
    char buf[0x40];
};

struct S {
    char pad[0x78];
    void* field78;
    void method(int* out);
};

void S::method(int* out)
{
    void* p;
    void* q;
    void* r;
    int* tmp;
    Obj* o;
    int flag;
    Str s;

    // call 0x403800 with field78, out
    // returns pointer to pair (vptr, ptr)
    // simplified: treat as returning Arg*
    Arg* a = (Arg*)0;
    // placeholder to keep structure
    (void)a;
    (void)p; (void)q; (void)r; (void)tmp; (void)o; (void)flag; (void)s;
}
