// from server: 100% by nuck16
// roc 2009-12 0096edd0  unit: seg_00960000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096edd0
//
// 0096edd0  6a01                 push 1
// 0096edd2  68bcc09c00           push 0x9cc0bc
// 0096edd7  68b4c09c00           push 0x9cc0b4
// 0096eddc  688c000000           push 0x8c
// 0096ede1  b95852b800           mov ecx, 0xb85258
// 0096ede6  e86574ccff           call 0x636250
// 0096edeb  68801a9800           push 0x981a80
// 0096edf0  e8345be8ff           call 0x7f4929
// 0096edf5  59                   pop ecx
// 0096edf6  c3                   ret 

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

static Desc desc(140, "Changed", "property", 1);
