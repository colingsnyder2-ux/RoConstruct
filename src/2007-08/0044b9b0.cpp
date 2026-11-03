// from server: 76% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0044de10  unit: CRobloxControlColorSelector  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044de10
//
// 0044de10  83ec10               sub esp, 0x10
// 0044de13  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044de17  53                   push ebx
// 0044de18  56                   push esi
// 0044de19  57                   push edi
// 0044de1a  8bf9                 mov edi, ecx
// 0044de1c  8bc8                 mov ecx, eax
// 0044de1e  c1e908               shr ecx, 8
// 0044de21  88442420             mov byte ptr [esp + 0x20], al
// 0044de25  51                   push ecx
// 0044de26  884c2425             mov byte ptr [esp + 0x25], cl
// 0044de2a  668b542424           mov dx, word ptr [esp + 0x24]
// 0044de2f  8bcc                 mov ecx, esp
// 0044de31  c1e810               shr eax, 0x10
// 0044de34  668911               mov word ptr [ecx], dx
// 0044de37  884102               mov byte ptr [ecx + 2], al
// 0044de3a  8d44241c             lea eax, [esp + 0x1c]
// 0044de3e  50                   push eax
// 0044de3f  e85c841600           call 0x5b62a0
// 0044de44  8b08                 mov ecx, dword ptr [eax]
// 0044de46  83c408               add esp, 8
// 0044de49  8d542420             lea edx, [esp + 0x20]
// 0044de4d  894c2414             mov dword ptr [esp + 0x14], ecx
// 0044de51  52                   push edx
// 0044de52  8d4c2418             lea ecx, [esp + 0x18]
// 0044de56  e825831600           call 0x5b6180
// 0044de5b  0fb65802             movzx ebx, byte ptr [eax + 2]
// 0044de5f  8d44240e             lea eax, [esp + 0xe]
// 0044de63  50                   push eax
// 0044de64  8d4c2418             lea ecx, [esp + 0x18]
// 0044de68  c1e308               shl ebx, 8
// 0044de6b  e810831600           call 0x5b6180
// 0044de70  0fb67001             movzx esi, byte ptr [eax + 1]
// 0044de74  8d4c2411             lea ecx, [esp + 0x11]
// 0044de78  51                   push ecx
// 0044de79  0bf3                 or esi, ebx
// 0044de7b  8d4c2418             lea ecx, [esp + 0x18]
// 0044de7f  c1e608               shl esi, 8
// 0044de82  e8f9821600           call 0x5b6180
// 0044de87  0fb610               movzx edx, byte ptr [eax]
// 0044de8a  0bd6                 or edx, esi
// 0044de8c  6a01                 push 1
// 0044de8e  8bcf                 mov ecx, edi
// 0044de90  899780010000         mov dword ptr [edi + 0x180], edx
// 0044de96  e835da2500           call 0x6ab8d0
// 0044de9b  5f                   pop edi
// 0044de9c  5e                   pop esi
// 0044de9d  5b                   pop ebx
// 0044de9e  83c410               add esp, 0x10
// 0044dea1  c20400               ret 4

struct RGB
{
    unsigned char r, g, b;
};

struct Color
{
    unsigned int value;
    RGB getRGB() const;
};

extern void *__cdecl convert(void *destination, RGB color);

struct CRobloxControlColorSelector
{
    char padding[0x180];
    unsigned int selectedColor;

    void update(int);
    void f(unsigned int);
};

void CRobloxControlColorSelector::f(unsigned int value)
{
    RGB rgb;
    rgb.r = (unsigned char)value;
    rgb.g = (unsigned char)(value >> 8);
    rgb.b = (unsigned char)(value >> 16);

    Color temporary;
    Color color = *(Color *)convert(&temporary, rgb);

    selectedColor = color.getRGB().r |
        ((color.getRGB().g | (color.getRGB().b << 8)) << 8);
    update(1);
}
