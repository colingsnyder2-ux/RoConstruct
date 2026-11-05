// from server: 100% by nuck16
// roc 2009-12 00979f00  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979f00
//
// 00979f00  6a01                 push 1
// 00979f02  68a0b19b00           push 0x9bb1a0
// 00979f07  33c9                 xor ecx, ecx
// 00979f09  6808289e00           push 0x9e2808
// 00979f0e  51                   push ecx
// 00979f0f  b890017400           mov eax, 0x740190
// 00979f14  50                   push eax
// 00979f15  b9b86bb900           mov ecx, 0xb96bb8
// 00979f1a  e88167dcff           call 0x7406a0
// 00979f1f  68208d9800           push 0x988d20
// 00979f24  e800aae7ff           call 0x7f4929
// 00979f29  59                   pop ecx
// 00979f2a  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(void (Owner::*)(), const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "MoveMouse", "position", 1);
