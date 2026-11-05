// from server: 40% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RbxParticleEmitter {
    void destructor();
};

void RbxParticleEmitter::destructor() {
    int* vptr_main = (int*)0xB6E82C;
    int* vptr_sub = (int*)0xB6E80C;
    void (__stdcall *sceneNodeDtor)(void*) = *(void (__stdcall **)(void*))0xB23948;
    void (__thiscall *subDtor)(void*) = (void (__thiscall *)(void*))0x673CE0;

    *reinterpret_cast<int**>(this) = vptr_main;
    int* subObj = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x1C4);
    *subObj = reinterpret_cast<int>(vptr_sub);

    int* refCounted = *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x170);
    refCounted = *reinterpret_cast<int**>(reinterpret_cast<char*>(refCounted) + 0x4720);
    refCounted = *reinterpret_cast<int**>(reinterpret_cast<char*>(refCounted) + 8);
    _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(reinterpret_cast<char*>(refCounted) + 8), -1);

    int* shared = *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x1E4);
    if (shared) {
        if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(shared + 1), -1) == 0) {
            void (__thiscall *dtor1)(int*) = *reinterpret_cast<void (__thiscall **)(int*)>(*shared + 4);
            dtor1(shared);
            if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(shared + 2), -1) == 0) {
                void (__thiscall *dtor2)(int*) = *reinterpret_cast<void (__thiscall **)(int*)>(*shared + 8);
                dtor2(shared);
            }
        }
    }

    subDtor(subObj);
    sceneNodeDtor(this);
}
