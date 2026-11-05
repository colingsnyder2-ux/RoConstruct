// from server: 100% by nuck16
// roc 2009-12 0096e770  unit: seg_00960000  size: 57 bytes
//
// 0096e770  56                   push esi
// 0096e771  33f6                 xor esi, esi
// 0096e773  56                   push esi
// 0096e774  6a0f                 push 0xf
// 0096e776  33c9                 xor ecx, ecx
// 0096e778  51                   push ecx
// 0096e779  b810166300           mov eax, 0x631610
// 0096e77e  50                   push eax
// 0096e77f  56                   push esi
// 0096e780  ba60bd6200           mov edx, 0x62bd60
// 0096e785  52                   push edx
// 0096e786  6820a79b00           push 0x9ba720
// 0096e78b  68bcb39c00           push 0x9cb3bc
// 0096e790  b9ec4ab800           mov ecx, 0xb84aec
// 0096e795  e85633ccff           call 0x631af0
// 0096e79a  68a0149800           push 0x9814a0
// 0096e79f  e88561e8ff           call 0x7f4929
// 0096e7a4  83c404               add esp, 4
// 0096e7a7  5e                   pop esi
// 0096e7a8  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
    void m1();
};


struct Desc
{
    Desc(const char *, const char *, void (Owner::*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("PriorityMethod", "Configuration", &Owner::m0, &Owner::m1, 15, 0);
