// from server: 100% by nuck16
// roc 2009-12 00973550  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973550
//
// 00973550  6a01                 push 1
// 00973552  68f8089d00           push 0x9d08f8
// 00973557  33c9                 xor ecx, ecx
// 00973559  68ec089d00           push 0x9d08ec
// 0097355e  51                   push ecx
// 0097355f  b8707a6800           mov eax, 0x687a70
// 00973564  50                   push eax
// 00973565  b9480fb900           mov ecx, 0xb90f48
// 0097356a  e86120d1ff           call 0x6855d0
// 0097356f  68704f9800           push 0x984f70
// 00973574  e8b013e8ff           call 0x7f4929
// 00973579  59                   pop ecx
// 0097357a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetEnabled", "state", 1);
