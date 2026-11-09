// from server: 100% by nuck16
// roc 2009-12 00979110  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979110
//
// 00979110  6a01                 push 1
// 00979112  6840b09b00           push 0x9bb040
// 00979117  68b4c09c00           push 0x9cc0b4
// 0097911c  68c4000000           push 0xc4
// 00979121  b90860b900           mov ecx, 0xb96008
// 00979126  e84593dbff           call 0x732470
// 0097912b  68b0839800           push 0x9883b0
// 00979130  e8f4b7e7ff           call 0x7f4929
// 00979135  59                   pop ecx
// 00979136  c3                   ret 

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

static Desc desc(196, "Changed", "value", 1);
