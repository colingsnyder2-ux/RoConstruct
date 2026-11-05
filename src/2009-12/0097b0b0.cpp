// from server: 100% by nuck16
// roc 2009-12 0097b0b0  unit: seg_00970000  size: 49 bytes
//
// 0097b0b0  33c9                 xor ecx, ecx
// 0097b0b2  51                   push ecx
// 0097b0b3  6a0f                 push 0xf
// 0097b0b5  51                   push ecx
// 0097b0b6  b820b17500           mov eax, 0x75b120
// 0097b0bb  50                   push eax
// 0097b0bc  6840887500           push 0x758840
// 0097b0c1  6884b09b00           push 0x9bb084
// 0097b0c6  68105f9e00           push 0x9e5f10
// 0097b0cb  b97877b900           mov ecx, 0xb97778
// 0097b0d0  e8db04deff           call 0x75b5b0
// 0097b0d5  68d0969800           push 0x9896d0
// 0097b0da  e84a98e7ff           call 0x7f4929
// 0097b0df  59                   pop ecx
// 0097b0e0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00758840();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextWrap", "Data", func_00758840, &Owner::m0, 15, 0);
