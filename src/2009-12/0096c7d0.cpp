// from server: 100% by nuck16
// roc 2009-12 0096c7d0  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c7d0
//
// 0096c7d0  6a01                 push 1
// 0096c7d2  689cb19b00           push 0x9bb19c
// 0096c7d7  33c9                 xor ecx, ecx
// 0096c7d9  6888b99b00           push 0x9bb988
// 0096c7de  51                   push ecx
// 0096c7df  b820255100           mov eax, 0x512520
// 0096c7e4  50                   push eax
// 0096c7e5  b930ecb700           mov ecx, 0xb7ec30
// 0096c7ea  e88106bbff           call 0x51ce70
// 0096c7ef  6820fc9700           push 0x97fc20
// 0096c7f4  e83081e8ff           call 0x7f4929
// 0096c7f9  59                   pop ecx
// 0096c7fa  c3                   ret 

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

static Desc desc(&Owner::m0, "SetSysStatsUrl", "url", 1);
