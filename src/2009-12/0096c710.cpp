// from server: 100% by nuck16
// roc 2009-12 0096c710  unit: seg_00960000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c710
//
// 0096c710  33c9                 xor ecx, ecx
// 0096c712  51                   push ecx
// 0096c713  6828b19b00           push 0x9bb128
// 0096c718  6840b99b00           push 0x9bb940
// 0096c71d  51                   push ecx
// 0096c71e  b8b05d5100           mov eax, 0x515db0
// 0096c723  50                   push eax
// 0096c724  b928f0b700           mov ecx, 0xb7f028
// 0096c729  e8a20cbbff           call 0x51d3d0
// 0096c72e  68a0fc9700           push 0x97fca0
// 0096c733  e8f181e8ff           call 0x7f4929
// 0096c738  59                   pop ecx
// 0096c739  c3                   ret 

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

static Desc desc(&Owner::m0, "playerFromCharacter", "character", 0);
