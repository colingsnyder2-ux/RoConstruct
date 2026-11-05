// from server: 100% by why2
extern "C" long (__stdcall *InterlockedIncrement)(long volatile*);

struct RBX_ExclusiveArbiter {
    char pad[0x198];
    long counter;
    long Increment();
};

long RBX_ExclusiveArbiter::Increment() {
    return InterlockedIncrement(&counter);
}
