// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006103a0  unit: RBX::BlockBlockContact  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006103a0
//
// 006103a0  83ec0c               sub esp, 0xc
// 006103a3  d9ee                 fldz 
// 006103a5  56                   push esi
// 006103a6  8b742418             mov esi, dword ptr [esp + 0x18]
// 006103aa  d9542404             fst dword ptr [esp + 4]
// 006103ae  d90564378400         fld dword ptr [0x843764]
// 006103b4  57                   push edi
// 006103b5  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 006103b9  d95c240c             fstp dword ptr [esp + 0xc]
// 006103bd  56                   push esi
// 006103be  8d44240c             lea eax, [esp + 0xc]
// 006103c2  50                   push eax
// 006103c3  d95c2418             fstp dword ptr [esp + 0x18]
// 006103c7  57                   push edi
// 006103c8  e8a3feffff           call 0x610270
// 006103cd  56                   push esi
// 006103ce  e88dd4fcff           call 0x5dd860
// 006103d3  83c410               add esp, 0x10
// 006103d6  84c0                 test al, al
// 006103d8  7554                 jne 0x61042e
// 006103da  53                   push ebx
// 006103db  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006103df  90                   nop 
// 006103e0  53                   push ebx
// 006103e1  57                   push edi
// 006103e2  e849fdffff           call 0x610130
// 006103e7  83c408               add esp, 8
// 006103ea  84c0                 test al, al
// 006103ec  7534                 jne 0x610422
// 006103ee  d9ee                 fldz 
// 006103f0  56                   push esi
// 006103f1  d9542410             fst dword ptr [esp + 0x10]
// 006103f5  8d4c2410             lea ecx, [esp + 0x10]
// 006103f9  d90564378400         fld dword ptr [0x843764]
// 006103ff  51                   push ecx
// 00610400  d95c2418             fstp dword ptr [esp + 0x18]
// 00610404  57                   push edi
// 00610405  d95c2420             fstp dword ptr [esp + 0x20]
// 00610409  e862feffff           call 0x610270
// 0061040e  56                   push esi
// 0061040f  e84cd4fcff           call 0x5dd860
// 00610414  83c410               add esp, 0x10
// 00610417  84c0                 test al, al
// 00610419  74c5                 je 0x6103e0
// 0061041b  5b                   pop ebx
// 0061041c  5f                   pop edi
// 0061041d  5e                   pop esi
// 0061041e  83c40c               add esp, 0xc
// 00610421  c3                   ret 
// 00610422  53                   push ebx
// 00610423  56                   push esi
// 00610424  57                   push edi
// 00610425  e8e6feffff           call 0x610310
// 0061042a  83c40c               add esp, 0xc
// 0061042d  5b                   pop ebx
// 0061042e  5f                   pop edi
// 0061042f  5e                   pop esi
// 00610430  83c40c               add esp, 0xc
// 00610433  c3                   ret 

struct Vector3
{
    float x, y, z;
    Vector3(float a, float b, float c);
};

__forceinline Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

extern const float directionY;
void __cdecl transform(void*, const Vector3&, Vector3&);
bool __cdecl invalid(const Vector3&);
bool __cdecl advance(void*, void*);
void __cdecl update(void*, Vector3&, void*);

void __cdecl process(void* object, Vector3& result, void* state)
{
    transform(object, Vector3(0.0f, directionY, 0.0f), result);
    while (!invalid(result))
    {
        if (advance(object, state))
        {
            update(object, result, state);
            return;
        }
        transform(object, Vector3(0.0f, directionY, 0.0f), result);
    }
}
