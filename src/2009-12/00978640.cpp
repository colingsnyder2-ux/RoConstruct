// from server: 100% by nuck16
// roc 2009-12 00978640  unit: seg_00970000  size: 57 bytes
//
// 00978640  56                   push esi
// 00978641  33f6                 xor esi, esi
// 00978643  56                   push esi
// 00978644  6a0f                 push 0xf
// 00978646  33c9                 xor ecx, ecx
// 00978648  51                   push ecx
// 00978649  b8c06b7100           mov eax, 0x716bc0
// 0097864e  50                   push eax
// 0097864f  56                   push esi
// 00978650  bae05e7100           mov edx, 0x715ee0
// 00978655  52                   push edx
// 00978656  6884b09b00           push 0x9bb084
// 0097865b  68c8f49d00           push 0x9df4c8
// 00978660  b9b456b900           mov ecx, 0xb956b4
// 00978665  e896ddd9ff           call 0x716400
// 0097866a  68307c9800           push 0x987c30
// 0097866f  e8b5c2e7ff           call 0x7f4929
// 00978674  83c404               add esp, 4
// 00978677  5e                   pop esi
// 00978678  c3                   ret 

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

static Desc desc("Part0", "Data", &Owner::m0, &Owner::m1, 15, 0);
