// from server: 100% by nuck16
// roc 2009-12 00979f30  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979f30
//
// 00979f30  6a01                 push 1
// 00979f32  68d8e19d00           push 0x9de1d8
// 00979f37  33c9                 xor ecx, ecx
// 00979f39  6814289e00           push 0x9e2814
// 00979f3e  51                   push ecx
// 00979f3f  b800047400           mov eax, 0x740400
// 00979f44  50                   push eax
// 00979f45  b9e06ab900           mov ecx, 0xb96ae0
// 00979f4a  e8e168dcff           call 0x740830
// 00979f4f  68308d9800           push 0x988d30
// 00979f54  e8d0a9e7ff           call 0x7f4929
// 00979f59  59                   pop ecx
// 00979f5a  c3                   ret 

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

static Desc desc(&Owner::m0, "TypeKey", "key", 1);
