// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006773f0  unit: RBX::AdornG3D  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006773f0
//
// 006773f0  83ec64               sub esp, 0x64
// 006773f3  8b442470             mov eax, dword ptr [esp + 0x70]
// 006773f7  56                   push esi
// 006773f8  57                   push edi
// 006773f9  50                   push eax
// 006773fa  e8d176f6ff           call 0x5dead0
// 006773ff  8b742478             mov esi, dword ptr [esp + 0x78]
// 00677403  83c404               add esp, 4
// 00677406  50                   push eax
// 00677407  8d4c241c             lea ecx, [esp + 0x1c]
// 0067740b  51                   push ecx
// 0067740c  8bce                 mov ecx, esi
// 0067740e  e83dbfe9ff           call 0x513350
// 00677413  50                   push eax
// 00677414  8d4c2440             lea ecx, [esp + 0x40]
// 00677418  e803bee9ff           call 0x513220
// 0067741d  d94624               fld dword ptr [esi + 0x24]
// 00677420  d95c2460             fstp dword ptr [esp + 0x60]
// 00677424  8d44243c             lea eax, [esp + 0x3c]
// 00677428  d94628               fld dword ptr [esi + 0x28]
// 0067742b  50                   push eax
// 0067742c  d95c2468             fstp dword ptr [esp + 0x68]
// 00677430  d9462c               fld dword ptr [esi + 0x2c]
// 00677433  8b742474             mov esi, dword ptr [esp + 0x74]
// 00677437  8b16                 mov edx, dword ptr [esi]
// 00677439  d95c246c             fstp dword ptr [esp + 0x6c]
// 0067743d  8b5238               mov edx, dword ptr [edx + 0x38]
// 00677440  8bce                 mov ecx, esi
// 00677442  ffd2                 call edx
// 00677444  8b842484000000       mov eax, dword ptr [esp + 0x84]
// 0067744b  d900                 fld dword ptr [eax]
// 0067744d  8b3e                 mov edi, dword ptr [esi]
// 0067744f  d95c2408             fstp dword ptr [esp + 8]
// 00677453  d94004               fld dword ptr [eax + 4]
// 00677456  d95c240c             fstp dword ptr [esp + 0xc]
// 0067745a  d94008               fld dword ptr [eax + 8]
// 0067745d  d95c2410             fstp dword ptr [esp + 0x10]
// 00677461  d9e8                 fld1 
// 00677463  d95c2414             fstp dword ptr [esp + 0x14]
// 00677467  e8a43a1400           call 0x7baf10
// 0067746c  d944247c             fld dword ptr [esp + 0x7c]
// 00677470  8b5750               mov edx, dword ptr [edi + 0x50]
// 00677473  50                   push eax
// 00677474  8d44240c             lea eax, [esp + 0xc]
// 00677478  50                   push eax
// 00677479  83ec08               sub esp, 8
// 0067747c  d95c2404             fstp dword ptr [esp + 4]
// 00677480  8bce                 mov ecx, esi
// 00677482  d9842490000000       fld dword ptr [esp + 0x90]
// 00677489  d91c24               fstp dword ptr [esp]
// 0067748c  ffd2                 call edx
// 0067748e  5f                   pop edi
// 0067748f  5e                   pop esi
// 00677490  83c464               add esp, 0x64
// 00677493  c3                   ret 

struct Matrix {
    float m[9];
    Matrix(const Matrix&);
    const Matrix& multiply(Matrix& result, const Matrix&) const;
};

struct Vector3 {
    float x, y, z;
};

struct Frame {
    Matrix rotation;
    Vector3 translation;
};

struct Color {
    float r, g, b, a;
};

struct Adorn;

struct AdornTable {
    char reserved0[56];
    void (__thiscall *setFrame)(Adorn*, const Frame&);
    char reserved1[20];
    void (__thiscall *draw)(Adorn*, float, float, const Color&, const Color&, int);
};

struct Adorn {
    AdornTable* table;
};

extern const Matrix& __cdecl convertRotation(const Vector3&);
extern const Color& __cdecl defaultColor();

void __cdecl render(Adorn* adorn, const Frame* frame,
                    const Vector3& rotation, float first, float second,
                    const Vector3& rgb, int extra)
{
    float temporary[9];
    Frame transformed = {
        frame->rotation.multiply(
            *reinterpret_cast<Matrix*>(temporary), convertRotation(rotation)),
        { frame->translation.x, frame->translation.y, frame->translation.z }
    };
    adorn->table->setFrame(adorn, transformed);

    AdornTable* table = adorn->table;
    Color color = { rgb.x, rgb.y, rgb.z, 1.0f };
    table->draw(adorn, second, first, color, defaultColor(), extra);
}
