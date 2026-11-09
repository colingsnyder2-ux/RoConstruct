// from server: 36% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted
{
    int vptr;
    int refCount;
    int weakCount;
};

struct SomeObject
{
    int vptr;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;

    int func_0090df60();
};

extern "C" void __stdcall func_0090de10(int*, int*, int*);
extern "C" void __cdecl func_004026a0(SomeObject*, int*);

int SomeObject::func_0090df60()
{
    int localC;
    int local10;
    int local14;

    func_0090de10(&localC, &local10, &local14);

    int* ptr = &localC;
    int value = *ptr;
    ++ptr;
    func_004026a0(this + 0x1C, &value);
    this->field18 = value;

    if (localC)
    {
        RefCounted* rc = reinterpret_cast<RefCounted*>(localC);
        if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&rc->refCount), -1) == 1)
        {
            int vptr = rc->vptr;
            int (__cdecl *dtor)(RefCounted*) = reinterpret_cast<int (__cdecl*)(RefCounted*)>(*(int*)(vptr + 4));
            dtor(rc);
            if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&rc->weakCount), -1) == 1)
            {
                int vptr2 = rc->vptr;
                int (__cdecl *weakDtor)(RefCounted*) = reinterpret_cast<int (__cdecl*)(RefCounted*)>(*(int*)(vptr2 + 8));
                weakDtor(rc);
            }
        }
    }

    int result = this->field18;
    int vptr3 = *reinterpret_cast<int*>(result);
    this->field14 = *reinterpret_cast<int*>(vptr3 + 0xC);
    return 0;
}
