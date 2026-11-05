// from server: 100% by nuck16
// roc 2009-12 00975660  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00975660
//
// 00975660  6a01                 push 1
// 00975662  68d81d9b00           push 0x9b1dd8
// 00975667  33c9                 xor ecx, ecx
// 00975669  68887f9d00           push 0x9d7f88
// 0097566e  51                   push ecx
// 0097566f  b86c020000           mov eax, 0x26c
// 00975674  50                   push eax
// 00975675  b91829b900           mov ecx, 0xb92918
// 0097567a  e8e1b6d5ff           call 0x6d0d60
// 0097567f  6810619800           push 0x986110
// 00975684  e8a0f2e7ff           call 0x7f4929
// 00975689  59                   pop ecx
// 0097568a  c3                   ret 

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

static Desc desc(&Owner::m0, "LocalSimulationTouched", "part", 1);
