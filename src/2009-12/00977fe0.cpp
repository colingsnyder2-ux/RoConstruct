// from server: 100% by nuck16
// roc 2009-12 00977fe0  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977fe0
//
// 00977fe0  33c9                 xor ecx, ecx
// 00977fe2  51                   push ecx
// 00977fe3  6818dd9d00           push 0x9ddd18
// 00977fe8  51                   push ecx
// 00977fe9  b8904a8500           mov eax, 0x854a90
// 00977fee  50                   push eax
// 00977fef  b9184eb900           mov ecx, 0xb94e18
// 00977ff4  e8177fd8ff           call 0x6fff10
// 00977ff9  6800789800           push 0x987800
// 00977ffe  e826c9e7ff           call 0x7f4929
// 00978003  59                   pop ecx
// 00978004  c3                   ret 

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

static Desc desc(&Owner::m0, "RebalanceTeams", 0);
