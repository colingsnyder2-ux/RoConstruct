// from server: 100% by Espeon
// from server: 99% by king_originala
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 96% by colin
// roc 2008-06 00676c90  unit: RBX::AdornG3D  size: 362 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00676c90
//
// 00676c90  83ec7c               sub esp, 0x7c
// 00676c93  53                   push ebx
// 00676c94  56                   push esi
// 00676c95  8bb42490000000       mov esi, dword ptr [esp + 0x90]
// 00676c9c  57                   push edi
// 00676c9d  8bbc248c000000       mov edi, dword ptr [esp + 0x8c]
// 00676ca4  d94704               fld dword ptr [edi + 4]
// 00676ca7  8b5cb720             mov ebx, dword ptr [edi + esi*4 + 0x20]
// 00676cab  d905ac9b8100         fld dword ptr [0x819bac]
// 00676cb1  56                   push esi
// 00676cb2  dcc9                 fmul st(1), st(0)
// 00676cb4  d9c9                 fxch st(1)
// 00676cb6  d95c241c             fstp dword ptr [esp + 0x1c]
// 00676cba  d94708               fld dword ptr [edi + 8]
// 00676cbd  d8c9                 fmul st(1)
// 00676cbf  d95c2420             fstp dword ptr [esp + 0x20]
// 00676cc3  d84f0c               fmul dword ptr [edi + 0xc]
// 00676cc6  d95c2424             fstp dword ptr [esp + 0x24]
// 00676cca  e8017ef6ff           call 0x5dead0
// 00676ccf  d9ee                 fldz 
// 00676cd1  8bc8                 mov ecx, eax
// 00676cd3  b856555555           mov eax, 0x55555556
// 00676cd8  d9542410             fst dword ptr [esp + 0x10]
// 00676cdc  f7ee                 imul esi
// 00676cde  d9542414             fst dword ptr [esp + 0x14]
// 00676ce2  d95c2418             fstp dword ptr [esp + 0x18]
// 00676ce6  8bc2                 mov eax, edx
// 00676ce8  c1e81f               shr eax, 0x1f
// 00676ceb  03c2                 add eax, edx
// 00676ced  8d0440               lea eax, [eax + eax*2]
// 00676cf0  8bd0                 mov edx, eax
// 00676cf2  8bc6                 mov eax, esi
// 00676cf4  83c404               add esp, 4
// 00676cf7  2bc2                 sub eax, edx
// 00676cf9  83fe02               cmp esi, 2
// 00676cfc  7e08                 jle 0x676d06
// 00676cfe  d905b8c38100         fld dword ptr [0x81c3b8]
// 00676d04  eb02                 jmp 0x676d08
// 00676d06  d9e8                 fld1 
// 00676d08  d84c8418             fmul dword ptr [esp + eax*4 + 0x18]
// 00676d0c  51                   push ecx
// 00676d0d  8d4c242c             lea ecx, [esp + 0x2c]
// 00676d11  d95c8410             fstp dword ptr [esp + eax*4 + 0x10]
// 00676d15  e806c5e9ff           call 0x513220
// 00676d1a  d944240c             fld dword ptr [esp + 0xc]
// 00676d1e  8d442428             lea eax, [esp + 0x28]
// 00676d22  d95c244c             fstp dword ptr [esp + 0x4c]
// 00676d26  50                   push eax
// 00676d27  d9442414             fld dword ptr [esp + 0x14]
// 00676d2b  8d4c245c             lea ecx, [esp + 0x5c]
// 00676d2f  d95c2454             fstp dword ptr [esp + 0x54]
// 00676d33  51                   push ecx
// 00676d34  d944241c             fld dword ptr [esp + 0x1c]
// 00676d38  8d4f38               lea ecx, [edi + 0x38]
// 00676d3b  d95c245c             fstp dword ptr [esp + 0x5c]
// 00676d3f  e8bcf9dfff           call 0x476700
// 00676d44  8bb42490000000       mov esi, dword ptr [esp + 0x90]
// 00676d4b  8b16                 mov edx, dword ptr [esi]
// 00676d4d  8b5238               mov edx, dword ptr [edx + 0x38]
// 00676d50  8d442458             lea eax, [esp + 0x58]
// 00676d54  50                   push eax
// 00676d55  8bce                 mov ecx, esi
// 00676d57  ffd2                 call edx
// 00676d59  e822dce9ff           call 0x514980
// 00676d5e  d900                 fld dword ptr [eax]
// 00676d60  8b3e                 mov edi, dword ptr [esi]
// 00676d62  d95c2418             fstp dword ptr [esp + 0x18]
// 00676d66  d94004               fld dword ptr [eax + 4]
// 00676d69  d95c241c             fstp dword ptr [esp + 0x1c]
// 00676d6d  d94008               fld dword ptr [eax + 8]
// 00676d70  d95c2420             fstp dword ptr [esp + 0x20]
// 00676d74  d9e8                 fld1 
// 00676d76  d95c2424             fstp dword ptr [esp + 0x24]
// 00676d7a  e891411400           call 0x7baf10
// 00676d7f  d9e8                 fld1 
// 00676d81  8b5750               mov edx, dword ptr [edi + 0x50]
// 00676d84  50                   push eax
// 00676d85  8d44241c             lea eax, [esp + 0x1c]
// 00676d89  50                   push eax
// 00676d8a  83ec08               sub esp, 8
// 00676d8d  d95c2404             fstp dword ptr [esp + 4]
// 00676d91  8bce                 mov ecx, esi
// 00676d93  d905f8498200         fld dword ptr [0x8249f8]
// 00676d99  d91c24               fstp dword ptr [esp]
// 00676d9c  ffd2                 call edx
// 00676d9e  83fb07               cmp ebx, 7
// 00676da1  7405                 je 0x676da8
// 00676da3  83fb08               cmp ebx, 8
// 00676da6  754b                 jne 0x676df3
// 00676da8  8b842498000000       mov eax, dword ptr [esp + 0x98]
// 00676daf  d900                 fld dword ptr [eax]
// 00676db1  8b3e                 mov edi, dword ptr [esi]
// 00676db3  d95c2418             fstp dword ptr [esp + 0x18]
// 00676db7  d94004               fld dword ptr [eax + 4]
// 00676dba  d95c241c             fstp dword ptr [esp + 0x1c]
// 00676dbe  d94008               fld dword ptr [eax + 8]
// 00676dc1  d95c2420             fstp dword ptr [esp + 0x20]
// 00676dc5  d9e8                 fld1 
// 00676dc7  d95c2424             fstp dword ptr [esp + 0x24]
// 00676dcb  e840411400           call 0x7baf10
// 00676dd0  d905e4a38300         fld dword ptr [0x83a3e4]
// 00676dd6  8b5750               mov edx, dword ptr [edi + 0x50]
// 00676dd9  50                   push eax
// 00676dda  8d44241c             lea eax, [esp + 0x1c]
// 00676dde  50                   push eax
// 00676ddf  83ec08               sub esp, 8
// 00676de2  d95c2404             fstp dword ptr [esp + 4]
// 00676de6  8bce                 mov ecx, esi
// 00676de8  d905182a8300         fld dword ptr [0x832a18]
// 00676dee  d91c24               fstp dword ptr [esp]
// 00676df1  ffd2                 call edx
// 00676df3  5f                   pop edi
// 00676df4  5e                   pop esi
// 00676df5  5b                   pop ebx
// 00676df6  83c47c               add esp, 0x7c
// 00676df9  c3                   ret 

// from server: 93% by king_originala
// roc 2008-06 00676c90  unit: RBX::AdornG3D  size: 362 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00676c90
//
// 00676c90  83ec7c               sub esp, 0x7c
// 00676c93  53                   push ebx
// 00676c94  56                   push esi
// 00676c95  8bb42490000000       mov esi, dword ptr [esp + 0x90]
// 00676c9c  57                   push edi
// 00676c9d  8bbc248c000000       mov edi, dword ptr [esp + 0x8c]
// 00676ca4  d94704               fld dword ptr [edi + 4]
// 00676ca7  8b5cb720             mov ebx, dword ptr [edi + esi*4 + 0x20]
// 00676cab  d905ac9b8100         fld dword ptr [0x819bac]
// 00676cb1  56                   push esi
// 00676cb2  dcc9                 fmul st(1), st(0)
// 00676cb4  d9c9                 fxch st(1)
// 00676cb6  d95c241c             fstp dword ptr [esp + 0x1c]
// 00676cba  d94708               fld dword ptr [edi + 8]
// 00676cbd  d8c9                 fmul st(1)
// 00676cbf  d95c2420             fstp dword ptr [esp + 0x20]
// 00676cc3  d84f0c               fmul dword ptr [edi + 0xc]
// 00676cc6  d95c2424             fstp dword ptr [esp + 0x24]
// 00676cca  e8017ef6ff           call 0x5dead0
// 00676ccf  d9ee                 fldz 
// 00676cd1  8bc8                 mov ecx, eax
// 00676cd3  b856555555           mov eax, 0x55555556
// 00676cd8  d9542410             fst dword ptr [esp + 0x10]
// 00676cdc  f7ee                 imul esi
// 00676cde  d9542414             fst dword ptr [esp + 0x14]
// 00676ce2  d95c2418             fstp dword ptr [esp + 0x18]
// 00676ce6  8bc2                 mov eax, edx
// 00676ce8  c1e81f               shr eax, 0x1f
// 00676ceb  03c2                 add eax, edx
// 00676ced  8d0440               lea eax, [eax + eax*2]
// 00676cf0  8bd0                 mov edx, eax
// 00676cf2  8bc6                 mov eax, esi
// 00676cf4  83c404               add esp, 4
// 00676cf7  2bc2                 sub eax, edx
// 00676cf9  83fe02               cmp esi, 2
// 00676cfc  7e08                 jle 0x676d06
// 00676cfe  d905b8c38100         fld dword ptr [0x81c3b8]
// 00676d04  eb02                 jmp 0x676d08
// 00676d06  d9e8                 fld1 
// 00676d08  d84c8418             fmul dword ptr [esp + eax*4 + 0x18]
// 00676d0c  51                   push ecx
// 00676d0d  8d4c242c             lea ecx, [esp + 0x2c]
// 00676d11  d95c8410             fstp dword ptr [esp + eax*4 + 0x10]
// 00676d15  e806c5e9ff           call 0x513220
// 00676d1a  d944240c             fld dword ptr [esp + 0xc]
// 00676d1e  8d442428             lea eax, [esp + 0x28]
// 00676d22  d95c244c             fstp dword ptr [esp + 0x4c]
// 00676d26  50                   push eax
// 00676d27  d9442414             fld dword ptr [esp + 0x14]
// 00676d2b  8d4c245c             lea ecx, [esp + 0x5c]
// 00676d2f  d95c2454             fstp dword ptr [esp + 0x54]
// 00676d33  51                   push ecx
// 00676d34  d944241c             fld dword ptr [esp + 0x1c]
// 00676d38  8d4f38               lea ecx, [edi + 0x38]
// 00676d3b  d95c245c             fstp dword ptr [esp + 0x5c]
// 00676d3f  e8bcf9dfff           call 0x476700
// 00676d44  8bb42490000000       mov esi, dword ptr [esp + 0x90]
// 00676d4b  8b16                 mov edx, dword ptr [esi]
// 00676d4d  8b5238               mov edx, dword ptr [edx + 0x38]
// 00676d50  8d442458             lea eax, [esp + 0x58]
// 00676d54  50                   push eax
// 00676d55  8bce                 mov ecx, esi
// 00676d57  ffd2                 call edx
// 00676d59  e822dce9ff           call 0x514980
// 00676d5e  d900                 fld dword ptr [eax]
// 00676d60  8b3e                 mov edi, dword ptr [esi]
// 00676d62  d95c2418             fstp dword ptr [esp + 0x18]
// 00676d66  d94004               fld dword ptr [eax + 4]
// 00676d69  d95c241c             fstp dword ptr [esp + 0x1c]
// 00676d6d  d94008               fld dword ptr [eax + 8]
// 00676d70  d95c2420             fstp dword ptr [esp + 0x20]
// 00676d74  d9e8                 fld1 
// 00676d76  d95c2424             fstp dword ptr [esp + 0x24]
// 00676d7a  e891411400           call 0x7baf10
// 00676d7f  d9e8                 fld1 
// 00676d81  8b5750               mov edx, dword ptr [edi + 0x50]
// 00676d84  50                   push eax
// 00676d85  8d44241c             lea eax, [esp + 0x1c]
// 00676d89  50                   push eax
// 00676d8a  83ec08               sub esp, 8
// 00676d8d  d95c2404             fstp dword ptr [esp + 4]
// 00676d91  8bce                 mov ecx, esi
// 00676d93  d905f8498200         fld dword ptr [0x8249f8]
// 00676d99  d91c24               fstp dword ptr [esp]
// 00676d9c  ffd2                 call edx
// 00676d9e  83fb07               cmp ebx, 7
// 00676da1  7405                 je 0x676da8
// 00676da3  83fb08               cmp ebx, 8
// 00676da6  754b                 jne 0x676df3
// 00676da8  8b842498000000       mov eax, dword ptr [esp + 0x98]
// 00676daf  d900                 fld dword ptr [eax]
// 00676db1  8b3e                 mov edi, dword ptr [esi]
// 00676db3  d95c2418             fstp dword ptr [esp + 0x18]
// 00676db7  d94004               fld dword ptr [eax + 4]
// 00676dba  d95c241c             fstp dword ptr [esp + 0x1c]
// 00676dbe  d94008               fld dword ptr [eax + 8]
// 00676dc1  d95c2420             fstp dword ptr [esp + 0x20]
// 00676dc5  d9e8                 fld1 
// 00676dc7  d95c2424             fstp dword ptr [esp + 0x24]
// 00676dcb  e840411400           call 0x7baf10
// 00676dd0  d905e4a38300         fld dword ptr [0x83a3e4]
// 00676dd6  8b5750               mov edx, dword ptr [edi + 0x50]
// 00676dd9  50                   push eax
// 00676dda  8d44241c             lea eax, [esp + 0x1c]
// 00676dde  50                   push eax
// 00676ddf  83ec08               sub esp, 8
// 00676de2  d95c2404             fstp dword ptr [esp + 4]
// 00676de6  8bce                 mov ecx, esi
// 00676de8  d905182a8300         fld dword ptr [0x832a18]
// 00676dee  d91c24               fstp dword ptr [esp]
// 00676df1  ffd2                 call edx
// 00676df3  5f                   pop edi
// 00676df4  5e                   pop esi
// 00676df5  5b                   pop ebx
// 00676df6  83c47c               add esp, 0x7c
// 00676df9  c3                   ret 
#include <intrin.h>



struct Vector3 {
    float x, y, z;
};

struct Matrix3 {
    float elements[9];
    Matrix3(const Matrix3&);
};

struct Frame {
    Matrix3 rotation;
    Vector3 translation;
    Frame(const Matrix3&, const Vector3&);
    Frame operator*(const Frame&) const;
};

__forceinline Frame::Frame(const Matrix3& r, const Vector3& t)
    : rotation(r)
{
    translation.x = t.x;
    translation.y = t.y;
    translation.z = t.z;
}

struct Color4 {
    float r, g, b, a;
};

struct Scratch {
    Vector3 offset;
    union {
        Vector3 halfSize;
        Color4 rgba;
    };
};

struct Object {
    unsigned char padding0[4];
    Vector3 size;
    unsigned char padding1[16];
    int surfaces[6];
    Frame frame;
};

struct Renderer;

struct RendererTable {
    unsigned char padding0[56];
    void (__thiscall *setFrame)(Renderer*, const Frame&);
    unsigned char padding1[20];
    void (__thiscall *draw)(Renderer*, float, float, const Color4&, void*);
};

struct Renderer {
    RendererTable* table;
};

extern const Matrix3& __cdecl faceRotation(int);
extern const Vector3& __cdecl defaultColor();
extern void* __cdecl drawResource();

extern const float baseRadius;
extern const float selectedRadius;
extern const float selectedScale;

void __cdecl drawFace(Object* object, Renderer* renderer, volatile int faceArgument,
                      const Vector3& color)
{
    int face = faceArgument;
    float sizeX = object->size.x;
    int surface = object->surfaces[face];
    Scratch scratch;

    scratch.halfSize.x = sizeX * 0.5f;
    scratch.halfSize.y = object->size.y * 0.5f;
    scratch.halfSize.z = object->size.z * 0.5f;

    const Matrix3& rotation = faceRotation(face);

    scratch.offset.x = 0.0f;
    scratch.offset.y = 0.0f;
    scratch.offset.z = 0.0f;

    int axis = face % 3;
    (&scratch.offset.x)[axis] =
        (face > 2 ? -1.0f : 1.0f) * (&scratch.halfSize.x)[axis];

    Frame local(rotation, scratch.offset);
    Frame world = object->frame * local;
    renderer->table->setFrame(renderer, world);

    const Vector3& initialColor = defaultColor();
    RendererTable* table = renderer->table;
    scratch.rgba.r = initialColor.x;
    scratch.rgba.g = initialColor.y;
    scratch.rgba.b = initialColor.z;
    scratch.rgba.a = 1.0f;
    void* resource = drawResource();
    table->draw(renderer, baseRadius, 1.0f, scratch.rgba, resource);

    if (surface == 7 || surface == 8) {
        table = renderer->table;
        scratch.rgba.r = color.x;
        scratch.rgba.g = color.y;
        scratch.rgba.b = color.z;
        scratch.rgba.a = 1.0f;
        resource = drawResource();
        table->draw(renderer, selectedRadius, selectedScale,
                    scratch.rgba, resource);
    }
}
