// from server: 100% by Yeetserama
// roc 2011-06 0048dbb0  unit: CScriptEditor  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048dbb0
//
// 0048dbb0  6aff                 push -1
// 0048dbb2  68395f9d00           push 0x9d5f39
// 0048dbb7  64a100000000         mov eax, dword ptr fs:[0]
// 0048dbbd  50                   push eax
// 0048dbbe  64892500000000       mov dword ptr fs:[0], esp
// 0048dbc5  51                   push ecx
// 0048dbc6  56                   push esi
// 0048dbc7  57                   push edi
// 0048dbc8  e823d4ffff           call 0x48aff0
// 0048dbcd  8bf0                 mov esi, eax
// 0048dbcf  6a01                 push 1
// 0048dbd1  8bce                 mov ecx, esi
// 0048dbd3  e828c1ffff           call 0x489d00
// 0048dbd8  6a01                 push 1
// 0048dbda  50                   push eax
// 0048dbdb  8bce                 mov ecx, esi
// 0048dbdd  e84eccffff           call 0x48a830
// 0048dbe2  6a01                 push 1
// 0048dbe4  50                   push eax
// 0048dbe5  8bce                 mov ecx, esi
// 0048dbe7  e814d1ffff           call 0x48ad00
// 0048dbec  8bf0                 mov esi, eax
// 0048dbee  81e6ff0f0000         and esi, 0xfff
// 0048dbf4  8d4c2408             lea ecx, [esp + 8]
// 0048dbf8  81ee00040000         sub esi, 0x400
// 0048dbfe  ff15b42da400         call dword ptr [0xa42db4]
// 0048dc04  56                   push esi
// 0048dc05  8d44240c             lea eax, [esp + 0xc]
// 0048dc09  68c9000000           push 0xc9
// 0048dc0e  50                   push eax
// 0048dc0f  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0048dc17  ff153423a400         call dword ptr [0xa42334]
// 0048dc1d  8b742428             mov esi, dword ptr [esp + 0x28]
// 0048dc21  8b3e                 mov edi, dword ptr [esi]
// 0048dc23  83c40c               add esp, 0xc
// 0048dc26  8d4c2408             lea ecx, [esp + 8]
// 0048dc2a  ff15c82da400         call dword ptr [0xa42dc8]
// 0048dc30  8b570c               mov edx, dword ptr [edi + 0xc]
// 0048dc33  50                   push eax
// 0048dc34  8bce                 mov ecx, esi
// 0048dc36  ffd2                 call edx
// 0048dc38  8d4c2408             lea ecx, [esp + 8]
// 0048dc3c  ff15082ea400         call dword ptr [0xa42e08]
// 0048dc42  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0048dc46  5f                   pop edi
// 0048dc47  5e                   pop esi
// 0048dc48  64890d00000000       mov dword ptr fs:[0], ecx
// 0048dc4f  83c410               add esp, 0x10
// 0048dc52  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000004_00464300@CScriptEditor@ns_ROCX000004@@QAEXPAUOutput@2@@Z)

namespace ns_ROCX000004 {
// from server: 100% by colin
struct Control {
    int fn_ROCX000004_00460120(int);
    int fn_ROCX000004_00460c10(int, int);
    int fn_ROCX000004_004610e0(int, int);
};

struct Text {
    char* data;
    __declspec(dllimport) Text();
    __declspec(dllimport) ~Text() throw();
};

extern void (__cdecl* text_format)(Text*, unsigned int, ...);
extern const char* (__thiscall* text_data)(Text*);





struct Output {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(const char*) = 0;
};

struct CScriptEditor {
    int* fn_ROCX000004_004613d0();
    void fn_ROCX000004_00464300(Output*);
};

void CScriptEditor::fn_ROCX000004_00464300(Output* output)
{
    Control* control = reinterpret_cast<Control*>(fn_ROCX000004_004613d0());
    int value = control->fn_ROCX000004_00460120(1);
    value = control->fn_ROCX000004_00460c10(value, 1);
    value = control->fn_ROCX000004_004610e0(value, 1);
    value = (value & 0xfff) - 0x400;

    Text text;
    text_format(&text, 201, value);
    output->set(text_data(&text));
}
}
