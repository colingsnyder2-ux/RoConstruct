// from server: 100% by nuck16
// roc 2009-12 00978d70  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978d70
//
// 00978d70  33c9                 xor ecx, ecx
// 00978d72  51                   push ecx
// 00978d73  6a0f                 push 0xf
// 00978d75  51                   push ecx
// 00978d76  b810317300           mov eax, 0x733110
// 00978d7b  50                   push eax
// 00978d7c  6894000000           push 0x94
// 00978d81  6884b09b00           push 0x9bb084
// 00978d86  684cd59a00           push 0x9ad54c
// 00978d8b  b90461b900           mov ecx, 0xb96104
// 00978d90  e88b5cdbff           call 0x72ea20
// 00978d95  6850819800           push 0x988150
// 00978d9a  e88abbe7ff           call 0x7f4929
// 00978d9f  59                   pop ecx
// 00978da0  c3                   ret 

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
