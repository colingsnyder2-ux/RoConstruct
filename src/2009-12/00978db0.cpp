// from server: 100% by nuck16
// roc 2009-12 00978db0  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978db0
//
// 00978db0  6a01                 push 1
// 00978db2  6840b09b00           push 0x9bb040
// 00978db7  68b4c09c00           push 0x9cc0b4
// 00978dbc  6898000000           push 0x98
// 00978dc1  b9a061b900           mov ecx, 0xb961a0
// 00978dc6  e86591dbff           call 0x731f30
// 00978dcb  6830859800           push 0x988530
// 00978dd0  e854bbe7ff           call 0x7f4929
// 00978dd5  59                   pop ecx
// 00978dd6  c3                   ret 

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

static Desc desc(152, "Changed", "value", 1);
