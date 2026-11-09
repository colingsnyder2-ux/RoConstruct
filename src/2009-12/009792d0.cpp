// from server: 100% by nuck16
// roc 2009-12 009792d0  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009792d0
//
// 009792d0  6a01                 push 1
// 009792d2  6840b09b00           push 0x9bb040
// 009792d7  68b4c09c00           push 0x9cc0b4
// 009792dc  68a0000000           push 0xa0
// 009792e1  b9b05fb900           mov ecx, 0xb95fb0
// 009792e6  e88594dbff           call 0x732770
// 009792eb  6870849800           push 0x988470
// 009792f0  e834b6e7ff           call 0x7f4929
// 009792f5  59                   pop ecx
// 009792f6  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};


struct Desc
{
    Desc(int, const char *, const char *, int);
    ~Desc();
};

static Desc desc(160, "Changed", "value", 1);
