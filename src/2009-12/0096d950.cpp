// from server: 100% by nuck16
// roc 2009-12 0096d950  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d950
//
// 0096d950  6a01                 push 1
// 0096d952  6840b09b00           push 0x9bb040
// 0096d957  33c9                 xor ecx, ecx
// 0096d959  6854e89b00           push 0x9be854
// 0096d95e  51                   push ecx
// 0096d95f  b860045500           mov eax, 0x550460
// 0096d964  50                   push eax
// 0096d965  b90008b800           mov ecx, 0xb80800
// 0096d96a  e8a132beff           call 0x550c10
// 0096d96f  68f0099800           push 0x9809f0
// 0096d974  e8b06fe8ff           call 0x7f4929
// 0096d979  59                   pop ecx
// 0096d97a  c3                   ret 

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

static Desc desc(&Owner::m0, "LogPackets", "value", 1);
