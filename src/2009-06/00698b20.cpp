// from server: 84% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060a520  unit: RBX::Feature  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060a520
//
// 0060a520  83ec30               sub esp, 0x30
// 0060a523  56                   push esi
// 0060a524  8bf1                 mov esi, ecx
// 0060a526  8d4c2404             lea ecx, [esp + 4]
// 0060a52a  e8a1dde6ff           call 0x4782d0
// 0060a52f  8d442404             lea eax, [esp + 4]
// 0060a533  50                   push eax
// 0060a534  8d8ed0feffff         lea ecx, [esi - 0x130]
// 0060a53a  e851ffffff           call 0x60a490
// 0060a53f  5e                   pop esi
// 0060a540  84c0                 test al, al
// 0060a542  7430                 je 0x60a574
// 0060a544  e807c70600           call 0x676c50
// 0060a549  d90538f88200         fld dword ptr [0x82f838]
// 0060a54f  8b542434             mov edx, dword ptr [esp + 0x34]
// 0060a553  50                   push eax
// 0060a554  83ec08               sub esp, 8
// 0060a557  d95c2404             fstp dword ptr [esp + 4]
// 0060a55b  8d4c240c             lea ecx, [esp + 0xc]
// 0060a55f  d9051c718200         fld dword ptr [0x82711c]
// 0060a565  d91c24               fstp dword ptr [esp]
// 0060a568  6a02                 push 2
// 0060a56a  51                   push ecx
// 0060a56b  52                   push edx
// 0060a56c  e87fce0600           call 0x6773f0
// 0060a571  83c418               add esp, 0x18
// 0060a574  83c430               add esp, 0x30
// 0060a577  c20800               ret 8

struct Transform {
    float rotation[9];
    float x, y, z;

    Transform();
};

extern float firstScale;
extern float secondScale;

extern "C" const void* __cdecl getColor();
extern "C" void __cdecl draw(
    void* context, const Transform& transform, int mode,
    float scale1, float scale2, const void* color);

struct Feature {
    bool get(Transform& result);
    void render(void* context, void* unused);
};

void Feature::render(void* context, void* unused)
{
    Transform transform;
    Feature* owner = reinterpret_cast<Feature*>(
        reinterpret_cast<char*>(this) - 0x130);

    if (owner->get(transform)) {
        const void* color = getColor();
        draw(context, transform, 2, firstScale, secondScale, color);
    }
}
