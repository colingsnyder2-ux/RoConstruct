// from server: 100% by nuck16
// roc 2009-12 00969090  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00969090
//
// 00969090  33c9                 xor ecx, ecx
// 00969092  51                   push ecx
// 00969093  6a0f                 push 0xf
// 00969095  51                   push ecx
// 00969096  b8809a4400           mov eax, 0x449a80
// 0096909b  50                   push eax
// 0096909c  68a0414400           push 0x4441a0
// 009690a1  6808aa9a00           push 0x9aaa08
// 009690a6  6850ab9a00           push 0x9aab50
// 009690ab  b9c0b1b700           mov ecx, 0xb7b1c0
// 009690b0  e81becadff           call 0x447cd0
// 009690b5  68d0e39700           push 0x97e3d0
// 009690ba  e86ab8e8ff           call 0x7f4929
// 009690bf  59                   pop ecx
// 009690c0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_004441a0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("ShowBoundingBoxes", "Debug", func_004441a0, &Owner::m0, 15, 0);
