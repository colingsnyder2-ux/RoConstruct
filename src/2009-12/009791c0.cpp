// from server: 100% by nuck16
// roc 2009-12 009791c0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009791c0
//
// 009791c0  33c9                 xor ecx, ecx
// 009791c2  51                   push ecx
// 009791c3  6a0f                 push 0xf
// 009791c5  51                   push ecx
// 009791c6  b810317300           mov eax, 0x733110
// 009791cb  50                   push eax
// 009791cc  6894000000           push 0x94
// 009791d1  6884b09b00           push 0x9bb084
// 009791d6  684cd59a00           push 0x9ad54c
// 009791db  b9285eb900           mov ecx, 0xb95e28
// 009791e0  e85b5edbff           call 0x72f040
// 009791e5  6850829800           push 0x988250
// 009791ea  e83ab7e7ff           call 0x7f4929
// 009791ef  59                   pop ecx
// 009791f0  c3                   ret 

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
