// from server: 100% by Yeetserama
// roc 2012-06 004a04f0  unit: CScriptEditor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a04f0
//
// 004a04f0  56                   push esi
// 004a04f1  e89a370500           call 0x4f3c90
// 004a04f6  8bf0                 mov esi, eax
// 004a04f8  6a01                 push 1
// 004a04fa  8bce                 mov ecx, esi
// 004a04fc  e82fc5ffff           call 0x49ca30
// 004a0501  6a01                 push 1
// 004a0503  50                   push eax
// 004a0504  8bce                 mov ecx, esi
// 004a0506  e855d0ffff           call 0x49d560
// 004a050b  6a01                 push 1
// 004a050d  50                   push eax
// 004a050e  8bce                 mov ecx, esi
// 004a0510  e8dbc8ffff           call 0x49cdf0
// 004a0515  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004a0519  8b11                 mov edx, dword ptr [ecx]
// 004a051b  f7d0                 not eax
// 004a051d  83e001               and eax, 1
// 004a0520  5e                   pop esi
// 004a0521  89442404             mov dword ptr [esp + 4], eax
// 004a0525  8b02                 mov eax, dword ptr [edx]
// 004a0527  ffe0                 jmp eax
// copied from an identical function in another client (function ?fn_ROCX000017_00463f40@CScriptEditor@ns_ROCX000017@@QAEXPAUOutput@2@@Z)

namespace ns_ROCX000017 {
// from server: 100% by king_originala
struct Control {
    int fn_ROCX000017_00460120(int);
    int fn_ROCX000017_00460c10(int, int);
    int fn_ROCX000017_004604a0(int, int);
};

struct Output {
    virtual void set(int);
};

struct CScriptEditor {
    int* fn_ROCX000017_004613d0();
    void fn_ROCX000017_00463f40(Output*);
};

void CScriptEditor::fn_ROCX000017_00463f40(Output* output)
{
    Control* control = reinterpret_cast<Control*>(fn_ROCX000017_004613d0());
    int value = control->fn_ROCX000017_00460120(1);
    value = control->fn_ROCX000017_00460c10(value, 1);
    value = control->fn_ROCX000017_004604a0(value, 1);
    output->set((~value) & 1);
}
}
