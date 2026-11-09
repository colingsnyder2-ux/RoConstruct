// from server: 100% by nuck16
// roc 2009-12 0097b0f0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b0f0
//
// 0097b0f0  33c9                 xor ecx, ecx
// 0097b0f2  51                   push ecx
// 0097b0f3  6a0f                 push 0xf
// 0097b0f5  51                   push ecx
// 0097b0f6  b850b17500           mov eax, 0x75b150
// 0097b0fb  50                   push eax
// 0097b0fc  68f0337700           push 0x7733f0
// 0097b101  6884b09b00           push 0x9bb084
// 0097b106  681c5f9e00           push 0x9e5f1c
// 0097b10b  b9c077b900           mov ecx, 0xb977c0
// 0097b110  e83b05deff           call 0x75b650
// 0097b115  68b0969800           push 0x9896b0
// 0097b11a  e80a98e7ff           call 0x7f4929
// 0097b11f  59                   pop ecx
// 0097b120  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_007733f0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextXAlignment", "Data", func_007733f0, &Owner::m0, 15, 0);
