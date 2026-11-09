// from server: 100% by nuck16
// roc 2009-12 009798a0  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009798a0
//
// 009798a0  33c9                 xor ecx, ecx
// 009798a2  51                   push ecx
// 009798a3  68e41c9e00           push 0x9e1ce4
// 009798a8  51                   push ecx
// 009798a9  b8f0537300           mov eax, 0x7353f0
// 009798ae  50                   push eax
// 009798af  b9d861b900           mov ecx, 0xb961d8
// 009798b4  e82707dcff           call 0x739fe0
// 009798b9  68b0899800           push 0x9889b0
// 009798be  e866b0e7ff           call 0x7f4929
// 009798c3  59                   pop ecx
// 009798c4  c3                   ret 

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

static Desc desc(&Owner::m0, "lastForce", 0);
