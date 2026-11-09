// from server: 100% by nuck16
// roc 2009-12 009782a0  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009782a0
//
// 009782a0  33c9                 xor ecx, ecx
// 009782a2  51                   push ecx
// 009782a3  6804e39d00           push 0x9de304
// 009782a8  68f0e29d00           push 0x9de2f0
// 009782ad  51                   push ecx
// 009782ae  b860097100           mov eax, 0x710960
// 009782b3  50                   push eax
// 009782b4  b97850b900           mov ecx, 0xb95078
// 009782b9  e8f238d9ff           call 0x70bbb0
// 009782be  6860789800           push 0x987860
// 009782c3  e861c6e7ff           call 0x7f4929
// 009782c8  59                   pop ecx
// 009782c9  c3                   ret 

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

static Desc desc(&Owner::m0, "LoadAssetVersion", "assetVersionId", 0);
