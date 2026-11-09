// from server: 100% by nuck16
// roc 2009-12 0096bab0  unit: seg_00960000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096bab0
//
// 0096bab0  33c9                 xor ecx, ecx
// 0096bab2  51                   push ecx
// 0096bab3  6870b09b00           push 0x9bb070
// 0096bab8  685cb09b00           push 0x9bb05c
// 0096babd  51                   push ecx
// 0096babe  b8f0524f00           mov eax, 0x4f52f0
// 0096bac3  50                   push eax
// 0096bac4  b960e4b700           mov ecx, 0xb7e460
// 0096bac9  e822dfb9ff           call 0x5099f0
// 0096bace  6850f49700           push 0x97f450
// 0096bad3  e8518ee8ff           call 0x7f4929
// 0096bad8  59                   pop ecx
// 0096bad9  c3                   ret 

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

static Desc desc(&Owner::m0, "HasBuildPermission", "role", 0);
