// from server: 100% by nuck16
// roc 2009-12 00969010  unit: seg_00960000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00969010
//
// 00969010  33c9                 xor ecx, ecx
// 00969012  51                   push ecx
// 00969013  6a0f                 push 0xf
// 00969015  51                   push ecx
// 00969016  b880994400           mov eax, 0x449980
// 0096901b  50                   push eax
// 0096901c  6880047400           push 0x740480
// 00969021  6880aa9a00           push 0x9aaa80
// 00969026  6830ab9a00           push 0x9aab30
// 0096902b  b978b1b700           mov ecx, 0xb7b178
// 00969030  e8db17aeff           call 0x44a810
// 00969035  6870e29700           push 0x97e270
// 0096903a  e8eab8e8ff           call 0x7f4929
// 0096903f  59                   pop ecx
// 00969040  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

extern "C" void func_00740480();

struct Desc
{
    Desc(const char *, const char *, void (*)(), void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("IceQuality", "Quality", func_00740480, &Owner::m0, 15, 0);
