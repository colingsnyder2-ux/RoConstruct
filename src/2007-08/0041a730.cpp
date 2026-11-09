// from server: 37% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __stdcall sub_56F410(void*);
extern "C" void* __stdcall sub_56FA60(void*);
extern "C" void* __stdcall sub_77E69C(void*);

struct Str {
    void* pad0;
    void* pad4;
    void* pad8;
    void* padC;
    void* pad10;
    void* pad14;
    void* pad18;
    void* pad1C;
};

struct S {
    char pad[0x28];
    void* field28;
    void* field2C;
    void method(int, Str*, Str*, int, int, int);
};

void S::method(int a, Str* b, Str* c, int d, int e, int f)
{
    void* p1 = sub_56F410(b);
    Str s1;
    sub_77E69C(&s1);
    void* p2 = sub_56F410(c);
    Str s2;
    sub_77E69C(&s2);
    void* p3 = sub_56FA60(p2);
    Str s3;
    *(void**)&s3 = *(void**)p3;
    void* ref = *(void**)((char*)p3 + 4);
    *(void**)((char*)&s3 + 4) = ref;
    if (ref) {
        _InterlockedExchangeAdd((volatile long*)((char*)ref + 4), 1);
    }
    int total = (int)this->field2C + d;
    void (*fn)(int) = (void (*)(int))this->field28;
    fn(total);
}
