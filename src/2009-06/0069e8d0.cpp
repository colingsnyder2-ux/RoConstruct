// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005fbf50  unit: RBX::VLocalBackpack::?$FactoryProduct  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fbf50
//
// 005fbf50  6aff                 push -1
// 005fbf52  6868917d00           push 0x7d9168
// 005fbf57  64a100000000         mov eax, dword ptr fs:[0]
// 005fbf5d  50                   push eax
// 005fbf5e  64892500000000       mov dword ptr fs:[0], esp
// 005fbf65  83ec08               sub esp, 8
// 005fbf68  8b442418             mov eax, dword ptr [esp + 0x18]
// 005fbf6c  56                   push esi
// 005fbf6d  8bf1                 mov esi, ecx
// 005fbf6f  50                   push eax
// 005fbf70  8d4c2408             lea ecx, [esp + 8]
// 005fbf74  51                   push ecx
// 005fbf75  e8c6ca0100           call 0x618a40
// 005fbf7a  83c408               add esp, 8
// 005fbf7d  8b10                 mov edx, dword ptr [eax]
// 005fbf7f  83c004               add eax, 4
// 005fbf82  50                   push eax
// 005fbf83  8d8e4c010000         lea ecx, [esi + 0x14c]
// 005fbf89  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005fbf91  899648010000         mov dword ptr [esi + 0x148], edx
// 005fbf97  e81466e0ff           call 0x4025b0
// 005fbf9c  8b742408             mov esi, dword ptr [esp + 8]
// 005fbfa0  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005fbfa8  85f6                 test esi, esi
// 005fbfaa  742a                 je 0x5fbfd6
// 005fbfac  8d4604               lea eax, [esi + 4]
// 005fbfaf  83c9ff               or ecx, 0xffffffff
// 005fbfb2  f00fc108             lock xadd dword ptr [eax], ecx
// 005fbfb6  751e                 jne 0x5fbfd6
// 005fbfb8  8b16                 mov edx, dword ptr [esi]
// 005fbfba  8b4204               mov eax, dword ptr [edx + 4]
// 005fbfbd  8bce                 mov ecx, esi
// 005fbfbf  ffd0                 call eax
// 005fbfc1  8d4e08               lea ecx, [esi + 8]
// 005fbfc4  83caff               or edx, 0xffffffff
// 005fbfc7  f00fc111             lock xadd dword ptr [ecx], edx
// 005fbfcb  7509                 jne 0x5fbfd6
// 005fbfcd  8b06                 mov eax, dword ptr [esi]
// 005fbfcf  8b5008               mov edx, dword ptr [eax + 8]
// 005fbfd2  8bce                 mov ecx, esi
// 005fbfd4  ffd2                 call edx
// 005fbfd6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005fbfda  5e                   pop esi
// 005fbfdb  64890d00000000       mov dword ptr fs:[0], ecx
// 005fbfe2  83c414               add esp, 0x14
// 005fbfe5  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Control::release() {
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct SharedCount {
    Control* control;
    SharedCount& operator=(const SharedCount& other);
    ~SharedCount();
};

inline SharedCount::~SharedCount() {
    if (control)
        control->release();
}

struct SharedValue {
    void* pointer;
    SharedCount count;
    SharedValue& operator=(const SharedValue& other);
};

inline SharedValue& SharedValue::operator=(const SharedValue& other) {
    pointer = other.pointer;
    count = other.count;
    return *this;
}

SharedValue __cdecl makeValue(void* argument);

struct S {
    char padding[0x148];
    SharedValue value;
    void f(void* argument);
};

void S::f(void* argument) {
    value = makeValue(argument);
}
