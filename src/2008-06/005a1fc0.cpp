// from server: 100% by colin
// from server: 95% by king_originala
// roc 2008-06 005a1fc0  unit: RBX::Workspace  size: 276 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a1fc0
//
// 005a1fc0  64a100000000         mov eax, dword ptr fs:[0]
// 005a1fc6  6aff                 push -1
// 005a1fc8  683beb7d00           push 0x7deb3b
// 005a1fcd  50                   push eax
// 005a1fce  64892500000000       mov dword ptr fs:[0], esp
// 005a1fd5  56                   push esi
// 005a1fd6  8b742414             mov esi, dword ptr [esp + 0x14]
// 005a1fda  57                   push edi
// 005a1fdb  8bf9                 mov edi, ecx
// 005a1fdd  85f6                 test esi, esi
// 005a1fdf  757a                 jne 0x5a205b
// 005a1fe1  8b8fb4030000         mov ecx, dword ptr [edi + 0x3b4]
// 005a1fe7  85c9                 test ecx, ecx
// 005a1fe9  740d                 je 0x5a1ff8
// 005a1feb  8b01                 mov eax, dword ptr [ecx]
// 005a1fed  8b5034               mov edx, dword ptr [eax + 0x34]
// 005a1ff0  ffd2                 call edx
// 005a1ff2  8bf0                 mov esi, eax
// 005a1ff4  85f6                 test esi, esi
// 005a1ff6  7563                 jne 0x5a205b
// 005a1ff8  57                   push edi
// 005a1ff9  e8828cefff           call 0x49ac80
// 005a1ffe  83c404               add esp, 4
// 005a2001  85c0                 test eax, eax
// 005a2003  754b                 jne 0x5a2050
// 005a2005  6a20                 push 0x20
// 005a2007  e814e90f00           call 0x6a0920
// 005a200c  8bf0                 mov esi, eax
// 005a200e  83c404               add esp, 4
// 005a2011  89742418             mov dword ptr [esp + 0x18], esi
// 005a2015  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005a201d  85f6                 test esi, esi
// 005a201f  7423                 je 0x5a2044
// 005a2021  57                   push edi
// 005a2022  8bce                 mov ecx, esi
// 005a2024  e8c7390700           call 0x6159f0
// 005a2029  c6461c00             mov byte ptr [esi + 0x1c], 0
// 005a202d  c706a4368300         mov dword ptr [esi], 0x8336a4
// 005a2033  c7460488368300       mov dword ptr [esi + 4], 0x833688
// 005a203a  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005a2042  eb17                 jmp 0x5a205b
// 005a2044  33f6                 xor esi, esi
// 005a2046  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005a204e  eb0b                 jmp 0x5a205b
// 005a2050  57                   push edi
// 005a2051  e82ae2ffff           call 0x5a0280
// 005a2056  83c404               add esp, 4
// 005a2059  8bf0                 mov esi, eax
// 005a205b  3bb7b0030000         cmp esi, dword ptr [edi + 0x3b0]
// 005a2061  745e                 je 0x5a20c1
// 005a2063  8b8fb0030000         mov ecx, dword ptr [edi + 0x3b0]
// 005a2069  3bf1                 cmp esi, ecx
// 005a206b  740d                 je 0x5a207a
// 005a206d  85c9                 test ecx, ecx
// 005a206f  7409                 je 0x5a207a
// 005a2071  8b01                 mov eax, dword ptr [ecx]
// 005a2073  8b5030               mov edx, dword ptr [eax + 0x30]
// 005a2076  6a01                 push 1
// 005a2078  ffd2                 call edx
// 005a207a  89b7b0030000         mov dword ptr [edi + 0x3b0], esi
// 005a2080  8b06                 mov eax, dword ptr [esi]
// 005a2082  8b5034               mov edx, dword ptr [eax + 0x34]
// 005a2085  8bce                 mov ecx, esi
// 005a2087  ffd2                 call edx
// 005a2089  8bf0                 mov esi, eax
// 005a208b  85f6                 test esi, esi
// 005a208d  741d                 je 0x5a20ac
// 005a208f  8b8fb4030000         mov ecx, dword ptr [edi + 0x3b4]
// 005a2095  3bf1                 cmp esi, ecx
// 005a2097  740d                 je 0x5a20a6
// 005a2099  85c9                 test ecx, ecx
// 005a209b  7409                 je 0x5a20a6
// 005a209d  8b01                 mov eax, dword ptr [ecx]
// 005a209f  8b5030               mov edx, dword ptr [eax + 0x30]
// 005a20a2  6a01                 push 1
// 005a20a4  ffd2                 call edx
// 005a20a6  89b7b4030000         mov dword ptr [edi + 0x3b4], esi
// 005a20ac  c644241800           mov byte ptr [esp + 0x18], 0
// 005a20b1  8b442418             mov eax, dword ptr [esp + 0x18]
// 005a20b5  50                   push eax
// 005a20b6  8d8f64030000         lea ecx, [edi + 0x364]
// 005a20bc  e86ff4ffff           call 0x5a1530
// 005a20c1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005a20c5  5f                   pop edi
// 005a20c6  64890d00000000       mov dword ptr fs:[0], ecx
// 005a20cd  5e                   pop esi
// 005a20ce  83c40c               add esp, 0xc
// 005a20d1  c20400               ret 4

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual ~Object();
    virtual Object* get();
};

struct Flag {
    unsigned char value;
};

struct Signal {
    void notify(Flag);
};

struct RawFirst {
    RawFirst(void* owner);
    virtual void first();
};
struct __declspec(novtable) RawSecond {
    virtual void second();
    unsigned char storage[20];
    unsigned char flag;
    __forceinline RawSecond() : flag(0) {}
};
struct RawObject : RawFirst, RawSecond {
    __forceinline RawObject(void* owner) : RawFirst(owner) {}
    virtual void first();
    virtual void second();
};
#include <intrin.h>
void* __cdecl func(void*);
Object* __cdecl create(void*);

struct Workspace {
    unsigned char padding[0x364];
    Signal signal;
    unsigned char remaining[0x4b];
    Object* current;
    Object* secondary;

    void set(Object*);
};

void Workspace::set(Object* object)
{
    if (!object) {
        if (secondary)
            object = secondary->get();

        if (!object) {
            if (!func(this))
                object = reinterpret_cast<Object*>(new RawObject(this));
            else
                object = create(this);
        }
    }

    if (object != current) {
        _ReadWriteBarrier();
        if (object != current) {
            if (current)
                delete current;
        }
        current = object;

        object = object->get();
        if (object) {
            if (object != secondary) {
                if (secondary)
                    delete secondary;
            }
            secondary = object;
        }

        Flag flag;
        flag.value = 0;
        signal.notify(flag);
    }
}
