// from server: 100% by nuck16
// roc 2009-12 00979410  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979410
//
// 00979410  6a01                 push 1
// 00979412  6840b09b00           push 0x9bb040
// 00979417  68b4c09c00           push 0x9cc0b4
// 0097941c  689c000000           push 0x9c
// 00979421  b9cc5db900           mov ecx, 0xb95dcc
// 00979426  e80595dbff           call 0x732930
// 0097942b  68f0849800           push 0x9884f0
// 00979430  e8f4b4e7ff           call 0x7f4929
// 00979435  59                   pop ecx
// 00979436  c3                   ret 

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

static Desc desc(156, "Changed", "value", 1);
