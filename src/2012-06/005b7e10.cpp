// from server: 45% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    int vptr;
    long refCount;
};

struct InterpolatingPhysicsReceiver {
    char pad[0x224];
    RefCounted* field_224;
    void ReleaseRef();
    void BaseDestructor();
};

void InterpolatingPhysicsReceiver::ReleaseRef() {
    RefCounted* ref = this->field_224;
    if (ref) {
        volatile long* counter = &ref->refCount;
        long old = _InterlockedExchangeAdd(counter, -1);
        if (old == 1) {
            int* vtable = *reinterpret_cast<int**>(ref);
            void (__thiscall *dtor)(RefCounted*) = reinterpret_cast<void (__thiscall *)(RefCounted*)>(vtable[2]);
            dtor(ref);
        }
    }
}

void InterpolatingPhysicsReceiver::BaseDestructor() {
    this->ReleaseRef();
    typedef void (__thiscall *Fn)(InterpolatingPhysicsReceiver*);
    static Fn baseDtor = reinterpret_cast<Fn>(0x570ad0);
    baseDtor(this);
}
