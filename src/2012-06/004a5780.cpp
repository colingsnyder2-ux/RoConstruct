// from server: 100% by Xemicl
// roc 2012-06 004a5780  unit: CSelectionCaption  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a5780
//
// 004a5780  56                   push esi
// 004a5781  8bf1                 mov esi, ecx
// 004a5783  e856cf4d00           call 0x9826de
// 004a5788  83f8ff               cmp eax, -1
// 004a578b  7506                 jne 0x4a5793
// 004a578d  0bc0                 or eax, eax
// 004a578f  5e                   pop esi
// 004a5790  c20400               ret 4
// 004a5793  8d8e90010000         lea ecx, [esi + 0x190]
// 004a5799  e8025cf8ff           call 0x42b3a0
// 004a579e  33c0                 xor eax, eax
// 004a57a0  5e                   pop esi
// 004a57a1  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00000b_00465e00@CSelectionCaption@ns_ROCX00000b@@QAEHPAX@Z)

namespace ns_ROCX00000b {
struct CaptionPart
{
    void fn_ROCX00000b_00420bd0();
};

struct CSelectionCaption
{
    char padding[0x190];
    CaptionPart caption;

    int fn_ROCX00000b_006a0c68();
    int fn_ROCX00000b_00465e00(void *);
};

int CSelectionCaption::fn_ROCX00000b_00465e00(void *)
{
    int result = fn_ROCX00000b_006a0c68();
    if (result == -1)
        return result;

    caption.fn_ROCX00000b_00420bd0();
    return 0;
}
}