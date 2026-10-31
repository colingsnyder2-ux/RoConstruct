// from server: 100% by EspClaude
// roc 2009-06 004c0210  unit: RBX::Network::VPlayer::?$BoundFuncDesc  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c0210
//
// 004c0210  6aff                 push -1
// 004c0212  6868398600           push 0x863968
// 004c0217  64a100000000         mov eax, dword ptr fs:[0]
// 004c021d  50                   push eax
// 004c021e  64892500000000       mov dword ptr fs:[0], esp
// 004c0225  83ec14               sub esp, 0x14
// 004c0228  56                   push esi
// 004c0229  57                   push edi
// 004c022a  8bf9                 mov edi, ecx
// 004c022c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 004c022f  8b4740               mov eax, dword ptr [edi + 0x40]
// 004c0232  89442408             mov dword ptr [esp + 8], eax
// 004c0236  85c9                 test ecx, ecx
// 004c0238  7409                 je 0x4c0243
// 004c023a  8b11                 mov edx, dword ptr [ecx]
// 004c023c  8b4208               mov eax, dword ptr [edx + 8]
// 004c023f  ffd0                 call eax
// 004c0241  eb02                 jmp 0x4c0245
// 004c0243  33c0                 xor eax, eax
// 004c0245  8944240c             mov dword ptr [esp + 0xc], eax
// 004c0249  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004c024d  8b11                 mov edx, dword ptr [ecx]
// 004c024f  8b5204               mov edx, dword ptr [edx + 4]
// 004c0252  8d442408             lea eax, [esp + 8]
// 004c0256  50                   push eax
// 004c0257  6a01                 push 1
// 004c0259  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004c0261  ffd2                 call edx
// 004c0263  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004c0267  6a00                 push 0
// 004c0269  6820ed9e00           push 0x9eed20
// 004c026e  68c4bf9d00           push 0x9dbfc4
// 004c0273  6a00                 push 0
// 004c0275  50                   push eax
// 004c0276  e8ff992500           call 0x719c7a
// 004c027b  8bf0                 mov esi, eax
// 004c027d  83c414               add esp, 0x14
// 004c0280  85f6                 test esi, esi
// 004c0282  751e                 jne 0x4c02a2
// 004c0284  6850d38a00           push 0x8ad350
// 004c0289  8d4c2414             lea ecx, [esp + 0x14]
// 004c028d  ff1570e98900         call dword ptr [0x89e970]
// 004c0293  68b04b9800           push 0x984bb0
// 004c0298  8d4c2414             lea ecx, [esp + 0x14]
// 004c029c  51                   push ecx
// 004c029d  e8a8972500           call 0x719a4a
// 004c02a2  8d4c2408             lea ecx, [esp + 8]
// 004c02a6  e8a57c1200           call 0x5e7f50
// 004c02ab  0fb610               movzx edx, byte ptr [eax]
// 004c02ae  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 004c02b1  8b4738               mov eax, dword ptr [edi + 0x38]
// 004c02b4  52                   push edx
// 004c02b5  03ce                 add ecx, esi
// 004c02b7  ffd0                 call eax
// 004c02b9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004c02bd  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004c02c5  85c9                 test ecx, ecx
// 004c02c7  7408                 je 0x4c02d1
// 004c02c9  8b11                 mov edx, dword ptr [ecx]
// 004c02cb  8b02                 mov eax, dword ptr [edx]
// 004c02cd  6a01                 push 1
// 004c02cf  ffd0                 call eax
// 004c02d1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c02d5  5f                   pop edi
// 004c02d6  5e                   pop esi
// 004c02d7  64890d00000000       mov dword ptr fs:[0], ecx
// 004c02de  83c420               add esp, 0x20
// 004c02e1  c20800               ret 8
// copied from an identical function in another client (function ?invoke@S@ns_ROCX000011@@QAEXPAXPAUArguments@2@@Z)

namespace ns_ROCX000011 {
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
