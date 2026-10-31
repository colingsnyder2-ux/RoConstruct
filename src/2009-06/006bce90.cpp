// from server: 94% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0061bb70  unit: RBX::Lua::LuaArguments  size: 313 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0061bb70
//
// 0061bb70  6aff                 push -1
// 0061bb72  68a0937d00           push 0x7d93a0
// 0061bb77  64a100000000         mov eax, dword ptr fs:[0]
// 0061bb7d  50                   push eax
// 0061bb7e  64892500000000       mov dword ptr fs:[0], esp
// 0061bb85  83ec14               sub esp, 0x14
// 0061bb88  56                   push esi
// 0061bb89  57                   push edi
// 0061bb8a  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0061bb8e  6a01                 push 1
// 0061bb90  57                   push edi
// 0061bb91  e81a0c0000           call 0x61c7b0
// 0061bb96  50                   push eax
// 0061bb97  e8f486f3ff           call 0x554290
// 0061bb9c  50                   push eax
// 0061bb9d  8d44241c             lea eax, [esp + 0x1c]
// 0061bba1  50                   push eax
// 0061bba2  e8e945e0ff           call 0x420190
// 0061bba7  57                   push edi
// 0061bba8  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 0061bbb0  e85b60ffff           call 0x611c10
// 0061bbb5  83c418               add esp, 0x18
// 0061bbb8  83f802               cmp eax, 2
// 0061bbbb  7c5e                 jl 0x61bc1b
// 0061bbbd  6a02                 push 2
// 0061bbbf  8d4c2418             lea ecx, [esp + 0x18]
// 0061bbc3  57                   push edi
// 0061bbc4  51                   push ecx
// 0061bbc5  e8f6eeffff           call 0x61aac0
// 0061bbca  83c40c               add esp, 0xc
// 0061bbcd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0061bbd1  c644242401           mov byte ptr [esp + 0x24], 1
// 0061bbd6  85c0                 test eax, eax
// 0061bbd8  740a                 je 0x61bbe4
// 0061bbda  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0061bbde  50                   push eax
// 0061bbdf  e80cedf3ff           call 0x55a8f0
// 0061bbe4  8b742418             mov esi, dword ptr [esp + 0x18]
// 0061bbe8  c644242400           mov byte ptr [esp + 0x24], 0
// 0061bbed  85f6                 test esi, esi
// 0061bbef  742a                 je 0x61bc1b
// 0061bbf1  8d5604               lea edx, [esi + 4]
// 0061bbf4  83c8ff               or eax, 0xffffffff
// 0061bbf7  f00fc102             lock xadd dword ptr [edx], eax
// 0061bbfb  751e                 jne 0x61bc1b
// 0061bbfd  8b16                 mov edx, dword ptr [esi]
// 0061bbff  8b4204               mov eax, dword ptr [edx + 4]
// 0061bc02  8bce                 mov ecx, esi
// 0061bc04  ffd0                 call eax
// 0061bc06  8d4e08               lea ecx, [esi + 8]
// 0061bc09  83caff               or edx, 0xffffffff
// 0061bc0c  f00fc111             lock xadd dword ptr [ecx], edx
// 0061bc10  7509                 jne 0x61bc1b
// 0061bc12  8b06                 mov eax, dword ptr [esi]
// 0061bc14  8b5008               mov edx, dword ptr [eax + 8]
// 0061bc17  8bce                 mov ecx, esi
// 0061bc19  ffd2                 call edx
// 0061bc1b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0061bc1f  83ec08               sub esp, 8
// 0061bc22  89642410             mov dword ptr [esp + 0x10], esp
// 0061bc26  8bc4                 mov eax, esp
// 0061bc28  85c9                 test ecx, ecx
// 0061bc2a  7405                 je 0x61bc31
// 0061bc2c  83c114               add ecx, 0x14
// 0061bc2f  eb02                 jmp 0x61bc33
// 0061bc31  33c9                 xor ecx, ecx
// 0061bc33  8908                 mov dword ptr [eax], ecx
// 0061bc35  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0061bc39  894804               mov dword ptr [eax + 4], ecx
// 0061bc3c  8b442418             mov eax, dword ptr [esp + 0x18]
// 0061bc40  85c0                 test eax, eax
// 0061bc42  740c                 je 0x61bc50
// 0061bc44  83c004               add eax, 4
// 0061bc47  ba01000000           mov edx, 1
// 0061bc4c  f00fc110             lock xadd dword ptr [eax], edx
// 0061bc50  57                   push edi
// 0061bc51  e8daeaf8ff           call 0x5aa730
// 0061bc56  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0061bc5a  83c40c               add esp, 0xc
// 0061bc5d  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0061bc65  85f6                 test esi, esi
// 0061bc67  742a                 je 0x61bc93
// 0061bc69  8d4604               lea eax, [esi + 4]
// 0061bc6c  83c9ff               or ecx, 0xffffffff
// 0061bc6f  f00fc108             lock xadd dword ptr [eax], ecx
// 0061bc73  751e                 jne 0x61bc93
// 0061bc75  8b16                 mov edx, dword ptr [esi]
// 0061bc77  8b4204               mov eax, dword ptr [edx + 4]
// 0061bc7a  8bce                 mov ecx, esi
// 0061bc7c  ffd0                 call eax
// 0061bc7e  8d4e08               lea ecx, [esi + 8]
// 0061bc81  83caff               or edx, 0xffffffff
// 0061bc84  f00fc111             lock xadd dword ptr [ecx], edx
// 0061bc88  7509                 jne 0x61bc93
// 0061bc8a  8b06                 mov eax, dword ptr [esi]
// 0061bc8c  8b5008               mov edx, dword ptr [eax + 8]
// 0061bc8f  8bce                 mov ecx, esi
// 0061bc91  ffd2                 call edx
// 0061bc93  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0061bc97  5f                   pop edi
// 0061bc98  b801000000           mov eax, 1
// 0061bc9d  64890d00000000       mov dword ptr fs:[0], ecx
// 0061bca4  5e                   pop esi
// 0061bca5  83c420               add esp, 0x20
// 0061bca8  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedIncrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
    void release();
};

void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Object {
    char padding[20];
    void setParent(Object*);
};

struct Shared {
    Object* pointer;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

Shared::~Shared()
{
    if (control)
        control->release();
}

struct Alias {
    void* pointer;
    Control* control;
    Alias(const Shared&);
    Alias(const Alias&);
    ~Alias();
};

Alias::Alias(const Shared& other)
    : pointer(other.pointer ? other.pointer->padding + 20 : 0),
      control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

Alias::Alias(const Alias& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

Alias::~Alias()
{
    if (control)
        control->release();
}

extern "C" void* __cdecl getArgument(void*, int);
extern "C" void* __cdecl resolveObject(void*);
extern Shared __cdecl makeShared(void*);
extern "C" int __cdecl argumentCount(void*);
extern Shared __cdecl readShared(void*, int);
extern void __cdecl pushShared(void*, Alias);

int __cdecl function(void* state)
{
    Shared object = makeShared(resolveObject(getArgument(state, 1)));
    if (argumentCount(state) >= 2) {
        Shared parent = readShared(state, 2);
        if (parent.pointer)
            object.pointer->setParent(parent.pointer);
    }
    pushShared(state, Alias(object));
    return 1;
}
