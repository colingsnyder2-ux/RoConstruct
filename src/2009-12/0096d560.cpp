// from server: 100% by nuck16
// roc 2009-12 0096d560  unit: seg_00960000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d560
//
// 0096d560  6a01                 push 1
// 0096d562  33c9                 xor ecx, ecx
// 0096d564  685ce39b00           push 0x9be35c
// 0096d569  51                   push ecx
// 0096d56a  b860b25400           mov eax, 0x54b260
// 0096d56f  50                   push eax
// 0096d570  b94006b800           mov ecx, 0xb80640
// 0096d575  e8b674bdff           call 0x544a30
// 0096d57a  6810079800           push 0x980710
// 0096d57f  e8a573e8ff           call 0x7f4929
// 0096d584  59                   pop ecx
// 0096d585  c3                   ret 

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

static Desc desc(&Owner::m0, "SendMarker", 1);
