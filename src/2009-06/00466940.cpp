// from server: 100% by EspClaude
// roc 2009-06 00466940  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00466940
//
// 00466940  8b442408             mov eax, dword ptr [esp + 8]
// 00466944  3d78eaffff           cmp eax, 0xffffea78
// 00466949  7409                 je 0x466954
// 0046694b  89442408             mov dword ptr [esp + 8], eax
// 0046694f  e952222b00           jmp 0x718ba6
// 00466954  80b9f400000000       cmp byte ptr [ecx + 0xf4], 0
// 0046695b  7419                 je 0x466976
// 0046695d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00466961  b903000000           mov ecx, 3
// 00466966  668908               mov word ptr [eax], cx
// 00466969  c7400830170000       mov dword ptr [eax + 8], 0x1730
// 00466970  8d41fe               lea eax, [ecx - 2]
// 00466973  c20c00               ret 0xc
// 00466976  c744240878eaffff     mov dword ptr [esp + 8], 0xffffea78
// 0046697e  e923222b00           jmp 0x718ba6
// copied from an identical function in another client (function ?f@S@ns_ROCX000005@@QAEHPAXJPAUVariant@2@@Z)

namespace ns_ROCX000005 {
struct Variant
{
    unsigned short type;
    unsigned short reserved[3];
    unsigned long value;
    unsigned long extra;
};

struct S
{
    unsigned char padding[0xF4];
    unsigned char enabled;

    int fallback(void* site, long id, Variant* result);
    int f(void* site, long id, Variant* result);
};

int S::f(void* site, long id, Variant* result)
{
    if (id != -5512)
        return fallback(site, id, result);

    if (enabled)
    {
        result->type = 3;
        result->value = 0x1730;
        return 1;
    }

    return fallback(site, -5512, result);
}
}
