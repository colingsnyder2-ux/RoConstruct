// from server: 100% by Yeetserama
// roc 2010-06 004cade0  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 282 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004cade0
//
// 004cade0  6aff                 push -1
// 004cade2  6880409a00           push 0x9a4080
// 004cade7  64a100000000         mov eax, dword ptr fs:[0]
// 004caded  50                   push eax
// 004cadee  64892500000000       mov dword ptr fs:[0], esp
// 004cadf5  83ec1c               sub esp, 0x1c
// 004cadf8  56                   push esi
// 004cadf9  57                   push edi
// 004cadfa  8bf9                 mov edi, ecx
// 004cadfc  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 004cadff  8b4740               mov eax, dword ptr [edi + 0x40]
// 004cae02  89442410             mov dword ptr [esp + 0x10], eax
// 004cae06  85c9                 test ecx, ecx
// 004cae08  7409                 je 0x4cae13
// 004cae0a  8b11                 mov edx, dword ptr [ecx]
// 004cae0c  8b4208               mov eax, dword ptr [edx + 8]
// 004cae0f  ffd0                 call eax
// 004cae11  eb02                 jmp 0x4cae15
// 004cae13  33c0                 xor eax, eax
// 004cae15  89442414             mov dword ptr [esp + 0x14], eax
// 004cae19  8b742438             mov esi, dword ptr [esp + 0x38]
// 004cae1d  8b16                 mov edx, dword ptr [esi]
// 004cae1f  8b5204               mov edx, dword ptr [edx + 4]
// 004cae22  8d442410             lea eax, [esp + 0x10]
// 004cae26  50                   push eax
// 004cae27  6a01                 push 1
// 004cae29  8bce                 mov ecx, esi
// 004cae2b  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004cae33  ffd2                 call edx
// 004cae35  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 004cae38  8b4748               mov eax, dword ptr [edi + 0x48]
// 004cae3b  89442408             mov dword ptr [esp + 8], eax
// 004cae3f  85c9                 test ecx, ecx
// 004cae41  7409                 je 0x4cae4c
// 004cae43  8b11                 mov edx, dword ptr [ecx]
// 004cae45  8b4208               mov eax, dword ptr [edx + 8]
// 004cae48  ffd0                 call eax
// 004cae4a  eb02                 jmp 0x4cae4e
// 004cae4c  33c0                 xor eax, eax
// 004cae4e  8944240c             mov dword ptr [esp + 0xc], eax
// 004cae52  8b16                 mov edx, dword ptr [esi]
// 004cae54  8b5204               mov edx, dword ptr [edx + 4]
// 004cae57  8d442408             lea eax, [esp + 8]
// 004cae5b  50                   push eax
// 004cae5c  6a02                 push 2
// 004cae5e  8bce                 mov ecx, esi
// 004cae60  c644243401           mov byte ptr [esp + 0x34], 1
// 004cae65  ffd2                 call edx
// 004cae67  8b442434             mov eax, dword ptr [esp + 0x34]
// 004cae6b  6a00                 push 0
// 004cae6d  68d873b800           push 0xb873d8
// 004cae72  684090b700           push 0xb79040
// 004cae77  6a00                 push 0
// 004cae79  50                   push eax
// 004cae7a  e86bdd2d00           call 0x7a8bea
// 004cae7f  83c414               add esp, 0x14
// 004cae82  85c0                 test eax, eax
// 004cae84  751e                 jne 0x4caea4
// 004cae86  68540aa000           push 0xa00a54
// 004cae8b  8d4c241c             lea ecx, [esp + 0x1c]
// 004cae8f  ff159ca89e00         call dword ptr [0x9ea89c]
// 004cae95  689022b100           push 0xb12290
// 004cae9a  8d4c241c             lea ecx, [esp + 0x1c]
// 004cae9e  51                   push ecx
// 004cae9f  e80edb2d00           call 0x7a89b2
// 004caea4  8d542408             lea edx, [esp + 8]
// 004caea8  52                   push edx
// 004caea9  8d4c2414             lea ecx, [esp + 0x14]
// 004caead  51                   push ecx
// 004caeae  83c604               add esi, 4
// 004caeb1  56                   push esi
// 004caeb2  50                   push eax
// 004caeb3  8bcf                 mov ecx, edi
// 004caeb5  e896feffff           call 0x4cad50
// 004caeba  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004caebe  c644242c00           mov byte ptr [esp + 0x2c], 0
// 004caec3  85c9                 test ecx, ecx
// 004caec5  7408                 je 0x4caecf
// 004caec7  8b11                 mov edx, dword ptr [ecx]
// 004caec9  8b02                 mov eax, dword ptr [edx]
// 004caecb  6a01                 push 1
// 004caecd  ffd0                 call eax
// 004caecf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004caed3  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004caedb  85c9                 test ecx, ecx
// 004caedd  7408                 je 0x4caee7
// 004caedf  8b11                 mov edx, dword ptr [ecx]
// 004caee1  8b02                 mov eax, dword ptr [edx]
// 004caee3  6a01                 push 1
// 004caee5  ffd0                 call eax
// 004caee7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004caeeb  5f                   pop edi
// 004caeec  5e                   pop esi
// 004caeed  64890d00000000       mov dword ptr fs:[0], ecx
// 004caef4  83c428               add esp, 0x28
// 004caef7  c20800               ret 8
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
