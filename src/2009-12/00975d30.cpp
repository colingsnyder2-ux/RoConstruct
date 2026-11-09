// from server: 100% by nuck16
// roc 2009-12 00975d30  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00975d30
//
// 00975d30  6a01                 push 1
// 00975d32  689cb19b00           push 0x9bb19c
// 00975d37  33c9                 xor ecx, ecx
// 00975d39  68a8a69d00           push 0x9da6a8
// 00975d3e  51                   push ecx
// 00975d3f  b870684700           mov eax, 0x476870
// 00975d44  50                   push eax
// 00975d45  b9a034b900           mov ecx, 0xb934a0
// 00975d4a  e861bbd6ff           call 0x6e18b0
// 00975d4f  68a0649800           push 0x9864a0
// 00975d54  e8d0ebe7ff           call 0x7f4929
// 00975d59  59                   pop ecx
// 00975d5a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetAssetUrl", "url", 1);
