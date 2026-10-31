// from server: 100% by EspClaude
// roc 2009-06 0044bf40  unit: CRobloxControlColorSelector  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044bf40
//
// 0044bf40  83ec10               sub esp, 0x10
// 0044bf43  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044bf47  53                   push ebx
// 0044bf48  56                   push esi
// 0044bf49  57                   push edi
// 0044bf4a  8bf9                 mov edi, ecx
// 0044bf4c  8bc8                 mov ecx, eax
// 0044bf4e  c1e908               shr ecx, 8
// 0044bf51  88442420             mov byte ptr [esp + 0x20], al
// 0044bf55  51                   push ecx
// 0044bf56  884c2425             mov byte ptr [esp + 0x25], cl
// 0044bf5a  668b542424           mov dx, word ptr [esp + 0x24]
// 0044bf5f  8bcc                 mov ecx, esp
// 0044bf61  c1e810               shr eax, 0x10
// 0044bf64  668911               mov word ptr [ecx], dx
// 0044bf67  884102               mov byte ptr [ecx + 2], al
// 0044bf6a  8d44241c             lea eax, [esp + 0x1c]
// 0044bf6e  50                   push eax
// 0044bf6f  e8ec6c1f00           call 0x642c60
// 0044bf74  8b08                 mov ecx, dword ptr [eax]
// 0044bf76  83c408               add esp, 8
// 0044bf79  8d542420             lea edx, [esp + 0x20]
// 0044bf7d  894c2414             mov dword ptr [esp + 0x14], ecx
// 0044bf81  52                   push edx
// 0044bf82  8d4c2418             lea ecx, [esp + 0x18]
// 0044bf86  e8956b1f00           call 0x642b20
// 0044bf8b  0fb65802             movzx ebx, byte ptr [eax + 2]
// 0044bf8f  8d44240e             lea eax, [esp + 0xe]
// 0044bf93  50                   push eax
// 0044bf94  8d4c2418             lea ecx, [esp + 0x18]
// 0044bf98  c1e308               shl ebx, 8
// 0044bf9b  e8806b1f00           call 0x642b20
// 0044bfa0  0fb67001             movzx esi, byte ptr [eax + 1]
// 0044bfa4  8d4c2411             lea ecx, [esp + 0x11]
// 0044bfa8  51                   push ecx
// 0044bfa9  0bf3                 or esi, ebx
// 0044bfab  8d4c2418             lea ecx, [esp + 0x18]
// 0044bfaf  c1e608               shl esi, 8
// 0044bfb2  e8696b1f00           call 0x642b20
// 0044bfb7  0fb610               movzx edx, byte ptr [eax]
// 0044bfba  0bd6                 or edx, esi
// 0044bfbc  6a01                 push 1
// 0044bfbe  8bcf                 mov ecx, edi
// 0044bfc0  899780010000         mov dword ptr [edi + 0x180], edx
// 0044bfc6  e8e53f2d00           call 0x71ffb0
// 0044bfcb  5f                   pop edi
// 0044bfcc  5e                   pop esi
// 0044bfcd  5b                   pop ebx
// 0044bfce  83c410               add esp, 0x10
// 0044bfd1  c20400               ret 4
// copied from an identical function in another client (function ?f@CRobloxControlColorSelector@ns_ROCX000013@@QAEXI@Z)

namespace ns_ROCX000013 {
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
}
