// from server: 100% by nuck16
// roc 2009-12 00975ab0  unit: seg_00970000  size: 57 bytes
//
// 00975ab0  56                   push esi
// 00975ab1  33f6                 xor esi, esi
// 00975ab3  56                   push esi
// 00975ab4  6a0f                 push 0xf
// 00975ab6  33c9                 xor ecx, ecx
// 00975ab8  51                   push ecx
// 00975ab9  b8e0d86d00           mov eax, 0x6dd8e0
// 00975abe  50                   push eax
// 00975abf  56                   push esi
// 00975ac0  ba407e6700           mov edx, 0x677e40
// 00975ac5  52                   push edx
// 00975ac6  68c09b9d00           push 0x9d9bc0
// 00975acb  68c09a9d00           push 0x9d9ac0
// 00975ad0  b91833b900           mov ecx, 0xb93318
// 00975ad5  e87680d6ff           call 0x6ddb50
// 00975ada  6890639800           push 0x986390
// 00975adf  e845eee7ff           call 0x7f4929
// 00975ae4  83c404               add esp, 4
// 00975ae7  5e                   pop esi
// 00975ae8  c3                   ret 

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

static Desc desc("CameraType", "Camera", &Owner::m0, &Owner::m1, 15, 0);
