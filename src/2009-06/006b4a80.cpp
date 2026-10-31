// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006104e0  unit: RBX::BlockBlockContact  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006104e0
//
// 006104e0  83ec0c               sub esp, 0xc
// 006104e3  d9ee                 fldz 
// 006104e5  56                   push esi
// 006104e6  8b742418             mov esi, dword ptr [esp + 0x18]
// 006104ea  d9542404             fst dword ptr [esp + 4]
// 006104ee  d9056c0b8300         fld dword ptr [0x830b6c]
// 006104f4  57                   push edi
// 006104f5  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 006104f9  d95c240c             fstp dword ptr [esp + 0xc]
// 006104fd  56                   push esi
// 006104fe  8d44240c             lea eax, [esp + 0xc]
// 00610502  50                   push eax
// 00610503  d95c2418             fstp dword ptr [esp + 0x18]
// 00610507  57                   push edi
// 00610508  e863fdffff           call 0x610270
// 0061050d  56                   push esi
// 0061050e  e84dd3fcff           call 0x5dd860
// 00610513  83c410               add esp, 0x10
// 00610516  84c0                 test al, al
// 00610518  7554                 jne 0x61056e
// 0061051a  53                   push ebx
// 0061051b  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0061051f  90                   nop 
// 00610520  53                   push ebx
// 00610521  57                   push edi
// 00610522  e809fcffff           call 0x610130
// 00610527  83c408               add esp, 8
// 0061052a  84c0                 test al, al
// 0061052c  7534                 jne 0x610562
// 0061052e  d9ee                 fldz 
// 00610530  56                   push esi
// 00610531  d9542410             fst dword ptr [esp + 0x10]
// 00610535  8d4c2410             lea ecx, [esp + 0x10]
// 00610539  d9056c0b8300         fld dword ptr [0x830b6c]
// 0061053f  51                   push ecx
// 00610540  d95c2418             fstp dword ptr [esp + 0x18]
// 00610544  57                   push edi
// 00610545  d95c2420             fstp dword ptr [esp + 0x20]
// 00610549  e822fdffff           call 0x610270
// 0061054e  56                   push esi
// 0061054f  e80cd3fcff           call 0x5dd860
// 00610554  83c410               add esp, 0x10
// 00610557  84c0                 test al, al
// 00610559  74c5                 je 0x610520
// 0061055b  5b                   pop ebx
// 0061055c  5f                   pop edi
// 0061055d  5e                   pop esi
// 0061055e  83c40c               add esp, 0xc
// 00610561  c3                   ret 
// 00610562  53                   push ebx
// 00610563  56                   push esi
// 00610564  57                   push edi
// 00610565  e8a6fdffff           call 0x610310
// 0061056a  83c40c               add esp, 0xc
// 0061056d  5b                   pop ebx
// 0061056e  5f                   pop edi
// 0061056f  5e                   pop esi
// 00610570  83c40c               add esp, 0xc
// 00610573  c3                   ret 

struct Vector3 {
    float x, y, z;
};

extern const float directionY;
void __cdecl transform(void* object, const Vector3& direction, Vector3& result);
bool __cdecl invalid(const Vector3& result);
bool __cdecl advance(void* object, void* state);
void __cdecl update(void* object, Vector3& result, void* state);

void __cdecl process(void* object, Vector3& result, void* state)
{
    Vector3 direction = { 0.0f, directionY, 0.0f };
    transform(object, direction, result);

    while (!invalid(result)) {
        if (advance(object, state)) {
            update(object, result, state);
            break;
        }

        direction.x = 0.0f;
        direction.y = directionY;
        direction.z = 0.0f;
        transform(object, direction, result);
    }
}
