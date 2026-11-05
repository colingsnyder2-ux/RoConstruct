// from server: 47% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct FuncDesc {
    char pad[0x28];
    int field_28;
    int field_2c;
    void construct(int a, int b, int c, int d);
};

extern "C" void* __cdecl sub_56F410(int);
extern "C" void* __cdecl sub_56FA60(void*);
extern "C" void __cdecl sub_77E69C(void*, void*);

void FuncDesc::construct(int a, int b, int c, int d) {
    void* p = sub_56F410(b);
    char buf[0x1c];
    sub_77E69C(buf, p);
    void* q = sub_56FA60(buf);
    void* r = *(void**)q;
    int s = *(int*)((char*)q + 4);
    if (s == 0) {
        _InterlockedExchangeAdd((volatile long*)(s + 4), 1);
    }
    int ecx = this->field_2c + c;
    int edx = this->field_28;
    ((void (__thiscall*)(int, void*, int))edx)(ecx, r, s);
}
