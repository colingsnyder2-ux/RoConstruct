// from server: 100% by nuck16
// roc 2009-12 0097b130  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b130
//
// 0097b130  33c9                 xor ecx, ecx
// 0097b132  51                   push ecx
// 0097b133  6a0f                 push 0xf
// 0097b135  51                   push ecx
// 0097b136  b880b17500           mov eax, 0x75b180
// 0097b13b  50                   push eax
// 0097b13c  6880047400           push 0x740480
// 0097b141  6884b09b00           push 0x9bb084
// 0097b146  682c5f9e00           push 0x9e5f2c
// 0097b14b  b99877b900           mov ecx, 0xb97798
// 0097b150  e8cb05deff           call 0x75b720
// 0097b155  6890969800           push 0x989690
// 0097b15a  e8ca97e7ff           call 0x7f4929
// 0097b15f  59                   pop ecx
// 0097b160  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00740480();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextYAlignment", "Data", func_00740480, &Owner::m0, 15, 0);
