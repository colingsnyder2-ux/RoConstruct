// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 005b63c0  unit: RBX::PartTool  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b63c0
//
// 005b63c0  6aff                 push -1
// 005b63c2  6868917d00           push 0x7d9168
// 005b63c7  64a100000000         mov eax, dword ptr fs:[0]
// 005b63cd  50                   push eax
// 005b63ce  64892500000000       mov dword ptr fs:[0], esp
// 005b63d5  83ec08               sub esp, 8
// 005b63d8  8b442418             mov eax, dword ptr [esp + 0x18]
// 005b63dc  56                   push esi
// 005b63dd  68e0be9700           push 0x97bee0
// 005b63e2  6a00                 push 0
// 005b63e4  50                   push eax
// 005b63e5  8bf1                 mov esi, ecx
// 005b63e7  e8a4f90500           call 0x615d90
// 005b63ec  50                   push eax
// 005b63ed  8d4c2408             lea ecx, [esp + 8]
// 005b63f1  51                   push ecx
// 005b63f2  e849260600           call 0x618a40
// 005b63f7  83c408               add esp, 8
// 005b63fa  8b10                 mov edx, dword ptr [eax]
// 005b63fc  83c004               add eax, 4
// 005b63ff  50                   push eax
// 005b6400  8d4e20               lea ecx, [esi + 0x20]
// 005b6403  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005b640b  89561c               mov dword ptr [esi + 0x1c], edx
// 005b640e  e89dc1e4ff           call 0x4025b0
// 005b6413  8b742408             mov esi, dword ptr [esp + 8]
// 005b6417  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005b641f  85f6                 test esi, esi
// 005b6421  742a                 je 0x5b644d
// 005b6423  8d4604               lea eax, [esi + 4]
// 005b6426  83c9ff               or ecx, 0xffffffff
// 005b6429  f00fc108             lock xadd dword ptr [eax], ecx
// 005b642d  751e                 jne 0x5b644d
// 005b642f  8b16                 mov edx, dword ptr [esi]
// 005b6431  8b4204               mov eax, dword ptr [edx + 4]
// 005b6434  8bce                 mov ecx, esi
// 005b6436  ffd0                 call eax
// 005b6438  8d4e08               lea ecx, [esi + 8]
// 005b643b  83caff               or edx, 0xffffffff
// 005b643e  f00fc111             lock xadd dword ptr [ecx], edx
// 005b6442  7509                 jne 0x5b644d
// 005b6444  8b06                 mov eax, dword ptr [esi]
// 005b6446  8b5008               mov edx, dword ptr [eax + 8]
// 005b6449  8bce                 mov ecx, esi
// 005b644b  ffd2                 call edx
// 005b644d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005b6451  5e                   pop esi
// 005b6452  64890d00000000       mov dword ptr fs:[0], ecx
// 005b6459  83c414               add esp, 0x14
// 005b645c  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Reference {
    Control* pointer;
    Reference& operator=(const Reference&);
};

struct Shared {
    void* object;
    Reference reference;

    Shared& operator=(const Shared& other) {
        object = other.object;
        reference = other.reference;
        return *this;
    }

    ~Shared() {
        if (reference.pointer) {
            Control* p = reference.pointer;
            if (_InterlockedDecrement(&p->strong) == 0) {
                p->dispose();
                if (_InterlockedDecrement(&p->weak) == 0)
                    p->destroy();
            }
        }
    }
};

extern const char typeTag;
extern void* __stdcall resolve(void*, int, const void*);
extern Shared __cdecl makeShared(void*);

struct PartTool {
    char padding[28];
    Shared value;
    void set(void*);
};

void PartTool::set(void* argument) {
    value = makeShared(resolve(argument, 0, &typeTag));
}
