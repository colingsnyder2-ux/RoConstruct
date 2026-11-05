// from server: 100% by user
// from server: 99% by colin
// roc 2008-06 005a1ce0  unit: RBX::Workspace  size: 408 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a1ce0
//
// 005a1ce0  6aff                 push -1
// 005a1ce2  68082a7d00           push 0x7d2a08
// 005a1ce7  64a100000000         mov eax, dword ptr fs:[0]
// 005a1ced  50                   push eax
// 005a1cee  64892500000000       mov dword ptr fs:[0], esp
// 005a1cf5  83ec08               sub esp, 8
// 005a1cf8  56                   push esi
// 005a1cf9  57                   push edi
// 005a1cfa  8b442420             mov eax, dword ptr [esp + 0x20]
// 005a1cfe  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005a1d02  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005a1d0a  3bc7                 cmp eax, edi
// 005a1d0c  0f841b010000         je 0x5a1e2d
// 005a1d12  6a00                 push 0
// 005a1d14  68402a9300           push 0x932a40
// 005a1d19  687c909200           push 0x92907c
// 005a1d1e  6a00                 push 0
// 005a1d20  50                   push eax
// 005a1d21  e8a0fa0f00           call 0x6a17c6
// 005a1d26  8bf0                 mov esi, eax
// 005a1d28  83c414               add esp, 0x14
// 005a1d2b  85f6                 test esi, esi
// 005a1d2d  746f                 je 0x5a1d9e
// 005a1d2f  56                   push esi
// 005a1d30  e8eb7c0300           call 0x5d9a20
// 005a1d35  83c404               add esp, 4
// 005a1d38  85c0                 test eax, eax
// 005a1d3a  7562                 jne 0x5a1d9e
// 005a1d3c  8bce                 mov ecx, esi
// 005a1d3e  e86df9ffff           call 0x5a16b0
// 005a1d43  85c0                 test eax, eax
// 005a1d45  7557                 jne 0x5a1d9e
// 005a1d47  8bce                 mov ecx, esi
// 005a1d49  e802faffff           call 0x5a1750
// 005a1d4e  85c0                 test eax, eax
// 005a1d50  754c                 jne 0x5a1d9e
// 005a1d52  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 005a1d58  50                   push eax
// 005a1d59  8d44240c             lea eax, [esp + 0xc]
// 005a1d5d  50                   push eax
// 005a1d5e  e8dd6c0700           call 0x618a40
// 005a1d63  83c408               add esp, 8
// 005a1d66  6a00                 push 0
// 005a1d68  8bce                 mov ecx, esi
// 005a1d6a  c644241c01           mov byte ptr [esp + 0x1c], 1
// 005a1d6f  e87c8bfbff           call 0x55a8f0
// 005a1d74  57                   push edi
// 005a1d75  83ec08               sub esp, 8
// 005a1d78  8d542414             lea edx, [esp + 0x14]
// 005a1d7c  8bcc                 mov ecx, esp
// 005a1d7e  89642434             mov dword ptr [esp + 0x34], esp
// 005a1d82  52                   push edx
// 005a1d83  e868f9e6ff           call 0x4116f0
// 005a1d88  e853ffffff           call 0x5a1ce0
// 005a1d8d  83c40c               add esp, 0xc
// 005a1d90  8d4c2408             lea ecx, [esp + 8]
// 005a1d94  c644241800           mov byte ptr [esp + 0x18], 0
// 005a1d99  e8c2e80500           call 0x600660
// 005a1d9e  8b442420             mov eax, dword ptr [esp + 0x20]
// 005a1da2  6a00                 push 0
// 005a1da4  6840be9400           push 0x94be40
// 005a1da9  687c909200           push 0x92907c
// 005a1dae  6a00                 push 0
// 005a1db0  50                   push eax
// 005a1db1  e810fa0f00           call 0x6a17c6
// 005a1db6  8bf0                 mov esi, eax
// 005a1db8  83c414               add esp, 0x14
// 005a1dbb  85f6                 test esi, esi
// 005a1dbd  746e                 je 0x5a1e2d
// 005a1dbf  8bce                 mov ecx, esi
// 005a1dc1  e8eaf8ffff           call 0x5a16b0
// 005a1dc6  85c0                 test eax, eax
// 005a1dc8  7563                 jne 0x5a1e2d
// 005a1dca  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 005a1dd0  50                   push eax
// 005a1dd1  8d4c240c             lea ecx, [esp + 0xc]
// 005a1dd5  51                   push ecx
// 005a1dd6  e8656c0700           call 0x618a40
// 005a1ddb  83c408               add esp, 8
// 005a1dde  6a00                 push 0
// 005a1de0  8bce                 mov ecx, esi
// 005a1de2  c644241c02           mov byte ptr [esp + 0x1c], 2
// 005a1de7  e8048bfbff           call 0x55a8f0
// 005a1dec  8b542408             mov edx, dword ptr [esp + 8]
// 005a1df0  57                   push edi
// 005a1df1  83ec08               sub esp, 8
// 005a1df4  8bc4                 mov eax, esp
// 005a1df6  8910                 mov dword ptr [eax], edx
// 005a1df8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005a1dfc  894804               mov dword ptr [eax + 4], ecx
// 005a1dff  8b442418             mov eax, dword ptr [esp + 0x18]
// 005a1e03  89642434             mov dword ptr [esp + 0x34], esp
// 005a1e07  85c0                 test eax, eax
// 005a1e09  740c                 je 0x5a1e17
// 005a1e0b  83c004               add eax, 4
// 005a1e0e  ba01000000           mov edx, 1
// 005a1e13  f00fc110             lock xadd dword ptr [eax], edx
// 005a1e17  e8c4feffff           call 0x5a1ce0
// 005a1e1c  83c40c               add esp, 0xc
// 005a1e1f  8d4c2408             lea ecx, [esp + 8]
// 005a1e23  c644241800           mov byte ptr [esp + 0x18], 0
// 005a1e28  e833e80500           call 0x600660
// 005a1e2d  8b742424             mov esi, dword ptr [esp + 0x24]
// 005a1e31  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 005a1e39  85f6                 test esi, esi
// 005a1e3b  742a                 je 0x5a1e67
// 005a1e3d  8d4604               lea eax, [esi + 4]
// 005a1e40  83c9ff               or ecx, 0xffffffff
// 005a1e43  f00fc108             lock xadd dword ptr [eax], ecx
// 005a1e47  751e                 jne 0x5a1e67
// 005a1e49  8b16                 mov edx, dword ptr [esi]
// 005a1e4b  8b4204               mov eax, dword ptr [edx + 4]
// 005a1e4e  8bce                 mov ecx, esi
// 005a1e50  ffd0                 call eax
// 005a1e52  8d4e08               lea ecx, [esi + 8]
// 005a1e55  83caff               or edx, 0xffffffff
// 005a1e58  f00fc111             lock xadd dword ptr [ecx], edx
// 005a1e5c  7509                 jne 0x5a1e67
// 005a1e5e  8b06                 mov eax, dword ptr [esi]
// 005a1e60  8b5008               mov edx, dword ptr [eax + 8]
// 005a1e63  8bce                 mov ecx, esi
// 005a1e65  ffd2                 call edx
// 005a1e67  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005a1e6b  5f                   pop edi
// 005a1e6c  64890d00000000       mov dword ptr fs:[0], ecx
// 005a1e73  5e                   pop esi
// 005a1e74  83c414               add esp, 0x14
// 005a1e77  c3                   ret 

// from server: 96% by colin
// roc 2008-06 005a1ce0  unit: RBX::Workspace  size: 408 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a1ce0
//
// 005a1ce0  6aff                 push -1
// 005a1ce2  68082a7d00           push 0x7d2a08
// 005a1ce7  64a100000000         mov eax, dword ptr fs:[0]
// 005a1ced  50                   push eax
// 005a1cee  64892500000000       mov dword ptr fs:[0], esp
// 005a1cf5  83ec08               sub esp, 8
// 005a1cf8  56                   push esi
// 005a1cf9  57                   push edi
// 005a1cfa  8b442420             mov eax, dword ptr [esp + 0x20]
// 005a1cfe  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005a1d02  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005a1d0a  3bc7                 cmp eax, edi
// 005a1d0c  0f841b010000         je 0x5a1e2d
// 005a1d12  6a00                 push 0
// 005a1d14  68402a9300           push 0x932a40
// 005a1d19  687c909200           push 0x92907c
// 005a1d1e  6a00                 push 0
// 005a1d20  50                   push eax
// 005a1d21  e8a0fa0f00           call 0x6a17c6
// 005a1d26  8bf0                 mov esi, eax
// 005a1d28  83c414               add esp, 0x14
// 005a1d2b  85f6                 test esi, esi
// 005a1d2d  746f                 je 0x5a1d9e
// 005a1d2f  56                   push esi
// 005a1d30  e8eb7c0300           call 0x5d9a20
// 005a1d35  83c404               add esp, 4
// 005a1d38  85c0                 test eax, eax
// 005a1d3a  7562                 jne 0x5a1d9e
// 005a1d3c  8bce                 mov ecx, esi
// 005a1d3e  e86df9ffff           call 0x5a16b0
// 005a1d43  85c0                 test eax, eax
// 005a1d45  7557                 jne 0x5a1d9e
// 005a1d47  8bce                 mov ecx, esi
// 005a1d49  e802faffff           call 0x5a1750
// 005a1d4e  85c0                 test eax, eax
// 005a1d50  754c                 jne 0x5a1d9e
// 005a1d52  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 005a1d58  50                   push eax
// 005a1d59  8d44240c             lea eax, [esp + 0xc]
// 005a1d5d  50                   push eax
// 005a1d5e  e8dd6c0700           call 0x618a40
// 005a1d63  83c408               add esp, 8
// 005a1d66  6a00                 push 0
// 005a1d68  8bce                 mov ecx, esi
// 005a1d6a  c644241c01           mov byte ptr [esp + 0x1c], 1
// 005a1d6f  e87c8bfbff           call 0x55a8f0
// 005a1d74  57                   push edi
// 005a1d75  83ec08               sub esp, 8
// 005a1d78  8d542414             lea edx, [esp + 0x14]
// 005a1d7c  8bcc                 mov ecx, esp
// 005a1d7e  89642434             mov dword ptr [esp + 0x34], esp
// 005a1d82  52                   push edx
// 005a1d83  e868f9e6ff           call 0x4116f0
// 005a1d88  e853ffffff           call 0x5a1ce0
// 005a1d8d  83c40c               add esp, 0xc
// 005a1d90  8d4c2408             lea ecx, [esp + 8]
// 005a1d94  c644241800           mov byte ptr [esp + 0x18], 0
// 005a1d99  e8c2e80500           call 0x600660
// 005a1d9e  8b442420             mov eax, dword ptr [esp + 0x20]
// 005a1da2  6a00                 push 0
// 005a1da4  6840be9400           push 0x94be40
// 005a1da9  687c909200           push 0x92907c
// 005a1dae  6a00                 push 0
// 005a1db0  50                   push eax
// 005a1db1  e810fa0f00           call 0x6a17c6
// 005a1db6  8bf0                 mov esi, eax
// 005a1db8  83c414               add esp, 0x14
// 005a1dbb  85f6                 test esi, esi
// 005a1dbd  746e                 je 0x5a1e2d
// 005a1dbf  8bce                 mov ecx, esi
// 005a1dc1  e8eaf8ffff           call 0x5a16b0
// 005a1dc6  85c0                 test eax, eax
// 005a1dc8  7563                 jne 0x5a1e2d
// 005a1dca  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 005a1dd0  50                   push eax
// 005a1dd1  8d4c240c             lea ecx, [esp + 0xc]
// 005a1dd5  51                   push ecx
// 005a1dd6  e8656c0700           call 0x618a40
// 005a1ddb  83c408               add esp, 8
// 005a1dde  6a00                 push 0
// 005a1de0  8bce                 mov ecx, esi
// 005a1de2  c644241c02           mov byte ptr [esp + 0x1c], 2
// 005a1de7  e8048bfbff           call 0x55a8f0
// 005a1dec  8b542408             mov edx, dword ptr [esp + 8]
// 005a1df0  57                   push edi
// 005a1df1  83ec08               sub esp, 8
// 005a1df4  8bc4                 mov eax, esp
// 005a1df6  8910                 mov dword ptr [eax], edx
// 005a1df8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005a1dfc  894804               mov dword ptr [eax + 4], ecx
// 005a1dff  8b442418             mov eax, dword ptr [esp + 0x18]
// 005a1e03  89642434             mov dword ptr [esp + 0x34], esp
// 005a1e07  85c0                 test eax, eax
// 005a1e09  740c                 je 0x5a1e17
// 005a1e0b  83c004               add eax, 4
// 005a1e0e  ba01000000           mov edx, 1
// 005a1e13  f00fc110             lock xadd dword ptr [eax], edx
// 005a1e17  e8c4feffff           call 0x5a1ce0
// 005a1e1c  83c40c               add esp, 0xc
// 005a1e1f  8d4c2408             lea ecx, [esp + 8]
// 005a1e23  c644241800           mov byte ptr [esp + 0x18], 0
// 005a1e28  e833e80500           call 0x600660
// 005a1e2d  8b742424             mov esi, dword ptr [esp + 0x24]
// 005a1e31  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 005a1e39  85f6                 test esi, esi
// 005a1e3b  742a                 je 0x5a1e67
// 005a1e3d  8d4604               lea eax, [esi + 4]
// 005a1e40  83c9ff               or ecx, 0xffffffff
// 005a1e43  f00fc108             lock xadd dword ptr [eax], ecx
// 005a1e47  751e                 jne 0x5a1e67
// 005a1e49  8b16                 mov edx, dword ptr [esi]
// 005a1e4b  8b4204               mov eax, dword ptr [edx + 4]
// 005a1e4e  8bce                 mov ecx, esi
// 005a1e50  ffd0                 call eax
// 005a1e52  8d4e08               lea ecx, [esi + 8]
// 005a1e55  83caff               or edx, 0xffffffff
// 005a1e58  f00fc111             lock xadd dword ptr [ecx], edx
// 005a1e5c  7509                 jne 0x5a1e67
// 005a1e5e  8b06                 mov eax, dword ptr [esi]
// 005a1e60  8b5008               mov edx, dword ptr [eax + 8]
// 005a1e63  8bce                 mov ecx, esi
// 005a1e65  ffd2                 call edx
// 005a1e67  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005a1e6b  5f                   pop edi
// 005a1e6c  64890d00000000       mov dword ptr fs:[0], ecx
// 005a1e73  5e                   pop esi
// 005a1e74  83c414               add esp, 0x14
// 005a1e77  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern char instance_type;
extern char flag_type;
extern char model_type;

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

struct Control {
    virtual void reserved() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Object {
    char padding[0x104];
    void* parent;
    int test1();
    int test2();
    void detach(int);
};

extern int __cdecl excluded(Object*);

struct Parent {
    Object* object;
    Control* control;
    ~Parent();
};

extern Parent __cdecl acquire(void*);

struct Shared {
    Object* object;
    Control* control;

    Shared(const Parent&);
    Shared(const Shared& other)
        : object(other.object), control(other.control)
    {
        if (control)
            _InterlockedIncrement(&control->strong);
    }

    ~Shared()
    {
        Control* p = control;
        if (p) {
            if (_InterlockedDecrement(&p->strong) == 0) {
                p->dispose();
                if (_InterlockedDecrement(&p->weak) == 0)
                    p->destroy();
            }
        }
    }
};

void __cdecl process(Shared value, Object* stop)
{
    if (value.object != stop) {
        Object* p = static_cast<Object*>(
            __RTDynamicCast(value.object, 0, &instance_type, &flag_type, 0));

        if (p && !excluded(p) && !p->test1() && !p->test2()) {
            void* parentCopy = p->parent;
            Parent parent = acquire(parentCopy);
            p->detach(0);
            process(parent, stop);
        }

        p = static_cast<Object*>(
            __RTDynamicCast(value.object, 0, &instance_type, &model_type, 0));

        if (p && !p->test1()) {
            void* parentCopy = p->parent;
            Parent parent = acquire(parentCopy);
            p->detach(0);
            process(reinterpret_cast<const Shared&>(parent), stop);
        }
    }
}
