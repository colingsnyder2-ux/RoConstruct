// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00610270  unit: RBX::BlockBlockContact  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00610270
//
// 00610270  83ec18               sub esp, 0x18
// 00610273  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00610277  56                   push esi
// 00610278  8b742424             mov esi, dword ptr [esp + 0x24]
// 0061027c  57                   push edi
// 0061027d  56                   push esi
// 0061027e  50                   push eax
// 0061027f  e86cfcffff           call 0x60fef0
// 00610284  d906                 fld dword ptr [esi]
// 00610286  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0061028a  d807                 fadd dword ptr [edi]
// 0061028c  b801000000           mov eax, 1
// 00610291  83c408               add esp, 8
// 00610294  d95c2408             fstp dword ptr [esp + 8]
// 00610298  d94604               fld dword ptr [esi + 4]
// 0061029b  d84704               fadd dword ptr [edi + 4]
// 0061029e  d95c240c             fstp dword ptr [esp + 0xc]
// 006102a2  d94608               fld dword ptr [esi + 8]
// 006102a5  d84708               fadd dword ptr [edi + 8]
// 006102a8  d95c2410             fstp dword ptr [esp + 0x10]
// 006102ac  840554639700         test byte ptr [0x976354], al
// 006102b2  7520                 jne 0x6102d4
// 006102b4  d9e8                 fld1 
// 006102b6  090554639700         or dword ptr [0x976354], eax
// 006102bc  d91548639700         fst dword ptr [0x976348]
// 006102c2  d90504e78100         fld dword ptr [0x81e704]
// 006102c8  d91d4c639700         fstp dword ptr [0x97634c]
// 006102ce  d91d50639700         fstp dword ptr [0x976350]
// 006102d4  6848639700           push 0x976348
// 006102d9  8d4c240c             lea ecx, [esp + 0xc]
// 006102dd  51                   push ecx
// 006102de  8d54241c             lea edx, [esp + 0x1c]
// 006102e2  52                   push edx
// 006102e3  e828ebfcff           call 0x5dee10
// 006102e8  d9442420             fld dword ptr [esp + 0x20]
// 006102ec  d91f                 fstp dword ptr [edi]
// 006102ee  83c40c               add esp, 0xc
// 006102f1  d9442418             fld dword ptr [esp + 0x18]
// 006102f5  d95f04               fstp dword ptr [edi + 4]
// 006102f8  d944241c             fld dword ptr [esp + 0x1c]
// 006102fc  d95f08               fstp dword ptr [edi + 8]
// 006102ff  5f                   pop edi
// 00610300  5e                   pop esi
// 00610301  83c418               add esp, 0x18
// 00610304  c3                   ret 

struct Vector3
{
    float x, y, z;
    Vector3();
    Vector3(float a, float b, float c);
};

__forceinline Vector3::Vector3()
{
}

__forceinline Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

extern void __cdecl transform(const void*, Vector3*);
extern void __cdecl multiply(Vector3*, const Vector3*, const Vector3*);

void __cdecl f(const void* source, Vector3* vector, Vector3* output)
{
    transform(source, vector);

    Vector3 result;
    Vector3 sum(
        vector->x + output->x,
        vector->y + output->y,
        vector->z + output->z);

    static Vector3 scale(1.0f, 0.1f, 1.0f);
    multiply(&result, &sum, &scale);

    output->x = result.x;
    output->y = result.y;
    output->z = result.z;
}
