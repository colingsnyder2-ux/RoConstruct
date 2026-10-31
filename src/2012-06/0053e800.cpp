// from server: 47% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl func_00439330(void* ecx, void* outPtr);
extern "C" void __cdecl func_0053de50();

struct RefCounted
{
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct VPlayerEventDesc
{
    void __thiscall construct(RefCounted* a, RefCounted* b);
};

void VPlayerEventDesc::construct(RefCounted* a, RefCounted* b)
{
    int cookie = -1;
    void* sehRecord = 0;
    void* prevSEH = 0;
    RefCounted* localPtr = 0;
    char state = 0;

    func_00439330(this, &localPtr);
    state = 2;

    RefCounted* ecx = localPtr;
    if (ecx)
    {
        RefCounted* edx = a;
        RefCounted* eax = b;
        if (eax)
        {
            _InterlockedExchangeAdd(&eax->ref1, 1);
        }
        func_0053de50();
    }

    RefCounted* esi = localPtr;
    state = 1;
    if (esi)
    {
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1)
        {
            void (__thiscall* func)(RefCounted*) = *reinterpret_cast<void (__thiscall**)(RefCounted*)>((char*)esi->vptr + 4);
            func(esi);
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1)
            {
                void (__thiscall* func2)(RefCounted*) = *reinterpret_cast<void (__thiscall**)(RefCounted*)>((char*)esi->vptr + 8);
                func2(esi);
            }
        }
    }

    RefCounted* eax2 = localPtr;
    state = 0;
    if (eax2)
    {
        RefCounted* ecx2 = eax2;
        if (_InterlockedExchangeAdd(&eax2->ref2, -1) == 1)
        {
            void (__thiscall* func3)(RefCounted*) = *reinterpret_cast<void (__thiscall**)(RefCounted*)>((char*)ecx2->vptr + 8);
            func3(ecx2);
        }
    }

    RefCounted* esi2 = b;
    state = -1;
    if (esi2)
    {
        if (_InterlockedExchangeAdd(&esi2->ref1, -1) == 1)
        {
            void (__thiscall* func4)(RefCounted*) = *reinterpret_cast<void (__thiscall**)(RefCounted*)>((char*)esi2->vptr + 4);
            func4(esi2);
            if (_InterlockedExchangeAdd(&esi2->ref2, -1) == 1)
            {
                void (__thiscall* func5)(RefCounted*) = *reinterpret_cast<void (__thiscall**)(RefCounted*)>((char*)esi2->vptr + 8);
                func5(esi2);
            }
        }
    }
}
