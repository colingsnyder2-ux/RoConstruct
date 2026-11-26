// from server: 100% by Xemicl
// roc 2012-06 00448c70  unit: CMultiPlayerPane  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00448c70
//
// 00448c70  837c240401           cmp dword ptr [esp + 4], 1
// 00448c75  56                   push esi
// 00448c76  8bf1                 mov esi, ecx
// 00448c78  741c                 je 0x448c96
// 00448c7a  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 00448c7d  85c9                 test ecx, ecx
// 00448c7f  7415                 je 0x448c96
// 00448c81  8b442410             mov eax, dword ptr [esp + 0x10]
// 00448c85  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00448c89  6a01                 push 1
// 00448c8b  50                   push eax
// 00448c8c  52                   push edx
// 00448c8d  6a00                 push 0
// 00448c8f  6a00                 push 0
// 00448c91  e844985300           call 0x9824da
// 00448c96  8bce                 mov ecx, esi
// 00448c98  e8419a5300           call 0x9826de
// 00448c9d  5e                   pop esi
// 00448c9e  c20c00               ret 0xc
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