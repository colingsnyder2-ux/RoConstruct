// from server: 100% by auto
// roc 2009-12 0060a960  unit: seg_00600000  size: 296 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060a960
//
// 0060a960  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0060a964  53                   push ebx
// 0060a965  55                   push ebp
// 0060a966  56                   push esi
// 0060a967  57                   push edi
// 0060a968  85c9                 test ecx, ecx
// 0060a96a  0f8411010000         je 0x60aa81
// 0060a970  8b742418             mov esi, dword ptr [esp + 0x18]
// 0060a974  85f6                 test esi, esi
// 0060a976  0f8405010000         je 0x60aa81
// 0060a97c  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0060a980  85db                 test ebx, ebx
// 0060a982  0f84f9000000         je 0x60aa81
// 0060a988  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0060a98c  85ed                 test ebp, ebp
// 0060a98e  0f84ed000000         je 0x60aa81
// 0060a994  8b442424             mov eax, dword ptr [esp + 0x24]
// 0060a998  85c0                 test eax, eax
// 0060a99a  0f84e1000000         je 0x60aa81
// 0060a9a0  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0060a9a4  85ff                 test edi, edi
// 0060a9a6  0f84d5000000         je 0x60aa81
// 0060a9ac  8b16                 mov edx, dword ptr [esi]
// 0060a9ae  8913                 mov dword ptr [ebx], edx
// 0060a9b0  8b5604               mov edx, dword ptr [esi + 4]
// 0060a9b3  895500               mov dword ptr [ebp], edx
// 0060a9b6  0fb65618             movzx edx, byte ptr [esi + 0x18]
// 0060a9ba  8910                 mov dword ptr [eax], edx
// 0060a9bc  807e1801             cmp byte ptr [esi + 0x18], 1
// 0060a9c0  7206                 jb 0x60a9c8
// 0060a9c2  807e1810             cmp byte ptr [esi + 0x18], 0x10
// 0060a9c6  7612                 jbe 0x60a9da
// 0060a9c8  6820539c00           push 0x9c5320
// 0060a9cd  51                   push ecx
// 0060a9ce  e8bd570000           call 0x610190
// 0060a9d3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060a9d7  83c408               add esp, 8
// 0060a9da  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 0060a9de  8907                 mov dword ptr [edi], eax
// 0060a9e0  807e1906             cmp byte ptr [esi + 0x19], 6
// 0060a9e4  7612                 jbe 0x60a9f8
// 0060a9e6  680c539c00           push 0x9c530c
// 0060a9eb  51                   push ecx
// 0060a9ec  e89f570000           call 0x610190
// 0060a9f1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060a9f5  83c408               add esp, 8
// 0060a9f8  8b442430             mov eax, dword ptr [esp + 0x30]
// 0060a9fc  85c0                 test eax, eax
// 0060a9fe  7406                 je 0x60aa06
// 0060aa00  0fb6561a             movzx edx, byte ptr [esi + 0x1a]
// 0060aa04  8910                 mov dword ptr [eax], edx
// 0060aa06  8b442434             mov eax, dword ptr [esp + 0x34]
// 0060aa0a  85c0                 test eax, eax
// 0060aa0c  7406                 je 0x60aa14
// 0060aa0e  0fb6561b             movzx edx, byte ptr [esi + 0x1b]
// 0060aa12  8910                 mov dword ptr [eax], edx
// 0060aa14  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0060aa18  85c0                 test eax, eax
// 0060aa1a  7406                 je 0x60aa22
// 0060aa1c  0fb6561c             movzx edx, byte ptr [esi + 0x1c]
// 0060aa20  8910                 mov dword ptr [eax], edx
// 0060aa22  8b03                 mov eax, dword ptr [ebx]
// 0060aa24  85c0                 test eax, eax
// 0060aa26  7407                 je 0x60aa2f
// 0060aa28  3dffffff7f           cmp eax, 0x7fffffff
// 0060aa2d  7612                 jbe 0x60aa41
// 0060aa2f  68f8529c00           push 0x9c52f8
// 0060aa34  51                   push ecx
// 0060aa35  e856570000           call 0x610190
// 0060aa3a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060aa3e  83c408               add esp, 8
// 0060aa41  8b4500               mov eax, dword ptr [ebp]
// 0060aa44  85c0                 test eax, eax
// 0060aa46  7407                 je 0x60aa4f
// 0060aa48  3dffffff7f           cmp eax, 0x7fffffff
// 0060aa4d  7612                 jbe 0x60aa61
// 0060aa4f  68e0529c00           push 0x9c52e0
// 0060aa54  51                   push ecx
// 0060aa55  e836570000           call 0x610190
// 0060aa5a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060aa5e  83c408               add esp, 8
// 0060aa61  813e7effff1f         cmp dword ptr [esi], 0x1fffff7e
// 0060aa67  760e                 jbe 0x60aa77
// 0060aa69  68ac529c00           push 0x9c52ac
// 0060aa6e  51                   push ecx
// 0060aa6f  e8cc570000           call 0x610240
// 0060aa74  83c408               add esp, 8
// 0060aa77  5f                   pop edi
// 0060aa78  5e                   pop esi
// 0060aa79  5d                   pop ebp
// 0060aa7a  b801000000           mov eax, 1
// 0060aa7f  5b                   pop ebx
// 0060aa80  c3                   ret 
// 0060aa81  5f                   pop edi
// 0060aa82  5e                   pop esi
// 0060aa83  5d                   pop ebp
// 0060aa84  33c0                 xor eax, eax
// 0060aa86  5b                   pop ebx
// 0060aa87  c3                   ret 
// library libpng-1.2.8/pngget.c (function _png_get_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.8 pngget.c
