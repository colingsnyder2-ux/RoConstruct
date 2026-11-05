// from server: 100% by nuck16
// roc 2009-12 00978150  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978150
//
// 00978150  6a01                 push 1
// 00978152  6854e29d00           push 0x9de254
// 00978157  33c9                 xor ecx, ecx
// 00978159  68a8a69d00           push 0x9da6a8
// 0097815e  51                   push ecx
// 0097815f  b8602a7000           mov eax, 0x702a60
// 00978164  50                   push eax
// 00978165  b9a04fb900           mov ecx, 0xb94fa0
// 0097816a  e8812dd9ff           call 0x70aef0
// 0097816f  6890789800           push 0x987890
// 00978174  e8b0c7e7ff           call 0x7f4929
// 00978179  59                   pop ecx
// 0097817a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetAssetUrl", "assetUrl", 1);
