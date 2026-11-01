// from server: 100% by Yeetserama
// roc 2007-08 00460f10  unit: RBX::VInstance::?$MarshaledListener::EventData  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460f10
//
// 00460f10  6aff                 push -1
// 00460f12  6893287400           push 0x742893
// 00460f17  64a100000000         mov eax, dword ptr fs:[0]
// 00460f1d  50                   push eax
// 00460f1e  51                   push ecx
// 00460f1f  56                   push esi
// 00460f20  a188518b00           mov eax, dword ptr [0x8b5188]
// 00460f25  33c4                 xor eax, esp
// 00460f27  50                   push eax
// 00460f28  8d44240c             lea eax, [esp + 0xc]
// 00460f2c  64a300000000         mov dword ptr fs:[0], eax
// 00460f32  8bf1                 mov esi, ecx
// 00460f34  89742408             mov dword ptr [esp + 8], esi
// 00460f38  33c0                 xor eax, eax
// 00460f3a  c706944b7900         mov dword ptr [esi], 0x794b94
// 00460f40  894604               mov dword ptr [esi + 4], eax
// 00460f43  89442414             mov dword ptr [esp + 0x14], eax
// 00460f47  894608               mov dword ptr [esi + 8], eax
// 00460f4a  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00460f4e  8b542420             mov edx, dword ptr [esp + 0x20]
// 00460f52  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00460f56  894e10               mov dword ptr [esi + 0x10], ecx
// 00460f59  52                   push edx
// 00460f5a  8bce                 mov ecx, esi
// 00460f5c  c644241801           mov byte ptr [esp + 0x18], 1
// 00460f61  89460c               mov dword ptr [esi + 0xc], eax
// 00460f64  e8e731ffff           call 0x454150
// 00460f69  8bc6                 mov eax, esi
// 00460f6b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00460f6f  64890d00000000       mov dword ptr fs:[0], ecx
// 00460f76  59                   pop ecx
// 00460f77  5e                   pop esi
// 00460f78  83c410               add esp, 0x10
// 00460f7b  c20c00               ret 0xc
// copied from an identical function in another client (function ??0S@ns_ROCX000019@@QAE@PAX00@Z)

namespace ns_ROCX000019 {
// from server: 100% by king_originala
struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

struct Base
{
    virtual ~Base();
};

struct Count
{
    Control *control;
    Count();
    ~Count();
};

inline Count::Count() : control(0)
{
}

inline Count::~Count()
{
    if (control)
        control->release();
}

struct S : Base
{
    void *value;
    Count count;
    void *first;
    void *last;

    S(void *, void *, void *);
    virtual ~S();
    void connect(void *);
};

S::S(void *a, void *b, void *c)
    : value(0), first(a), last(c)
{
    connect(b);
}
}
