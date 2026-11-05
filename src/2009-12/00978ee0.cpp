// from server: 100% by nuck16
// roc 2009-12 00978ee0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978ee0
//
// 00978ee0  33c9                 xor ecx, ecx
// 00978ee2  51                   push ecx
// 00978ee3  6a0f                 push 0xf
// 00978ee5  51                   push ecx
// 00978ee6  b820327300           mov eax, 0x733220
// 00978eeb  50                   push eax
// 00978eec  6894000000           push 0x94
// 00978ef1  6884b09b00           push 0x9bb084
// 00978ef6  684cd59a00           push 0x9ad54c
// 00978efb  b9085db900           mov ecx, 0xb95d08
// 00978f00  e8bb5ddbff           call 0x72ecc0
// 00978f05  68b0819800           push 0x9881b0
// 00978f0a  e81abae7ff           call 0x7f4929
// 00978f0f  59                   pop ecx
// 00978f10  c3                   ret 

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
    Desc(const char *, const char *, int, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Value", "Data", 148, &Owner::m0, 15, 0);
