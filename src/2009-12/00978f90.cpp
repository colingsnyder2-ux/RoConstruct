// from server: 100% by nuck16
// roc 2009-12 00978f90  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978f90
//
// 00978f90  6a01                 push 1
// 00978f92  6840b09b00           push 0x9bb040
// 00978f97  68b4c09c00           push 0x9cc0b4
// 00978f9c  68a0000000           push 0xa0
// 00978fa1  b9f45eb900           mov ecx, 0xb95ef4
// 00978fa6  e80593dbff           call 0x7322b0
// 00978fab  6830839800           push 0x988330
// 00978fb0  e874b9e7ff           call 0x7f4929
// 00978fb5  59                   pop ecx
// 00978fb6  c3                   ret 

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
