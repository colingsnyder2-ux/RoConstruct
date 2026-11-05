// from server: 100% by EspClaude
// roc 2009-06 00628c20  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00628c20
//
// 00628c20  83ec0c               sub esp, 0xc
// 00628c23  56                   push esi
// 00628c24  57                   push edi
// 00628c25  8b7918               mov edi, dword ptr [ecx + 0x18]
// 00628c28  8b37                 mov esi, dword ptr [edi]
// 00628c2a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00628c2e  8d442408             lea eax, [esp + 8]
// 00628c32  50                   push eax
// 00628c33  83c60c               add esi, 0xc
// 00628c36  e835fdffff           call 0x628970
// 00628c3b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00628c3f  8b16                 mov edx, dword ptr [esi]
// 00628c41  50                   push eax
// 00628c42  51                   push ecx
// 00628c43  8bcf                 mov ecx, edi
// 00628c45  ffd2                 call edx
// 00628c47  5f                   pop edi
// 00628c48  5e                   pop esi
// 00628c49  83c40c               add esp, 0xc
// 00628c4c  c20800               ret 8
// copied from an identical function in another client (function ?set@S@ns_ROCX000003@@QAEXPAXPAUValue@2@@Z)

namespace ns_ROCX000003 {
struct Color {
    float r, g, b;
};

struct Value {
    const Color* get(Color* temporary);
};

struct Accessor;

typedef void (__thiscall *Setter)(Accessor*, void*, const Color*);

struct AccessorTable {
    void* reserved[3];
    Setter set;
};

struct Accessor {
    AccessorTable* table;
};

struct S {
    unsigned char reserved[24];
    Accessor* accessor;
    void set(void* object, Value* value);
};

void S::set(void* object, Value* value)
{
    Color temporary;
    Accessor* target = accessor;
    Setter* slot = &target->table->set;
    const Color* color = value->get(&temporary);
    (*slot)(target, object, color);
}
}
