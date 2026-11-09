// from server: 100% by nuck16
// roc 2009-12 00978180  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978180
//
// 00978180  6a01                 push 1
// 00978182  6874e29d00           push 0x9de274
// 00978187  33c9                 xor ecx, ecx
// 00978189  6860e29d00           push 0x9de260
// 0097818e  51                   push ecx
// 0097818f  b870684700           mov eax, 0x476870
// 00978194  50                   push eax
// 00978195  b9a051b900           mov ecx, 0xb951a0
// 0097819a  e8512dd9ff           call 0x70aef0
// 0097819f  68a0789800           push 0x9878a0
// 009781a4  e880c7e7ff           call 0x7f4929
// 009781a9  59                   pop ecx
// 009781aa  c3                   ret 

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

static Desc desc(&Owner::m0, "SetAssetVersionUrl", "assetVersionUrl", 1);
