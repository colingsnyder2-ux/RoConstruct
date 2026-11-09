// from server: 100% by nuck16
// roc 2009-12 0096d620  unit: seg_00960000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d620
//
// 0096d620  6a01                 push 1
// 0096d622  33c9                 xor ecx, ecx
// 0096d624  51                   push ecx
// 0096d625  68ace39b00           push 0x9be3ac
// 0096d62a  6898e39b00           push 0x9be398
// 0096d62f  51                   push ecx
// 0096d630  b870945300           mov eax, 0x539470
// 0096d635  50                   push eax
// 0096d636  b9d006b800           mov ecx, 0xb806d0
// 0096d63b  e8d077bdff           call 0x544e10
// 0096d640  6800079800           push 0x980700
// 0096d645  e8df72e8ff           call 0x7f4929
// 0096d64a  59                   pop ecx
// 0096d64b  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(void (Owner::*)(), const char *, const char *, int, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "GetRakStatsString", "verbosityLevel", 0, 1);
