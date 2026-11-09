// from server: 100% by nuck16
// roc 2009-12 00978990  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978990
//
// 00978990  6a01                 push 1
// 00978992  68d81d9b00           push 0x9b1dd8
// 00978997  684cf69d00           push 0x9df64c
// 0097899c  68d8000000           push 0xd8
// 009789a1  b94858b900           mov ecx, 0xb95848
// 009789a6  e8e50bdaff           call 0x719590
// 009789ab  68c07d9800           push 0x987dc0
// 009789b0  e874bfe7ff           call 0x7f4929
// 009789b5  59                   pop ecx
// 009789b6  c3                   ret 

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

static Desc desc(216, "AssemblyRemoved", "part", 1);
