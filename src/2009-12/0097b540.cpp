// from server: 100% by nuck16
// roc 2009-12 0097b540  unit: seg_00970000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b540
//
// 0097b540  33c9                 xor ecx, ecx
// 0097b542  51                   push ecx
// 0097b543  68207b9e00           push 0x9e7b20
// 0097b548  68347b9e00           push 0x9e7b34
// 0097b54d  51                   push ecx
// 0097b54e  b860667600           mov eax, 0x766660
// 0097b553  50                   push eax
// 0097b554  b9807bb900           mov ecx, 0xb97b80
// 0097b559  e86284deff           call 0x7639c0
// 0097b55e  68c0999800           push 0x9899c0
// 0097b563  e8c193e7ff           call 0x7f4929
// 0097b568  59                   pop ecx
// 0097b569  c3                   ret 

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

static Desc desc(&Owner::m0, "IsDisabled", "badgeId", 0);
