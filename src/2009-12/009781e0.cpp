// from server: 100% by nuck16
// roc 2009-12 009781e0  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009781e0
//
// 009781e0  33c9                 xor ecx, ecx
// 009781e2  51                   push ecx
// 009781e3  68a0e29d00           push 0x9de2a0
// 009781e8  51                   push ecx
// 009781e9  b8a0e37000           mov eax, 0x70e3a0
// 009781ee  50                   push eax
// 009781ef  b90053b900           mov ecx, 0xb95300
// 009781f4  e81730d9ff           call 0x70b210
// 009781f9  6800799800           push 0x987900
// 009781fe  e826c7e7ff           call 0x7f4929
// 00978203  59                   pop ecx
// 00978204  c3                   ret 

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

static Desc desc(&Owner::m0, "GetBaseCategories", 0);
