// from server: 100% by auto
// roc 2007-03 005c52a0  unit: seg_005c0000  size: 204 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c52a0
//
// 005c52a0  83c0cf               add eax, -0x31
// 005c52a3  56                   push esi
// 005c52a4  57                   push edi
// 005c52a5  8bf1                 mov esi, ecx
// 005c52a7  780c                 js 0x5c52b5
// 005c52a9  3b460c               cmp eax, dword ptr [esi + 0xc]
// 005c52ac  7d07                 jge 0x5c52b5
// 005c52ae  837cc614ff           cmp dword ptr [esi + eax*8 + 0x14], -1
// 005c52b3  7511                 jne 0x5c52c6
// 005c52b5  8b4608               mov eax, dword ptr [esi + 8]
// 005c52b8  68689f7b00           push 0x7b9f68
// 005c52bd  50                   push eax
// 005c52be  e88d48ffff           call 0x5b9b50
// 005c52c3  83c408               add esp, 8
// 005c52c6  8b4e04               mov ecx, dword ptr [esi + 4]
// 005c52c9  8b7cc614             mov edi, dword ptr [esi + eax*8 + 0x14]
// 005c52cd  2bcb                 sub ecx, ebx
// 005c52cf  3bcf                 cmp ecx, edi
// 005c52d1  0f8290000000         jb 0x5c5367
// 005c52d7  83ff04               cmp edi, 4
// 005c52da  8b44c610             mov eax, dword ptr [esi + eax*8 + 0x10]
// 005c52de  55                   push ebp
// 005c52df  8bcf                 mov ecx, edi
// 005c52e1  8bd3                 mov edx, ebx
// 005c52e3  7214                 jb 0x5c52f9
// 005c52e5  8b30                 mov esi, dword ptr [eax]
// 005c52e7  3b32                 cmp esi, dword ptr [edx]
// 005c52e9  7512                 jne 0x5c52fd
// 005c52eb  83e904               sub ecx, 4
// 005c52ee  83c204               add edx, 4
// 005c52f1  83c004               add eax, 4
// 005c52f4  83f904               cmp ecx, 4
// 005c52f7  73ec                 jae 0x5c52e5
// 005c52f9  85c9                 test ecx, ecx
// 005c52fb  745d                 je 0x5c535a
// 005c52fd  0fb630               movzx esi, byte ptr [eax]
// 005c5300  0fb62a               movzx ebp, byte ptr [edx]
// 005c5303  2bf5                 sub esi, ebp
// 005c5305  7545                 jne 0x5c534c
// 005c5307  83e901               sub ecx, 1
// 005c530a  83c201               add edx, 1
// 005c530d  83c001               add eax, 1
// 005c5310  85c9                 test ecx, ecx
// 005c5312  7446                 je 0x5c535a
// 005c5314  0fb630               movzx esi, byte ptr [eax]
// 005c5317  0fb62a               movzx ebp, byte ptr [edx]
// 005c531a  2bf5                 sub esi, ebp
// 005c531c  752e                 jne 0x5c534c
// 005c531e  83e901               sub ecx, 1
// 005c5321  83c201               add edx, 1
// 005c5324  83c001               add eax, 1
// 005c5327  85c9                 test ecx, ecx
// 005c5329  742f                 je 0x5c535a
// 005c532b  0fb630               movzx esi, byte ptr [eax]
// 005c532e  0fb62a               movzx ebp, byte ptr [edx]
// 005c5331  2bf5                 sub esi, ebp
// 005c5333  7517                 jne 0x5c534c
// 005c5335  83e901               sub ecx, 1
// 005c5338  83c201               add edx, 1
// 005c533b  83c001               add eax, 1
// 005c533e  85c9                 test ecx, ecx
// 005c5340  7418                 je 0x5c535a
// 005c5342  0fb630               movzx esi, byte ptr [eax]
// 005c5345  0fb612               movzx edx, byte ptr [edx]
// 005c5348  2bf2                 sub esi, edx
// 005c534a  740e                 je 0x5c535a
// 005c534c  85f6                 test esi, esi
// 005c534e  b801000000           mov eax, 1
// 005c5353  7f07                 jg 0x5c535c
// 005c5355  83c8ff               or eax, 0xffffffff
// 005c5358  eb02                 jmp 0x5c535c
// 005c535a  33c0                 xor eax, eax
// 005c535c  85c0                 test eax, eax
// 005c535e  5d                   pop ebp
// 005c535f  7506                 jne 0x5c5367
// 005c5361  8d041f               lea eax, [edi + ebx]
// 005c5364  5f                   pop edi
// 005c5365  5e                   pop esi
// 005c5366  c3                   ret 
// 005c5367  5f                   pop edi
// 005c5368  33c0                 xor eax, eax
// 005c536a  5e                   pop esi
// 005c536b  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _match_capture)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
