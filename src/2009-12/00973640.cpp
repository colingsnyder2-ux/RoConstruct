// from server: 100% by nuck16
// roc 2009-12 00973640  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973640
//
// 00973640  6a01                 push 1
// 00973642  33c9                 xor ecx, ecx
// 00973644  6828099d00           push 0x9d0928
// 00973649  51                   push ecx
// 0097364a  b810626800           mov eax, 0x686210
// 0097364f  50                   push eax
// 00973650  b92010b900           mov ecx, 0xb91020
// 00973655  e87623d1ff           call 0x6859d0
// 0097365a  68a04e9800           push 0x984ea0
// 0097365f  e8c512e8ff           call 0x7f4929
// 00973664  59                   pop ecx
// 00973665  c3                   ret 

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

static Desc desc(&Owner::m0, "GetCanRedo", 1);
