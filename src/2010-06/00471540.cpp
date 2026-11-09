// from server: 100% by Yeetserama
// roc 2010-06 00471540  unit: CScriptEditor  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00471540
//
// 00471540  56                   push esi
// 00471541  e8aad1ffff           call 0x46e6f0
// 00471546  8bf0                 mov esi, eax
// 00471548  6a01                 push 1
// 0047154a  6a02                 push 2
// 0047154c  8bce                 mov ecx, esi
// 0047154e  e8ddc3ffff           call 0x46d930
// 00471553  6a01                 push 1
// 00471555  8bce                 mov ecx, esi
// 00471557  85c0                 test eax, eax
// 00471559  740b                 je 0x471566
// 0047155b  6a00                 push 0
// 0047155d  6a02                 push 2
// 0047155f  e87cc3ffff           call 0x46d8e0
// 00471564  5e                   pop esi
// 00471565  c3                   ret 
// 00471566  6a10                 push 0x10
// 00471568  6a02                 push 2
// 0047156a  e871c3ffff           call 0x46d8e0
// 0047156f  5e                   pop esi
// 00471570  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00001c_00464090@CScriptEditor@ns_ROCX00001c@@QAEXXZ)

namespace ns_ROCX00001c {
// from server: 100% by king_originala
struct Control {
    int query(int, bool);
    void update(int, int, bool);
};

struct CScriptEditor {
    int* control();
    void fn_ROCX00001c_00464090();
};

void CScriptEditor::fn_ROCX00001c_00464090()
{
    Control* p = reinterpret_cast<Control*>(control());
    if (p->query(2, true))
        p->update(2, 0, true);
    else
        p->update(2, 16, true);
}
}
