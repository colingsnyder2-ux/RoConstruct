// from server: 100% by nuck16
// roc 2009-12 00978470  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978470
//
// 00978470  33c9                 xor ecx, ecx
// 00978472  51                   push ecx
// 00978473  6854e79d00           push 0x9de754
// 00978478  51                   push ecx
// 00978479  b8c0317100           mov eax, 0x7131c0
// 0097847e  50                   push eax
// 0097847f  b9d054b900           mov ecx, 0xb954d0
// 00978484  e8f7c4d9ff           call 0x714980
// 00978489  68c07a9800           push 0x987ac0
// 0097848e  e896c4e7ff           call 0x7f4929
// 00978493  59                   pop ecx
// 00978494  c3                   ret 

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

static Desc desc(&Owner::m0, "GetSunDirection", 0);
