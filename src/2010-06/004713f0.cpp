// from server: 100% by Yeetserama
// roc 2010-06 004713f0  unit: CScriptEditor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004713f0
//
// 004713f0  56                   push esi
// 004713f1  e8fad2ffff           call 0x46e6f0
// 004713f6  8bf0                 mov esi, eax
// 004713f8  6a01                 push 1
// 004713fa  8bce                 mov ecx, esi
// 004713fc  e82fc0ffff           call 0x46d430
// 00471401  6a01                 push 1
// 00471403  50                   push eax
// 00471404  8bce                 mov ecx, esi
// 00471406  e815cbffff           call 0x46df20
// 0047140b  6a01                 push 1
// 0047140d  50                   push eax
// 0047140e  8bce                 mov ecx, esi
// 00471410  e89bc3ffff           call 0x46d7b0
// 00471415  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00471419  8b11                 mov edx, dword ptr [ecx]
// 0047141b  f7d0                 not eax
// 0047141d  83e001               and eax, 1
// 00471420  5e                   pop esi
// 00471421  89442404             mov dword ptr [esp + 4], eax
// 00471425  8b02                 mov eax, dword ptr [edx]
// 00471427  ffe0                 jmp eax
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
