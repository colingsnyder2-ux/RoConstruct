// from server: 100% by Yeetserama
// roc 2012-06 004451c0  unit: std::D::DU?$char_traits::?$basic_ifstream  size: 247 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004451c0
//
// 004451c0  6aff                 push -1
// 004451c2  68abdca900           push 0xa9dcab
// 004451c7  64a100000000         mov eax, dword ptr fs:[0]
// 004451cd  50                   push eax
// 004451ce  64892500000000       mov dword ptr fs:[0], esp
// 004451d5  81ec44010000         sub esp, 0x144
// 004451db  a13449db00           mov eax, dword ptr [0xdb4934]
// 004451e0  56                   push esi
// 004451e1  8bf1                 mov esi, ecx
// 004451e3  8d4c2410             lea ecx, [esp + 0x10]
// 004451e7  51                   push ecx
// 004451e8  8d4c240c             lea ecx, [esp + 0xc]
// 004451ec  8944240c             mov dword ptr [esp + 0xc], eax
// 004451f0  e8bbdd2f00           call 0x742fb0
// 004451f5  50                   push eax
// 004451f6  8d4c2408             lea ecx, [esp + 8]
// 004451fa  e8b1321e00           call 0x6284b0
// 004451ff  0fb6442406           movzx eax, byte ptr [esp + 6]
// 00445204  0fb6542405           movzx edx, byte ptr [esp + 5]
// 00445209  0fb64c2404           movzx ecx, byte ptr [esp + 4]
// 0044520e  c1e008               shl eax, 8
// 00445211  0bc2                 or eax, edx
// 00445213  56                   push esi
// 00445214  c1e008               shl eax, 8
// 00445217  0bc1                 or eax, ecx
// 00445219  6a40                 push 0x40
// 0044521b  50                   push eax
// 0044521c  50                   push eax
// 0044521d  8d4c242c             lea ecx, [esp + 0x2c]
// 00445221  e87a3c5a00           call 0x9e8ea0
// 00445226  8d4c241c             lea ecx, [esp + 0x1c]
// 0044522a  c784245001000000000000 mov dword ptr [esp + 0x150], 0
// 00445235  e842d95300           call 0x982b7c
// 0044523a  83f801               cmp eax, 1
// 0044523d  754c                 jne 0x44528b
// 0044523f  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 00445246  8bd0                 mov edx, eax
// 00445248  c1ea08               shr edx, 8
// 0044524b  88442408             mov byte ptr [esp + 8], al
// 0044524f  51                   push ecx
// 00445250  8bcc                 mov ecx, esp
// 00445252  8854240d             mov byte ptr [esp + 0xd], dl
// 00445256  668b54240c           mov dx, word ptr [esp + 0xc]
// 0044525b  c1e810               shr eax, 0x10
// 0044525e  668911               mov word ptr [ecx], dx
// 00445261  884102               mov byte ptr [ecx + 2], al
// 00445264  8d442410             lea eax, [esp + 0x10]
// 00445268  50                   push eax
// 00445269  e882dd2f00           call 0x742ff0
// 0044526e  8b00                 mov eax, dword ptr [eax]
// 00445270  83c408               add esp, 8
// 00445273  39053449db00         cmp dword ptr [0xdb4934], eax
// 00445279  7410                 je 0x44528b
// 0044527b  50                   push eax
// 0044527c  b93849db00           mov ecx, 0xdb4938
// 00445281  a33449db00           mov dword ptr [0xdb4934], eax
// 00445286  e855f9ffff           call 0x444be0
// 0044528b  8d4c241c             lea ecx, [esp + 0x1c]
// 0044528f  c7842450010000ffffffff mov dword ptr [esp + 0x150], 0xffffffff
// 0044529a  e8513d5a00           call 0x9e8ff0
// 0044529f  8b8c2448010000       mov ecx, dword ptr [esp + 0x148]
// 004452a6  64890d00000000       mov dword ptr fs:[0], ecx
// 004452ad  5e                   pop esi
// 004452ae  81c450010000         add esp, 0x150
// 004452b4  c20800               ret 8
// copied from an identical function in another client (function ?func_431160@CDataModelPropGrid@ns_ROCX00000d@@QAEXHH@Z)

namespace ns_ROCX00000d {
// from server: 100% by colin
struct Float3
{
    float r, g, b;
};

struct RGB
{
    unsigned char r, g, b;
    RGB() {}
    RGB(const Float3&);
};

struct PackedColor
{
    unsigned int value;
    Float3* getColor(Float3*);
};

extern PackedColor currentColor;
extern "C" unsigned int* __cdecl closestColor(unsigned int*, RGB);

struct CDataModelPropGrid
{
    void func_431160(int, int);
};

struct ColorDialog
{
    char padding[0x124];
    unsigned int color;
    char tail[4];

    ColorDialog(unsigned int, unsigned int, unsigned int,
                CDataModelPropGrid*);
    ~ColorDialog();
    int doModal();
};

struct MainFrame
{
    void updateColor(unsigned int);
};

extern MainFrame mainFrame;

void CDataModelPropGrid::func_431160(int, int)
{
    Float3 floats;
    RGB rgb(*PackedColor(currentColor).getColor(&floats));

    unsigned int color =
        ((static_cast<unsigned int>(rgb.b) << 8) | rgb.g) << 8 | rgb.r;

    ColorDialog dialog(color, color, 0x40, this);
    if (dialog.doModal() == 1)
    {
        RGB selected;
        selected.r = static_cast<unsigned char>(dialog.color);
        selected.g = static_cast<unsigned char>(dialog.color >> 8);
        selected.b = static_cast<unsigned char>(dialog.color >> 16);

        unsigned int result;
        unsigned int value = *closestColor(&result, selected);
        if (currentColor.value != value)
        {
            currentColor.value = value;
            mainFrame.updateColor(value);
        }
    }
}
}
