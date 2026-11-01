// from server: 100% by auto
// roc 2009-12 0079b020  unit: lua_exception  size: 372 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b020
//
// 0079b020  53                   push ebx
// 0079b021  55                   push ebp
// 0079b022  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0079b026  8bd8                 mov ebx, eax
// 0079b028  8b4504               mov eax, dword ptr [ebp + 4]
// 0079b02b  83780806             cmp dword ptr [eax + 8], 6
// 0079b02f  56                   push esi
// 0079b030  57                   push edi
// 0079b031  0f8596000000         jne 0x79b0cd
// 0079b037  8b4504               mov eax, dword ptr [ebp + 4]
// 0079b03a  8b08                 mov ecx, dword ptr [eax]
// 0079b03c  80790600             cmp byte ptr [ecx + 6], 0
// 0079b040  0f8587000000         jne 0x79b0cd
// 0079b046  83780806             cmp dword ptr [eax + 8], 6
// 0079b04a  8b7910               mov edi, dword ptr [ecx + 0x10]
// 0079b04d  7520                 jne 0x79b06f
// 0079b04f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0079b053  3b6914               cmp ebp, dword ptr [ecx + 0x14]
// 0079b056  7506                 jne 0x79b05e
// 0079b058  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0079b05b  894d0c               mov dword ptr [ebp + 0xc], ecx
// 0079b05e  8b10                 mov edx, dword ptr [eax]
// 0079b060  8b4210               mov eax, dword ptr [edx + 0x10]
// 0079b063  8b750c               mov esi, dword ptr [ebp + 0xc]
// 0079b066  2b700c               sub esi, dword ptr [eax + 0xc]
// 0079b069  c1fe02               sar esi, 2
// 0079b06c  4e                   dec esi
// 0079b06d  eb03                 jmp 0x79b072
// 0079b06f  83ceff               or esi, 0xffffffff
// 0079b072  56                   push esi
// 0079b073  8d4b01               lea ecx, [ebx + 1]
// 0079b076  51                   push ecx
// 0079b077  57                   push edi
// 0079b078  e803600300           call 0x7d1080
// 0079b07d  8b542428             mov edx, dword ptr [esp + 0x28]
// 0079b081  83c40c               add esp, 0xc
// 0079b084  8902                 mov dword ptr [edx], eax
// 0079b086  85c0                 test eax, eax
// 0079b088  754a                 jne 0x79b0d4
// 0079b08a  53                   push ebx
// 0079b08b  56                   push esi
// 0079b08c  57                   push edi
// 0079b08d  e88efaffff           call 0x79ab20
// 0079b092  8bc8                 mov ecx, eax
// 0079b094  83e13f               and ecx, 0x3f
// 0079b097  83c40c               add esp, 0xc
// 0079b09a  83f90b               cmp ecx, 0xb
// 0079b09d  772e                 ja 0x79b0cd
// 0079b09f  0fb68988b17900       movzx ecx, byte ptr [ecx + 0x79b188]
// 0079b0a6  ff248d70b17900       jmp dword ptr [ecx*4 + 0x79b170]
// 0079b0ad  8bc8                 mov ecx, eax
// 0079b0af  c1e806               shr eax, 6
// 0079b0b2  c1e917               shr ecx, 0x17
// 0079b0b5  25ff000000           and eax, 0xff
// 0079b0ba  3bc8                 cmp ecx, eax
// 0079b0bc  7d0f                 jge 0x79b0cd
// 0079b0be  8b5504               mov edx, dword ptr [ebp + 4]
// 0079b0c1  837a0806             cmp dword ptr [edx + 8], 6
// 0079b0c5  8bd9                 mov ebx, ecx
// 0079b0c7  0f846affffff         je 0x79b037
// 0079b0cd  5f                   pop edi
// 0079b0ce  5e                   pop esi
// 0079b0cf  5d                   pop ebp
// 0079b0d0  33c0                 xor eax, eax
// 0079b0d2  5b                   pop ebx
// 0079b0d3  c3                   ret 
// 0079b0d4  5f                   pop edi
// 0079b0d5  5e                   pop esi
// 0079b0d6  5d                   pop ebp
// 0079b0d7  b8acab9e00           mov eax, 0x9eabac
// 0079b0dc  5b                   pop ebx
// 0079b0dd  c3                   ret 
// 0079b0de  8b4f08               mov ecx, dword ptr [edi + 8]
// 0079b0e1  c1e80e               shr eax, 0xe
// 0079b0e4  c1e004               shl eax, 4
// 0079b0e7  8b1408               mov edx, dword ptr [eax + ecx]
// 0079b0ea  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0079b0ee  5f                   pop edi
// 0079b0ef  5e                   pop esi
// 0079b0f0  83c210               add edx, 0x10
// 0079b0f3  5d                   pop ebp
// 0079b0f4  8910                 mov dword ptr [eax], edx
// 0079b0f6  b8a4ab9e00           mov eax, 0x9eaba4
// 0079b0fb  5b                   pop ebx
// 0079b0fc  c3                   ret 
// 0079b0fd  c1e80e               shr eax, 0xe
// 0079b100  25ff010000           and eax, 0x1ff
// 0079b105  8bcf                 mov ecx, edi
// 0079b107  e8e4feffff           call 0x79aff0
// 0079b10c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0079b110  5f                   pop edi
// 0079b111  5e                   pop esi
// 0079b112  5d                   pop ebp
// 0079b113  8901                 mov dword ptr [ecx], eax
// 0079b115  b89cab9e00           mov eax, 0x9eab9c
// 0079b11a  5b                   pop ebx
// 0079b11b  c3                   ret 
// 0079b11c  8b7f1c               mov edi, dword ptr [edi + 0x1c]
// 0079b11f  85ff                 test edi, edi
// 0079b121  7419                 je 0x79b13c
// 0079b123  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0079b127  c1e817               shr eax, 0x17
// 0079b12a  8b0487               mov eax, dword ptr [edi + eax*4]
// 0079b12d  5f                   pop edi
// 0079b12e  5e                   pop esi
// 0079b12f  83c010               add eax, 0x10
// 0079b132  5d                   pop ebp
// 0079b133  8902                 mov dword ptr [edx], eax
// 0079b135  b894ab9e00           mov eax, 0x9eab94
// 0079b13a  5b                   pop ebx
// 0079b13b  c3                   ret 
// 0079b13c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0079b140  5f                   pop edi
// 0079b141  5e                   pop esi
// 0079b142  b8d0d99b00           mov eax, 0x9bd9d0
// 0079b147  5d                   pop ebp
// 0079b148  8902                 mov dword ptr [edx], eax
// 0079b14a  b894ab9e00           mov eax, 0x9eab94
// 0079b14f  5b                   pop ebx
// 0079b150  c3                   ret 
// 0079b151  c1e80e               shr eax, 0xe
// 0079b154  25ff010000           and eax, 0x1ff
// 0079b159  8bcf                 mov ecx, edi
// 0079b15b  e890feffff           call 0x79aff0
// 0079b160  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0079b164  5f                   pop edi
// 0079b165  5e                   pop esi
// 0079b166  5d                   pop ebp
// 0079b167  8901                 mov dword ptr [ecx], eax
// 0079b169  b8889d9e00           mov eax, 0x9e9d88
// 0079b16e  5b                   pop ebx
// 0079b16f  c3                   ret 
// 0079b170  ad                   lodsd eax, dword ptr [esi]
// 0079b171  b079                 mov al, 0x79
// 0079b173  001cb1               add byte ptr [ecx + esi*4], bl
// 0079b176  7900                 jns 0x79b178
// 0079b178  deb07900fdb0         fidiv word ptr [eax - 0x4f02ff87]
// 0079b17e  7900                 jns 0x79b180
// 0079b180  51                   push ecx
// 0079b181  b179                 mov cl, 0x79
// 0079b183  00cd                 add ch, cl
// 0079b185  b079                 mov al, 0x79
// 0079b187  0000                 add byte ptr [eax], al
// 0079b189  0505050102           add eax, 0x2010505
// 0079b18e  030505050504         add eax, dword ptr [0x4050505]
// library lua-5.1/ldebug.c (function _getobjname)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
