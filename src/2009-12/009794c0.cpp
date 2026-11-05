// from server: 100% by nuck16
// roc 2009-12 009794c0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009794c0
//
// 009794c0  33c9                 xor ecx, ecx
// 009794c2  51                   push ecx
// 009794c3  6a0f                 push 0xf
// 009794c5  51                   push ecx
// 009794c6  b850547300           mov eax, 0x735450
// 009794cb  50                   push eax
// 009794cc  687c010000           push 0x17c
// 009794d1  68141c9e00           push 0x9e1c14
// 009794d6  682c1c9e00           push 0x9e1c2c
// 009794db  b91863b900           mov ecx, 0xb96318
// 009794e0  e87bf0dbff           call 0x738560
// 009794e5  6890889800           push 0x988890
// 009794ea  e83ab4e7ff           call 0x7f4929
// 009794ef  59                   pop ecx
// 009794f0  c3                   ret 

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
    Desc(const char *, const char *, int, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TargetRadius", "Goals", 380, &Owner::m0, 15, 0);
