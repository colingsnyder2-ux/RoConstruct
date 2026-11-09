// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00584f70  unit: G3D::VCoordinateFrame::?$TypedPropertyDescriptor  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00584f70
//
// 00584f70  83ec30               sub esp, 0x30
// 00584f73  56                   push esi
// 00584f74  57                   push edi
// 00584f75  8b7918               mov edi, dword ptr [ecx + 0x18]
// 00584f78  8b37                 mov esi, dword ptr [edi]
// 00584f7a  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00584f7e  8d442408             lea eax, [esp + 8]
// 00584f82  50                   push eax
// 00584f83  83c60c               add esi, 0xc
// 00584f86  e805fdffff           call 0x584c90
// 00584f8b  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00584f8f  8b16                 mov edx, dword ptr [esi]
// 00584f91  50                   push eax
// 00584f92  51                   push ecx
// 00584f93  8bcf                 mov ecx, edi
// 00584f95  ffd2                 call edx
// 00584f97  5f                   pop edi
// 00584f98  5e                   pop esi
// 00584f99  83c430               add esp, 0x30
// 00584f9c  c20800               ret 8

struct Frame
{
    float data[12];
};

struct Value
{
    Frame *get(Frame *storage);
};

struct Accessor
{
    typedef void (__thiscall *Setter)(Accessor *, void *, const Frame *);
    Setter *table;
};

struct S
{
    char padding[24];
    Accessor *accessor;

    void f(void *object, Value *value);
};

void S::f(void *object, Value *value)
{
    Frame storage;
    Accessor *target = accessor;
    Accessor::Setter *slot = target->table + 3;
    const Frame *frame = value->get(&storage);
    (*slot)(target, object, frame);
}
