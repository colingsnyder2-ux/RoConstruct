// from server: 100% by nuck16
// roc 2009-12 0097b6c0  unit: seg_00970000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b6c0
//
// 0097b6c0  6a01                 push 1
// 0097b6c2  683c7e9e00           push 0x9e7e3c
// 0097b6c7  68287e9e00           push 0x9e7e28
// 0097b6cc  33c9                 xor ecx, ecx
// 0097b6ce  68187e9e00           push 0x9e7e18
// 0097b6d3  51                   push ecx
// 0097b6d4  b860827600           mov eax, 0x768260
// 0097b6d9  50                   push eax
// 0097b6da  b9487eb900           mov ecx, 0xb97e48
// 0097b6df  e8fcf2deff           call 0x76a9e0
// 0097b6e4  68f0999800           push 0x9899f0
// 0097b6e9  e83b92e7ff           call 0x7f4929
// 0097b6ee  59                   pop ecx
// 0097b6ef  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(void (Owner::*)(), const char *, const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "SetFilterLimits", "outstandingRequests", "cacheSize", 1);
