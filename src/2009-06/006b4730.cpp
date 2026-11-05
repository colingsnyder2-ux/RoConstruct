// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00610180  unit: RBX::BlockBlockContact  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00610180
//
// 00610180  83ec18               sub esp, 0x18
// 00610183  53                   push ebx
// 00610184  56                   push esi
// 00610185  8b742428             mov esi, dword ptr [esp + 0x28]
// 00610189  d906                 fld dword ptr [esi]
// 0061018b  57                   push edi
// 0061018c  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00610190  d827                 fsub dword ptr [edi]
// 00610192  bb01000000           mov ebx, 1
// 00610197  d95c2418             fstp dword ptr [esp + 0x18]
// 0061019b  d94604               fld dword ptr [esi + 4]
// 0061019e  d86704               fsub dword ptr [edi + 4]
// 006101a1  d95c241c             fstp dword ptr [esp + 0x1c]
// 006101a5  d94608               fld dword ptr [esi + 8]
// 006101a8  d86708               fsub dword ptr [edi + 8]
// 006101ab  d95c2420             fstp dword ptr [esp + 0x20]
// 006101af  841d54639700         test byte ptr [0x976354], bl
// 006101b5  7520                 jne 0x6101d7
// 006101b7  d9e8                 fld1 
// 006101b9  091d54639700         or dword ptr [0x976354], ebx
// 006101bf  d91548639700         fst dword ptr [0x976348]
// 006101c5  d90504e78100         fld dword ptr [0x81e704]
// 006101cb  d91d4c639700         fstp dword ptr [0x97634c]
// 006101d1  d91d50639700         fstp dword ptr [0x976350]
// 006101d7  6848639700           push 0x976348
// 006101dc  8d44241c             lea eax, [esp + 0x1c]
// 006101e0  50                   push eax
// 006101e1  8d4c2414             lea ecx, [esp + 0x14]
// 006101e5  51                   push ecx
// 006101e6  e825ecfcff           call 0x5dee10
// 006101eb  83c40c               add esp, 0xc
// 006101ee  841d50f09600         test byte ptr [0x96f050], bl
// 006101f4  751a                 jne 0x610210
// 006101f6  d9ee                 fldz 
// 006101f8  091d50f09600         or dword ptr [0x96f050], ebx
// 006101fe  d91544f09600         fst dword ptr [0x96f044]
// 00610204  d91548f09600         fst dword ptr [0x96f048]
// 0061020a  d91d4cf09600         fstp dword ptr [0x96f04c]
// 00610210  d90544f09600         fld dword ptr [0x96f044]
// 00610216  d85c240c             fcomp dword ptr [esp + 0xc]
// 0061021a  dfe0                 fnstsw ax
// 0061021c  f6c444               test ah, 0x44
// 0061021f  7a22                 jp 0x610243
// 00610221  d90548f09600         fld dword ptr [0x96f048]
// 00610227  d85c2410             fcomp dword ptr [esp + 0x10]
// 0061022b  dfe0                 fnstsw ax
// 0061022d  f6c444               test ah, 0x44
// 00610230  7a11                 jp 0x610243
// 00610232  d9054cf09600         fld dword ptr [0x96f04c]
// 00610238  d85c2414             fcomp dword ptr [esp + 0x14]
// 0061023c  dfe0                 fnstsw ax
// 0061023e  f6c444               test ah, 0x44
// 00610241  7b22                 jnp 0x610265
// 00610243  8b442428             mov eax, dword ptr [esp + 0x28]
// 00610247  8d54240c             lea edx, [esp + 0xc]
// 0061024b  52                   push edx
// 0061024c  50                   push eax
// 0061024d  e89efcffff           call 0x60fef0
// 00610252  d906                 fld dword ptr [esi]
// 00610254  d91f                 fstp dword ptr [edi]
// 00610256  83c408               add esp, 8
// 00610259  d94604               fld dword ptr [esi + 4]
// 0061025c  d95f04               fstp dword ptr [edi + 4]
// 0061025f  d94608               fld dword ptr [esi + 8]
// 00610262  d95f08               fstp dword ptr [edi + 8]
// 00610265  5f                   pop edi
// 00610266  5e                   pop esi
// 00610267  5b                   pop ebx
// 00610268  83c418               add esp, 0x18
// 0061026b  c3                   ret 

struct Vector3
{
    float x, y, z;
};

extern Vector3 scaleVector;
extern unsigned int scaleInitialized;
extern const float scaleY;
extern Vector3 zeroVector;
extern unsigned int zeroInitialized;

extern void __cdecl transformVector(
    Vector3* result, const Vector3* value, const Vector3* scale);
extern void __cdecl applyVector(void* object, const Vector3* value);

#pragma float_control(precise, off)

void __cdecl updateVector(void* object, const Vector3* source, Vector3* previous)
{
    Vector3 difference;
    Vector3 result;

    difference.x = source->x - previous->x;
    difference.y = source->y - previous->y;
    difference.z = source->z - previous->z;

    if (!(scaleInitialized & 1))
    {
        scaleInitialized |= 1;
        scaleVector.x = 1.0f;
        scaleVector.y = scaleY;
        scaleVector.z = 1.0f;
    }

    transformVector(&result, &difference, &scaleVector);

    if (!(zeroInitialized & 1))
    {
        zeroInitialized |= 1;
        zeroVector.x = 0.0f;
        zeroVector.y = 0.0f;
        zeroVector.z = 0.0f;
    }

    if (result.x != zeroVector.x ||
        result.y != zeroVector.y ||
        result.z != zeroVector.z)
    {
        applyVector(object, &result);
        previous->x = source->x;
        previous->y = source->y;
        previous->z = source->z;
    }
}
