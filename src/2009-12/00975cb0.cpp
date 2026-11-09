// from server: 100% by nuck16
// roc 2009-12 00975cb0  unit: seg_00970000  size: 57 bytes
//
// 00975cb0  56                   push esi
// 00975cb1  33f6                 xor esi, esi
// 00975cb3  56                   push esi
// 00975cb4  6a0f                 push 0xf
// 00975cb6  33c9                 xor ecx, ecx
// 00975cb8  51                   push ecx
// 00975cb9  b8402a6800           mov eax, 0x682a40
// 00975cbe  50                   push eax
// 00975cbf  56                   push esi
// 00975cc0  ba00905c00           mov edx, 0x5c9000
// 00975cc5  52                   push edx
// 00975cc6  6884b09b00           push 0x9bb084
// 00975ccb  68141b9d00           push 0x9d1b14
// 00975cd0  b9c033b900           mov ecx, 0xb933c0
// 00975cd5  e8169cd6ff           call 0x6df8f0
// 00975cda  6830649800           push 0x986430
// 00975cdf  e845ece7ff           call 0x7f4929
// 00975ce4  83c404               add esp, 4
// 00975ce7  5e                   pop esi
// 00975ce8  c3                   ret 

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

static Desc desc("TextureId", "Data", &Owner::m0, &Owner::m1, 15, 0);
