// from server: 100% by nuck16
// roc 2009-12 00969190  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00969190
//
// 00969190  33c9                 xor ecx, ecx
// 00969192  51                   push ecx
// 00969193  6a0f                 push 0xf
// 00969195  51                   push ecx
// 00969196  b8409b4400           mov eax, 0x449b40
// 0096919b  50                   push eax
// 0096919c  68d0414400           push 0x4441d0
// 009691a1  6808aa9a00           push 0x9aaa08
// 009691a6  68a8ab9a00           push 0x9aaba8
// 009691ab  b940b2b700           mov ecx, 0xb7b240
// 009691b0  e81bebadff           call 0x447cd0
// 009691b5  6850e49700           push 0x97e450
// 009691ba  e86ab7e8ff           call 0x7f4929
// 009691bf  59                   pop ecx
// 009691c0  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_004441d0();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("DebugFRMCullHumanoids", "Debug", func_004441d0, &Owner::m0, 15, 0);
