// from server: 27% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall SetEvent(void*);
extern "C" void __stdcall DestroyWindow(void*);

struct RefCounted
{
    long refCount;
    long weakCount;
};

struct FunctionMarshaller
{
    void __cdecl execute(void* job);
};

void FunctionMarshaller::execute(void* job)
{
    void (__cdecl *initFunc)(int, int) = (void (__cdecl*)(int, int))0x4015a0;
    initFunc(0x4259B0, 0xE1822C);

    RefCounted* (*getRefCounted)() = (RefCounted*(*)())0x425910;
    RefCounted* rc = getRefCounted();
    RefCounted* ref = rc + 3;

    void (__thiscall *addRef)(RefCounted*) = (void (__thiscall*)(RefCounted*))0x424260;
    addRef(ref);

    int* jobPtr = (int*)job;
    int val = jobPtr[19];
    jobPtr[19] = val - 1;

    if (val - 1 == 0)
    {
        initFunc(0x4259B0, 0xE1822C);
        void (__thiscall *func1)(int*) = (void (__thiscall*)(int*))0x425910;
        func1(jobPtr + 20);
        void (__thiscall *func2)(int) = (void (__thiscall*)(int))0x4A11D0;
        func2(jobPtr[1]);
        void (__stdcall *destroyWindow)(void*) = (void (__stdcall*)(void*))0xB23AAC;
        destroyWindow((void*)jobPtr[1]);
    }

    long oldRef = _InterlockedExchangeAdd(&ref->refCount, -1);
    if (oldRef - 1 == 0)
    {
        long oldWeak = _InterlockedExchangeAdd(&ref->weakCount, -1);
        if ((oldWeak & 0x40000000) == 0 && oldWeak != 0x80000000 && oldWeak > 0x80000000)
        {
            long newWeak = _InterlockedExchangeAdd(&ref->weakCount, 0x40000000);
            if ((newWeak & 0x40000000) == 0)
            {
                void* (__cdecl *alloc)() = (void* (__cdecl*)())0x40B9C0;
                void* mem = alloc();
                void (__stdcall *setEvent)(void*) = (void (__stdcall*)(void*))0xB2230C;
                setEvent(mem);
            }
        }
    }
}
