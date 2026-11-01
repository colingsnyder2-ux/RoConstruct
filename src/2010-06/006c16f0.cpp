// from server: 100% by Yeetserama
// roc 2010-06 006c16f0  unit: RBX::VDebrisService::?$BoundFuncDesc  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006c16f0
//
// 006c16f0  6aff                 push -1
// 006c16f2  68e8d09800           push 0x98d0e8
// 006c16f7  64a100000000         mov eax, dword ptr fs:[0]
// 006c16fd  50                   push eax
// 006c16fe  64892500000000       mov dword ptr fs:[0], esp
// 006c1705  83ec14               sub esp, 0x14
// 006c1708  56                   push esi
// 006c1709  57                   push edi
// 006c170a  8bf9                 mov edi, ecx
// 006c170c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 006c170f  8b4740               mov eax, dword ptr [edi + 0x40]
// 006c1712  89442408             mov dword ptr [esp + 8], eax
// 006c1716  85c9                 test ecx, ecx
// 006c1718  7409                 je 0x6c1723
// 006c171a  8b11                 mov edx, dword ptr [ecx]
// 006c171c  8b4208               mov eax, dword ptr [edx + 8]
// 006c171f  ffd0                 call eax
// 006c1721  eb02                 jmp 0x6c1725
// 006c1723  33c0                 xor eax, eax
// 006c1725  8944240c             mov dword ptr [esp + 0xc], eax
// 006c1729  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 006c172d  8b11                 mov edx, dword ptr [ecx]
// 006c172f  8b5204               mov edx, dword ptr [edx + 4]
// 006c1732  8d442408             lea eax, [esp + 8]
// 006c1736  50                   push eax
// 006c1737  6a01                 push 1
// 006c1739  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006c1741  ffd2                 call edx
// 006c1743  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006c1747  6a00                 push 0
// 006c1749  6864f6bc00           push 0xbcf664
// 006c174e  684090b700           push 0xb79040
// 006c1753  6a00                 push 0
// 006c1755  50                   push eax
// 006c1756  e88f740e00           call 0x7a8bea
// 006c175b  8bf0                 mov esi, eax
// 006c175d  83c414               add esp, 0x14
// 006c1760  85f6                 test esi, esi
// 006c1762  751e                 jne 0x6c1782
// 006c1764  68540aa000           push 0xa00a54
// 006c1769  8d4c2414             lea ecx, [esp + 0x14]
// 006c176d  ff159ca89e00         call dword ptr [0x9ea89c]
// 006c1773  689022b100           push 0xb12290
// 006c1778  8d4c2414             lea ecx, [esp + 0x14]
// 006c177c  51                   push ecx
// 006c177d  e830720e00           call 0x7a89b2
// 006c1782  8d4c2408             lea ecx, [esp + 8]
// 006c1786  e84574eeff           call 0x5a8bd0
// 006c178b  0fb610               movzx edx, byte ptr [eax]
// 006c178e  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 006c1791  8b4738               mov eax, dword ptr [edi + 0x38]
// 006c1794  52                   push edx
// 006c1795  03ce                 add ecx, esi
// 006c1797  ffd0                 call eax
// 006c1799  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006c179d  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 006c17a5  85c9                 test ecx, ecx
// 006c17a7  7408                 je 0x6c17b1
// 006c17a9  8b11                 mov edx, dword ptr [ecx]
// 006c17ab  8b02                 mov eax, dword ptr [edx]
// 006c17ad  6a01                 push 1
// 006c17af  ffd0                 call eax
// 006c17b1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006c17b5  5f                   pop edi
// 006c17b6  5e                   pop esi
// 006c17b7  64890d00000000       mov dword ptr fs:[0], ecx
// 006c17be  83c420               add esp, 0x20
// 006c17c1  c20800               ret 8
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
