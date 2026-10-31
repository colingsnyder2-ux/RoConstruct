// from server: 100% by EspClaude
// roc 2009-06 004b7160  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004b7160
//
// 004b7160  8b542404             mov edx, dword ptr [esp + 4]
// 004b7164  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004b7167  8b01                 mov eax, dword ptr [ecx]
// 004b7169  8b4008               mov eax, dword ptr [eax + 8]
// 004b716c  52                   push edx
// 004b716d  8d542408             lea edx, [esp + 8]
// 004b7171  52                   push edx
// 004b7172  ffd0                 call eax
// 004b7174  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004b7178  50                   push eax
// 004b7179  e822f5ffff           call 0x4b66a0
// 004b717e  c20800               ret 8
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
