// from server: 100% by nuck16
// roc 2009-12 0096d590  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d590
//
// 0096d590  6a01                 push 1
// 0096d592  33c9                 xor ecx, ecx
// 0096d594  6868e39b00           push 0x9be368
// 0096d599  51                   push ecx
// 0096d59a  b8a09f5400           mov eax, 0x549fa0
// 0096d59f  50                   push eax
// 0096d5a0  b98006b800           mov ecx, 0xb80680
// 0096d5a5  e80676bdff           call 0x544bb0
// 0096d5aa  6880069800           push 0x980680
// 0096d5af  e87573e8ff           call 0x7f4929
// 0096d5b4  59                   pop ecx
// 0096d5b5  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "RequestCharacter", 1);
