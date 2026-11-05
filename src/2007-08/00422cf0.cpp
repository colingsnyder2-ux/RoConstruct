// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void Release();
};

struct Inner {
    char pad[0xb0];
    void Lock();
    void Unlock();
    void sub_154(void*);
};

struct CRobloxTreeCtrlNode {
    char pad0[0x28];
    unsigned int flags;
    Inner* inner;
    char pad2[0x34 - 0x2c];
    char field34[0x4];
    void sub_421640(void*, void*);
    void func(int, int, int);
};

void CRobloxTreeCtrlNode::func(int a, int b, int c)
{
    RefCounted* rc = 0;
    if (flags & 2) {
        Inner* in = inner;
        in = (Inner*)((char*)in + 0xb0);
        in->Lock();
        sub_421640(&field34, &rc);
        in->Unlock();
    }
    inner->sub_154((char*)this - 4);
    if (rc) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)rc + 4), -1) == 1) {
            rc->Release();
            if (_InterlockedExchangeAdd((volatile long*)((char*)rc + 8), -1) == 1) {
                rc->Release();
            }
        }
    }
}
