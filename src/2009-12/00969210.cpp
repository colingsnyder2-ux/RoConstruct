// from server: 100% by nuck16
// roc 2009-12 00969210  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00969210
//
// 00969210  33c9                 xor ecx, ecx
// 00969212  51                   push ecx
// 00969213  6a0f                 push 0xf
// 00969215  51                   push ecx
// 00969216  b8a09b4400           mov eax, 0x449ba0
// 0096921b  50                   push eax
// 0096921c  68f0414400           push 0x4441f0
// 00969221  6808aa9a00           push 0x9aaa08
// 00969226  68d4ab9a00           push 0x9aabd4
// 0096922b  b980b2b700           mov ecx, 0xb7b280
// 00969230  e89beaadff           call 0x447cd0
// 00969235  6890e49700           push 0x97e490
// 0096923a  e8eab6e8ff           call 0x7f4929
// 0096923f  59                   pop ecx
// 00969240  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_004441f0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("DebugDisableDebriService", "Debug", func_004441f0, &Owner::m0, 15, 0);
