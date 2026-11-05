// from server: 100% by nuck16
// roc 2009-12 0097b690  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b690
//
// 0097b690  6a01                 push 1
// 0097b692  689cb19b00           push 0x9bb19c
// 0097b697  33c9                 xor ecx, ecx
// 0097b699  68087e9e00           push 0x9e7e08
// 0097b69e  51                   push ecx
// 0097b69f  b810827600           mov eax, 0x768210
// 0097b6a4  50                   push eax
// 0097b6a5  b9007eb900           mov ecx, 0xb97e00
// 0097b6aa  e8a1f1deff           call 0x76a850
// 0097b6af  68009a9800           push 0x989a00
// 0097b6b4  e87092e7ff           call 0x7f4929
// 0097b6b9  59                   pop ecx
// 0097b6ba  c3                   ret 

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

static Desc desc(&Owner::m0, "SetFilterUrl", "url", 1);
