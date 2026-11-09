// from server: 100% by nuck16
// roc 2009-12 0096ba50  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096ba50
//
// 0096ba50  6a01                 push 1
// 0096ba52  6840b09b00           push 0x9bb040
// 0096ba57  33c9                 xor ecx, ecx
// 0096ba59  6834b09b00           push 0x9bb034
// 0096ba5e  51                   push ecx
// 0096ba5f  b8102a9100           mov eax, 0x912a10
// 0096ba64  50                   push eax
// 0096ba65  b9a8e5b700           mov ecx, 0xb7e5a8
// 0096ba6a  e8f1ddb9ff           call 0x509860
// 0096ba6f  6830f49700           push 0x97f430
// 0096ba74  e8b08ee8ff           call 0x7f4929
// 0096ba79  59                   pop ecx
// 0096ba7a  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "SetUnder13", "value", 1);
