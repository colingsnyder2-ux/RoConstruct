// from server: 100% by nuck16
// roc 2009-12 00979f90  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979f90
//
// 00979f90  6a01                 push 1
// 00979f92  68d8e19d00           push 0x9de1d8
// 00979f97  33c9                 xor ecx, ecx
// 00979f99  6828289e00           push 0x9e2828
// 00979f9e  51                   push ecx
// 00979f9f  b840037400           mov eax, 0x740340
// 00979fa4  50                   push eax
// 00979fa5  b9506ab900           mov ecx, 0xb96a50
// 00979faa  e88168dcff           call 0x740830
// 00979faf  68c08c9800           push 0x988cc0
// 00979fb4  e870a9e7ff           call 0x7f4929
// 00979fb9  59                   pop ecx
// 00979fba  c3                   ret 

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

static Desc desc(&Owner::m0, "SetKeyUp", "key", 1);
