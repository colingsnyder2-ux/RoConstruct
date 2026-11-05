// from server: 100% by Espeon
// from server: 81% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 80% by colin
// roc 2008-06 005fae00  unit: UString_sink::?$stream_buffer  size: 196 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fae00
//
// 005fae00  83ec0c               sub esp, 0xc
// 005fae03  56                   push esi
// 005fae04  57                   push edi
// 005fae05  8bf9                 mov edi, ecx
// 005fae07  e814360400           call 0x63e420
// 005fae0c  8b742418             mov esi, dword ptr [esp + 0x18]
// 005fae10  8bc8                 mov ecx, eax
// 005fae12  8bc6                 mov eax, esi
// 005fae14  99                   cdq 
// 005fae15  f7f9                 idiv ecx
// 005fae17  85d2                 test edx, edx
// 005fae19  0f858a000000         jne 0x5faea9
// 005fae1f  e8fc350400           call 0x63e420
// 005fae24  d9ee                 fldz 
// 005fae26  8bc8                 mov ecx, eax
// 005fae28  d9542408             fst dword ptr [esp + 8]
// 005fae2c  8bc6                 mov eax, esi
// 005fae2e  d95c240c             fstp dword ptr [esp + 0xc]
// 005fae32  99                   cdq 
// 005fae33  f7f9                 idiv ecx
// 005fae35  8bf0                 mov esi, eax
// 005fae37  e884e40400           call 0x6492c0
// 005fae3c  8bc8                 mov ecx, eax
// 005fae3e  8bc6                 mov eax, esi
// 005fae40  99                   cdq 
// 005fae41  f7f9                 idiv ecx
// 005fae43  2503000080           and eax, 0x80000003
// 005fae48  7905                 jns 0x5fae4f
// 005fae4a  48                   dec eax
// 005fae4b  83c8fc               or eax, 0xfffffffc
// 005fae4e  40                   inc eax
// 005fae4f  83f803               cmp eax, 3
// 005fae52  7729                 ja 0x5fae7d
// 005fae54  ff2485b4ae5f00       jmp dword ptr [eax*4 + 0x5faeb4]
// 005fae5b  d9e8                 fld1 
// 005fae5d  d95c2408             fstp dword ptr [esp + 8]
// 005fae61  eb1a                 jmp 0x5fae7d
// 005fae63  d9e8                 fld1 
// 005fae65  eb12                 jmp 0x5fae79
// 005fae67  d905b8c38100         fld dword ptr [0x81c3b8]
// 005fae6d  d95c2408             fstp dword ptr [esp + 8]
// 005fae71  eb0a                 jmp 0x5fae7d
// 005fae73  d905b8c38100         fld dword ptr [0x81c3b8]
// 005fae79  d95c240c             fstp dword ptr [esp + 0xc]
// 005fae7d  d9442408             fld dword ptr [esp + 8]
// 005fae81  8d542408             lea edx, [esp + 8]
// 005fae85  d905182a8300         fld dword ptr [0x832a18]
// 005fae8b  52                   push edx
// 005fae8c  dcc9                 fmul st(1), st(0)
// 005fae8e  8bcf                 mov ecx, edi
// 005fae90  d9c9                 fxch st(1)
// 005fae92  d95c240c             fstp dword ptr [esp + 0xc]
// 005fae96  d84c2410             fmul dword ptr [esp + 0x10]
// 005fae9a  d95c2410             fstp dword ptr [esp + 0x10]
// 005fae9e  d9ee                 fldz 
// 005faea0  d95c2414             fstp dword ptr [esp + 0x14]
// 005faea4  e8f7fbffff           call 0x5faaa0
// 005faea9  5f                   pop edi
// 005faeaa  5e                   pop esi
// 005faeab  83c40c               add esp, 0xc
// 005faeae  c20400               ret 4
// 005faeb1  8d4900               lea ecx, [ecx]
// 005faeb4  5b                   pop ebx
// 005faeb5  ae                   scasb al, byte ptr es:[edi]
// 005faeb6  5f                   pop edi
// 005faeb7  0063ae               add byte ptr [ebx - 0x52], ah
// 005faeba  5f                   pop edi
// 005faebb  0067ae               add byte ptr [edi - 0x52], ah
// 005faebe  5f                   pop edi
// 005faebf  0073ae               add byte ptr [ebx - 0x52], dh
// 005faec2  5f                   pop edi





struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3&);
};

struct S {
    void f(int);
    void apply(Vector3*);
};

static const float g_81c3b8 = -1.0f;
static const float g_832a18 = 0.4f;

unsigned int func_0063e420();
unsigned int func_006492c0();
void func_005faaa0(S*, Vector3*);

void S::f(int arg)
{
    if (arg % (int)func_0063e420() != 0)
        return;

    int q = arg / (int)func_0063e420();

    Vector3 v;
    v.x = 0.0f;
    v.y = 0.0f;

    int r = q / (int)func_006492c0();
    int m = r % 4;

    switch (m) {
    case 0:
        v.x = 1.0f;
        break;
    case 1:
        v.y = 1.0f;
        break;
    case 2:
        v.x = g_81c3b8;
        break;
    case 3:
        v.y = g_81c3b8;
        break;
    }

    v.x *= g_832a18;
    v.y *= g_832a18;
    v.z = 0.0f;

    apply(&v);
}
