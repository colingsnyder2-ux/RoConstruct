// from server: 100% by why2
extern "C" long (__stdcall *InterlockedDecrement)(long volatile*);

struct RBX_ExclusiveArbiter
{
    char pad[0x198];
    long refcount;
    long Release();
};

long RBX_ExclusiveArbiter::Release()
{
    return InterlockedDecrement(&refcount);
}
