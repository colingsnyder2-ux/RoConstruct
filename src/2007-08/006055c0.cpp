// from server: 85% by EspClaude
// from server: 49% by colin
// roc 2007-08 006055c0  unit: RBX::SleepStage  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006055c0
//
// 006055c0  83ec14               sub esp, 0x14
// 006055c3  53                   push ebx
// 006055c4  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 006055c8  8b03                 mov eax, dword ptr [ebx]
// 006055ca  56                   push esi
// 006055cb  57                   push edi
// 006055cc  8bf9                 mov edi, ecx
// 006055ce  8b4860               mov ecx, dword ptr [eax + 0x60]
// 006055d1  d94108               fld dword ptr [ecx + 8]
// 006055d4  83c104               add ecx, 4
// 006055d7  d819                 fcomp dword ptr [ecx]
// 006055d9  dfe0                 fnstsw ax
// 006055db  d94108               fld dword ptr [ecx + 8]
// 006055de  f6c441               test ah, 0x41
// 006055e1  7511                 jne 0x6055f4
// 006055e3  d819                 fcomp dword ptr [ecx]
// 006055e5  dfe0                 fnstsw ax
// 006055e7  f6c441               test ah, 0x41
// 006055ea  7519                 jne 0x605605
// 006055ec  d94104               fld dword ptr [ecx + 4]
// 006055ef  d84908               fmul dword ptr [ecx + 8]
// 006055f2  eb16                 jmp 0x60560a
// 006055f4  d85904               fcomp dword ptr [ecx + 4]
// 006055f7  dfe0                 fnstsw ax
// 006055f9  f6c441               test ah, 0x41
// 006055fc  7507                 jne 0x605605
// 006055fe  d901                 fld dword ptr [ecx]
// 00605600  d84908               fmul dword ptr [ecx + 8]
// 00605603  eb05                 jmp 0x60560a
// 00605605  d901                 fld dword ptr [ecx]
// 00605607  d84904               fmul dword ptr [ecx + 4]
// 0060560a  83ec08               sub esp, 8
// 0060560d  dd1c24               fstp qword ptr [esp]
// 00605610  e813bb0200           call 0x631128
// 00605615  d95c2414             fstp dword ptr [esp + 0x14]
// 00605619  83c408               add esp, 8
// 0060561c  d944240c             fld dword ptr [esp + 0xc]
// 00605620  db5c2424             fistp dword ptr [esp + 0x24]
// 00605624  8b742424             mov esi, dword ptr [esp + 0x24]
// 00605628  8d4c240c             lea ecx, [esp + 0xc]
// 0060562c  51                   push ecx
// 0060562d  8d542418             lea edx, [esp + 0x18]
// 00605631  52                   push edx
// 00605632  8d4f14               lea ecx, [edi + 0x14]
// 00605635  895c2414             mov dword ptr [esp + 0x14], ebx
// 00605639  89742418             mov dword ptr [esp + 0x18], esi
// 0060563d  e8de85f2ff           call 0x52dc20
// 00605642  8d44240c             lea eax, [esp + 0xc]
// 00605646  50                   push eax
// 00605647  8d4c2418             lea ecx, [esp + 0x18]
// 0060564b  51                   push ecx
// 0060564c  8d4f38               lea ecx, [edi + 0x38]
// 0060564f  895c2414             mov dword ptr [esp + 0x14], ebx
// 00605653  89742418             mov dword ptr [esp + 0x18], esi
// 00605657  e8a4fcffff           call 0x605300
// 0060565c  5f                   pop edi
// 0060565d  5e                   pop esi
// 0060565e  5b                   pop ebx
// 0060565f  83c414               add esp, 0x14
// 00605662  c20400               ret 4
// roc-flags: /O2 /GS /EHsc /MD /QIfist /fp:fast
#include <map>
#include <math.h>

struct Vector3 { float x, y, z; };

struct Geometry {
    int pad0;          // size Vector3 read at +4 (target: add ecx,4)
    Vector3 size;
};

struct Primitive {
    char pad0[0x60];
    Geometry* geometry; // +0x60
};

struct Assembly {
    Primitive* root;    // +0
};

struct SleepStage {
    char pad0[0x14];
    std::map<Assembly*, int> sleepers;      // +0x14
    char pad1[0x38 - 0x14 - sizeof(std::map<Assembly*, int>)];
    std::multimap<Assembly*, int> awake;    // +0x38
    void stepSleepStage(Assembly* a);
};

void SleepStage::stepSleepStage(Assembly* a)
{
    const Vector3& s = a->root->geometry->size;
    double area = (s.x < s.y)
        ? ((s.x < s.z) ? s.y * s.z : s.x * s.y)
        : ((s.y < s.z) ? s.x * s.z : s.x * s.y);
    volatile float f = (float)floor(area);
    int n = (int)f;
    sleepers.insert(std::map<Assembly*, int>::value_type(a, n));
    awake.insert(std::multimap<Assembly*, int>::value_type(a, n));
}
