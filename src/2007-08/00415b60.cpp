// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    long refcount;
    long refcount2;
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
};

struct String {
    void* data;
    String();
    String(const String&);
    ~String();
};

struct Content {
    void* field0;
    void* field4;
};

extern "C" void __stdcall StringCopy(String*, const String*);
extern "C" void __stdcall StringDtor(String*);

struct VCContent {
    void Method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11);
};

void VCContent::Method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    int* p = (int*)a1;
    RefCounted* rc = (RefCounted*)a2;
    Content* c = (Content*)this;
    String s;
    StringCopy(&s, (const String*)a3);
    int val = *p;
    int ecx = (int)c->field4;
    int edx = *(int*)c->field0;
    ecx += val;
    ((void (__thiscall*)(int, int))edx)(ecx, a4);
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            rc->dummy1();
            if (_InterlockedExchangeAdd(&rc->refcount2, -1) == 1) {
                rc->dummy2();
            }
        }
    }
    StringDtor(&s);
}
