// from server: 100% by nuck16
// roc 2009-12 0097b5a0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097b5a0
//
// 0097b5a0  6a01                 push 1
// 0097b5a2  68547b9e00           push 0x9e7b54
// 0097b5a7  33c9                 xor ecx, ecx
// 0097b5a9  68487b9e00           push 0x9e7b48
// 0097b5ae  51                   push ecx
// 0097b5af  b8300e7600           mov eax, 0x760e30
// 0097b5b4  50                   push eax
// 0097b5b5  b9507db900           mov ecx, 0xb97d50
// 0097b5ba  e8b184deff           call 0x763a70
// 0097b5bf  68d0999800           push 0x9899d0
// 0097b5c4  e86093e7ff           call 0x7f4929
// 0097b5c9  59                   pop ecx
// 0097b5ca  c3                   ret 

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

static Desc desc(&Owner::m0, "SetPlaceId", "placeId", 1);
