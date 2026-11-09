// from server: 100% by nuck16
// roc 2009-12 00978240  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978240
//
// 00978240  33c9                 xor ecx, ecx
// 00978242  51                   push ecx
// 00978243  68d8e29d00           push 0x9de2d8
// 00978248  68c8e29d00           push 0x9de2c8
// 0097824d  51                   push ecx
// 0097824e  b810ea7000           mov eax, 0x70ea10
// 00978253  50                   push eax
// 00978254  b9b052b900           mov ecx, 0xb952b0
// 00978259  e89237d9ff           call 0x70b9f0
// 0097825e  6850789800           push 0x987850
// 00978263  e8c1c6e7ff           call 0x7f4929
// 00978268  59                   pop ecx
// 00978269  c3                   ret 

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

static Desc desc(&Owner::m0, "GetCollection", "categoryId", 0);
