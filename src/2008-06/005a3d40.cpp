// from server: 100% by coldek
// roc 2008-06 005a3d40  unit: RBX::VWorkspace::?$RefPropDescriptor  size: 205 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a3d40
//
// 005a3d40  6aff                 push -1
// 005a3d42  68732c7d00           push 0x7d2c73
// 005a3d47  64a100000000         mov eax, dword ptr fs:[0]
// 005a3d4d  50                   push eax
// 005a3d4e  64892500000000       mov dword ptr fs:[0], esp
// 005a3d55  83ec0c               sub esp, 0xc
// 005a3d58  55                   push ebp
// 005a3d59  56                   push esi
// 005a3d5a  57                   push edi
// 005a3d5b  8bf9                 mov edi, ecx
// 005a3d5d  33f6                 xor esi, esi
// 005a3d5f  897c240c             mov dword ptr [esp + 0xc], edi
// 005a3d63  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005a3d6b  89742414             mov dword ptr [esp + 0x14], esi
// 005a3d6f  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005a3d73  89742420             mov dword ptr [esp + 0x20], esi
// 005a3d77  85ed                 test ebp, ebp
// 005a3d79  7417                 je 0x5a3d92
// 005a3d7b  55                   push ebp
// 005a3d7c  6a01                 push 1
// 005a3d7e  8d4c2414             lea ecx, [esp + 0x14]
// 005a3d82  e839dffdff           call 0x581cc0
// 005a3d87  8bc8                 mov ecx, eax
// 005a3d89  e8e239fcff           call 0x567770
// 005a3d8e  8b742414             mov esi, dword ptr [esp + 0x14]
// 005a3d92  6a50                 push 0x50
// 005a3d94  e887cb0f00           call 0x6a0920
// 005a3d99  83c404               add esp, 4
// 005a3d9c  89442428             mov dword ptr [esp + 0x28], eax
// 005a3da0  c644242001           mov byte ptr [esp + 0x20], 1
// 005a3da5  85c0                 test eax, eax
// 005a3da7  740b                 je 0x5a3db4
// 005a3da9  55                   push ebp
// 005a3daa  57                   push edi
// 005a3dab  8bc8                 mov ecx, eax
// 005a3dad  e83edcffff           call 0x5a19f0
// 005a3db2  eb02                 jmp 0x5a3db6
// 005a3db4  33c0                 xor eax, eax
// 005a3db6  50                   push eax
// 005a3db7  8bcf                 mov ecx, edi
// 005a3db9  c644242400           mov byte ptr [esp + 0x24], 0
// 005a3dbe  e8fde1ffff           call 0x5a1fc0
// 005a3dc3  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 005a3dcb  85f6                 test esi, esi
// 005a3dcd  742a                 je 0x5a3df9
// 005a3dcf  8d4604               lea eax, [esi + 4]
// 005a3dd2  83c9ff               or ecx, 0xffffffff
// 005a3dd5  f00fc108             lock xadd dword ptr [eax], ecx
// 005a3dd9  751e                 jne 0x5a3df9
// 005a3ddb  8b16                 mov edx, dword ptr [esi]
// 005a3ddd  8b4204               mov eax, dword ptr [edx + 4]
// 005a3de0  8bce                 mov ecx, esi
// 005a3de2  ffd0                 call eax
// 005a3de4  8d4e08               lea ecx, [esi + 8]
// 005a3de7  83caff               or edx, 0xffffffff
// 005a3dea  f00fc111             lock xadd dword ptr [ecx], edx
// 005a3dee  7509                 jne 0x5a3df9
// 005a3df0  8b06                 mov eax, dword ptr [esi]
// 005a3df2  8b5008               mov edx, dword ptr [eax + 8]
// 005a3df5  8bce                 mov ecx, esi
// 005a3df7  ffd2                 call edx
// 005a3df9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005a3dfd  5f                   pop edi
// 005a3dfe  5e                   pop esi
// 005a3dff  5d                   pop ebp
// 005a3e00  64890d00000000       mov dword ptr fs:[0], ecx
// 005a3e07  83c418               add esp, 0x18
// 005a3e0a  c20400               ret 4

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// v2: nil-local for control init (drives esi-allocation before this), no barrier.
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Descriptor;

struct Control {
    virtual void slot0();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    __forceinline void release() {
        if (_InterlockedDecrement(&strong) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak) == 0)
                destroy();
        }
    }
};

struct Guard {
    Descriptor* owner;
    void* pointer;
    Control* control;

    __declspec(noalias) Guard* acquire(int, void*);
    void finish();
    void release();
    Guard(Descriptor* o) : owner(o), pointer(0), control(0) {}
    ~Guard() { if (control) control->release(); }
};

struct Object {
    char storage[0x50];
    Object(Descriptor*, void*);
};

struct Descriptor {
    void attach(Object*);
    void f(void*);
};

inline void Guard::release()
{
    if (control)
        control->release();
}

void Descriptor::f(void* value)
{
    Guard guard(this);
    if (value)
        guard.acquire(1, value)->finish();
    attach(new Object(this, value));
}
