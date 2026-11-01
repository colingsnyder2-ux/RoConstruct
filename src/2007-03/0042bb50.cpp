// from server: 100% by auto
// roc 2007-03 0042bb50  unit: seg_00420000  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0042bb50
//
// 0042bb50  8b442408             mov eax, dword ptr [esp + 8]
// 0042bb54  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042bb58  56                   push esi
// 0042bb59  57                   push edi
// 0042bb5a  be10000000           mov esi, 0x10
// 0042bb5f  90                   nop 
// 0042bb60  8b11                 mov edx, dword ptr [ecx]
// 0042bb62  3b10                 cmp edx, dword ptr [eax]
// 0042bb64  7512                 jne 0x42bb78
// 0042bb66  83ee04               sub esi, 4
// 0042bb69  83c004               add eax, 4
// 0042bb6c  83c104               add ecx, 4
// 0042bb6f  83fe04               cmp esi, 4
// 0042bb72  73ec                 jae 0x42bb60
// 0042bb74  85f6                 test esi, esi
// 0042bb76  7467                 je 0x42bbdf
// 0042bb78  0fb611               movzx edx, byte ptr [ecx]
// 0042bb7b  0fb638               movzx edi, byte ptr [eax]
// 0042bb7e  2bd7                 sub edx, edi
// 0042bb80  7545                 jne 0x42bbc7
// 0042bb82  83ee01               sub esi, 1
// 0042bb85  83c001               add eax, 1
// 0042bb88  83c101               add ecx, 1
// 0042bb8b  85f6                 test esi, esi
// 0042bb8d  7450                 je 0x42bbdf
// 0042bb8f  0fb611               movzx edx, byte ptr [ecx]
// 0042bb92  0fb638               movzx edi, byte ptr [eax]
// 0042bb95  2bd7                 sub edx, edi
// 0042bb97  752e                 jne 0x42bbc7
// 0042bb99  83ee01               sub esi, 1
// 0042bb9c  83c001               add eax, 1
// 0042bb9f  83c101               add ecx, 1
// 0042bba2  85f6                 test esi, esi
// 0042bba4  7439                 je 0x42bbdf
// 0042bba6  0fb611               movzx edx, byte ptr [ecx]
// 0042bba9  0fb638               movzx edi, byte ptr [eax]
// 0042bbac  2bd7                 sub edx, edi
// 0042bbae  7517                 jne 0x42bbc7
// 0042bbb0  83ee01               sub esi, 1
// 0042bbb3  83c001               add eax, 1
// 0042bbb6  83c101               add ecx, 1
// 0042bbb9  85f6                 test esi, esi
// 0042bbbb  7422                 je 0x42bbdf
// 0042bbbd  0fb611               movzx edx, byte ptr [ecx]
// 0042bbc0  0fb600               movzx eax, byte ptr [eax]
// 0042bbc3  2bd0                 sub edx, eax
// 0042bbc5  7418                 je 0x42bbdf
// 0042bbc7  85d2                 test edx, edx
// 0042bbc9  b801000000           mov eax, 1
// 0042bbce  7f11                 jg 0x42bbe1
// 0042bbd0  83c8ff               or eax, 0xffffffff
// 0042bbd3  33c9                 xor ecx, ecx
// 0042bbd5  85c0                 test eax, eax
// 0042bbd7  0f94c1               sete cl
// 0042bbda  5f                   pop edi
// 0042bbdb  5e                   pop esi
// 0042bbdc  8bc1                 mov eax, ecx
// 0042bbde  c3                   ret 
// 0042bbdf  33c0                 xor eax, eax
// 0042bbe1  33c9                 xor ecx, ecx
// 0042bbe3  85c0                 test eax, eax
// 0042bbe5  0f94c1               sete cl
// 0042bbe8  5f                   pop edi
// 0042bbe9  5e                   pop esi
// 0042bbea  8bc1                 mov eax, ecx
// 0042bbec  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\cmdtarg.cpp (function _IsEqualGUID)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/cmdtarg.cpp
