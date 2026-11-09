// from server: 100% by nuck16
// roc 2009-12 0096ece0  unit: seg_00960000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ece0
//
// 0096ece0  6a01                 push 1
// 0096ece2  6860c09c00           push 0x9cc060
// 0096ece7  6854c09c00           push 0x9cc054
// 0096ecec  6a78                 push 0x78
// 0096ecee  b97c54b800           mov ecx, 0xb8547c
// 0096ecf3  e83873ccff           call 0x636030
// 0096ecf8  68d01a9800           push 0x981ad0
// 0096ecfd  e8275ce8ff           call 0x7f4929
// 0096ed02  59                   pop ecx
// 0096ed03  c3                   ret 

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

static Desc desc(120, "ChildAdded", "child", 1);
