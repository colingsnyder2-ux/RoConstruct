// from server: 100% by nuck16
// roc 2009-12 00978f20  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978f20
//
// 00978f20  6a01                 push 1
// 00978f22  6840b09b00           push 0x9bb040
// 00978f27  68b4c09c00           push 0x9cc0b4
// 00978f2c  68b0000000           push 0xb0
// 00978f31  b96861b900           mov ecx, 0xb96168
// 00978f36  e89592dbff           call 0x7321d0
// 00978f3b  68f0829800           push 0x9882f0
// 00978f40  e8e4b9e7ff           call 0x7f4929
// 00978f45  59                   pop ecx
// 00978f46  c3                   ret 

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
