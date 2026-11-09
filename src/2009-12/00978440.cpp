// from server: 100% by nuck16
// roc 2009-12 00978440  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978440
//
// 00978440  33c9                 xor ecx, ecx
// 00978442  51                   push ecx
// 00978443  6840e79d00           push 0x9de740
// 00978448  51                   push ecx
// 00978449  b890317100           mov eax, 0x713190
// 0097844e  50                   push eax
// 0097844f  b93055b900           mov ecx, 0xb95530
// 00978454  e827c5d9ff           call 0x714980
// 00978459  68007b9800           push 0x987b00
// 0097845e  e8c6c4e7ff           call 0x7f4929
// 00978463  59                   pop ecx
// 00978464  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GetMoonDirection", 0);
