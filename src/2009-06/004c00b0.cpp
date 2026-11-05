// from server: 100% by EspClaude
// roc 2009-06 004c00b0  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c00b0
//
// 004c00b0  56                   push esi
// 004c00b1  57                   push edi
// 004c00b2  8b7918               mov edi, dword ptr [ecx + 0x18]
// 004c00b5  8b37                 mov esi, dword ptr [edi]
// 004c00b7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c00bb  8d442410             lea eax, [esp + 0x10]
// 004c00bf  50                   push eax
// 004c00c0  83c60c               add esi, 0xc
// 004c00c3  e868f2ffff           call 0x4bf330
// 004c00c8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004c00cc  8b16                 mov edx, dword ptr [esi]
// 004c00ce  50                   push eax
// 004c00cf  51                   push ecx
// 004c00d0  8bcf                 mov ecx, edi
// 004c00d2  ffd2                 call edx
// 004c00d4  5f                   pop edi
// 004c00d5  5e                   pop esi
// 004c00d6  c20800               ret 8
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
