// from server: 100% by nuck16
// roc 2009-12 00975d60  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00975d60
//
// 00975d60  6a04                 push 4
// 00975d62  68c4a69d00           push 0x9da6c4
// 00975d67  33c9                 xor ecx, ecx
// 00975d69  68b4a69d00           push 0x9da6b4
// 00975d6e  51                   push ecx
// 00975d6f  b8200a6e00           mov eax, 0x6e0a20
// 00975d74  50                   push eax
// 00975d75  b95834b900           mov ecx, 0xb93458
// 00975d7a  e831bbd6ff           call 0x6e18b0
// 00975d7f  6890649800           push 0x986490
// 00975d84  e8a0ebe7ff           call 0x7f4929
// 00975d89  59                   pop ecx
// 00975d8a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetAccessKey", "access", 4);
