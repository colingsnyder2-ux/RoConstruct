// from server: 100% by nuck16
// roc 2009-12 00975970  unit: seg_00970000  size: 57 bytes
//
// 00975970  56                   push esi
// 00975971  33f6                 xor esi, esi
// 00975973  56                   push esi
// 00975974  6a02                 push 2
// 00975976  33c9                 xor ecx, ecx
// 00975978  51                   push ecx
// 00975979  b810b56d00           mov eax, 0x6db510
// 0097597e  50                   push eax
// 0097597f  56                   push esi
// 00975980  bab0a86d00           mov edx, 0x6da8b0
// 00975985  52                   push edx
// 00975986  68e0989d00           push 0x9d98e0
// 0097598b  68c09a9d00           push 0x9d9ac0
// 00975990  b95432b900           mov ecx, 0xb93254
// 00975995  e88662d6ff           call 0x6dbc20
// 0097599a  68f0629800           push 0x9862f0
// 0097599f  e885efe7ff           call 0x7f4929
// 009759a4  83c404               add esp, 4
// 009759a7  5e                   pop esi
// 009759a8  c3                   ret 

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

static Desc desc("CameraType", "PlayerCamera", &Owner::m0, &Owner::m1, 2, 0);
