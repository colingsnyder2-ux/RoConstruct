// from server: 100% by EspClaude
// roc 2009-06 00440a70  unit: G3D::VVector2int16::?$TypedPropertyDescriptor  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00440a70
//
// 00440a70  8b542404             mov edx, dword ptr [esp + 4]
// 00440a74  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00440a77  8b01                 mov eax, dword ptr [ecx]
// 00440a79  8b4008               mov eax, dword ptr [eax + 8]
// 00440a7c  52                   push edx
// 00440a7d  8d542408             lea edx, [esp + 8]
// 00440a81  52                   push edx
// 00440a82  ffd0                 call eax
// 00440a84  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00440a88  50                   push eax
// 00440a89  e832feffff           call 0x4408c0
// 00440a8e  c20800               ret 8
// copied from an identical function in another client (function ?get@S@ns_ROCX000029@@QAEXPAXPAUOutput@2@@Z)

namespace ns_ROCX000029 {
struct Getter;
typedef void* (__thiscall *GetValue)(Getter*, void**, void*);

struct Getter {
    GetValue* table;
};

struct Output {
    void assign(void* value);
};

struct S {
    unsigned char padding[24];
    Getter* getter;
    void get(void* object, Output* output);
};

void S::get(void* object, Output* output)
{
    void* value = getter->table[2](getter, &object, object);
    output->assign(value);
}
}
