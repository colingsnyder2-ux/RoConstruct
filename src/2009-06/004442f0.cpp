// from server: 100% by EspClaude
// roc 2009-06 004442f0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004442f0
//
// 004442f0  56                   push esi
// 004442f1  8bf1                 mov esi, ecx
// 004442f3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004442f7  8d44240c             lea eax, [esp + 0xc]
// 004442fb  50                   push eax
// 004442fc  51                   push ecx
// 004442fd  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00444300  e84ba21a00           call 0x5ee550
// 00444305  84c0                 test al, al
// 00444307  7422                 je 0x44432b
// 00444309  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0044430d  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00444310  8954240c             mov dword ptr [esp + 0xc], edx
// 00444314  8b01                 mov eax, dword ptr [ecx]
// 00444316  8b400c               mov eax, dword ptr [eax + 0xc]
// 00444319  8d54240c             lea edx, [esp + 0xc]
// 0044431d  52                   push edx
// 0044431e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00444322  52                   push edx
// 00444323  ffd0                 call eax
// 00444325  b001                 mov al, 1
// 00444327  5e                   pop esi
// 00444328  c20800               ret 8
// 0044432b  32c0                 xor al, al
// 0044432d  5e                   pop esi
// 0044432e  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000038@@QAE_NPAXH@Z)

namespace ns_ROCX000038 {
enum Value { ValueZero = 0 };

struct Converter {
    bool convert(int value, int& result);
};

struct Setter {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(void* object, const Value& value) = 0;
};

struct S {
    char padding[0x1c];
    Setter* setter;
    Converter* converter;

    bool f(void* object, int value);
};

bool S::f(void* object, int value)
{
    if (converter->convert(value, value)) {
        value = *reinterpret_cast<volatile int*>(&value);
        setter->set(object, reinterpret_cast<const Value&>(value));
        return true;
    }
    return false;
}
}
