// from server: 100% by EspClaude
// roc 2009-06 00660280  unit: G3D::VColor3::?$TypedPropertyDescriptor  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00660280
//
// 00660280  83ec0c               sub esp, 0xc
// 00660283  56                   push esi
// 00660284  57                   push edi
// 00660285  8b7918               mov edi, dword ptr [ecx + 0x18]
// 00660288  8b37                 mov esi, dword ptr [edi]
// 0066028a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0066028e  8d442408             lea eax, [esp + 8]
// 00660292  50                   push eax
// 00660293  83c60c               add esi, 0xc
// 00660296  e8b5fbffff           call 0x65fe50
// 0066029b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0066029f  8b16                 mov edx, dword ptr [esi]
// 006602a1  50                   push eax
// 006602a2  51                   push ecx
// 006602a3  8bcf                 mov ecx, edi
// 006602a5  ffd2                 call edx
// 006602a7  5f                   pop edi
// 006602a8  5e                   pop esi
// 006602a9  83c40c               add esp, 0xc
// 006602ac  c20800               ret 8
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
