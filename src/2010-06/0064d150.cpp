// from server: 100% by Yeetserama
// roc 2010-06 0064d150  unit: RBX::VController::?$BoundFuncDesc  size: 282 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0064d150
//
// 0064d150  6aff                 push -1
// 0064d152  6880409a00           push 0x9a4080
// 0064d157  64a100000000         mov eax, dword ptr fs:[0]
// 0064d15d  50                   push eax
// 0064d15e  64892500000000       mov dword ptr fs:[0], esp
// 0064d165  83ec1c               sub esp, 0x1c
// 0064d168  56                   push esi
// 0064d169  57                   push edi
// 0064d16a  8bf9                 mov edi, ecx
// 0064d16c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 0064d16f  8b4740               mov eax, dword ptr [edi + 0x40]
// 0064d172  89442410             mov dword ptr [esp + 0x10], eax
// 0064d176  85c9                 test ecx, ecx
// 0064d178  7409                 je 0x64d183
// 0064d17a  8b11                 mov edx, dword ptr [ecx]
// 0064d17c  8b4208               mov eax, dword ptr [edx + 8]
// 0064d17f  ffd0                 call eax
// 0064d181  eb02                 jmp 0x64d185
// 0064d183  33c0                 xor eax, eax
// 0064d185  89442414             mov dword ptr [esp + 0x14], eax
// 0064d189  8b742438             mov esi, dword ptr [esp + 0x38]
// 0064d18d  8b16                 mov edx, dword ptr [esi]
// 0064d18f  8b5204               mov edx, dword ptr [edx + 4]
// 0064d192  8d442410             lea eax, [esp + 0x10]
// 0064d196  50                   push eax
// 0064d197  6a01                 push 1
// 0064d199  8bce                 mov ecx, esi
// 0064d19b  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0064d1a3  ffd2                 call edx
// 0064d1a5  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 0064d1a8  8b4748               mov eax, dword ptr [edi + 0x48]
// 0064d1ab  89442408             mov dword ptr [esp + 8], eax
// 0064d1af  85c9                 test ecx, ecx
// 0064d1b1  7409                 je 0x64d1bc
// 0064d1b3  8b11                 mov edx, dword ptr [ecx]
// 0064d1b5  8b4208               mov eax, dword ptr [edx + 8]
// 0064d1b8  ffd0                 call eax
// 0064d1ba  eb02                 jmp 0x64d1be
// 0064d1bc  33c0                 xor eax, eax
// 0064d1be  8944240c             mov dword ptr [esp + 0xc], eax
// 0064d1c2  8b16                 mov edx, dword ptr [esi]
// 0064d1c4  8b5204               mov edx, dword ptr [edx + 4]
// 0064d1c7  8d442408             lea eax, [esp + 8]
// 0064d1cb  50                   push eax
// 0064d1cc  6a02                 push 2
// 0064d1ce  8bce                 mov ecx, esi
// 0064d1d0  c644243401           mov byte ptr [esp + 0x34], 1
// 0064d1d5  ffd2                 call edx
// 0064d1d7  8b442434             mov eax, dword ptr [esp + 0x34]
// 0064d1db  6a00                 push 0
// 0064d1dd  683c87bb00           push 0xbb873c
// 0064d1e2  684090b700           push 0xb79040
// 0064d1e7  6a00                 push 0
// 0064d1e9  50                   push eax
// 0064d1ea  e8fbb91500           call 0x7a8bea
// 0064d1ef  83c414               add esp, 0x14
// 0064d1f2  85c0                 test eax, eax
// 0064d1f4  751e                 jne 0x64d214
// 0064d1f6  68540aa000           push 0xa00a54
// 0064d1fb  8d4c241c             lea ecx, [esp + 0x1c]
// 0064d1ff  ff159ca89e00         call dword ptr [0x9ea89c]
// 0064d205  689022b100           push 0xb12290
// 0064d20a  8d4c241c             lea ecx, [esp + 0x1c]
// 0064d20e  51                   push ecx
// 0064d20f  e89eb71500           call 0x7a89b2
// 0064d214  8d542408             lea edx, [esp + 8]
// 0064d218  52                   push edx
// 0064d219  8d4c2414             lea ecx, [esp + 0x14]
// 0064d21d  51                   push ecx
// 0064d21e  83c604               add esi, 4
// 0064d221  56                   push esi
// 0064d222  50                   push eax
// 0064d223  8bcf                 mov ecx, edi
// 0064d225  e8b6feffff           call 0x64d0e0
// 0064d22a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0064d22e  c644242c00           mov byte ptr [esp + 0x2c], 0
// 0064d233  85c9                 test ecx, ecx
// 0064d235  7408                 je 0x64d23f
// 0064d237  8b11                 mov edx, dword ptr [ecx]
// 0064d239  8b02                 mov eax, dword ptr [edx]
// 0064d23b  6a01                 push 1
// 0064d23d  ffd0                 call eax
// 0064d23f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0064d243  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0064d24b  85c9                 test ecx, ecx
// 0064d24d  7408                 je 0x64d257
// 0064d24f  8b11                 mov edx, dword ptr [ecx]
// 0064d251  8b02                 mov eax, dword ptr [edx]
// 0064d253  6a01                 push 1
// 0064d255  ffd0                 call eax
// 0064d257  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0064d25b  5f                   pop edi
// 0064d25c  5e                   pop esi
// 0064d25d  64890d00000000       mov dword ptr fs:[0], ecx
// 0064d264  83c428               add esp, 0x28
// 0064d267  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000019@@QAEXPAXPAUArguments@2@@Z)

namespace ns_ROCX000019 {
// from server: 100% by king_originala
struct Holder {
    virtual ~Holder();
    virtual void reserved();
    virtual Holder* clone();

    static Holder* copy(Holder*);
};

__forceinline Holder* Holder::copy(Holder* h)
{
    if (h)
        return h->clone();
    return 0;
}

struct Value {
    void* object;
    Holder* holder;

    Value(const Value&);
    ~Value();
};

__forceinline Value::Value(const Value& other)
    : object(other.object), holder(Holder::copy(other.holder))
{
}

__forceinline Value::~Value()
{
    Holder* h = holder;
    if (h)
        delete h;
}

struct Arguments {
    virtual void reserved();
    virtual void get(int index, Value* value);
};

namespace std {
    struct bad_cast {
        char storage[12];
        bad_cast(const char*);
    };
}

typedef void (__thiscall *BadCastConstructor)(std::bad_cast*, const char*);
extern BadCastConstructor constructBadCast;

__forceinline std::bad_cast::bad_cast(const char* message)
{
    constructBadCast(this, message);
}

extern unsigned char sourceType;
extern unsigned char destinationType;
extern unsigned char badCastThrowInfo;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

extern "C" __declspec(noreturn) void __stdcall throwException(void*, void*);

struct S {
    char padding[64];
    Value first;
    Value second;

    void invoke(void*, void*, Value*, Value*);
    void f(void*, Arguments*);
};

void S::f(void* instance, Arguments* arguments)
{
    Value a(first);
    arguments->get(1, &a);

    Value b(second);
    arguments->get(2, &b);

    void* converted = __RTDynamicCast(
        instance, 0, &sourceType, &destinationType, 0);

    if (!converted) {
        std::bad_cast error("bad cast");
        throwException(&error, &badCastThrowInfo);
    }

    invoke(converted, reinterpret_cast<char*>(arguments) + 4, &a, &b);
}
}
