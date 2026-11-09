// from server: 100% by nuck16
// roc 2009-12 00978210  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978210
//
// 00978210  33c9                 xor ecx, ecx
// 00978212  51                   push ecx
// 00978213  68a0b09b00           push 0x9bb0a0
// 00978218  68b4e29d00           push 0x9de2b4
// 0097821d  51                   push ecx
// 0097821e  b890e67000           mov eax, 0x70e690
// 00978223  50                   push eax
// 00978224  b92052b900           mov ecx, 0xb95220
// 00978229  e8c237d9ff           call 0x70b9f0
// 0097822e  68c0789800           push 0x9878c0
// 00978233  e8f1c6e7ff           call 0x7f4929
// 00978238  59                   pop ecx
// 00978239  c3                   ret 

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

static Desc desc(&Owner::m0, "GetUserCategories", "userId", 0);
