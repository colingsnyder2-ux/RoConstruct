// from server: 100% by nuck16
// roc 2009-12 0096c650  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c650
//
// 0096c650  6a04                 push 4
// 0096c652  689cb19b00           push 0x9bb19c
// 0096c657  33c9                 xor ecx, ecx
// 0096c659  68e8b89b00           push 0x9bb8e8
// 0096c65e  51                   push ecx
// 0096c65f  b810295200           mov eax, 0x522910
// 0096c664  50                   push eax
// 0096c665  b9e0efb700           mov ecx, 0xb7efe0
// 0096c66a  e80108bbff           call 0x51ce70
// 0096c66f  68d0fb9700           push 0x97fbd0
// 0096c674  e8b082e8ff           call 0x7f4929
// 0096c679  59                   pop ecx
// 0096c67a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetAbuseReportUrl", "url", 4);
