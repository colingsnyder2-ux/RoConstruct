// from server: 100% by nuck16
// roc 2009-12 00968bb0  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968bb0
//
// 00968bb0  33c9                 xor ecx, ecx
// 00968bb2  51                   push ecx
// 00968bb3  6a0f                 push 0xf
// 00968bb5  51                   push ecx
// 00968bb6  b820ae4400           mov eax, 0x44ae20
// 00968bbb  50                   push eax
// 00968bbc  6860414400           push 0x444160
// 00968bc1  6828aa9a00           push 0x9aaa28
// 00968bc6  6810aa9a00           push 0x9aaa10
// 00968bcb  b9d0aeb700           mov ecx, 0xb7aed0
// 00968bd0  e89bf1adff           call 0x447d70
// 00968bd5  6810e59700           push 0x97e510
// 00968bda  e84abde8ff           call 0x7f4929
// 00968bdf  59                   pop ecx
// 00968be0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00444160();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("WindowSizePreference", "Screen", func_00444160, &Owner::m0, 15, 0);
