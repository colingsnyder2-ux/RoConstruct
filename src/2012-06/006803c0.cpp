// from server: 50% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VTable {
    void* dtor;
    void* release;
};

struct RefCounted {
    VTable* vptr;
    long refCount;
};

struct AncestryChangedSignalData {
    VTable* vptr;
    RefCounted* ref;
    AncestryChangedSignalData();
};

AncestryChangedSignalData::AncestryChangedSignalData() {
    this->vptr = reinterpret_cast<VTable*>(0x00B8EE7C);
    RefCounted* ref = this->ref;
    if (ref) {
        long* counter = &ref->refCount;
        long oldValue = _InterlockedExchangeAdd(counter, -1);
        if (oldValue != 1) {
            return;
        }
        VTable* vtable = ref->vptr;
        void (__stdcall* releaseFunc)(RefCounted*) = reinterpret_cast<void (__stdcall*)(RefCounted*)>(vtable->release);
        releaseFunc(ref);
    }
}
