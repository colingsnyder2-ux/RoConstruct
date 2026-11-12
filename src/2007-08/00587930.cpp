// from server: 76% by EspClaude
// roc 2007-08 00587930  unit: RBX::Reflection::EnumDescriptor  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00587930
//
// 00587930  83ec18               sub esp, 0x18
// 00587933  56                   push esi
// 00587934  8bf1                 mov esi, ecx
// 00587936  f6861d01000001       test byte ptr [esi + 0x11d], 1
// 0058793d  745a                 je 0x587999
// 0058793f  8b8e24010000         mov ecx, dword ptr [esi + 0x124]
// 00587945  85c9                 test ecx, ecx
// 00587947  7450                 je 0x587999
// 00587949  e832c6feff           call 0x573f80
// 0058794e  d94024               fld dword ptr [eax + 0x24]
// 00587951  8b8e24010000         mov ecx, dword ptr [esi + 0x124]
// 00587957  d95c2410             fstp dword ptr [esp + 0x10]
// 0058795b  d94028               fld dword ptr [eax + 0x28]
// 0058795e  83c024               add eax, 0x24
// 00587961  d95c2414             fstp dword ptr [esp + 0x14]
// 00587965  d94008               fld dword ptr [eax + 8]
// 00587968  d95c2418             fstp dword ptr [esp + 0x18]
// 0058796c  e85fc6feff           call 0x573fd0
// 00587971  d900                 fld dword ptr [eax]
// 00587973  8b542420             mov edx, dword ptr [esp + 0x20]
// 00587977  d95c2404             fstp dword ptr [esp + 4]
// 0058797b  8d4c2410             lea ecx, [esp + 0x10]
// 0058797f  d94004               fld dword ptr [eax + 4]
// 00587982  d95c2408             fstp dword ptr [esp + 8]
// 00587986  d94008               fld dword ptr [eax + 8]
// 00587989  8d442404             lea eax, [esp + 4]
// 0058798d  50                   push eax
// 0058798e  d95c2410             fstp dword ptr [esp + 0x10]
// 00587992  51                   push ecx
// 00587993  52                   push edx
// 00587994  e869820a00           call 0x62fc02
// 00587999  5e                   pop esi
// 0058799a  83c418               add esp, 0x18
// 0058799d  c20400               ret 4
// 005879a0  c701bce87a00         mov dword ptr [ecx], 0x7ae8bc
// 005879a6  c74104b0e87a00       mov dword ptr [ecx + 4], 0x7ae8b0
// 005879ad  c74110a8e87a00       mov dword ptr [ecx + 0x10], 0x7ae8a8
// 005879b4  c7411498e87a00       mov dword ptr [ecx + 0x14], 0x7ae898
// 005879bb  c7412c88e87a00       mov dword ptr [ecx + 0x2c], 0x7ae888
// 005879c2  c7414478e87a00       mov dword ptr [ecx + 0x44], 0x7ae878
// 005879c9  c7415c68e87a00       mov dword ptr [ecx + 0x5c], 0x7ae868
// 005879d0  c7417458e87a00       mov dword ptr [ecx + 0x74], 0x7ae858
// 005879d7  c7818c00000048e87a00 mov dword ptr [ecx + 0x8c], 0x7ae848
// 005879e1  e9ca88fbff           jmp 0x5402b0

struct Vector3 {
    float x, y, z;
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct CoordinateFrame {
    float rotation[9];          // +0x00..0x24
    Vector3 translation;        // +0x24
};

class Part {
public:
    const CoordinateFrame& getCoordinateFrame() const;   // 0x573f80
    const Vector3& getSize() const;                      // 0x573fd0
};

struct Adorn;
void __stdcall drawBox(Adorn* adorn, const Vector3& pos, const Vector3& size);  // 0x62fc02

class Descriptor {
public:
    void render(Adorn* adorn);
    char pad0[0x11d];
    unsigned char flags;        // +0x11d
    char pad11e[0x124 - 0x11e];
    Part* part;                 // +0x124
};

void Descriptor::render(Adorn* adorn)
{
    if ((flags & 1) && part) {
        Vector3 pos = part->getCoordinateFrame().translation;
        Vector3 size = part->getSize();
        drawBox(adorn, pos, size);
    }
}
