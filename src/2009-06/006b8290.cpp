// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00619c30  unit: RBX::DecalTool  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00619c30
//
// 00619c30  83ec10               sub esp, 0x10
// 00619c33  56                   push esi
// 00619c34  8bf1                 mov esi, ecx
// 00619c36  837e1800             cmp dword ptr [esi + 0x18], 0
// 00619c3a  743e                 je 0x619c7a
// 00619c3c  e86fadefff           call 0x5149b0
// 00619c41  d900                 fld dword ptr [eax]
// 00619c43  8b542418             mov edx, dword ptr [esp + 0x18]
// 00619c47  d95c2404             fstp dword ptr [esp + 4]
// 00619c4b  d94004               fld dword ptr [eax + 4]
// 00619c4e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00619c51  d95c2408             fstp dword ptr [esp + 8]
// 00619c55  d94008               fld dword ptr [eax + 8]
// 00619c58  8d442404             lea eax, [esp + 4]
// 00619c5c  50                   push eax
// 00619c5d  d95c2410             fstp dword ptr [esp + 0x10]
// 00619c61  8b4624               mov eax, dword ptr [esi + 0x24]
// 00619c64  d9e8                 fld1 
// 00619c66  52                   push edx
// 00619c67  d95c2418             fstp dword ptr [esp + 0x18]
// 00619c6b  50                   push eax
// 00619c6c  e81f0ef8ff           call 0x59aa90
// 00619c71  50                   push eax
// 00619c72  e8b9d90500           call 0x677630
// 00619c77  83c410               add esp, 0x10
// 00619c7a  5e                   pop esi
// 00619c7b  83c410               add esp, 0x10
// 00619c7e  c20400               ret 4

struct Vector3 {
    float x, y, z;
};

struct Vector4 {
    float x, y, z, w;
};

const Vector3& __cdecl getVector();

struct Decal {
    void* getTexture();
};

void __cdecl renderDecal(void*, int, int, const Vector4*);

struct DecalTool {
    char padding0[0x18];
    Decal* decal;
    char padding1[8];
    int face;

    void render(int);
};

void DecalTool::render(int argument)
{
    if (decal) {
        const Vector3& v = getVector();
        Decal* d = decal;
        Vector4 color = { v.x, v.y, v.z, 1.0f };
        renderDecal(d->getTexture(), face, argument, &color);
    }
}
