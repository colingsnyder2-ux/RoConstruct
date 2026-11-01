// from server: 100% by Yeetserama
// roc 2010-06 006141f0  unit: RBX::VScriptContext::?$BoundFuncDesc  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006141f0
//
// 006141f0  6aff                 push -1
// 006141f2  68e8d09800           push 0x98d0e8
// 006141f7  64a100000000         mov eax, dword ptr fs:[0]
// 006141fd  50                   push eax
// 006141fe  64892500000000       mov dword ptr fs:[0], esp
// 00614205  83ec14               sub esp, 0x14
// 00614208  56                   push esi
// 00614209  57                   push edi
// 0061420a  8bf9                 mov edi, ecx
// 0061420c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 0061420f  8b4740               mov eax, dword ptr [edi + 0x40]
// 00614212  89442408             mov dword ptr [esp + 8], eax
// 00614216  85c9                 test ecx, ecx
// 00614218  7409                 je 0x614223
// 0061421a  8b11                 mov edx, dword ptr [ecx]
// 0061421c  8b4208               mov eax, dword ptr [edx + 8]
// 0061421f  ffd0                 call eax
// 00614221  eb02                 jmp 0x614225
// 00614223  33c0                 xor eax, eax
// 00614225  8944240c             mov dword ptr [esp + 0xc], eax
// 00614229  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0061422d  8b11                 mov edx, dword ptr [ecx]
// 0061422f  8b5204               mov edx, dword ptr [edx + 4]
// 00614232  8d442408             lea eax, [esp + 8]
// 00614236  50                   push eax
// 00614237  6a01                 push 1
// 00614239  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00614241  ffd2                 call edx
// 00614243  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00614247  6a00                 push 0
// 00614249  68a800bb00           push 0xbb00a8
// 0061424e  684090b700           push 0xb79040
// 00614253  6a00                 push 0
// 00614255  50                   push eax
// 00614256  e88f491900           call 0x7a8bea
// 0061425b  8bf0                 mov esi, eax
// 0061425d  83c414               add esp, 0x14
// 00614260  85f6                 test esi, esi
// 00614262  751e                 jne 0x614282
// 00614264  68540aa000           push 0xa00a54
// 00614269  8d4c2414             lea ecx, [esp + 0x14]
// 0061426d  ff159ca89e00         call dword ptr [0x9ea89c]
// 00614273  689022b100           push 0xb12290
// 00614278  8d4c2414             lea ecx, [esp + 0x14]
// 0061427c  51                   push ecx
// 0061427d  e830471900           call 0x7a89b2
// 00614282  8d4c2408             lea ecx, [esp + 8]
// 00614286  e84549f9ff           call 0x5a8bd0
// 0061428b  0fb610               movzx edx, byte ptr [eax]
// 0061428e  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 00614291  8b4738               mov eax, dword ptr [edi + 0x38]
// 00614294  52                   push edx
// 00614295  03ce                 add ecx, esi
// 00614297  ffd0                 call eax
// 00614299  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0061429d  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 006142a5  85c9                 test ecx, ecx
// 006142a7  7408                 je 0x6142b1
// 006142a9  8b11                 mov edx, dword ptr [ecx]
// 006142ab  8b02                 mov eax, dword ptr [edx]
// 006142ad  6a01                 push 1
// 006142af  ffd0                 call eax
// 006142b1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006142b5  5f                   pop edi
// 006142b6  5e                   pop esi
// 006142b7  64890d00000000       mov dword ptr fs:[0], ecx
// 006142be  83c420               add esp, 0x20
// 006142c1  c20800               ret 8
// copied from an identical function in another client (function ?invoke@S@ns_ROCX000005@@QAEXPAXPAUArguments@2@@Z)

namespace ns_ROCX000005 {
// from server: 100% by colin
struct ValueOwner {
    virtual ~ValueOwner();
    virtual void reserved();
    virtual ValueOwner* clone() = 0;
};

struct Value {
    void* data;
    ValueOwner* owner;

    Value(const Value& other);
    ~Value();
    unsigned char* get();
    static ValueOwner* copyOwner(ValueOwner* owner);
};

inline ValueOwner* Value::copyOwner(ValueOwner* owner)
{
    if (owner)
        return owner->clone();
    return 0;
}

inline Value::Value(const Value& other)
    : data(other.data), owner(copyOwner(other.owner))
{
}

inline Value::~Value()
{
    if (owner)
        delete owner;
}

struct Arguments {
    virtual void reserved();
    virtual void read(int index, Value* value) = 0;
};

namespace std {
    class bad_cast {
        void* vtable;
        const char* message;
        int ownsMessage;
    };
}

extern std::bad_cast* (__thiscall* badCastConstruct)(
    std::bad_cast*, const char*);

extern char sourceType;
extern char destinationType;
extern char badCastThrowInfo;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

extern "C" __declspec(noreturn) void __stdcall throwException(
    void*, void*);

struct S {
    char padding[0x38];
    void (__thiscall* callback)(void*, int);
    int adjustment;
    Value defaultValue;

    void invoke(void* object, Arguments* arguments);
};

void S::invoke(void* object, Arguments* arguments)
{
    Value value(defaultValue);
    arguments->read(1, &value);

    void* peer = __RTDynamicCast(
        object, 0, &sourceType, &destinationType, 0);

    if (!peer) {
        std::bad_cast error;
        badCastConstruct(&error, "bad cast");
        throwException(&error, &badCastThrowInfo);
    }

    callback(static_cast<char*>(peer) + adjustment, *value.get());
}
}
