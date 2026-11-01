// from server: 46% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_441580(int*);
extern "C" void __cdecl sub_972290(const char*, int);

struct RefCounted
{
    int vptr;
    int refCount;
};

struct Creator
{
    void __cdecl f(void* outPtr, int arg);
};

void Creator::f(void* outPtr, int arg)
{
    int sehCookie = 0;
    if (*(unsigned char*)0xE580B3 != 0)
    {
        if (*(int*)0xE188B0 != 0x29A)
        {
            int (__cdecl* callback)(const char*, const char*, int) = (int (__cdecl*)(const char*, const char*, int))*(int*)0xE5809C;
            if (callback != 0)
            {
                if (callback("C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util/Object.h", "wasConstructed()", 0xCA) != 0)
                {
                    goto LABEL_RETURN;
                }
            }
            sub_972290("wasConstructed() file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util/Object.h line: 202", *(unsigned char*)0xE580B3);
        }
    }

LABEL_RETURN:
    int localPtr[2];
    sub_441580(localPtr);
    RefCounted* obj = (RefCounted*)localPtr[0];
    int* result = (int*)outPtr;
    int ptrVal = 0;
    if (obj != 0)
    {
        ptrVal = (int)((char*)obj + 0x18);
    }
    *result = ptrVal;
    int ref = localPtr[1];
    result[1] = ref;
    if (ref != 0)
    {
        if (_InterlockedExchangeAdd((volatile long*)(ref + 4), 1) != 0)
        {
        }
    }

    int esi = arg;
    int guard = 0;
    int state = 1;
    if (esi != 0)
    {
        long old = _InterlockedExchangeAdd((volatile long*)(esi + 4), -1);
        if (old == 1)
        {
            int vtable = *(int*)esi;
            void (__thiscall* dtor)(int) = (void (__thiscall*)(int))*(int*)(vtable + 4);
            dtor(esi);
            long old2 = _InterlockedExchangeAdd((volatile long*)(esi + 8), -1);
            if (old2 == 1)
            {
                int vtable2 = *(int*)esi;
                void (__thiscall* deleter)(int) = (void (__thiscall*)(int))*(int*)(vtable2 + 8);
                deleter(esi);
            }
        }
    }
}
