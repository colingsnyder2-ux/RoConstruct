// from server: 100% by nuck16
// roc 2009-12 0097adb0  unit: seg_00970000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097adb0
//
// 0097adb0  33c9                 xor ecx, ecx
// 0097adb2  51                   push ecx
// 0097adb3  6a0f                 push 0xf
// 0097adb5  51                   push ecx
// 0097adb6  b8608e7500           mov eax, 0x758e60
// 0097adbb  50                   push eax
// 0097adbc  6880047400           push 0x740480
// 0097adc1  6884b09b00           push 0x9bb084
// 0097adc6  682c5f9e00           push 0x9e5f2c
// 0097adcb  b9a075b900           mov ecx, 0xb975a0
// 0097add0  e87be5ddff           call 0x759350
// 0097add5  68d0949800           push 0x9894d0
// 0097adda  e84a9be7ff           call 0x7f4929
// 0097addf  59                   pop ecx
// 0097ade0  c3                   ret 

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

static Desc desc("TextYAlignment", "Data", func_00740480, &Owner::m0, 15, 0);
