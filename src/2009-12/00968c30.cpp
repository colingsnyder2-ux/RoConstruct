// from server: 100% by nuck16
// roc 2009-12 00968c30  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968c30
//
// 00968c30  33c9                 xor ecx, ecx
// 00968c32  51                   push ecx
// 00968c33  6a0f                 push 0xf
// 00968c35  51                   push ecx
// 00968c36  b870964400           mov eax, 0x449670
// 00968c3b  50                   push eax
// 00968c3c  68d0ac4100           push 0x41acd0
// 00968c41  6858aa9a00           push 0x9aaa58
// 00968c46  684caa9a00           push 0x9aaa4c
// 00968c4b  b910afb700           mov ecx, 0xb7af10
// 00968c50  e8bbf1adff           call 0x447e10
// 00968c55  6850e59700           push 0x97e550
// 00968c5a  e8cabce8ff           call 0x7f4929
// 00968c5f  59                   pop ecx
// 00968c60  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_0041acd0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("BatchSize", "Performance", func_0041acd0, &Owner::m0, 15, 0);
