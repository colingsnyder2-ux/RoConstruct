// from server: 100% by Yeetserama
// roc 2011-06 0048d7f0  unit: CScriptEditor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048d7f0
//
// 0048d7f0  56                   push esi
// 0048d7f1  e8fad7ffff           call 0x48aff0
// 0048d7f6  8bf0                 mov esi, eax
// 0048d7f8  6a01                 push 1
// 0048d7fa  8bce                 mov ecx, esi
// 0048d7fc  e8ffc4ffff           call 0x489d00
// 0048d801  6a01                 push 1
// 0048d803  50                   push eax
// 0048d804  8bce                 mov ecx, esi
// 0048d806  e825d0ffff           call 0x48a830
// 0048d80b  6a01                 push 1
// 0048d80d  50                   push eax
// 0048d80e  8bce                 mov ecx, esi
// 0048d810  e8abc8ffff           call 0x48a0c0
// 0048d815  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0048d819  8b11                 mov edx, dword ptr [ecx]
// 0048d81b  f7d0                 not eax
// 0048d81d  83e001               and eax, 1
// 0048d820  5e                   pop esi
// 0048d821  89442404             mov dword ptr [esp + 4], eax
// 0048d825  8b02                 mov eax, dword ptr [edx]
// 0048d827  ffe0                 jmp eax
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
