// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00619e50  unit: RBX::DecalTool  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00619e50
//
// 00619e50  6aff                 push -1
// 00619e52  6868917d00           push 0x7d9168
// 00619e57  64a100000000         mov eax, dword ptr fs:[0]
// 00619e5d  50                   push eax
// 00619e5e  64892500000000       mov dword ptr fs:[0], esp
// 00619e65  83ec08               sub esp, 8
// 00619e68  8b542418             mov edx, dword ptr [esp + 0x18]
// 00619e6c  56                   push esi
// 00619e6d  8bf1                 mov esi, ecx
// 00619e6f  8d4628               lea eax, [esi + 0x28]
// 00619e72  50                   push eax
// 00619e73  8d4c2420             lea ecx, [esp + 0x20]
// 00619e77  51                   push ecx
// 00619e78  52                   push edx
// 00619e79  8bce                 mov ecx, esi
// 00619e7b  e890c0ffff           call 0x615f10
// 00619e80  894624               mov dword ptr [esi + 0x24], eax
// 00619e83  f7d8                 neg eax
// 00619e85  1bc0                 sbb eax, eax
// 00619e87  2344241c             and eax, dword ptr [esp + 0x1c]
// 00619e8b  50                   push eax
// 00619e8c  8d442408             lea eax, [esp + 8]
// 00619e90  50                   push eax
// 00619e91  e8aaebffff           call 0x618a40
// 00619e96  83c408               add esp, 8
// 00619e99  8b08                 mov ecx, dword ptr [eax]
// 00619e9b  83c004               add eax, 4
// 00619e9e  894e1c               mov dword ptr [esi + 0x1c], ecx
// 00619ea1  50                   push eax
// 00619ea2  8d4e20               lea ecx, [esi + 0x20]
// 00619ea5  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00619ead  e8fe86deff           call 0x4025b0
// 00619eb2  8b442408             mov eax, dword ptr [esp + 8]
// 00619eb6  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00619ebe  85c0                 test eax, eax
// 00619ec0  742c                 je 0x619eee
// 00619ec2  8bf0                 mov esi, eax
// 00619ec4  83c004               add eax, 4
// 00619ec7  83caff               or edx, 0xffffffff
// 00619eca  f00fc110             lock xadd dword ptr [eax], edx
// 00619ece  751e                 jne 0x619eee
// 00619ed0  8b06                 mov eax, dword ptr [esi]
// 00619ed2  8b5004               mov edx, dword ptr [eax + 4]
// 00619ed5  8bce                 mov ecx, esi
// 00619ed7  ffd2                 call edx
// 00619ed9  8d4608               lea eax, [esi + 8]
// 00619edc  83c9ff               or ecx, 0xffffffff
// 00619edf  f00fc108             lock xadd dword ptr [eax], ecx
// 00619ee3  7509                 jne 0x619eee
// 00619ee5  8b16                 mov edx, dword ptr [esi]
// 00619ee7  8b4208               mov eax, dword ptr [edx + 8]
// 00619eea  8bce                 mov ecx, esi
// 00619eec  ffd0                 call eax
// 00619eee  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00619ef2  5e                   pop esi
// 00619ef3  64890d00000000       mov dword ptr fs:[0], ecx
// 00619efa  83c414               add esp, 0x14
// 00619efd  c20400               ret 4

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
};

struct Count {
    Control* control;
    ~Count();
    Count& operator=(const Count&);
};

inline Count::~Count()
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

struct Pair {
    void* object;
    Count count;
    Pair& operator=(const Pair&);
};

inline Pair& Pair::operator=(const Pair& other)
{
    object = other.object;
    count = other.count;
    return *this;
}

Pair __cdecl makePair(void*);

struct S {
    char padding[0x1c];
    Pair pair;
    void* selected;
    float position[3];

    void* find(void*, void**, float*);
    void f(void*);
};

void S::f(void* input)
{
    selected = find(input, &input, position);
    pair = makePair(selected ? input : 0);
}
