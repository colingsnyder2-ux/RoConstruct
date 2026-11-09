// from server: 100% by nuck16
// roc 2009-12 009781b0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009781b0
//
// 009781b0  6a01                 push 1
// 009781b2  6898e29d00           push 0x9de298
// 009781b7  33c9                 xor ecx, ecx
// 009781b9  6884e29d00           push 0x9de284
// 009781be  51                   push ecx
// 009781bf  b8b02a7000           mov eax, 0x702ab0
// 009781c4  50                   push eax
// 009781c5  b95851b900           mov ecx, 0xb95158
// 009781ca  e8b12ed9ff           call 0x70b080
// 009781cf  68b0789800           push 0x9878b0
// 009781d4  e850c7e7ff           call 0x7f4929
// 009781d9  59                   pop ecx
// 009781da  c3                   ret 

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

static Desc desc(&Owner::m0, "SetAdvancedResults", "enable", 1);
