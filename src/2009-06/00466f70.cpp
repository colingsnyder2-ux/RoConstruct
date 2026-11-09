// from server: 100% by EspClaude
// roc 2009-06 00466f70  unit: CSelectionCaption  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00466f70
//
// 00466f70  56                   push esi
// 00466f71  8bf1                 mov esi, ecx
// 00466f73  e890202b00           call 0x719008
// 00466f78  83f8ff               cmp eax, -1
// 00466f7b  7506                 jne 0x466f83
// 00466f7d  0bc0                 or eax, eax
// 00466f7f  5e                   pop esi
// 00466f80  c20400               ret 4
// 00466f83  8d8e90010000         lea ecx, [esi + 0x190]
// 00466f89  e8923efbff           call 0x41ae20
// 00466f8e  33c0                 xor eax, eax
// 00466f90  5e                   pop esi
// 00466f91  c20400               ret 4
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
