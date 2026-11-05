// from server: 100% by nuck16
// roc 2009-12 009743c0  unit: seg_00970000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009743c0
//
// 009743c0  33c9                 xor ecx, ecx
// 009743c2  51                   push ecx
// 009743c3  6a09                 push 9
// 009743c5  51                   push ecx
// 009743c6  51                   push ecx
// 009743c7  b880396b00           mov eax, 0x6b3980
// 009743cc  50                   push eax
// 009743cd  6884b09b00           push 0x9bb084
// 009743d2  6864669d00           push 0x9d6664
// 009743d7  b9081bb900           mov ecx, 0xb91b08
// 009743dc  e86f28d4ff           call 0x6b6c50
// 009743e1  6830579800           push 0x985730
// 009743e6  e83e05e8ff           call 0x7f4929
// 009743eb  59                   pop ecx
// 009743ec  c3                   ret 

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
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("IsPlaying", "Data", &Owner::m0, 0, 9, 0);
