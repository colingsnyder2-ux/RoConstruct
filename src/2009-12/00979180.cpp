// from server: 100% by nuck16
// roc 2009-12 00979180  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979180
//
// 00979180  6a01                 push 1
// 00979182  6840b09b00           push 0x9bb040
// 00979187  68b4c09c00           push 0x9cc0b4
// 0097918c  68a0000000           push 0xa0
// 00979191  b9a05eb900           mov ecx, 0xb95ea0
// 00979196  e81594dbff           call 0x7325b0
// 0097919b  68f0839800           push 0x9883f0
// 009791a0  e884b7e7ff           call 0x7f4929
// 009791a5  59                   pop ecx
// 009791a6  c3                   ret 

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
