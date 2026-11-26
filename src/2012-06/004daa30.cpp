// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 004da9f0  unit: Ogre::ManualObject  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004da9f0
//
// 004da9f0  56                   push esi
// 004da9f1  57                   push edi
// 004da9f2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004da9f6  57                   push edi
// 004da9f7  8bf1                 mov esi, ecx
// 004da9f9  ff15fc2db200         call dword ptr [0xb22dfc]
// 004da9ff  8b4710               mov eax, dword ptr [edi + 0x10]
// 004daa02  894610               mov dword ptr [esi + 0x10], eax
// 004daa05  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 004daa08  894e14               mov dword ptr [esi + 0x14], ecx
// 004daa0b  8b5718               mov edx, dword ptr [edi + 0x18]
// 004daa0e  895618               mov dword ptr [esi + 0x18], edx
// 004daa11  8b471c               mov eax, dword ptr [edi + 0x1c]
// 004daa14  89461c               mov dword ptr [esi + 0x1c], eax
// 004daa17  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 004daa1a  894e20               mov dword ptr [esi + 0x20], ecx
// 004daa1d  8a5724               mov dl, byte ptr [edi + 0x24]
// 004daa20  5f                   pop edi
// 004daa21  885624               mov byte ptr [esi + 0x24], dl
// 004daa24  8bc6                 mov eax, esi
// 004daa26  5e                   pop esi
// 004daa27  c20400               ret 4

class TexturePtr {
public:
    __declspec(dllimport) TexturePtr(const TexturePtr& r);
private:
    char pad0[0x10];
};

struct ManualObject {
    TexturePtr tex;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    char f24;
    ManualObject(const ManualObject& other);
};

ManualObject::ManualObject(const ManualObject& other)
    : tex(other.tex), f10(other.f10), f14(other.f14), f18(other.f18),
      f1c(other.f1c), f20(other.f20), f24(other.f24)
{
}
