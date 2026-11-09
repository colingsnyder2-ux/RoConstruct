// from server: 100% by nuck16
// roc 2009-12 00969150  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00969150
//
// 00969150  33c9                 xor ecx, ecx
// 00969152  51                   push ecx
// 00969153  6a0f                 push 0xf
// 00969155  51                   push ecx
// 00969156  b8109b4400           mov eax, 0x449b10
// 0096915b  50                   push eax
// 0096915c  68c0414400           push 0x4441c0
// 00969161  6808aa9a00           push 0x9aaa08
// 00969166  688cab9a00           push 0x9aab8c
// 0096916b  b920b2b700           mov ecx, 0xb7b220
// 00969170  e85bebadff           call 0x447cd0
// 00969175  6830e49700           push 0x97e430
// 0096917a  e8aab7e8ff           call 0x7f4929
// 0096917f  59                   pop ecx
// 00969180  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_004441c0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("TextureCompositingEnabled", "Debug", func_004441c0, &Owner::m0, 15, 0);
