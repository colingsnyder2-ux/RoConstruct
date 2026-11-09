// from server: 100% by nuck16
// roc 2009-12 00978e50  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978e50
//
// 00978e50  33c9                 xor ecx, ecx
// 00978e52  51                   push ecx
// 00978e53  6a0f                 push 0xf
// 00978e55  51                   push ecx
// 00978e56  b8d0317300           mov eax, 0x7331d0
// 00978e5b  50                   push eax
// 00978e5c  6898000000           push 0x98
// 00978e61  6884b09b00           push 0x9bb084
// 00978e66  684cd59a00           push 0x9ad54c
// 00978e6b  b94060b900           mov ecx, 0xb96040
// 00978e70  e86b5ddbff           call 0x72ebe0
// 00978e75  6890819800           push 0x988190
// 00978e7a  e8aabae7ff           call 0x7f4929
// 00978e7f  59                   pop ecx
// 00978e80  c3                   ret 

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

static Desc desc("Value", "Data", 152, &Owner::m0, 15, 0);
