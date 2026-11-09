// from server: 100% by nuck16
// roc 2009-12 00979d50  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979d50
//
// 00979d50  33c9                 xor ecx, ecx
// 00979d52  51                   push ecx
// 00979d53  6880f99c00           push 0x9cf980
// 00979d58  68c8e29d00           push 0x9de2c8
// 00979d5d  51                   push ecx
// 00979d5e  b8d0ee7300           mov eax, 0x73eed0
// 00979d63  50                   push eax
// 00979d64  b9e068b900           mov ecx, 0xb968e0
// 00979d69  e89257dcff           call 0x73f500
// 00979d6e  68608c9800           push 0x988c60
// 00979d73  e8b1abe7ff           call 0x7f4929
// 00979d78  59                   pop ecx
// 00979d79  c3                   ret 

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

static Desc desc(&Owner::m0, "GetCollection", "class", 0);
