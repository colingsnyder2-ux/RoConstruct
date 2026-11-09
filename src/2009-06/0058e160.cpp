// from server: 100% by auto
// roc 2009-06 0058e160  unit: seg_00580000  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058e160
//
// 0058e160  83ec10               sub esp, 0x10
// 0058e163  55                   push ebp
// 0058e164  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0058e168  56                   push esi
// 0058e169  8b742420             mov esi, dword ptr [esp + 0x20]
// 0058e16d  85ed                 test ebp, ebp
// 0058e16f  0f8487000000         je 0x58e1fc
// 0058e175  8b556c               mov edx, dword ptr [ebp + 0x6c]
// 0058e178  f7c200000c00         test edx, 0xc0000
// 0058e17e  746e                 je 0x58e1ee
// 0058e180  803e23               cmp byte ptr [esi], 0x23
// 0058e183  7553                 jne 0x58e1d8
// 0058e185  b801000000           mov eax, 1
// 0058e18a  b120                 mov cl, 0x20
// 0058e18c  8d642400             lea esp, [esp]
// 0058e190  380c30               cmp byte ptr [eax + esi], cl
// 0058e193  7411                 je 0x58e1a6
// 0058e195  384c3001             cmp byte ptr [eax + esi + 1], cl
// 0058e199  740a                 je 0x58e1a5
// 0058e19b  83c002               add eax, 2
// 0058e19e  83f80f               cmp eax, 0xf
// 0058e1a1  7ced                 jl 0x58e190
// 0058e1a3  eb01                 jmp 0x58e1a6
// 0058e1a5  40                   inc eax
// 0058e1a6  f7c200000800         test edx, 0x80000
// 0058e1ac  7426                 je 0x58e1d4
// 0058e1ae  57                   push edi
// 0058e1af  8d78ff               lea edi, [eax - 1]
// 0058e1b2  33c9                 xor ecx, ecx
// 0058e1b4  85ff                 test edi, edi
// 0058e1b6  7e14                 jle 0x58e1cc
// 0058e1b8  8d4601               lea eax, [esi + 1]
// 0058e1bb  57                   push edi
// 0058e1bc  50                   push eax
// 0058e1bd  8d442414             lea eax, [esp + 0x14]
// 0058e1c1  50                   push eax
// 0058e1c2  e8efbc1800           call 0x719eb6
// 0058e1c7  83c40c               add esp, 0xc
// 0058e1ca  8bcf                 mov ecx, edi
// 0058e1cc  c6440c0b00           mov byte ptr [esp + ecx + 0xb], 0
// 0058e1d1  5f                   pop edi
// 0058e1d2  eb16                 jmp 0x58e1ea
// 0058e1d4  03f0                 add esi, eax
// 0058e1d6  eb16                 jmp 0x58e1ee
// 0058e1d8  f7c200000800         test edx, 0x80000
// 0058e1de  740e                 je 0x58e1ee
// 0058e1e0  c644240830           mov byte ptr [esp + 8], 0x30
// 0058e1e5  c644240900           mov byte ptr [esp + 9], 0
// 0058e1ea  8d742408             lea esi, [esp + 8]
// 0058e1ee  8b4540               mov eax, dword ptr [ebp + 0x40]
// 0058e1f1  85c0                 test eax, eax
// 0058e1f3  7407                 je 0x58e1fc
// 0058e1f5  56                   push esi
// 0058e1f6  55                   push ebp
// 0058e1f7  ffd0                 call eax
// 0058e1f9  83c408               add esp, 8
// 0058e1fc  55                   push ebp
// 0058e1fd  8bc6                 mov eax, esi
// 0058e1ff  e8fcfcffff           call 0x58df00
// 0058e204  83c404               add esp, 4
// 0058e207  5e                   pop esi
// 0058e208  5d                   pop ebp
// 0058e209  83c410               add esp, 0x10
// 0058e20c  c3                   ret 
// library libpng-1.2.32/pngerror.c (function _png_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngerror.c
