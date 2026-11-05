// from server: 100% by nuck16
// roc 2009-12 0096d390  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d390
//
// 0096d390  6a01                 push 1
// 0096d392  33c9                 xor ecx, ecx
// 0096d394  68b4cb9b00           push 0x9bcbb4
// 0096d399  51                   push ecx
// 0096d39a  b870c55200           mov eax, 0x52c570
// 0096d39f  50                   push eax
// 0096d3a0  b95004b800           mov ecx, 0xb80450
// 0096d3a5  e88603bcff           call 0x52d730
// 0096d3aa  6840049800           push 0x980440
// 0096d3af  e87575e8ff           call 0x7f4929
// 0096d3b4  59                   pop ecx
// 0096d3b5  c3                   ret 

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

static Desc desc(&Owner::m0, "GetClientCount", 1);
