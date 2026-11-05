// from server: 100% by nuck16
// roc 2009-12 00968b70  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968b70
//
// 00968b70  33c9                 xor ecx, ecx
// 00968b72  51                   push ecx
// 00968b73  6a0f                 push 0xf
// 00968b75  51                   push ecx
// 00968b76  b810964400           mov eax, 0x449610
// 00968b7b  50                   push eax
// 00968b7c  6830414400           push 0x444130
// 00968b81  6808aa9a00           push 0x9aaa08
// 00968b86  68f4a99a00           push 0x9aa9f4
// 00968b8b  b9b0aeb700           mov ecx, 0xb7aeb0
// 00968b90  e83bf1adff           call 0x447cd0
// 00968b95  68b0e49700           push 0x97e4b0
// 00968b9a  e88abde8ff           call 0x7f4929
// 00968b9f  59                   pop ecx
// 00968ba0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00444130();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("IsAggregationShown", "Debug", func_00444130, &Owner::m0, 15, 0);
