// from server: 100% by EspClaude
// roc 2009-06 005e6850  unit: RBX::Reflection::N::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e6850
//
// 005e6850  83ec08               sub esp, 8
// 005e6853  8b542410             mov edx, dword ptr [esp + 0x10]
// 005e6857  c7042400000000       mov dword ptr [esp], 0
// 005e685e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005e6861  8b01                 mov eax, dword ptr [ecx]
// 005e6863  8b4008               mov eax, dword ptr [eax + 8]
// 005e6866  56                   push esi
// 005e6867  52                   push edx
// 005e6868  ffd0                 call eax
// 005e686a  dd5c2404             fstp qword ptr [esp + 4]
// 005e686e  8b742410             mov esi, dword ptr [esp + 0x10]
// 005e6872  8d4c2404             lea ecx, [esp + 4]
// 005e6876  51                   push ecx
// 005e6877  56                   push esi
// 005e6878  e8934c0600           call 0x64b510
// 005e687d  83c408               add esp, 8
// 005e6880  8bc6                 mov eax, esi
// 005e6882  5e                   pop esi
// 005e6883  83c408               add esp, 8
// 005e6886  c20800               ret 8
// copied from an identical function in another client (function ?convert@S@ns_ROCX000005@@QAEPAUString@2@PAU32@PAX@Z)

namespace ns_ROCX000005 {
struct String;
String* __cdecl convertNumber(String*, const double&);

struct Getter {
    virtual void slot0();
    virtual void slot1();
    virtual double get(void*);
};

struct S {
    unsigned char padding[24];
    Getter* volatile getter;
    String* convert(String*, void*);
};

String* S::convert(String* result, void* object)
{
    union {
        volatile int initial;
        double value;
    } number;

    number.initial = 0;
    number.value = getter->get(object);
    convertNumber(result, number.value);
    return result;
}
}
