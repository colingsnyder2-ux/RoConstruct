// from server: 100% by nuck16
// roc 2009-12 00978de0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978de0
//
// 00978de0  33c9                 xor ecx, ecx
// 00978de2  51                   push ecx
// 00978de3  6a0f                 push 0xf
// 00978de5  51                   push ecx
// 00978de6  b830317300           mov eax, 0x733130
// 00978deb  50                   push eax
// 00978dec  6894000000           push 0x94
// 00978df1  6884b09b00           push 0x9bb084
// 00978df6  684cd59a00           push 0x9ad54c
// 00978dfb  b92c5fb900           mov ecx, 0xb95f2c
// 00978e00  e8fb5cdbff           call 0x72eb00
// 00978e05  6870819800           push 0x988170
// 00978e0a  e81abbe7ff           call 0x7f4929
// 00978e0f  59                   pop ecx
// 00978e10  c3                   ret 

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
