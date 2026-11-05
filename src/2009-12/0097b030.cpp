// from server: 100% by nuck16
// roc 2009-12 0097b030  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b030
//
// 0097b030  33c9                 xor ecx, ecx
// 0097b032  51                   push ecx
// 0097b033  6a0f                 push 0xf
// 0097b035  51                   push ecx
// 0097b036  b870b07500           mov eax, 0x75b070
// 0097b03b  50                   push eax
// 0097b03c  6820887500           push 0x758820
// 0097b041  6884b09b00           push 0x9bb084
// 0097b046  68f05e9e00           push 0x9e5ef0
// 0097b04b  b93477b900           mov ecx, 0xb97734
// 0097b050  e81b04deff           call 0x75b470
// 0097b055  6810979800           push 0x989710
// 0097b05a  e8ca98e7ff           call 0x7f4929
// 0097b05f  59                   pop ecx
// 0097b060  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00758820();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextColor3", "Data", func_00758820, &Owner::m0, 15, 0);
