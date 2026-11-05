// from server: 53% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern void __stdcall sub_432530(void*, void*);

struct RefCounted {
    void AddRef();
    void Release();
};

struct LocalBackpackItem {
    char pad[0x120];
    int field120;
    int field124;
    char pad128[0x148 - 0x128];
    RefCounted* field148;
    RefCounted* field14C;
    void sub_541c30();
    void func_005d0690();
};

void LocalBackpackItem::func_005d0690()
{
    sub_541c30();
    if (field148 != 0) {
        RefCounted* p = field148;
        if (p != 0) {
            sub_432530(&field120, (char*)p + 0x14);
        }
        if (p != 0) {
            sub_432530(&field124, (char*)p + 0x2C);
        }
        field148 = 0;
        RefCounted* r = field14C;
        field14C = 0;
        if (r != 0) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)r + 4), -1) == 1) {
                r->Release();
            }
            if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
                r->AddRef();
            }
        }
    }
}
