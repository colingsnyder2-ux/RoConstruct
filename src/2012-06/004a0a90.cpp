// from server: 100% by Xemicl
// roc 2012-06 004a0a90  unit: CScriptEditor  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0a90
//
// 004a0a90  56                   push esi
// 004a0a91  e8fa310500           call 0x4f3c90
// 004a0a96  8bf0                 mov esi, eax
// 004a0a98  6a01                 push 1
// 004a0a9a  8bce                 mov ecx, esi
// 004a0a9c  e85fcfffff           call 0x49da00
// 004a0aa1  85c0                 test eax, eax
// 004a0aa3  7409                 je 0x4a0aae
// 004a0aa5  6a01                 push 1
// 004a0aa7  8bce                 mov ecx, esi
// 004a0aa9  e822cfffff           call 0x49d9d0
// 004a0aae  5e                   pop esi
// 004a0aaf  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000014_004644e0@CScriptEditor@ns_ROCX000014@@QAEXH@Z)

namespace ns_ROCX000014 {
struct Control
{
    int canUndo(int direct);
    void undo(int direct);
};

struct CScriptEditor
{
    int* getControl();
    void fn_ROCX000014_004644e0(int unused);
};

void CScriptEditor::fn_ROCX000014_004644e0(int unused)
{
    Control* control = reinterpret_cast<Control*>(getControl());
    if (control->canUndo(1))
        control->undo(1);
}
}
