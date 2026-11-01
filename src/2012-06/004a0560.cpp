// from server: 100% by Yeetserama
// roc 2012-06 004a0560  unit: CScriptEditor  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0560
//
// 004a0560  56                   push esi
// 004a0561  e82a370500           call 0x4f3c90
// 004a0566  8bf0                 mov esi, eax
// 004a0568  6a01                 push 1
// 004a056a  8bce                 mov ecx, esi
// 004a056c  e8bfc4ffff           call 0x49ca30
// 004a0571  6a01                 push 1
// 004a0573  50                   push eax
// 004a0574  8bce                 mov ecx, esi
// 004a0576  e8e5cfffff           call 0x49d560
// 004a057b  6a01                 push 1
// 004a057d  50                   push eax
// 004a057e  8bce                 mov ecx, esi
// 004a0580  e86bc8ffff           call 0x49cdf0
// 004a0585  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004a0589  8b11                 mov edx, dword ptr [ecx]
// 004a058b  83e001               and eax, 1
// 004a058e  5e                   pop esi
// 004a058f  89442404             mov dword ptr [esp + 4], eax
// 004a0593  8b02                 mov eax, dword ptr [edx]
// 004a0595  ffe0                 jmp eax
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
