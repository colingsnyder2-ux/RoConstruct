// from server: 100% by nuck16
// roc 2009-12 00975b70  unit: seg_00970000  size: 57 bytes
//
// 00975b70  56                   push esi
// 00975b71  33f6                 xor esi, esi
// 00975b73  56                   push esi
// 00975b74  6a0f                 push 0xf
// 00975b76  33c9                 xor ecx, ecx
// 00975b78  51                   push ecx
// 00975b79  b820d96d00           mov eax, 0x6dd920
// 00975b7e  50                   push eax
// 00975b7f  56                   push esi
// 00975b80  ba70c16d00           mov edx, 0x6dc170
// 00975b85  52                   push edx
// 00975b86  68c09b9d00           push 0x9d9bc0
// 00975b8b  68889b9d00           push 0x9d9b88
// 00975b90  b9ec32b900           mov ecx, 0xb932ec
// 00975b95  e87676d6ff           call 0x6dd210
// 00975b9a  6870639800           push 0x986370
// 00975b9f  e885ede7ff           call 0x7f4929
// 00975ba4  83c404               add esp, 4
// 00975ba7  5e                   pop esi
// 00975ba8  c3                   ret 

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

static Desc desc("CameraSubject", "Camera", &Owner::m0, &Owner::m1, 15, 0);
