// from server: 100% by nuck16
// roc 2009-12 009793a0  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009793a0
//
// 009793a0  6a01                 push 1
// 009793a2  6840b09b00           push 0x9bb040
// 009793a7  68b4c09c00           push 0x9cc0b4
// 009793ac  68b0000000           push 0xb0
// 009793b1  b9285db900           mov ecx, 0xb95d28
// 009793b6  e89594dbff           call 0x732850
// 009793bb  68b0849800           push 0x9884b0
// 009793c0  e864b5e7ff           call 0x7f4929
// 009793c5  59                   pop ecx
// 009793c6  c3                   ret 

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
