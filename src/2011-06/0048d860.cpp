// from server: 100% by Yeetserama
// roc 2011-06 0048d860  unit: CScriptEditor  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048d860
//
// 0048d860  56                   push esi
// 0048d861  e88ad7ffff           call 0x48aff0
// 0048d866  8bf0                 mov esi, eax
// 0048d868  6a01                 push 1
// 0048d86a  8bce                 mov ecx, esi
// 0048d86c  e88fc4ffff           call 0x489d00
// 0048d871  6a01                 push 1
// 0048d873  50                   push eax
// 0048d874  8bce                 mov ecx, esi
// 0048d876  e8b5cfffff           call 0x48a830
// 0048d87b  6a01                 push 1
// 0048d87d  50                   push eax
// 0048d87e  8bce                 mov ecx, esi
// 0048d880  e83bc8ffff           call 0x48a0c0
// 0048d885  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0048d889  8b11                 mov edx, dword ptr [ecx]
// 0048d88b  83e001               and eax, 1
// 0048d88e  5e                   pop esi
// 0048d88f  89442404             mov dword ptr [esp + 4], eax
// 0048d893  8b02                 mov eax, dword ptr [edx]
// 0048d895  ffe0                 jmp eax
// copied from an identical function in another client (function ?update@CScriptEditor@ns_ROCX000019@@QAEXPAUCommand@2@@Z)

namespace ns_ROCX000019 {
// from server: 100% by king_originala
struct Command {
    virtual void set(int value);
};

struct Control {
    int current(int direct);
    int line(int position, int direct);
    int state(int line, int direct);
};

struct CScriptEditor {
    int* f();
    void update(Command* command);
};

void CScriptEditor::update(Command* command)
{
    Control* control = reinterpret_cast<Control*>(f());
    int position = control->current(1);
    int line = control->line(position, 1);
    int state = control->state(line, 1);
    command->set(state & 1);
}
}
