// from server: 100% by nuck16
// roc 2009-12 00968bf0  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968bf0
//
// 00968bf0  33c9                 xor ecx, ecx
// 00968bf2  51                   push ecx
// 00968bf3  6a0f                 push 0xf
// 00968bf5  51                   push ecx
// 00968bf6  b8f0ad4400           mov eax, 0x44adf0
// 00968bfb  50                   push eax
// 00968bfc  6850414400           push 0x444150
// 00968c01  6828aa9a00           push 0x9aaa28
// 00968c06  6830aa9a00           push 0x9aaa30
// 00968c0b  b9f0aeb700           mov ecx, 0xb7aef0
// 00968c10  e85bf1adff           call 0x447d70
// 00968c15  68f0e49700           push 0x97e4f0
// 00968c1a  e80abde8ff           call 0x7f4929
// 00968c1f  59                   pop ecx
// 00968c20  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00444150();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("FullscreenSizePreference", "Screen", func_00444150, &Owner::m0, 15, 0);
