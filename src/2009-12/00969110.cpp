// from server: 100% by nuck16
// roc 2009-12 00969110  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00969110
//
// 00969110  33c9                 xor ecx, ecx
// 00969112  51                   push ecx
// 00969113  6a0f                 push 0xf
// 00969115  51                   push ecx
// 00969116  b8e09a4400           mov eax, 0x449ae0
// 0096911b  50                   push eax
// 0096911c  68b0414400           push 0x4441b0
// 00969121  6808aa9a00           push 0x9aaa08
// 00969126  6874ab9a00           push 0x9aab74
// 0096912b  b900b2b700           mov ecx, 0xb7b200
// 00969130  e89bebadff           call 0x447cd0
// 00969135  6810e49700           push 0x97e410
// 0096913a  e8eab7e8ff           call 0x7f4929
// 0096913f  59                   pop ecx
// 00969140  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_004441b0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("DebugLogFRMLogVariables", "Debug", func_004441b0, &Owner::m0, 15, 0);
