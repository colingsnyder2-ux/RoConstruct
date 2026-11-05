// from server: 100% by nuck16
// roc 2009-12 00979680  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979680
//
// 00979680  33c9                 xor ecx, ecx
// 00979682  51                   push ecx
// 00979683  68a01c9e00           push 0x9e1ca0
// 00979688  51                   push ecx
// 00979689  b810567300           mov eax, 0x735610
// 0097968e  50                   push eax
// 0097968f  b92064b900           mov ecx, 0xb96420
// 00979694  e86708dcff           call 0x739f00
// 00979699  68308a9800           push 0x988a30
// 0097969e  e886b2e7ff           call 0x7f4929
// 009796a3  59                   pop ecx
// 009796a4  c3                   ret 

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

static Desc desc(&Owner::m0, "Fire", 0);
