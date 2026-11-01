// from server: 100% by colin
// from server: 98% by colin
// roc 2008-06 005e2cd0  unit: RBX::JointInstance  size: 316 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e2cd0
//
// 005e2cd0  6aff                 push -1
// 005e2cd2  6868917d00           push 0x7d9168
// 005e2cd7  64a100000000         mov eax, dword ptr fs:[0]
// 005e2cdd  50                   push eax
// 005e2cde  64892500000000       mov dword ptr fs:[0], esp
// 005e2ce5  83ec14               sub esp, 0x14
// 005e2ce8  8b442424             mov eax, dword ptr [esp + 0x24]
// 005e2cec  53                   push ebx
// 005e2ced  55                   push ebp
// 005e2cee  56                   push esi
// 005e2cef  894c240c             mov dword ptr [esp + 0xc], ecx
// 005e2cf3  8db4c140010000       lea esi, [ecx + eax*8 + 0x140]
// 005e2cfa  57                   push edi
// 005e2cfb  8d4c2414             lea ecx, [esp + 0x14]
// 005e2cff  51                   push ecx
// 005e2d00  8bce                 mov ecx, esi
// 005e2d02  e8f97dfeff           call 0x5cab00
// 005e2d07  8b00                 mov eax, dword ptr [eax]
// 005e2d09  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 005e2d0d  3bc5                 cmp eax, ebp
// 005e2d0f  8b442418             mov eax, dword ptr [esp + 0x18]
// 005e2d13  0f95c3               setne bl
// 005e2d16  85c0                 test eax, eax
// 005e2d18  742c                 je 0x5e2d46
// 005e2d1a  8bf8                 mov edi, eax
// 005e2d1c  83c004               add eax, 4
// 005e2d1f  83caff               or edx, 0xffffffff
// 005e2d22  f00fc110             lock xadd dword ptr [eax], edx
// 005e2d26  751e                 jne 0x5e2d46
// 005e2d28  8b07                 mov eax, dword ptr [edi]
// 005e2d2a  8b5004               mov edx, dword ptr [eax + 4]
// 005e2d2d  8bcf                 mov ecx, edi
// 005e2d2f  ffd2                 call edx
// 005e2d31  8d4708               lea eax, [edi + 8]
// 005e2d34  83c9ff               or ecx, 0xffffffff
// 005e2d37  f00fc108             lock xadd dword ptr [eax], ecx
// 005e2d3b  7509                 jne 0x5e2d46
// 005e2d3d  8b17                 mov edx, dword ptr [edi]
// 005e2d3f  8b4208               mov eax, dword ptr [edx + 8]
// 005e2d42  8bcf                 mov ecx, edi
// 005e2d44  ffd0                 call eax
// 005e2d46  84db                 test bl, bl
// 005e2d48  0f84a9000000         je 0x5e2df7
// 005e2d4e  8d4c241c             lea ecx, [esp + 0x1c]
// 005e2d52  55                   push ebp
// 005e2d53  51                   push ecx
// 005e2d54  e8e75c0300           call 0x618a40
// 005e2d59  83c408               add esp, 8
// 005e2d5c  8b10                 mov edx, dword ptr [eax]
// 005e2d5e  8916                 mov dword ptr [esi], edx
// 005e2d60  8b7804               mov edi, dword ptr [eax + 4]
// 005e2d63  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005e2d6b  85ff                 test edi, edi
// 005e2d6d  740c                 je 0x5e2d7b
// 005e2d6f  8d4708               lea eax, [edi + 8]
// 005e2d72  b901000000           mov ecx, 1
// 005e2d77  f00fc108             lock xadd dword ptr [eax], ecx
// 005e2d7b  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e2d7e  85c9                 test ecx, ecx
// 005e2d80  7413                 je 0x5e2d95
// 005e2d82  8d5108               lea edx, [ecx + 8]
// 005e2d85  83c8ff               or eax, 0xffffffff
// 005e2d88  f00fc102             lock xadd dword ptr [edx], eax
// 005e2d8c  7507                 jne 0x5e2d95
// 005e2d8e  8b11                 mov edx, dword ptr [ecx]
// 005e2d90  8b4208               mov eax, dword ptr [edx + 8]
// 005e2d93  ffd0                 call eax
// 005e2d95  897e04               mov dword ptr [esi + 4], edi
// 005e2d98  8b742420             mov esi, dword ptr [esp + 0x20]
// 005e2d9c  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 005e2da4  85f6                 test esi, esi
// 005e2da6  742a                 je 0x5e2dd2
// 005e2da8  8d4e04               lea ecx, [esi + 4]
// 005e2dab  83caff               or edx, 0xffffffff
// 005e2dae  f00fc111             lock xadd dword ptr [ecx], edx
// 005e2db2  751e                 jne 0x5e2dd2
// 005e2db4  8b06                 mov eax, dword ptr [esi]
// 005e2db6  8b5004               mov edx, dword ptr [eax + 4]
// 005e2db9  8bce                 mov ecx, esi
// 005e2dbb  ffd2                 call edx
// 005e2dbd  8d4608               lea eax, [esi + 8]
// 005e2dc0  83c9ff               or ecx, 0xffffffff
// 005e2dc3  f00fc108             lock xadd dword ptr [eax], ecx
// 005e2dc7  7509                 jne 0x5e2dd2
// 005e2dc9  8b16                 mov edx, dword ptr [esi]
// 005e2dcb  8b4208               mov eax, dword ptr [edx + 8]
// 005e2dce  8bce                 mov ecx, esi
// 005e2dd0  ffd0                 call eax
// 005e2dd2  85ed                 test ebp, ebp
// 005e2dd4  7408                 je 0x5e2dde
// 005e2dd6  8d8528020000         lea eax, [ebp + 0x228]
// 005e2ddc  eb02                 jmp 0x5e2de0
// 005e2dde  33c0                 xor eax, eax
// 005e2de0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005e2de4  8b8950010000         mov ecx, dword ptr [ecx + 0x150]
// 005e2dea  8b11                 mov edx, dword ptr [ecx]
// 005e2dec  8b5210               mov edx, dword ptr [edx + 0x10]
// 005e2def  50                   push eax
// 005e2df0  8b442438             mov eax, dword ptr [esp + 0x38]
// 005e2df4  50                   push eax
// 005e2df5  ffd2                 call edx
// 005e2df7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005e2dfb  5f                   pop edi
// 005e2dfc  5e                   pop esi
// 005e2dfd  5d                   pop ebp
// 005e2dfe  5b                   pop ebx
// 005e2dff  64890d00000000       mov dword ptr fs:[0], ecx
// 005e2e06  83c420               add esp, 0x20
// 005e2e09  c20800               ret 8

// from server: 84% by king_originala
// roc 2008-06 005e2cd0  unit: RBX::JointInstance  size: 316 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e2cd0
//
// 005e2cd0  6aff                 push -1
// 005e2cd2  6868917d00           push 0x7d9168
// 005e2cd7  64a100000000         mov eax, dword ptr fs:[0]
// 005e2cdd  50                   push eax
// 005e2cde  64892500000000       mov dword ptr fs:[0], esp
// 005e2ce5  83ec14               sub esp, 0x14
// 005e2ce8  8b442424             mov eax, dword ptr [esp + 0x24]
// 005e2cec  53                   push ebx
// 005e2ced  55                   push ebp
// 005e2cee  56                   push esi
// 005e2cef  894c240c             mov dword ptr [esp + 0xc], ecx
// 005e2cf3  8db4c140010000       lea esi, [ecx + eax*8 + 0x140]
// 005e2cfa  57                   push edi
// 005e2cfb  8d4c2414             lea ecx, [esp + 0x14]
// 005e2cff  51                   push ecx
// 005e2d00  8bce                 mov ecx, esi
// 005e2d02  e8f97dfeff           call 0x5cab00
// 005e2d07  8b00                 mov eax, dword ptr [eax]
// 005e2d09  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 005e2d0d  3bc5                 cmp eax, ebp
// 005e2d0f  8b442418             mov eax, dword ptr [esp + 0x18]
// 005e2d13  0f95c3               setne bl
// 005e2d16  85c0                 test eax, eax
// 005e2d18  742c                 je 0x5e2d46
// 005e2d1a  8bf8                 mov edi, eax
// 005e2d1c  83c004               add eax, 4
// 005e2d1f  83caff               or edx, 0xffffffff
// 005e2d22  f00fc110             lock xadd dword ptr [eax], edx
// 005e2d26  751e                 jne 0x5e2d46
// 005e2d28  8b07                 mov eax, dword ptr [edi]
// 005e2d2a  8b5004               mov edx, dword ptr [eax + 4]
// 005e2d2d  8bcf                 mov ecx, edi
// 005e2d2f  ffd2                 call edx
// 005e2d31  8d4708               lea eax, [edi + 8]
// 005e2d34  83c9ff               or ecx, 0xffffffff
// 005e2d37  f00fc108             lock xadd dword ptr [eax], ecx
// 005e2d3b  7509                 jne 0x5e2d46
// 005e2d3d  8b17                 mov edx, dword ptr [edi]
// 005e2d3f  8b4208               mov eax, dword ptr [edx + 8]
// 005e2d42  8bcf                 mov ecx, edi
// 005e2d44  ffd0                 call eax
// 005e2d46  84db                 test bl, bl
// 005e2d48  0f84a9000000         je 0x5e2df7
// 005e2d4e  8d4c241c             lea ecx, [esp + 0x1c]
// 005e2d52  55                   push ebp
// 005e2d53  51                   push ecx
// 005e2d54  e8e75c0300           call 0x618a40
// 005e2d59  83c408               add esp, 8
// 005e2d5c  8b10                 mov edx, dword ptr [eax]
// 005e2d5e  8916                 mov dword ptr [esi], edx
// 005e2d60  8b7804               mov edi, dword ptr [eax + 4]
// 005e2d63  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005e2d6b  85ff                 test edi, edi
// 005e2d6d  740c                 je 0x5e2d7b
// 005e2d6f  8d4708               lea eax, [edi + 8]
// 005e2d72  b901000000           mov ecx, 1
// 005e2d77  f00fc108             lock xadd dword ptr [eax], ecx
// 005e2d7b  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e2d7e  85c9                 test ecx, ecx
// 005e2d80  7413                 je 0x5e2d95
// 005e2d82  8d5108               lea edx, [ecx + 8]
// 005e2d85  83c8ff               or eax, 0xffffffff
// 005e2d88  f00fc102             lock xadd dword ptr [edx], eax
// 005e2d8c  7507                 jne 0x5e2d95
// 005e2d8e  8b11                 mov edx, dword ptr [ecx]
// 005e2d90  8b4208               mov eax, dword ptr [edx + 8]
// 005e2d93  ffd0                 call eax
// 005e2d95  897e04               mov dword ptr [esi + 4], edi
// 005e2d98  8b742420             mov esi, dword ptr [esp + 0x20]
// 005e2d9c  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 005e2da4  85f6                 test esi, esi
// 005e2da6  742a                 je 0x5e2dd2
// 005e2da8  8d4e04               lea ecx, [esi + 4]
// 005e2dab  83caff               or edx, 0xffffffff
// 005e2dae  f00fc111             lock xadd dword ptr [ecx], edx
// 005e2db2  751e                 jne 0x5e2dd2
// 005e2db4  8b06                 mov eax, dword ptr [esi]
// 005e2db6  8b5004               mov edx, dword ptr [eax + 4]
// 005e2db9  8bce                 mov ecx, esi
// 005e2dbb  ffd2                 call edx
// 005e2dbd  8d4608               lea eax, [esi + 8]
// 005e2dc0  83c9ff               or ecx, 0xffffffff
// 005e2dc3  f00fc108             lock xadd dword ptr [eax], ecx
// 005e2dc7  7509                 jne 0x5e2dd2
// 005e2dc9  8b16                 mov edx, dword ptr [esi]
// 005e2dcb  8b4208               mov eax, dword ptr [edx + 8]
// 005e2dce  8bce                 mov ecx, esi
// 005e2dd0  ffd0                 call eax
// 005e2dd2  85ed                 test ebp, ebp
// 005e2dd4  7408                 je 0x5e2dde
// 005e2dd6  8d8528020000         lea eax, [ebp + 0x228]
// 005e2ddc  eb02                 jmp 0x5e2de0
// 005e2dde  33c0                 xor eax, eax
// 005e2de0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005e2de4  8b8950010000         mov ecx, dword ptr [ecx + 0x150]
// 005e2dea  8b11                 mov edx, dword ptr [ecx]
// 005e2dec  8b5210               mov edx, dword ptr [edx + 0x10]
// 005e2def  50                   push eax
// 005e2df0  8b442438             mov eax, dword ptr [esp + 0x38]
// 005e2df4  50                   push eax
// 005e2df5  ffd2                 call edx
// 005e2df7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005e2dfb  5f                   pop edi
// 005e2dfc  5e                   pop esi
// 005e2dfd  5d                   pop ebp
// 005e2dfe  5b                   pop ebx
// 005e2dff  64890d00000000       mov dword ptr fs:[0], ecx
// 005e2e06  83c420               add esp, 0x20
// 005e2e09  c20800               ret 8

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Part {
    char padding[0x228];
};

struct Shared {
    Part* ptr;
    Control* control;
    ~Shared();
    Part* get() const { return ptr; }
};

__forceinline Shared::~Shared()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Weak {
    Part* ptr;
    Control* control;
    Shared lock();
    Weak& operator=(const Shared&);
};

__forceinline Weak& Weak::operator=(const Shared& value)
{
    ptr = value.ptr;
    Control* incoming = value.control;
    if (incoming)
        _InterlockedIncrement(&incoming->weak);
    Control* old = control;
    if (old && _InterlockedDecrement(&old->weak) == 0)
        old->destroy();
    control = incoming;
    return *this;
}

Shared __cdecl makeShared(Part*);

struct Joint {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void setPart(int, void*) = 0;
};

struct S {
    char padding[0x140];
    Weak parts[2];
    Joint* joint;
    void f(int, Part*);
};

void S::f(int index, Part* part)
{
    Weak& target = parts[index];
    if (target.lock().get() != part) {
        target = makeShared(part);
        joint->setPart(index, part ? part->padding + 0x228 : 0);
    }
}
