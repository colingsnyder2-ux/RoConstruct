// from server: 100% by nuck16
// roc 2009-12 00979020  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979020
//
// 00979020  6a01                 push 1
// 00979022  6840b09b00           push 0x9bb040
// 00979027  68b4c09c00           push 0x9cc0b4
// 0097902c  68b0000000           push 0xb0
// 00979031  b9b05cb900           mov ecx, 0xb95cb0
// 00979036  e85593dbff           call 0x732390
// 0097903b  6870839800           push 0x988370
// 00979040  e8e4b8e7ff           call 0x7f4929
// 00979045  59                   pop ecx
// 00979046  c3                   ret 

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

static Desc desc(176, "Changed", "value", 1);
