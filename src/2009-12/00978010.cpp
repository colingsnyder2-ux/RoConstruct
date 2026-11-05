// from server: 100% by nuck16
// roc 2009-12 00978010  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978010
//
// 00978010  33c9                 xor ecx, ecx
// 00978012  51                   push ecx
// 00978013  6828dd9d00           push 0x9ddd28
// 00978018  51                   push ecx
// 00978019  b8e0866300           mov eax, 0x6386e0
// 0097801e  50                   push eax
// 0097801f  b9584eb900           mov ecx, 0xb94e58
// 00978024  e8c77fd8ff           call 0x6ffff0
// 00978029  68c0779800           push 0x9877c0
// 0097802e  e8f6c8e7ff           call 0x7f4929
// 00978033  59                   pop ecx
// 00978034  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GetTeams", 0);
