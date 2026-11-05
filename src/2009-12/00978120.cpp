// from server: 100% by nuck16
// roc 2009-12 00978120  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978120
//
// 00978120  6a01                 push 1
// 00978122  6844e29d00           push 0x9de244
// 00978127  33c9                 xor ecx, ecx
// 00978129  6830e29d00           push 0x9de230
// 0097812e  51                   push ecx
// 0097812f  b8102a7000           mov eax, 0x702a10
// 00978134  50                   push eax
// 00978135  b9c050b900           mov ecx, 0xb950c0
// 0097813a  e8b12dd9ff           call 0x70aef0
// 0097813f  6880789800           push 0x987880
// 00978144  e8e0c7e7ff           call 0x7f4929
// 00978149  59                   pop ecx
// 0097814a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetCollectionUrl", "collectionUrl", 1);
