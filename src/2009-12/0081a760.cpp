// roc 2009-12 0081a760  unit: XTP_REPORTRECORDITEM_DRAWARGS  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081a760
//
// 0081a760  53                   push ebx
// 0081a761  56                   push esi
// 0081a762  57                   push edi
// 0081a763  8bf9                 mov edi, ecx
// 0081a765  8b4f28               mov ecx, dword ptr [edi + 0x28]
// 0081a768  33f6                 xor esi, esi
// 0081a76a  e811350300           call 0x84dc80
// 0081a76f  85c0                 test eax, eax
// 0081a771  7e1c                 jle 0x81a78f
// 0081a773  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0081a777  56                   push esi
// 0081a778  e8b3870800           call 0x8a2f30
// 0081a77d  395824               cmp dword ptr [eax + 0x24], ebx
// 0081a780  740f                 je 0x81a791
// 0081a782  8b4f28               mov ecx, dword ptr [edi + 0x28]
// 0081a785  46                   inc esi
// 0081a786  e8f5340300           call 0x84dc80
// 0081a78b  3bf0                 cmp esi, eax
// 0081a78d  7ce8                 jl 0x81a777
// 0081a78f  33c0                 xor eax, eax
// 0081a791  5f                   pop edi
// 0081a792  5e                   pop esi
// 0081a793  5b                   pop ebx
// 0081a794  c20400               ret 4
// copied from an identical function in another client (function ?find@XTP_REPORTRECORDITEM_METRICS@ns_ROCX000002@@QAEPAXH@Z)

namespace ns_ROCX000002 {
struct XTP_REPORTRECORDITEM_METRICS
{
    char pad[0x28];
    void* field_28;
    void* find(int index);
};

extern "C" int __fastcall sub_653870(void* p);
extern "C" void* __stdcall sub_699220(int index);

void* XTP_REPORTRECORDITEM_METRICS::find(int index)
{
    int count = sub_653870(field_28);
    int i = 0;
    if (count > 0)
    {
        do
        {
            void* item = sub_699220(i);
            if (*(int*)((char*)item + 0x24) == index)
                return item;
            i++;
        } while (i < sub_653870(field_28));
    }
    return 0;
}
}
