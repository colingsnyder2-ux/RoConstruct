// from server: 100% by nuck16
// roc 2009-12 00978f50  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978f50
//
// 00978f50  33c9                 xor ecx, ecx
// 00978f52  51                   push ecx
// 00978f53  6a0f                 push 0xf
// 00978f55  51                   push ecx
// 00978f56  b850327300           mov eax, 0x733250
// 00978f5b  50                   push eax
// 00978f5c  6894000000           push 0x94
// 00978f61  6884b09b00           push 0x9bb084
// 00978f66  684cd59a00           push 0x9ad54c
// 00978f6b  b9085eb900           mov ecx, 0xb95e08
// 00978f70  e82b5edbff           call 0x72eda0
// 00978f75  68d0819800           push 0x9881d0
// 00978f7a  e8aab9e7ff           call 0x7f4929
// 00978f7f  59                   pop ecx
// 00978f80  c3                   ret 

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
