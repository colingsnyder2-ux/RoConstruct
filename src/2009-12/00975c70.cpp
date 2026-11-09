// from server: 100% by nuck16
// roc 2009-12 00975c70  unit: seg_00970000  size: 57 bytes
//
// 00975c70  56                   push esi
// 00975c71  33f6                 xor esi, esi
// 00975c73  56                   push esi
// 00975c74  6a0f                 push 0xf
// 00975c76  33c9                 xor ecx, ecx
// 00975c78  51                   push ecx
// 00975c79  b870846300           mov eax, 0x638470
// 00975c7e  50                   push eax
// 00975c7f  56                   push esi
// 00975c80  ba40795700           mov edx, 0x577940
// 00975c85  52                   push edx
// 00975c86  6884b09b00           push 0x9bb084
// 00975c8b  6828a49d00           push 0x9da428
// 00975c90  b9e033b900           mov ecx, 0xb933e0
// 00975c95  e8a69bd6ff           call 0x6df840
// 00975c9a  6850649800           push 0x986450
// 00975c9f  e885ece7ff           call 0x7f4929
// 00975ca4  83c404               add esp, 4
// 00975ca7  5e                   pop esi
// 00975ca8  c3                   ret 

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

static Desc desc("MeshId", "Data", &Owner::m0, &Owner::m1, 15, 0);
