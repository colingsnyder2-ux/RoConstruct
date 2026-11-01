// from server: 100% by colin
// from server: 98% by colin
// roc 2008-06 0046b0e0  unit: VCWorkspace::?$CComObject  size: 242 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046b0e0
//
// 0046b0e0  64a100000000         mov eax, dword ptr fs:[0]
// 0046b0e6  6aff                 push -1
// 0046b0e8  6828397c00           push 0x7c3928
// 0046b0ed  50                   push eax
// 0046b0ee  64892500000000       mov dword ptr fs:[0], esp
// 0046b0f5  83ec10               sub esp, 0x10
// 0046b0f8  53                   push ebx
// 0046b0f9  56                   push esi
// 0046b0fa  57                   push edi
// 0046b0fb  8bf9                 mov edi, ecx
// 0046b0fd  837f2400             cmp dword ptr [edi + 0x24], 0
// 0046b101  8d7724               lea esi, [edi + 0x24]
// 0046b104  0f84b6000000         je 0x46b1c0
// 0046b10a  8b06                 mov eax, dword ptr [esi]
// 0046b10c  83ec08               sub esp, 8
// 0046b10f  8bcc                 mov ecx, esp
// 0046b111  8901                 mov dword ptr [ecx], eax
// 0046b113  8b4604               mov eax, dword ptr [esi + 4]
// 0046b116  89642414             mov dword ptr [esp + 0x14], esp
// 0046b11a  894104               mov dword ptr [ecx + 4], eax
// 0046b11d  85c0                 test eax, eax
// 0046b11f  740c                 je 0x46b12d
// 0046b121  83c004               add eax, 4
// 0046b124  b901000000           mov ecx, 1
// 0046b129  f00fc108             lock xadd dword ptr [eax], ecx
// 0046b12d  8d4c2418             lea ecx, [esp + 0x18]
// 0046b131  e80a6afaff           call 0x411b40
// 0046b136  8b0e                 mov ecx, dword ptr [esi]
// 0046b138  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0046b140  8d5f18               lea ebx, [edi + 0x18]
// 0046b143  e8b8a0faff           call 0x415200
// 0046b148  85c0                 test eax, eax
// 0046b14a  740c                 je 0x46b158
// 0046b14c  53                   push ebx
// 0046b14d  8d8830010000         lea ecx, [eax + 0x130]
// 0046b153  e828a91700           call 0x5e5a80
// 0046b158  8b06                 mov eax, dword ptr [esi]
// 0046b15a  8b8004020000         mov eax, dword ptr [eax + 0x204]
// 0046b160  8d4f1c               lea ecx, [edi + 0x1c]
// 0046b163  85c0                 test eax, eax
// 0046b165  740c                 je 0x46b173
// 0046b167  51                   push ecx
// 0046b168  8d8844030000         lea ecx, [eax + 0x344]
// 0046b16e  e80da91700           call 0x5e5a80
// 0046b173  8d4c2410             lea ecx, [esp + 0x10]
// 0046b177  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0046b17f  e83cc21000           call 0x5773c0
// 0046b184  8d4f2c               lea ecx, [edi + 0x2c]
// 0046b187  e8f4bcfeff           call 0x456e80
// 0046b18c  8b16                 mov edx, dword ptr [esi]
// 0046b18e  6a01                 push 1
// 0046b190  83ec08               sub esp, 8
// 0046b193  8bcc                 mov ecx, esp
// 0046b195  8911                 mov dword ptr [ecx], edx
// 0046b197  8b4604               mov eax, dword ptr [esi + 4]
// 0046b19a  89642418             mov dword ptr [esp + 0x18], esp
// 0046b19e  894104               mov dword ptr [ecx + 4], eax
// 0046b1a1  85c0                 test eax, eax
// 0046b1a3  740c                 je 0x46b1b1
// 0046b1a5  83c004               add eax, 4
// 0046b1a8  b901000000           mov ecx, 1
// 0046b1ad  f00fc108             lock xadd dword ptr [eax], ecx
// 0046b1b1  e84a061100           call 0x57b800
// 0046b1b6  83c40c               add esp, 0xc
// 0046b1b9  8bce                 mov ecx, esi
// 0046b1bb  e8c0bcfeff           call 0x456e80
// 0046b1c0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046b1c4  5f                   pop edi
// 0046b1c5  5e                   pop esi
// 0046b1c6  64890d00000000       mov dword ptr fs:[0], ecx
// 0046b1cd  5b                   pop ebx
// 0046b1ce  83c41c               add esp, 0x1c
// 0046b1d1  c3                   ret 

// from server: 95% by king_originala
// roc 2008-06 0046b0e0  unit: VCWorkspace::?$CComObject  size: 242 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046b0e0
//
// 0046b0e0  64a100000000         mov eax, dword ptr fs:[0]
// 0046b0e6  6aff                 push -1
// 0046b0e8  6828397c00           push 0x7c3928
// 0046b0ed  50                   push eax
// 0046b0ee  64892500000000       mov dword ptr fs:[0], esp
// 0046b0f5  83ec10               sub esp, 0x10
// 0046b0f8  53                   push ebx
// 0046b0f9  56                   push esi
// 0046b0fa  57                   push edi
// 0046b0fb  8bf9                 mov edi, ecx
// 0046b0fd  837f2400             cmp dword ptr [edi + 0x24], 0
// 0046b101  8d7724               lea esi, [edi + 0x24]
// 0046b104  0f84b6000000         je 0x46b1c0
// 0046b10a  8b06                 mov eax, dword ptr [esi]
// 0046b10c  83ec08               sub esp, 8
// 0046b10f  8bcc                 mov ecx, esp
// 0046b111  8901                 mov dword ptr [ecx], eax
// 0046b113  8b4604               mov eax, dword ptr [esi + 4]
// 0046b116  89642414             mov dword ptr [esp + 0x14], esp
// 0046b11a  894104               mov dword ptr [ecx + 4], eax
// 0046b11d  85c0                 test eax, eax
// 0046b11f  740c                 je 0x46b12d
// 0046b121  83c004               add eax, 4
// 0046b124  b901000000           mov ecx, 1
// 0046b129  f00fc108             lock xadd dword ptr [eax], ecx
// 0046b12d  8d4c2418             lea ecx, [esp + 0x18]
// 0046b131  e80a6afaff           call 0x411b40
// 0046b136  8b0e                 mov ecx, dword ptr [esi]
// 0046b138  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0046b140  8d5f18               lea ebx, [edi + 0x18]
// 0046b143  e8b8a0faff           call 0x415200
// 0046b148  85c0                 test eax, eax
// 0046b14a  740c                 je 0x46b158
// 0046b14c  53                   push ebx
// 0046b14d  8d8830010000         lea ecx, [eax + 0x130]
// 0046b153  e828a91700           call 0x5e5a80
// 0046b158  8b06                 mov eax, dword ptr [esi]
// 0046b15a  8b8004020000         mov eax, dword ptr [eax + 0x204]
// 0046b160  8d4f1c               lea ecx, [edi + 0x1c]
// 0046b163  85c0                 test eax, eax
// 0046b165  740c                 je 0x46b173
// 0046b167  51                   push ecx
// 0046b168  8d8844030000         lea ecx, [eax + 0x344]
// 0046b16e  e80da91700           call 0x5e5a80
// 0046b173  8d4c2410             lea ecx, [esp + 0x10]
// 0046b177  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0046b17f  e83cc21000           call 0x5773c0
// 0046b184  8d4f2c               lea ecx, [edi + 0x2c]
// 0046b187  e8f4bcfeff           call 0x456e80
// 0046b18c  8b16                 mov edx, dword ptr [esi]
// 0046b18e  6a01                 push 1
// 0046b190  83ec08               sub esp, 8
// 0046b193  8bcc                 mov ecx, esp
// 0046b195  8911                 mov dword ptr [ecx], edx
// 0046b197  8b4604               mov eax, dword ptr [esi + 4]
// 0046b19a  89642418             mov dword ptr [esp + 0x18], esp
// 0046b19e  894104               mov dword ptr [ecx + 4], eax
// 0046b1a1  85c0                 test eax, eax
// 0046b1a3  740c                 je 0x46b1b1
// 0046b1a5  83c004               add eax, 4
// 0046b1a8  b901000000           mov ecx, 1
// 0046b1ad  f00fc108             lock xadd dword ptr [eax], ecx
// 0046b1b1  e84a061100           call 0x57b800
// 0046b1b6  83c40c               add esp, 0xc
// 0046b1b9  8bce                 mov ecx, esi
// 0046b1bb  e8c0bcfeff           call 0x456e80
// 0046b1c0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046b1c4  5f                   pop edi
// 0046b1c5  5e                   pop esi
// 0046b1c6  64890d00000000       mov dword ptr fs:[0], ecx
// 0046b1cd  5b                   pop ebx
// 0046b1ce  83c41c               add esp, 0x1c
// 0046b1d1  c3                   ret 

#include <intrin.h>

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    long reserved;
    volatile long references;
    void addRef();
};

__forceinline void Control::addRef()
{
    _InterlockedIncrement(&references);
}

struct Connection {
    unsigned long value;
};

struct Signal {
    void disconnect(Connection*);
};

struct Service {
    char reserved[0x130];
    Signal signal;
};

struct Provider {
    char reserved[0x344];
    Signal signal;
};

struct Object {
    char reserved[0x204];
    Provider* provider;
    Service* getService();
};

struct Shared {
    Object* object;
    Control* control;
    Shared(const Shared&);
    ~Shared();
    void reset();
};

__forceinline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        control->addRef();
}

struct Guard {
    char reserved[12];
    Guard(Shared);
    ~Guard();
};

void __cdecl releaseObject(Shared, int);

struct S {
    char reserved[0x18];
    Connection first;
    Connection second;
    unsigned long padding;
    Shared object;
    Shared other;
    void f();
};

void S::f()
{
    if (object.object) {
        {
            Guard guard(object);
            Connection* firstConnection = &first;
            Service* service = object.object->getService();
            if (service)
                service->signal.disconnect(firstConnection);

            Object* obj = object.object;
            Connection* secondConnection = &second;
            if (obj->provider)
                obj->provider->signal.disconnect(secondConnection);
        }
        other.reset();
        Object* obj = object.object;
        (void)obj;
        releaseObject(object, 1);
        object.reset();
    }
}
