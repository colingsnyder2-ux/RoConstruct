// from server: 100% by Yeetserama
// roc 2010-06 00471460  unit: CScriptEditor  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00471460
//
// 00471460  56                   push esi
// 00471461  e88ad2ffff           call 0x46e6f0
// 00471466  8bf0                 mov esi, eax
// 00471468  6a01                 push 1
// 0047146a  8bce                 mov ecx, esi
// 0047146c  e8bfbfffff           call 0x46d430
// 00471471  6a01                 push 1
// 00471473  50                   push eax
// 00471474  8bce                 mov ecx, esi
// 00471476  e8a5caffff           call 0x46df20
// 0047147b  6a01                 push 1
// 0047147d  50                   push eax
// 0047147e  8bce                 mov ecx, esi
// 00471480  e82bc3ffff           call 0x46d7b0
// 00471485  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00471489  8b11                 mov edx, dword ptr [ecx]
// 0047148b  83e001               and eax, 1
// 0047148e  5e                   pop esi
// 0047148f  89442404             mov dword ptr [esp + 4], eax
// 00471493  8b02                 mov eax, dword ptr [edx]
// 00471495  ffe0                 jmp eax
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
