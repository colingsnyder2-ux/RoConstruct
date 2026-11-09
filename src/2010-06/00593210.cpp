// from server: 100% by Yeetserama
// roc 2010-06 00593210  unit: RBX::VDebugSettings::?$BoundFuncDesc  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00593210
//
// 00593210  6aff                 push -1
// 00593212  68e8d09800           push 0x98d0e8
// 00593217  64a100000000         mov eax, dword ptr fs:[0]
// 0059321d  50                   push eax
// 0059321e  64892500000000       mov dword ptr fs:[0], esp
// 00593225  83ec14               sub esp, 0x14
// 00593228  56                   push esi
// 00593229  57                   push edi
// 0059322a  8bf9                 mov edi, ecx
// 0059322c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 0059322f  8b4740               mov eax, dword ptr [edi + 0x40]
// 00593232  89442408             mov dword ptr [esp + 8], eax
// 00593236  85c9                 test ecx, ecx
// 00593238  7409                 je 0x593243
// 0059323a  8b11                 mov edx, dword ptr [ecx]
// 0059323c  8b4208               mov eax, dword ptr [edx + 8]
// 0059323f  ffd0                 call eax
// 00593241  eb02                 jmp 0x593245
// 00593243  33c0                 xor eax, eax
// 00593245  8944240c             mov dword ptr [esp + 0xc], eax
// 00593249  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0059324d  8b11                 mov edx, dword ptr [ecx]
// 0059324f  8b5204               mov edx, dword ptr [edx + 4]
// 00593252  8d442408             lea eax, [esp + 8]
// 00593256  50                   push eax
// 00593257  6a01                 push 1
// 00593259  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00593261  ffd2                 call edx
// 00593263  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00593267  6a00                 push 0
// 00593269  68b0d4b900           push 0xb9d4b0
// 0059326e  684090b700           push 0xb79040
// 00593273  6a00                 push 0
// 00593275  50                   push eax
// 00593276  e86f592100           call 0x7a8bea
// 0059327b  8bf0                 mov esi, eax
// 0059327d  83c414               add esp, 0x14
// 00593280  85f6                 test esi, esi
// 00593282  751e                 jne 0x5932a2
// 00593284  68540aa000           push 0xa00a54
// 00593289  8d4c2414             lea ecx, [esp + 0x14]
// 0059328d  ff159ca89e00         call dword ptr [0x9ea89c]
// 00593293  689022b100           push 0xb12290
// 00593298  8d4c2414             lea ecx, [esp + 0x14]
// 0059329c  51                   push ecx
// 0059329d  e810572100           call 0x7a89b2
// 005932a2  8d4c2408             lea ecx, [esp + 8]
// 005932a6  e825590100           call 0x5a8bd0
// 005932ab  0fb610               movzx edx, byte ptr [eax]
// 005932ae  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 005932b1  8b4738               mov eax, dword ptr [edi + 0x38]
// 005932b4  52                   push edx
// 005932b5  03ce                 add ecx, esi
// 005932b7  ffd0                 call eax
// 005932b9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005932bd  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 005932c5  85c9                 test ecx, ecx
// 005932c7  7408                 je 0x5932d1
// 005932c9  8b11                 mov edx, dword ptr [ecx]
// 005932cb  8b02                 mov eax, dword ptr [edx]
// 005932cd  6a01                 push 1
// 005932cf  ffd0                 call eax
// 005932d1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005932d5  5f                   pop edi
// 005932d6  5e                   pop esi
// 005932d7  64890d00000000       mov dword ptr fs:[0], ecx
// 005932de  83c420               add esp, 0x20
// 005932e1  c20800               ret 8
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
