// from server: 100% by nuck16
// roc 2009-12 0096de80  unit: seg_00960000  size: 45 bytes
//
// 0096de80  33c9                 xor ecx, ecx
// 0096de82  51                   push ecx
// 0096de83  6a0f                 push 0xf
// 0096de85  51                   push ecx
// 0096de86  51                   push ecx
// 0096de87  b850be6200           mov eax, 0x62be50
// 0096de8c  50                   push eax
// 0096de8d  6864b79a00           push 0x9ab764
// 0096de92  68d8b89c00           push 0x9cb8d8
// 0096de97  b95c4cb800           mov ecx, 0xb84c5c
// 0096de9c  e81f16ccff           call 0x62f4c0
// 0096dea1  6840159800           push 0x981540
// 0096dea6  e87e6ae8ff           call 0x7f4929
// 0096deab  59                   pop ecx
// 0096deac  c3                   ret 

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
    Desc(const char *, const char *, void (Owner::*)(), int, int, int);
    ~Desc();
};

static Desc desc("VertexShaderModel", "Profile", &Owner::m0, 0, 15, 0);
