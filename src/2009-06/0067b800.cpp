// from server: 100% by EspClaude
// from server: 97% by EspClaude
// roc 2009-06 0067b800  unit: RBX::VRotate::?$FactoryProduct  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0067b800
//
// 0067b800  83ec08               sub esp, 8
// 0067b803  56                   push esi
// 0067b804  57                   push edi
// 0067b805  8d442408             lea eax, [esp + 8]
// 0067b809  50                   push eax
// 0067b80a  81c19c000000         add ecx, 0x9c
// 0067b810  e81be3f7ff           call 0x5f9b30
// 0067b815  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0067b819  8b38                 mov edi, dword ptr [eax]
// 0067b81b  85f6                 test esi, esi
// 0067b81d  742a                 je 0x67b849
// 0067b81f  8d4e04               lea ecx, [esi + 4]
// 0067b822  83caff               or edx, 0xffffffff
// 0067b825  f00fc111             lock xadd dword ptr [ecx], edx
// 0067b829  751e                 jne 0x67b849
// 0067b82b  8b06                 mov eax, dword ptr [esi]
// 0067b82d  8b5004               mov edx, dword ptr [eax + 4]
// 0067b830  8bce                 mov ecx, esi
// 0067b832  ffd2                 call edx
// 0067b834  8d4608               lea eax, [esi + 8]
// 0067b837  83c9ff               or ecx, 0xffffffff
// 0067b83a  f00fc108             lock xadd dword ptr [eax], ecx
// 0067b83e  7509                 jne 0x67b849
// 0067b840  8b16                 mov edx, dword ptr [esi]
// 0067b842  8b4208               mov eax, dword ptr [edx + 8]
// 0067b845  8bce                 mov ecx, esi
// 0067b847  ffd0                 call eax
// 0067b849  8bc7                 mov eax, edi
// 0067b84b  5f                   pop edi
// 0067b84c  5e                   pop esi
// 0067b84d  83c408               add esp, 8
// 0067b850  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 005e2a10  unit: RBX::RotatePJoint  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e2a10
//
// 005e2a10  83ec08               sub esp, 8
// 005e2a13  56                   push esi
// 005e2a14  57                   push edi
// 005e2a15  8d442408             lea eax, [esp + 8]
// 005e2a19  50                   push eax
// 005e2a1a  81c140010000         add ecx, 0x140
// 005e2a20  e8db80feff           call 0x5cab00
// 005e2a25  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005e2a29  8b38                 mov edi, dword ptr [eax]
// 005e2a2b  85f6                 test esi, esi
// 005e2a2d  742a                 je 0x5e2a59
// 005e2a2f  8d4e04               lea ecx, [esi + 4]
// 005e2a32  83caff               or edx, 0xffffffff
// 005e2a35  f00fc111             lock xadd dword ptr [ecx], edx
// 005e2a39  751e                 jne 0x5e2a59
// 005e2a3b  8b06                 mov eax, dword ptr [esi]
// 005e2a3d  8b5004               mov edx, dword ptr [eax + 4]
// 005e2a40  8bce                 mov ecx, esi
// 005e2a42  ffd2                 call edx
// 005e2a44  8d4608               lea eax, [esi + 8]
// 005e2a47  83c9ff               or ecx, 0xffffffff
// 005e2a4a  f00fc108             lock xadd dword ptr [eax], ecx
// 005e2a4e  7509                 jne 0x5e2a59
// 005e2a50  8b16                 mov edx, dword ptr [esi]
// 005e2a52  8b4208               mov eax, dword ptr [edx + 8]
// 005e2a55  8bce                 mov ecx, esi
// 005e2a57  ffd0                 call eax
// 005e2a59  8bc7                 mov eax, edi
// 005e2a5b  5f                   pop edi
// 005e2a5c  5e                   pop esi
// 005e2a5d  83c408               add esp, 8
// 005e2a60  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();

    volatile long strongCount;
    volatile long weakCount;
};

struct Shared {
    void* ptr;
    Control* control;

    ~Shared() {
        Control* p = control;
        if (p) {
            if (_InterlockedDecrement(&p->strongCount) == 0) {
                p->dispose();
                if (_InterlockedDecrement(&p->weakCount) == 0)
                    p->destroy();
            }
        }
    }
};

struct Factory {
    Shared get();
};

struct RotatePJoint {
    char padding[0x9c];
    Factory factory;

    void* get();
};

void* RotatePJoint::get() {
    return factory.get().ptr;
}
