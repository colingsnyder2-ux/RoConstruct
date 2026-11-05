// from server: 100% by nuck16
// roc 2009-12 0096e6d0  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096e6d0
//
// 0096e6d0  6a01                 push 1
// 0096e6d2  33c9                 xor ecx, ecx
// 0096e6d4  68a0bb9c00           push 0x9cbba0
// 0096e6d9  51                   push ecx
// 0096e6da  b8a0bc6200           mov eax, 0x62bca0
// 0096e6df  50                   push eax
// 0096e6e0  b9c84db800           mov ecx, 0xb84dc8
// 0096e6e5  e8f62accff           call 0x6311e0
// 0096e6ea  68c0169800           push 0x9816c0
// 0096e6ef  e83562e8ff           call 0x7f4929
// 0096e6f4  59                   pop ecx
// 0096e6f5  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "LegacyScriptMode", 1);
