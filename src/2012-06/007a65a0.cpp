// from server: 41% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_684200(int, int);

struct VKeyframeFactoryProduct {
    int field_38;

    void method(int arg0, int arg1);
};

void VKeyframeFactoryProduct::method(int arg0, int arg1)
{
    int v0 = this->field_38;
    if (v0 == (int)this)
    {
        sub_684200(0, 0);
    }

    int* esi = (int*)arg1;
    if (esi)
    {
        long old = _InterlockedExchangeAdd((volatile long*)(esi + 1), -1);
        if (old == 1)
        {
            int vtable = esi[0];
            int (__thiscall *destructor)(int*) = (int (__thiscall*)(int*))*(int*)(vtable + 4);
            destructor(esi);

            old = _InterlockedExchangeAdd((volatile long*)(esi + 2), -1);
            if (old == 1)
            {
                int (__thiscall *deleter)(int*) = (int (__thiscall*)(int*))*(int*)(vtable + 8);
                deleter(esi);
            }
        }
    }
}
