// from server: 41% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct CRobloxTreeCtrlNode
{
    unsigned char pad[0x2c];
    unsigned char flags;
    unsigned char pad2[3];
    void* field_30;
    void f(void* arg1, void* arg2);
};

struct RefCounted
{
    long ref1;
    long ref2;
};

struct VTable
{
    void (__thiscall* func_15c)(void*, void*);
};

void CRobloxTreeCtrlNode::f(void* arg1, void* arg2)
{
    if (flags & 2)
    {
        RefCounted* rc = (RefCounted*)((char*)field_30 + 0xB0);
        ((void (__thiscall*)(RefCounted*))0x424260)(rc);

        char local_c = 1;
        char local_20 = 1;

        ((void (__thiscall*)(void*, char*, char*))0x42C330)((char*)this + 0x3C, &local_c, &local_20);

        long old1 = _InterlockedExchangeAdd(&rc->ref1, -1);
        local_20 = 0;
        if (old1 == 1)
        {
            long old2 = _InterlockedExchangeAdd(&rc->ref2, 0x80000000);
            if (!(old2 & 0x40000000))
            {
                if (old2 > 0x80000000)
                {
                    long old3 = _InterlockedExchangeAdd(&rc->ref2, 0);
                    if (!(_InterlockedExchangeAdd(&rc->ref2, 0) & 0x40000000))
                    {
                        void* evt = ((void* (__cdecl*)())0x40B9C0)();
                        ((void (__stdcall*)(void*))0xB2230C)(evt);
                    }
                }
            }
        }
    }

    void* vptr = *(void**)field_30;
    void (__thiscall* func)(void*, void*) = *(void (__thiscall**)(void*, void*))((char*)vptr + 0x15C);
    func(field_30, this);

    RefCounted* rc2 = (RefCounted*)*(unsigned int*)((char*)this + 0x2C);
    if (rc2)
    {
        long old4 = _InterlockedExchangeAdd(&rc2->ref1, -1);
        if (old4 == 1)
        {
            void* vptr2 = *(void**)rc2;
            void (__thiscall* dtor)(void*) = *(void (__thiscall**)(void*))((char*)vptr2 + 4);
            dtor(rc2);
        }

        long old5 = _InterlockedExchangeAdd(&rc2->ref2, -1);
        if (old5 == 1)
        {
            void* vptr3 = *(void**)rc2;
            void (__thiscall* delete_func)(void*) = *(void (__thiscall**)(void*))((char*)vptr3 + 8);
            delete_func(rc2);
        }
    }
}
