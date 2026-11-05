// from server: 100% by nuck16
// roc 2009-12 00978270  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978270
//
// 00978270  33c9                 xor ecx, ecx
// 00978272  51                   push ecx
// 00978273  68f8ec9c00           push 0x9cecf8
// 00978278  68e4e29d00           push 0x9de2e4
// 0097827d  51                   push ecx
// 0097827e  b880077100           mov eax, 0x710780
// 00978283  50                   push eax
// 00978284  b96852b900           mov ecx, 0xb95268
// 00978289  e82239d9ff           call 0x70bbb0
// 0097828e  68d0789800           push 0x9878d0
// 00978293  e891c6e7ff           call 0x7f4929
// 00978298  59                   pop ecx
// 00978299  c3                   ret 

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

static Desc desc(&Owner::m0, "LoadAsset", "assetId", 0);
