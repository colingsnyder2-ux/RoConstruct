// from server: 100% by nuck16
// roc 2009-12 0097b570  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b570
//
// 0097b570  33c9                 xor ecx, ecx
// 0097b572  51                   push ecx
// 0097b573  68207b9e00           push 0x9e7b20
// 0097b578  68407b9e00           push 0x9e7b40
// 0097b57d  51                   push ecx
// 0097b57e  b8806b7600           mov eax, 0x766b80
// 0097b583  50                   push eax
// 0097b584  b9187cb900           mov ecx, 0xb97c18
// 0097b589  e83284deff           call 0x7639c0
// 0097b58e  6890999800           push 0x989990
// 0097b593  e89193e7ff           call 0x7f4929
// 0097b598  59                   pop ecx
// 0097b599  c3                   ret 

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

static Desc desc(&Owner::m0, "IsLegal", "badgeId", 0);
