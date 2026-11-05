// from server: 100% by nuck16
// roc 2009-12 009690d0  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009690d0
//
// 009690d0  33c9                 xor ecx, ecx
// 009690d2  51                   push ecx
// 009690d3  6a0f                 push 0xf
// 009690d5  51                   push ecx
// 009690d6  b8b09a4400           mov eax, 0x449ab0
// 009690db  50                   push eax
// 009690dc  68a0107000           push 0x7010a0
// 009690e1  6858aa9a00           push 0x9aaa58
// 009690e6  6864ab9a00           push 0x9aab64
// 009690eb  b9e0b1b700           mov ecx, 0xb7b1e0
// 009690f0  e85befadff           call 0x448050
// 009690f5  68f0e39700           push 0x97e3f0
// 009690fa  e82ab8e8ff           call 0x7f4929
// 009690ff  59                   pop ecx
// 00969100  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_007010a0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("MinCullDistance", "Performance", func_007010a0, &Owner::m0, 15, 0);
