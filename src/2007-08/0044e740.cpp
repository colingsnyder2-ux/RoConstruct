// from server: 46% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Helper_00403800_result
{
    void* ptr;
};

extern Helper_00403800_result* __cdecl func_00403800(Helper_00403800_result* out);

struct CRobloxDoc
{
    char pad_0000[0x48];
    int field_0048;
    char pad_004c[0x78 - 0x4c];
    void* field_0078;
    void setMode(int mode);
};

void CRobloxDoc::setMode(int mode)
{
    field_0048 = mode;
    if (field_0078 != 0)
    {
        Helper_00403800_result local;
        Helper_00403800_result* p = func_00403800(&local);
        void* obj = p->ptr;
        void** vtbl = *(void***)obj;
        void* vtable_entry = *(void**)((char*)vtbl + 0x160);
        void (*fn)(void*, int) = *(void (**)(void*, int))((char*)vtable_entry + 4);
        int flag = (mode == 1) ? 1 : 0;
        fn((char*)obj + 0x160, flag);
        void* ref = local.ptr;
        if (ref != 0)
        {
            if (_InterlockedExchangeAdd((volatile long*)((char*)ref + 4), -1) == 1)
            {
                void** vt = *(void***)ref;
                void (*dtor)(void*) = *(void (**)(void*))((char*)vt + 4);
                dtor(ref);
                if (_InterlockedExchangeAdd((volatile long*)((char*)ref + 8), -1) == 1)
                {
                    void** vt2 = *(void***)ref;
                    void (*dtor2)(void*) = *(void (**)(void*))((char*)vt2 + 8);
                    dtor2(ref);
                }
            }
        }
    }
}
