// from server: 100% by EspClaude
// roc 2009-06 004434f0  unit: G3D::VVector2int16::?$TypedPropertyDescriptor  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004434f0
//
// 004434f0  56                   push esi
// 004434f1  57                   push edi
// 004434f2  8b7918               mov edi, dword ptr [ecx + 0x18]
// 004434f5  8b37                 mov esi, dword ptr [edi]
// 004434f7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004434fb  8d442410             lea eax, [esp + 0x10]
// 004434ff  50                   push eax
// 00443500  83c60c               add esi, 0xc
// 00443503  e8f8faffff           call 0x443000
// 00443508  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044350c  8b16                 mov edx, dword ptr [esi]
// 0044350e  50                   push eax
// 0044350f  51                   push ecx
// 00443510  8bcf                 mov ecx, edi
// 00443512  ffd2                 call edx
// 00443514  5f                   pop edi
// 00443515  5e                   pop esi
// 00443516  c20800               ret 8
// copied from an identical function in another client (function ?set@S@ns_ROCX00002a@@QAEXPAXPAUValue@2@@Z)

namespace ns_ROCX00002a {
struct Value {
    void* convert(Value** value);
};

struct Target;
typedef void (__thiscall *Setter)(Target*, void*, void*);

struct Target {
    Setter* table;
};

struct S {
    char padding[24];
    Target* target;
    void set(void* object, Value* value);
};

void S::set(void* object, Value* value)
{
    Target* destination = target;
    Setter* slot = destination->table + 3;
    void* converted = value->convert(&value);
    (*slot)(destination, object, converted);
}
}
