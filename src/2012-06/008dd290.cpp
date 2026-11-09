// from server: 27% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl func_005226c0(int);
extern "C" void __cdecl func_0051c940(void*);

struct PropDescriptorBase {
    void* vptr;
    int refcount;
};

struct PropDescriptorHolder {
    int field0;
    PropDescriptorBase* ptr8;
};

struct Outer {
    int field0;
    int field4;
    PropDescriptorHolder field8;
    int fieldC;
    int field10;
};

int Outer_ctor(Outer* self, int a, int b, int c, int d, int e);

int Outer_ctor(Outer* self, int a, int b, int c, int d, int e)
{
    PropDescriptorBase* p1 = (PropDescriptorBase*)c;
    PropDescriptorBase* p2 = (PropDescriptorBase*)e;
    int result;

    if (p1)
        _InterlockedExchangeAdd((volatile long*)((char*)p1 + 8), 1);
    if (p2)
        _InterlockedExchangeAdd((volatile long*)((char*)p2 + 8), 1);

    result = func_005226c0(0xdf7044);
    result = -(unsigned char)result;
    result = result & 0xdf7044;
    self->field0 = result;

    func_0051c940((void*)0);
    return result;
}
