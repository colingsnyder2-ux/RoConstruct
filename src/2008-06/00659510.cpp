// from server: 100% by colin
// from server: 98% by colin
// roc 2008-06 00659510  unit: RBX::BallBallContact  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00659510
//
// 00659510  83ec18               sub esp, 0x18
// 00659513  a1ac259600           mov eax, dword ptr [0x9625ac]
// 00659518  56                   push esi
// 00659519  57                   push edi
// 0065951a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0065951e  8bcf                 mov ecx, edi
// 00659520  d3e0                 shl eax, cl
// 00659522  8b742428             mov esi, dword ptr [esp + 0x28]
// 00659526  8d4c2408             lea ecx, [esp + 8]
// 0065952a  51                   push ecx
// 0065952b  89442428             mov dword ptr [esp + 0x28], eax
// 0065952f  db442428             fild dword ptr [esp + 0x28]
// 00659533  8d542418             lea edx, [esp + 0x18]
// 00659537  d9e8                 fld1 
// 00659539  52                   push edx
// 0065953a  def1                 fdivrp st(1)
// 0065953c  d906                 fld dword ptr [esi]
// 0065953e  d8c9                 fmul st(1)
// 00659540  d95c2410             fstp dword ptr [esp + 0x10]
// 00659544  d94604               fld dword ptr [esi + 4]
// 00659547  d8c9                 fmul st(1)
// 00659549  d95c2414             fstp dword ptr [esp + 0x14]
// 0065954d  d84e08               fmul dword ptr [esi + 8]
// 00659550  d95c2418             fstp dword ptr [esp + 0x18]
// 00659554  e857fdffff           call 0x6592b0
// 00659559  8b442434             mov eax, dword ptr [esp + 0x34]
// 0065955d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00659561  8b542420             mov edx, dword ptr [esp + 0x20]
// 00659565  8908                 mov dword ptr [eax], ecx
// 00659567  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0065956b  895004               mov dword ptr [eax + 4], edx
// 0065956e  894808               mov dword ptr [eax + 8], ecx
// 00659571  8b15ac259600         mov edx, dword ptr [0x9625ac]
// 00659577  8bcf                 mov ecx, edi
// 00659579  d3e2                 shl edx, cl
// 0065957b  8d44241c             lea eax, [esp + 0x1c]
// 0065957f  50                   push eax
// 00659580  8d4c2414             lea ecx, [esp + 0x14]
// 00659584  89542430             mov dword ptr [esp + 0x30], edx
// 00659588  db442430             fild dword ptr [esp + 0x30]
// 0065958c  51                   push ecx
// 0065958d  d9e8                 fld1 
// 0065958f  def1                 fdivrp st(1)
// 00659591  d9460c               fld dword ptr [esi + 0xc]
// 00659594  d8c9                 fmul st(1)
// 00659596  d95c2424             fstp dword ptr [esp + 0x24]
// 0065959a  d94610               fld dword ptr [esi + 0x10]
// 0065959d  d8c9                 fmul st(1)
// 0065959f  d95c2428             fstp dword ptr [esp + 0x28]
// 006595a3  d84e14               fmul dword ptr [esi + 0x14]
// 006595a6  d95c242c             fstp dword ptr [esp + 0x2c]
// 006595aa  e801fdffff           call 0x6592b0
// 006595af  8b442440             mov eax, dword ptr [esp + 0x40]
// 006595b3  8b542418             mov edx, dword ptr [esp + 0x18]
// 006595b7  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006595bb  83c410               add esp, 0x10
// 006595be  8910                 mov dword ptr [eax], edx
// 006595c0  8b542410             mov edx, dword ptr [esp + 0x10]
// 006595c4  5f                   pop edi
// 006595c5  894804               mov dword ptr [eax + 4], ecx
// 006595c8  895008               mov dword ptr [eax + 8], edx
// 006595cb  5e                   pop esi
// 006595cc  83c418               add esp, 0x18
// 006595cf  c3                   ret 

#include <intrin.h>
struct Float3 { float x, y, z; };
struct Int3 { int x, y, z; };
struct Bounds { Float3 first, second; };

union Temporary {
    Float3 floating;
    Int3 integer;
};

struct Temporaries {
    Temporary a, b;
};

extern int scaleBase;
extern void __cdecl convert(Int3* result, const Float3* input);

void __cdecl quantize(int level, const Bounds* input, Int3* first, Int3* second)
{
    Temporaries t;

    {
        double inverse = 1.0 / (scaleBase << level);
        t.a.floating.x = (float)(input->first.x * inverse);
        t.a.floating.y = (float)(input->first.y * inverse);
        t.a.floating.z = (float)(input->first.z * inverse);
        convert(&t.b.integer, &t.a.floating);
        Int3* __restrict out = first;
        out->x = t.b.integer.x;
        out->y = t.b.integer.y;
        out->z = t.b.integer.z;
    }

    _ReadWriteBarrier();

    {
        double inverse = 1.0 / (scaleBase << level);
        t.b.floating.x = (float)(input->second.x * inverse);
        t.b.floating.y = (float)(input->second.y * inverse);
        t.b.floating.z = (float)(input->second.z * inverse);
        convert(&t.a.integer, &t.b.floating);
        second->x = t.a.integer.x;
        second->y = t.a.integer.y;
        second->z = t.a.integer.z;
    }
}
