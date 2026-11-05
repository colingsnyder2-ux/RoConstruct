// from server: 100% by nuck16
// roc 2009-12 00968af0  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968af0
//
// 00968af0  33c9                 xor ecx, ecx
// 00968af2  51                   push ecx
// 00968af3  6a0f                 push 0xf
// 00968af5  51                   push ecx
// 00968af6  b810974400           mov eax, 0x449710
// 00968afb  50                   push eax
// 00968afc  68c0f78600           push 0x86f7c0
// 00968b01  68c0a99a00           push 0x9aa9c0
// 00968b06  68c8a99a00           push 0x9aa9c8
// 00968b0b  b968aeb700           mov ecx, 0xb7ae68
// 00968b10  e80b16aeff           call 0x44a120
// 00968b15  6890e29700           push 0x97e290
// 00968b1a  e80abee8ff           call 0x7f4929
// 00968b1f  59                   pop ecx
// 00968b20  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_0086f7c0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("FrameRateManager", "General", func_0086f7c0, &Owner::m0, 15, 0);
