// from server: 74% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0042fb20  unit: CMainFrame  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042fb20
//
// 0042fb20  83ec10               sub esp, 0x10
// 0042fb23  56                   push esi
// 0042fb24  57                   push edi
// 0042fb25  8d44240c             lea eax, [esp + 0xc]
// 0042fb29  8bf9                 mov edi, ecx
// 0042fb2b  50                   push eax
// 0042fb2c  8d4c2424             lea ecx, [esp + 0x24]
// 0042fb30  e83b671800           call 0x5b6270
// 0042fb35  50                   push eax
// 0042fb36  8d4c240c             lea ecx, [esp + 0xc]
// 0042fb3a  e8610b0e00           call 0x5106a0
// 0042fb3f  0fb674240a           movzx esi, byte ptr [esp + 0xa]
// 0042fb44  0fb64c2409           movzx ecx, byte ptr [esp + 9]
// 0042fb49  0fb6542408           movzx edx, byte ptr [esp + 8]
// 0042fb4e  6a01                 push 1
// 0042fb50  c1e608               shl esi, 8
// 0042fb53  0bf1                 or esi, ecx
// 0042fb55  8b4ffc               mov ecx, dword ptr [edi - 4]
// 0042fb58  6a01                 push 1
// 0042fb5a  6840800000           push 0x8040
// 0042fb5f  c1e608               shl esi, 8
// 0042fb62  6a02                 push 2
// 0042fb64  0bf2                 or esi, edx
// 0042fb66  e8d5532700           call 0x6a4f40
// 0042fb6b  85c0                 test eax, eax
// 0042fb6d  7408                 je 0x42fb77
// 0042fb6f  56                   push esi
// 0042fb70  8bc8                 mov ecx, eax
// 0042fb72  e8799c2b00           call 0x6e97f0
// 0042fb77  5f                   pop edi
// 0042fb78  5e                   pop esi
// 0042fb79  83c410               add esp, 0x10
// 0042fb7c  c20800               ret 8

struct Color3 {
    float r, g, b;
};

struct BrickColor {
    int value;
    Color3 color() const;
};

struct Color3uint8 {
    unsigned char r, g, b;
    Color3uint8(const Color3&);
};

struct ColorPopup {
    void SetColor(unsigned long);
};

struct CommandBars {
    ColorPopup* FindControl(int, int, int, int);
};

struct CMainFrame {
    void UpdateColor(int, BrickColor);
};

void CMainFrame::UpdateColor(int, BrickColor color)
{
    Color3uint8 rgb(color.color());
    unsigned long value = (((unsigned long)rgb.b << 8) | rgb.g) << 8;
    value |= rgb.r;

    CommandBars* bars = reinterpret_cast<CommandBars**>(this)[-1];
    ColorPopup* popup = bars->FindControl(2, 0x8040, 1, 1);
    if (popup)
        popup->SetColor(value);
}
