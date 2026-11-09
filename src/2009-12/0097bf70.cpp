// from server: 100% by nuck16
// roc 2009-12 0097bf70  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097bf70
//
// 0097bf70  6a00                 push 0
// 0097bf72  6a02                 push 2
// 0097bf74  68f8000000           push 0xf8
// 0097bf79  68801b9d00           push 0x9d1b80
// 0097bf7e  68883e9e00           push 0x9e3e88
// 0097bf83  b9d083b900           mov ecx, 0xb983d0
// 0097bf88  e8132bdfff           call 0x76eaa0
// 0097bf8d  68d09d9800           push 0x989dd0
// 0097bf92  e89289e7ff           call 0x7f4929
// 0097bf97  59                   pop ecx
// 0097bf98  c3                   ret 

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
    Desc(const char *, const char *, int, int, int);
    ~Desc();
};

static Desc desc("MouseLeaveConnectionCount", "EventReplicator", 248, 2, 0);
