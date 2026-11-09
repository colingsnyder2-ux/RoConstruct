// from server: 39% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCountedBase {
    virtual void ReleaseRef() = 0;
    virtual void Destroy() = 0;
};

struct VThreadLogManager {
    char pad[0x834];
    RefCountedBase* m_ptr;

    void Cleanup();
};

extern "C" void __stdcall __CxxFrameHandler3();
extern "C" void __cdecl sub_97C260(int);

void VThreadLogManager::Cleanup()
{
    RefCountedBase* ptr = m_ptr;
    if (ptr) {
        volatile long* strongRef = reinterpret_cast<volatile long*>(ptr + 1);
        if (_InterlockedExchangeAdd(strongRef, -1) == 1) {
            ptr->ReleaseRef();
        }

        volatile long* weakRef = reinterpret_cast<volatile long*>(reinterpret_cast<char*>(ptr) + 8);
        if (_InterlockedExchangeAdd(weakRef, -1) == 1) {
            ptr->Destroy();
        }
    }

    *reinterpret_cast<int*>(0xE581AC);
    *reinterpret_cast<int*>(this) = 0xB986CC;
    sub_97C260(0);
}
