// from server: 100% by nuck16
// roc 2009-12 0096ed10  unit: seg_00960000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ed10
//
// 0096ed10  6a01                 push 1
// 0096ed12  6860c09c00           push 0x9cc060
// 0096ed17  6868c09c00           push 0x9cc068
// 0096ed1c  6a7c                 push 0x7c
// 0096ed1e  b9b454b800           mov ecx, 0xb854b4
// 0096ed23  e80873ccff           call 0x636030
// 0096ed28  6880199800           push 0x981980
// 0096ed2d  e8f75be8ff           call 0x7f4929
// 0096ed32  59                   pop ecx
// 0096ed33  c3                   ret 

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

static Desc desc(124, "ChildRemoved", "child", 1);
