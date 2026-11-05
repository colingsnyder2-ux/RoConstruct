// from server: 100% by nuck16
// roc 2009-12 0096d9c0  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d9c0
//
// 0096d9c0  6a01                 push 1
// 0096d9c2  68b4e89b00           push 0x9be8b4
// 0096d9c7  33c9                 xor ecx, ecx
// 0096d9c9  689ce89b00           push 0x9be89c
// 0096d9ce  51                   push ecx
// 0096d9cf  b8d0ff5400           mov eax, 0x54ffd0
// 0096d9d4  50                   push eax
// 0096d9d5  b9a008b800           mov ecx, 0xb808a0
// 0096d9da  e8d135beff           call 0x550fb0
// 0096d9df  68e0099800           push 0x9809e0
// 0096d9e4  e8406fe8ff           call 0x7f4929
// 0096d9e9  59                   pop ecx
// 0096d9ea  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "SetOutgoingKBPSLimit", "limit", 1);
