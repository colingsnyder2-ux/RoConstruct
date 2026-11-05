// from server: 100% by nuck16
// roc 2009-12 00973580  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973580
//
// 00973580  6a01                 push 1
// 00973582  68e01d9b00           push 0x9b1de0
// 00973587  33c9                 xor ecx, ecx
// 00973589  6800099d00           push 0x9d0900
// 0097358e  51                   push ecx
// 0097358f  b820776800           mov eax, 0x687720
// 00973594  50                   push eax
// 00973595  b9000fb900           mov ecx, 0xb90f00
// 0097359a  e8c121d1ff           call 0x685760
// 0097359f  68e04e9800           push 0x984ee0
// 009735a4  e88013e8ff           call 0x7f4929
// 009735a9  59                   pop ecx
// 009735aa  c3                   ret 

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

static Desc desc(&Owner::m0, "SetWaypoint", "name", 1);
