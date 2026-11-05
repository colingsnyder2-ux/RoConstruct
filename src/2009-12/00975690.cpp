// from server: 100% by nuck16
// roc 2009-12 00975690  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00975690
//
// 00975690  6a01                 push 1
// 00975692  68a87f9d00           push 0x9d7fa8
// 00975697  33c9                 xor ecx, ecx
// 00975699  68a07f9d00           push 0x9d7fa0
// 0097569e  51                   push ecx
// 0097569f  b870020000           mov eax, 0x270
// 009756a4  50                   push eax
// 009756a5  b95829b900           mov ecx, 0xb92958
// 009756aa  e891b7d5ff           call 0x6d0e40
// 009756af  6850609800           push 0x986050
// 009756b4  e870f2e7ff           call 0x7f4929
// 009756b9  59                   pop ecx
// 009756ba  c3                   ret 

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

static Desc desc(&Owner::m0, "Touched", "otherPart", 1);
