// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005738e0  unit: RBX::PercentPanel  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005738e0
//
// 005738e0  83ec20               sub esp, 0x20
// 005738e3  d905784d9700         fld dword ptr [0x974d78]
// 005738e9  56                   push esi
// 005738ea  d95c2404             fstp dword ptr [esp + 4]
// 005738ee  8bf1                 mov esi, ecx
// 005738f0  d9057c4d9700         fld dword ptr [0x974d7c]
// 005738f6  d95c2408             fstp dword ptr [esp + 8]
// 005738fa  e8a162f9ff           call 0x509ba0
// 005738ff  d900                 fld dword ptr [eax]
// 00573901  8d4c240c             lea ecx, [esp + 0xc]
// 00573905  d95c2414             fstp dword ptr [esp + 0x14]
// 00573909  d94004               fld dword ptr [eax + 4]
// 0057390c  8d8664010000         lea eax, [esi + 0x164]
// 00573912  d95c2418             fstp dword ptr [esp + 0x18]
// 00573916  50                   push eax
// 00573917  d9442408             fld dword ptr [esp + 8]
// 0057391b  51                   push ecx
// 0057391c  d95c2424             fstp dword ptr [esp + 0x24]
// 00573920  d9442410             fld dword ptr [esp + 0x10]
// 00573924  d95c2428             fstp dword ptr [esp + 0x28]
// 00573928  e8c3fdffff           call 0x5736f0
// 0057392d  8b9660010000         mov edx, dword ptr [esi + 0x160]
// 00573933  8b865c010000         mov eax, dword ptr [esi + 0x15c]
// 00573939  8b742430             mov esi, dword ptr [esp + 0x30]
// 0057393d  83c408               add esp, 8
// 00573940  52                   push edx
// 00573941  50                   push eax
// 00573942  8d4c2414             lea ecx, [esp + 0x14]
// 00573946  51                   push ecx
// 00573947  56                   push esi
// 00573948  8d4c2424             lea ecx, [esp + 0x24]
// 0057394c  e8afb50500           call 0x5cef00
// 00573951  8bc6                 mov eax, esi
// 00573953  5e                   pop esi
// 00573954  83c420               add esp, 0x20
// 00573957  c20400               ret 4

struct Vector2 {
    float x, y;

    Vector2() {}
    Vector2(float a, float b) : x(a), y(b) {}
};

extern float scaleX;
extern float scaleY;

const Vector2& __cdecl zeroVector();
Vector2 __cdecl transformVector(const Vector2&);

struct UserInputBase {
    float unk0;
    float unk4;
    float unk8;
    float unkC;

    void getSteerThrottle(float* out, const float* in,
                          int steerMode, int throttleMode);
};

struct PercentPanel {
    char padding[0xb8];
    int steerMode;
    int throttleMode;
    Vector2 value;

    Vector2 getInput();
};

Vector2 PercentPanel::getInput()
{
    Vector2 scale(scaleX, scaleY);
    const Vector2& zero = zeroVector();
    UserInputBase input = { zero.x, zero.y, scale.x, scale.y };
    Vector2 transformed = transformVector(value);
    Vector2 result;
    input.getSteerThrottle(&result.x, &transformed.x,
                          steerMode, throttleMode);
    return result;
}
