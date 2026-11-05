// from server: 100% by EspClaude
// roc 2009-06 0061b740  unit: RBX::VChangeHistoryService::?$BoundFuncDesc  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0061b740
//
// 0061b740  6aff                 push -1
// 0061b742  6868398600           push 0x863968
// 0061b747  64a100000000         mov eax, dword ptr fs:[0]
// 0061b74d  50                   push eax
// 0061b74e  64892500000000       mov dword ptr fs:[0], esp
// 0061b755  83ec14               sub esp, 0x14
// 0061b758  56                   push esi
// 0061b759  57                   push edi
// 0061b75a  8bf9                 mov edi, ecx
// 0061b75c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 0061b75f  8b4740               mov eax, dword ptr [edi + 0x40]
// 0061b762  89442408             mov dword ptr [esp + 8], eax
// 0061b766  85c9                 test ecx, ecx
// 0061b768  7409                 je 0x61b773
// 0061b76a  8b11                 mov edx, dword ptr [ecx]
// 0061b76c  8b4208               mov eax, dword ptr [edx + 8]
// 0061b76f  ffd0                 call eax
// 0061b771  eb02                 jmp 0x61b775
// 0061b773  33c0                 xor eax, eax
// 0061b775  8944240c             mov dword ptr [esp + 0xc], eax
// 0061b779  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0061b77d  8b11                 mov edx, dword ptr [ecx]
// 0061b77f  8b5204               mov edx, dword ptr [edx + 4]
// 0061b782  8d442408             lea eax, [esp + 8]
// 0061b786  50                   push eax
// 0061b787  6a01                 push 1
// 0061b789  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0061b791  ffd2                 call edx
// 0061b793  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0061b797  6a00                 push 0
// 0061b799  68fc9ca000           push 0xa09cfc
// 0061b79e  68c4bf9d00           push 0x9dbfc4
// 0061b7a3  6a00                 push 0
// 0061b7a5  50                   push eax
// 0061b7a6  e8cfe40f00           call 0x719c7a
// 0061b7ab  8bf0                 mov esi, eax
// 0061b7ad  83c414               add esp, 0x14
// 0061b7b0  85f6                 test esi, esi
// 0061b7b2  751e                 jne 0x61b7d2
// 0061b7b4  6850d38a00           push 0x8ad350
// 0061b7b9  8d4c2414             lea ecx, [esp + 0x14]
// 0061b7bd  ff1570e98900         call dword ptr [0x89e970]
// 0061b7c3  68b04b9800           push 0x984bb0
// 0061b7c8  8d4c2414             lea ecx, [esp + 0x14]
// 0061b7cc  51                   push ecx
// 0061b7cd  e878e20f00           call 0x719a4a
// 0061b7d2  8d4c2408             lea ecx, [esp + 8]
// 0061b7d6  e875c7fcff           call 0x5e7f50
// 0061b7db  0fb610               movzx edx, byte ptr [eax]
// 0061b7de  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 0061b7e1  8b4738               mov eax, dword ptr [edi + 0x38]
// 0061b7e4  52                   push edx
// 0061b7e5  03ce                 add ecx, esi
// 0061b7e7  ffd0                 call eax
// 0061b7e9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0061b7ed  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0061b7f5  85c9                 test ecx, ecx
// 0061b7f7  7408                 je 0x61b801
// 0061b7f9  8b11                 mov edx, dword ptr [ecx]
// 0061b7fb  8b02                 mov eax, dword ptr [edx]
// 0061b7fd  6a01                 push 1
// 0061b7ff  ffd0                 call eax
// 0061b801  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0061b805  5f                   pop edi
// 0061b806  5e                   pop esi
// 0061b807  64890d00000000       mov dword ptr fs:[0], ecx
// 0061b80e  83c420               add esp, 0x20
// 0061b811  c20800               ret 8
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
