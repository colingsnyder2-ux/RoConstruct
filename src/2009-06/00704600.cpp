// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00677030  unit: RBX::AdornG3D  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00677030
//
// 00677030  83ec10               sub esp, 0x10
// 00677033  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 00677038  753a                 jne 0x677074
// 0067703a  b801000000           mov eax, 1
// 0067703f  840538db9700         test byte ptr [0x97db38], al
// 00677045  7526                 jne 0x67706d
// 00677047  d90504e78100         fld dword ptr [0x81e704]
// 0067704d  090538db9700         or dword ptr [0x97db38], eax
// 00677053  d91d2cdb9700         fstp dword ptr [0x97db2c]
// 00677059  d90538f88200         fld dword ptr [0x82f838]
// 0067705f  d91d30db9700         fstp dword ptr [0x97db30]
// 00677065  d9e8                 fld1 
// 00677067  d91d34db9700         fstp dword ptr [0x97db34]
// 0067706d  b82cdb9700           mov eax, 0x97db2c
// 00677072  eb05                 jmp 0x677079
// 00677074  e837d9e9ff           call 0x5149b0
// 00677079  d900                 fld dword ptr [eax]
// 0067707b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0067707f  8b542414             mov edx, dword ptr [esp + 0x14]
// 00677083  d91c24               fstp dword ptr [esp]
// 00677086  d94004               fld dword ptr [eax + 4]
// 00677089  d95c2404             fstp dword ptr [esp + 4]
// 0067708d  d94008               fld dword ptr [eax + 8]
// 00677090  8d0424               lea eax, [esp]
// 00677093  50                   push eax
// 00677094  d95c240c             fstp dword ptr [esp + 0xc]
// 00677098  d9e8                 fld1 
// 0067709a  51                   push ecx
// 0067709b  52                   push edx
// 0067709c  d95c2418             fstp dword ptr [esp + 0x18]
// 006770a0  e85bfdffff           call 0x676e00
// 006770a5  83c41c               add esp, 0x1c
// 006770a8  c3                   ret 

extern const float colorComponent0;
extern const float colorComponent1;

struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c);
};

inline Vec3::Vec3(float a, float b, float c)
    : x(a), y(b), z(c) {}

struct Vec4 {
    float x, y, z, w;
};

extern const Vec3& __cdecl alternateColor();
extern void __cdecl draw(void*, void*, const Vec4&);

void __cdecl render(void* a, void* b, int mode)
{
    const Vec3* selected;
    if (mode == 0) {
        static const Vec3 color(colorComponent0, colorComponent1, 1.0f);
        selected = &color;
    } else {
        selected = &alternateColor();
    }

    Vec4 color;
    color.x = selected->x;
    color.y = selected->y;
    color.z = selected->z;
    color.w = 1.0f;
    draw(a, b, color);
}
