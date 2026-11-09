// from server: 100% by nuck16
// roc 2009-12 0096c680  unit: seg_00960000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096c680
//
// 0096c680  6a04                 push 4
// 0096c682  689cb19b00           push 0x9bb19c
// 0096c687  33c9                 xor ecx, ecx
// 0096c689  68fcb89b00           push 0x9bb8fc
// 0096c68e  51                   push ecx
// 0096c68f  b8d0245100           mov eax, 0x5124d0
// 0096c694  50                   push eax
// 0096c695  b960efb700           mov ecx, 0xb7ef60
// 0096c69a  e8d107bbff           call 0x51ce70
// 0096c69f  68e0fb9700           push 0x97fbe0
// 0096c6a4  e88082e8ff           call 0x7f4929
// 0096c6a9  59                   pop ecx
// 0096c6aa  c3                   ret 

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

static Desc desc(&Owner::m0, "SetChatFilterUrl", "url", 4);
