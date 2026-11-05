// from server: 100% by nuck16
// roc 2009-12 009759b0  unit: seg_00970000  size: 57 bytes
//
// 009759b0  56                   push esi
// 009759b1  33f6                 xor esi, esi
// 009759b3  56                   push esi
// 009759b4  6a02                 push 2
// 009759b6  33c9                 xor ecx, ecx
// 009759b8  51                   push ecx
// 009759b9  b8e0b96d00           mov eax, 0x6db9e0
// 009759be  50                   push eax
// 009759bf  56                   push esi
// 009759c0  ba70a96d00           mov edx, 0x6da970
// 009759c5  52                   push edx
// 009759c6  68e0989d00           push 0x9d98e0
// 009759cb  68889b9d00           push 0x9d9b88
// 009759d0  b93032b900           mov ecx, 0xb93230
// 009759d5  e81652d6ff           call 0x6dabf0
// 009759da  68d0629800           push 0x9862d0
// 009759df  e845efe7ff           call 0x7f4929
// 009759e4  83c404               add esp, 4
// 009759e7  5e                   pop esi
// 009759e8  c3                   ret 

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

static Desc desc("CameraSubject", "PlayerCamera", &Owner::m0, &Owner::m1, 2, 0);
