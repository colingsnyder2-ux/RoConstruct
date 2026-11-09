// from server: 100% by auto
// roc 2010-06 0087d4e0  unit: VCEdit::?$CXTMaskEditT  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087d4e0
//
// 0087d4e0  8b542404             mov edx, dword ptr [esp + 4]
// 0087d4e4  0fb7c2               movzx eax, dx
// 0087d4e7  05e01effff           add eax, 0xffff1ee0
// 0087d4ec  83f80b               cmp eax, 0xb
// 0087d4ef  7755                 ja 0x87d546
// 0087d4f1  ff248550d58700       jmp dword ptr [eax*4 + 0x87d550]
// 0087d4f8  e803faffff           call 0x87cf00
// 0087d4fd  b801000000           mov eax, 1
// 0087d502  c20800               ret 8
// 0087d505  e866eeffff           call 0x87c370
// 0087d50a  b801000000           mov eax, 1
// 0087d50f  c20800               ret 8
// 0087d512  e849faffff           call 0x87cf60
// 0087d517  b801000000           mov eax, 1
// 0087d51c  c20800               ret 8
// 0087d51f  e85cf4ffff           call 0x87c980
// 0087d524  b801000000           mov eax, 1
// 0087d529  c20800               ret 8
// 0087d52c  e8dfe6ffff           call 0x87bc10
// 0087d531  b801000000           mov eax, 1
// 0087d536  c20800               ret 8
// 0087d539  e802f1ffff           call 0x87c640
// 0087d53e  b801000000           mov eax, 1
// 0087d543  c20800               ret 8
// 0087d546  89542404             mov dword ptr [esp + 4], edx
// 0087d54a  e9a7a5f2ff           jmp 0x7a7af6
// 0087d54f  90                   nop 
// 0087d550  1f                   pop ds
// 0087d551  d587                 aad 0x87
// 0087d553  0046d5               add byte ptr [esi - 0x2b], al
// 0087d556  8700                 xchg dword ptr [eax], eax
// 0087d558  05d58700f8           add eax, 0xf80087d5
// 0087d55d  d487                 aam 0x87
// 0087d55f  0046d5               add byte ptr [esi - 0x2b], al
// 0087d562  8700                 xchg dword ptr [eax], eax
// 0087d564  12d5                 adc dl, ch
// 0087d566  8700                 xchg dword ptr [eax], eax
// 0087d568  46                   inc esi
// 0087d569  d587                 aad 0x87
// 0087d56b  0046d5               add byte ptr [esi - 0x2b], al
// 0087d56e  8700                 xchg dword ptr [eax], eax
// 0087d570  46                   inc esi
// 0087d571  d587                 aad 0x87
// 0087d573  0046d5               add byte ptr [esi - 0x2b], al
// 0087d576  8700                 xchg dword ptr [eax], eax
// 0087d578  39d5                 cmp ebp, edx
// 0087d57a  8700                 xchg dword ptr [eax], eax
// 0087d57c  2cd5                 sub al, 0xd5
// 0087d57e  8700                 xchg dword ptr [eax], eax
// library xtp-13.2.1/Source\Controls\XTBrowseEdit.cpp (function ?OnCommand@?$CXTMaskEditT@VCEdit@@@@MAEHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTBrowseEdit.cpp
