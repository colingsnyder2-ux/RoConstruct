// from server: 100% by nuck16
// roc 2009-12 00968b30  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968b30
//
// 00968b30  33c9                 xor ecx, ecx
// 00968b32  51                   push ecx
// 00968b33  6a09                 push 9
// 00968b35  51                   push ecx
// 00968b36  b8b0994400           mov eax, 0x4499b0
// 00968b3b  50                   push eax
// 00968b3c  6890414400           push 0x444190
// 00968b41  68c0a99a00           push 0x9aa9c0
// 00968b46  68dca99a00           push 0x9aa9dc
// 00968b4b  b990aeb700           mov ecx, 0xb7ae90
// 00968b50  e87bf1adff           call 0x447cd0
// 00968b55  68d0e49700           push 0x97e4d0
// 00968b5a  e8cabde8ff           call 0x7f4929
// 00968b5f  59                   pop ecx
// 00968b60  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00444190();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("AlwaysDrawConnectors", "General", func_00444190, &Owner::m0, 9, 0);
