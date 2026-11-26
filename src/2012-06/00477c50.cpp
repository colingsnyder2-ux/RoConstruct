// from server: 100% by Xemicl
// roc 2012-06 00477c50  unit: CRobloxControlColorSelector  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00477c50
//
// 00477c50  83ec10               sub esp, 0x10
// 00477c53  8b442414             mov eax, dword ptr [esp + 0x14]
// 00477c57  53                   push ebx
// 00477c58  56                   push esi
// 00477c59  57                   push edi
// 00477c5a  8bf9                 mov edi, ecx
// 00477c5c  8bc8                 mov ecx, eax
// 00477c5e  c1e908               shr ecx, 8
// 00477c61  88442420             mov byte ptr [esp + 0x20], al
// 00477c65  51                   push ecx
// 00477c66  884c2425             mov byte ptr [esp + 0x25], cl
// 00477c6a  668b542424           mov dx, word ptr [esp + 0x24]
// 00477c6f  8bcc                 mov ecx, esp
// 00477c71  c1e810               shr eax, 0x10
// 00477c74  668911               mov word ptr [ecx], dx
// 00477c77  884102               mov byte ptr [ecx + 2], al
// 00477c7a  8d44241c             lea eax, [esp + 0x1c]
// 00477c7e  50                   push eax
// 00477c7f  e86cb32c00           call 0x742ff0
// 00477c84  8b08                 mov ecx, dword ptr [eax]
// 00477c86  83c408               add esp, 8
// 00477c89  8d542420             lea edx, [esp + 0x20]
// 00477c8d  894c2414             mov dword ptr [esp + 0x14], ecx
// 00477c91  52                   push edx
// 00477c92  8d4c2418             lea ecx, [esp + 0x18]
// 00477c96  e8a5b12c00           call 0x742e40
// 00477c9b  0fb65802             movzx ebx, byte ptr [eax + 2]
// 00477c9f  8d44240e             lea eax, [esp + 0xe]
// 00477ca3  50                   push eax
// 00477ca4  8d4c2418             lea ecx, [esp + 0x18]
// 00477ca8  c1e308               shl ebx, 8
// 00477cab  e890b12c00           call 0x742e40
// 00477cb0  0fb67001             movzx esi, byte ptr [eax + 1]
// 00477cb4  8d4c2411             lea ecx, [esp + 0x11]
// 00477cb8  51                   push ecx
// 00477cb9  0bf3                 or esi, ebx
// 00477cbb  8d4c2418             lea ecx, [esp + 0x18]
// 00477cbf  c1e608               shl esi, 8
// 00477cc2  e879b12c00           call 0x742e40
// 00477cc7  0fb610               movzx edx, byte ptr [eax]
// 00477cca  0bd6                 or edx, esi
// 00477ccc  6a01                 push 1
// 00477cce  8bcf                 mov ecx, edi
// 00477cd0  899780010000         mov dword ptr [edi + 0x180], edx
// 00477cd6  e855d35000           call 0x985030
// 00477cdb  5f                   pop edi
// 00477cdc  5e                   pop esi
// 00477cdd  5b                   pop ebx
// 00477cde  83c410               add esp, 0x10
// 00477ce1  c20400               ret 4
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