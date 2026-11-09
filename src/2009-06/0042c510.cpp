// from server: 100% by EspClaude
// roc 2009-06 0042c510  unit: CMultiPlayerPane  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042c510
//
// 0042c510  837c240401           cmp dword ptr [esp + 4], 1
// 0042c515  56                   push esi
// 0042c516  8bf1                 mov esi, ecx
// 0042c518  741c                 je 0x42c536
// 0042c51a  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 0042c51d  85c9                 test ecx, ecx
// 0042c51f  7415                 je 0x42c536
// 0042c521  8b442410             mov eax, dword ptr [esp + 0x10]
// 0042c525  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0042c529  6a01                 push 1
// 0042c52b  50                   push eax
// 0042c52c  52                   push edx
// 0042c52d  6a00                 push 0
// 0042c52f  6a00                 push 0
// 0042c531  e8d4c82e00           call 0x718e0a
// 0042c536  8bce                 mov ecx, esi
// 0042c538  e8cbca2e00           call 0x719008
// 0042c53d  5e                   pop esi
// 0042c53e  c20c00               ret 0xc
// copied from an identical function in another client (function ?OnSize@CMultiPlayerPane@ns_ROCX000022@@QAEXIHH@Z)

namespace ns_ROCX000022 {
struct ChildWindow
{
    void __thiscall MoveWindow(int x, int y, int width, int height, int repaint);
};

struct CMultiPlayerPane
{
    char reserved[0x54];
    ChildWindow* child;

    void __thiscall UpdateLayout();
    void __thiscall OnSize(unsigned int type, int width, int height);
};

void CMultiPlayerPane::OnSize(unsigned int type, int width, int height)
{
    if (type != 1 && child)
        child->MoveWindow(0, 0, width, height, 1);

    UpdateLayout();
}
}
