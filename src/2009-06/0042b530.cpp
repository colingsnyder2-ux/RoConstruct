// from server: 93% by EspClaude
// from server: 100% by colin
// roc 2008-06 00431160  unit: CDataModelPropGrid  size: 247 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00431160
//
// 00431160  6aff                 push -1
// 00431162  689bfb7b00           push 0x7bfb9b
// 00431167  64a100000000         mov eax, dword ptr fs:[0]
// 0043116d  50                   push eax
// 0043116e  64892500000000       mov dword ptr fs:[0], esp
// 00431175  81ec44010000         sub esp, 0x144
// 0043117b  a1c06f9700           mov eax, dword ptr [0x976fc0]
// 00431180  56                   push esi
// 00431181  8bf1                 mov esi, ecx
// 00431183  8d4c2410             lea ecx, [esp + 0x10]
// 00431187  51                   push ecx
// 00431188  8d4c240c             lea ecx, [esp + 0xc]
// 0043118c  8944240c             mov dword ptr [esp + 0xc], eax
// 00431190  e8db501800           call 0x5b6270
// 00431195  50                   push eax
// 00431196  8d4c2408             lea ecx, [esp + 8]
// 0043119a  e801f50d00           call 0x5106a0
// 0043119f  0fb6442406           movzx eax, byte ptr [esp + 6]
// 004311a4  0fb6542405           movzx edx, byte ptr [esp + 5]
// 004311a9  0fb64c2404           movzx ecx, byte ptr [esp + 4]
// 004311ae  c1e008               shl eax, 8
// 004311b1  0bc2                 or eax, edx
// 004311b3  56                   push esi
// 004311b4  c1e008               shl eax, 8
// 004311b7  0bc1                 or eax, ecx
// 004311b9  6a40                 push 0x40
// 004311bb  50                   push eax
// 004311bc  50                   push eax
// 004311bd  8d4c242c             lea ecx, [esp + 0x2c]
// 004311c1  e82a542d00           call 0x7065f0
// 004311c6  8d4c241c             lea ecx, [esp + 0x1c]
// 004311ca  c784245001000000000000 mov dword ptr [esp + 0x150], 0
// 004311d5  e866fe2600           call 0x6a1040
// 004311da  83f801               cmp eax, 1
// 004311dd  754c                 jne 0x43122b
// 004311df  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 004311e6  8bd0                 mov edx, eax
// 004311e8  c1ea08               shr edx, 8
// 004311eb  88442408             mov byte ptr [esp + 8], al
// 004311ef  51                   push ecx
// 004311f0  8bcc                 mov ecx, esp
// 004311f2  8854240d             mov byte ptr [esp + 0xd], dl
// 004311f6  668b54240c           mov dx, word ptr [esp + 0xc]
// 004311fb  c1e810               shr eax, 0x10
// 004311fe  668911               mov word ptr [ecx], dx
// 00431201  884102               mov byte ptr [ecx + 2], al
// 00431204  8d442410             lea eax, [esp + 0x10]
// 00431208  50                   push eax
// 00431209  e892501800           call 0x5b62a0
// 0043120e  8b00                 mov eax, dword ptr [eax]
// 00431210  83c408               add esp, 8
// 00431213  3905c06f9700         cmp dword ptr [0x976fc0], eax
// 00431219  7410                 je 0x43122b
// 0043121b  50                   push eax
// 0043121c  b9a06f9700           mov ecx, 0x976fa0
// 00431221  a3c06f9700           mov dword ptr [0x976fc0], eax
// 00431226  e8e5fbffff           call 0x430e10
// 0043122b  8d4c241c             lea ecx, [esp + 0x1c]
// 0043122f  c7842450010000ffffffff mov dword ptr [esp + 0x150], 0xffffffff
// 0043123a  e801552d00           call 0x706740
// 0043123f  8b8c2448010000       mov ecx, dword ptr [esp + 0x148]
// 00431246  64890d00000000       mov dword ptr fs:[0], ecx
// 0043124d  5e                   pop esi
// 0043124e  81c450010000         add esp, 0x150
// 00431254  c20800               ret 8

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
