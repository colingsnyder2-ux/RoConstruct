// from server: 100% by Xemicl
// roc 2012-06 004366b0  unit: CPatchedControlComboBox  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004366b0
//
// 004366b0  83ec08               sub esp, 8
// 004366b3  a13449db00           mov eax, dword ptr [0xdb4934]
// 004366b8  56                   push esi
// 004366b9  57                   push edi
// 004366ba  8bf9                 mov edi, ecx
// 004366bc  8d4c2408             lea ecx, [esp + 8]
// 004366c0  51                   push ecx
// 004366c1  8d4c2410             lea ecx, [esp + 0x10]
// 004366c5  89442410             mov dword ptr [esp + 0x10], eax
// 004366c9  e872c73000           call 0x742e40
// 004366ce  0fb674240a           movzx esi, byte ptr [esp + 0xa]
// 004366d3  0fb6542409           movzx edx, byte ptr [esp + 9]
// 004366d8  0fb6442408           movzx eax, byte ptr [esp + 8]
// 004366dd  8b8fec000000         mov ecx, dword ptr [edi + 0xec]
// 004366e3  6a01                 push 1
// 004366e5  c1e608               shl esi, 8
// 004366e8  6a01                 push 1
// 004366ea  0bf2                 or esi, edx
// 004366ec  6840800000           push 0x8040
// 004366f1  c1e608               shl esi, 8
// 004366f4  6a02                 push 2
// 004366f6  0bf0                 or esi, eax
// 004366f8  e823df5600           call 0x9a4620
// 004366fd  85c0                 test eax, eax
// 004366ff  7408                 je 0x436709
// 00436701  56                   push esi
// 00436702  8bc8                 mov ecx, eax
// 00436704  e867465900           call 0x9cad70
// 00436709  5f                   pop edi
// 0043670a  33c0                 xor eax, eax
// 0043670c  5e                   pop esi
// 0043670d  83c408               add esp, 8
// 00436710  c20800               ret 8
// copied from an identical function in another client (function ?OnUpdateColor@CMainFrame@@QAEJIJ@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Color3uint8 {
    unsigned char r, g, b;
};

struct BrickColor {
    int value;
    Color3uint8 color8() const;
    static BrickColor current;
};

struct ColorPopup {
    void SetColor(unsigned long);
};

struct CommandBars {
    ColorPopup* FindControl(int, int, int, int);
};

struct CMainFrame {
    char pad[0xec];
    CommandBars* bars;
    long OnUpdateColor(unsigned int, long);
};

long CMainFrame::OnUpdateColor(unsigned int, long)
{
    BrickColor color = BrickColor::current;
    Color3uint8 rgb = color.color8();
    unsigned long value = (((unsigned long)rgb.b << 8) | rgb.g) << 8;
    value |= rgb.r;

    ColorPopup* popup = bars->FindControl(2, 0x8040, 1, 1);
    if (popup)
        popup->SetColor(value);
    return 0;
}