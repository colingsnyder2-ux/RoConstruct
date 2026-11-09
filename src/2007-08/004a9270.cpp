// from server: 100% by Yeetserama
// roc 2007-08 004a9270  unit: RBX::Network::VClient::?$FactoryProduct  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a9270
//
// 004a9270  6aff                 push -1
// 004a9272  68d9717400           push 0x7471d9
// 004a9277  64a100000000         mov eax, dword ptr fs:[0]
// 004a927d  50                   push eax
// 004a927e  83ec0c               sub esp, 0xc
// 004a9281  56                   push esi
// 004a9282  57                   push edi
// 004a9283  a188518b00           mov eax, dword ptr [0x8b5188]
// 004a9288  33c4                 xor eax, esp
// 004a928a  50                   push eax
// 004a928b  8d442418             lea eax, [esp + 0x18]
// 004a928f  64a300000000         mov dword ptr fs:[0], eax
// 004a9295  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004a929d  8b01                 mov eax, dword ptr [ecx]
// 004a929f  8b5044               mov edx, dword ptr [eax + 0x44]
// 004a92a2  ffd2                 call edx
// 004a92a4  50                   push eax
// 004a92a5  8d442414             lea eax, [esp + 0x14]
// 004a92a9  50                   push eax
// 004a92aa  e8c143ffff           call 0x49d670
// 004a92af  8b08                 mov ecx, dword ptr [eax]
// 004a92b1  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004a92b5  890f                 mov dword ptr [edi], ecx
// 004a92b7  8b4004               mov eax, dword ptr [eax + 4]
// 004a92ba  83c408               add esp, 8
// 004a92bd  85c0                 test eax, eax
// 004a92bf  894704               mov dword ptr [edi + 4], eax
// 004a92c2  740c                 je 0x4a92d0
// 004a92c4  83c004               add eax, 4
// 004a92c7  ba01000000           mov edx, 1
// 004a92cc  f00fc110             lock xadd dword ptr [eax], edx
// 004a92d0  8b742414             mov esi, dword ptr [esp + 0x14]
// 004a92d4  85f6                 test esi, esi
// 004a92d6  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004a92de  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 004a92e6  742a                 je 0x4a9312
// 004a92e8  8d4604               lea eax, [esi + 4]
// 004a92eb  83c9ff               or ecx, 0xffffffff
// 004a92ee  f00fc108             lock xadd dword ptr [eax], ecx
// 004a92f2  751e                 jne 0x4a9312
// 004a92f4  8b16                 mov edx, dword ptr [esi]
// 004a92f6  8b4204               mov eax, dword ptr [edx + 4]
// 004a92f9  8bce                 mov ecx, esi
// 004a92fb  ffd0                 call eax
// 004a92fd  8d4e08               lea ecx, [esi + 8]
// 004a9300  83caff               or edx, 0xffffffff
// 004a9303  f00fc111             lock xadd dword ptr [ecx], edx
// 004a9307  7509                 jne 0x4a9312
// 004a9309  8b06                 mov eax, dword ptr [esi]
// 004a930b  8b5008               mov edx, dword ptr [eax + 8]
// 004a930e  8bce                 mov ecx, esi
// 004a9310  ffd2                 call edx
// 004a9312  8bc7                 mov eax, edi
// 004a9314  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a9318  64890d00000000       mov dword ptr fs:[0], ecx
// 004a931f  59                   pop ecx
// 004a9320  5f                   pop edi
// 004a9321  5e                   pop esi
// 004a9322  83c418               add esp, 0x18
// 004a9325  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX00000c@@QAE?AUResult@2@XZ)

namespace ns_ROCX00000c {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void weakRelease();
};

inline void Control::weakRelease()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

struct Temporary {
    void* pointer;
    Control* control;
    ~Temporary();
};

struct Result {
    void* pointer;
    Control* control;
    Result(const Temporary&);
    ~Result();
};

inline Temporary::~Temporary()
{
    Control* p = control;
    if (p) {
        volatile long* count = &p->strong;
        if (_InterlockedDecrement(count) == 0) {
            p->dispose();
            p->weakRelease();
        }
    }
}

inline Result::Result(const Temporary& value)
    : pointer(value.pointer), control(value.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Result::~Result()
{
    Control* p = control;
    if (p) {
        volatile long* count = &p->strong;
        if (_InterlockedDecrement(count) == 0) {
            p->dispose();
            p->weakRelease();
        }
    }
}

struct S;

struct VTable {
    void* preceding[17];
    void* (__thiscall *get)(S*);
};

struct S {
    VTable* table;
    Result f();
};

extern Temporary __cdecl makeTemporary(void*);

Result S::f()
{
    return Result(makeTemporary(table->get(this)));
}
}
