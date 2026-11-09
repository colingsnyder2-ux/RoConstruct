// from server: 100% by nuck16
// roc 2009-12 00973e50  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973e50
//
// 00973e50  6a01                 push 1
// 00973e52  68ccf39c00           push 0x9cf3cc
// 00973e57  33c9                 xor ecx, ecx
// 00973e59  6858309d00           push 0x9d3058
// 00973e5e  51                   push ecx
// 00973e5f  b890956a00           mov eax, 0x6a9590
// 00973e64  50                   push eax
// 00973e65  b97017b900           mov ecx, 0xb91770
// 00973e6a  e8512bd3ff           call 0x6a69c0
// 00973e6f  6890549800           push 0x985490
// 00973e74  e8b00ae8ff           call 0x7f4929
// 00973e79  59                   pop ecx
// 00973e7a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetTimeout", "seconds", 1);
