// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00610310  unit: RBX::BlockBlockContact  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00610310
//
// 00610310  83ec0c               sub esp, 0xc
// 00610313  d9ee                 fldz 
// 00610315  56                   push esi
// 00610316  8b742418             mov esi, dword ptr [esp + 0x18]
// 0061031a  d9542404             fst dword ptr [esp + 4]
// 0061031e  d90504e78100         fld dword ptr [0x81e704]
// 00610324  57                   push edi
// 00610325  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00610329  d95c240c             fstp dword ptr [esp + 0xc]
// 0061032d  56                   push esi
// 0061032e  8d44240c             lea eax, [esp + 0xc]
// 00610332  50                   push eax
// 00610333  d95c2418             fstp dword ptr [esp + 0x18]
// 00610337  57                   push edi
// 00610338  e833ffffff           call 0x610270
// 0061033d  56                   push esi
// 0061033e  e81dd5fcff           call 0x5dd860
// 00610343  83c410               add esp, 0x10
// 00610346  84c0                 test al, al
// 00610348  7542                 jne 0x61038c
// 0061034a  53                   push ebx
// 0061034b  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0061034f  90                   nop 
// 00610350  53                   push ebx
// 00610351  57                   push edi
// 00610352  e8d9fdffff           call 0x610130
// 00610357  83c408               add esp, 8
// 0061035a  84c0                 test al, al
// 0061035c  742d                 je 0x61038b
// 0061035e  d9ee                 fldz 
// 00610360  56                   push esi
// 00610361  d9542410             fst dword ptr [esp + 0x10]
// 00610365  8d4c2410             lea ecx, [esp + 0x10]
// 00610369  d90504e78100         fld dword ptr [0x81e704]
// 0061036f  51                   push ecx
// 00610370  d95c2418             fstp dword ptr [esp + 0x18]
// 00610374  57                   push edi
// 00610375  d95c2420             fstp dword ptr [esp + 0x20]
// 00610379  e8f2feffff           call 0x610270
// 0061037e  56                   push esi
// 0061037f  e8dcd4fcff           call 0x5dd860
// 00610384  83c410               add esp, 0x10
// 00610387  84c0                 test al, al
// 00610389  74c5                 je 0x610350
// 0061038b  5b                   pop ebx
// 0061038c  5f                   pop edi
// 0061038d  5e                   pop esi
// 0061038e  83c40c               add esp, 0xc
// 00610391  c3                   ret 

struct Vector3 {
    float x, y, z;
};

extern const float directionY;

void __cdecl transform(void*, const Vector3&, Vector3&);
bool __cdecl invalid(const Vector3&);
bool __cdecl advance(void*, void*);

void __cdecl update(void* object, Vector3& result, void* state)
{
    Vector3 direction = { 0.0f, directionY, 0.0f };
    transform(object, direction, result);

    while (!invalid(result) && advance(object, state)) {
        direction.x = 0.0f;
        direction.y = directionY;
        direction.z = 0.0f;
        transform(object, direction, result);
    }
}
