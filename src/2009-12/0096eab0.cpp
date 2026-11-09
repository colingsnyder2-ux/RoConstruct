// from server: 100% by nuck16
// roc 2009-12 0096eab0  unit: seg_00960000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096eab0
//
// 0096eab0  33c9                 xor ecx, ecx
// 0096eab2  51                   push ecx
// 0096eab3  6838a79b00           push 0x9ba738
// 0096eab8  51                   push ecx
// 0096eab9  b800796300           mov eax, 0x637900
// 0096eabe  50                   push eax
// 0096eabf  b9d051b800           mov ecx, 0xb851d0
// 0096eac4  e81760ccff           call 0x634ae0
// 0096eac9  6860189800           push 0x981860
// 0096eace  e8565ee8ff           call 0x7f4929
// 0096ead3  59                   pop ecx
// 0096ead4  c3                   ret 

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

static Desc desc(&Owner::m0, "Clone", 0);
