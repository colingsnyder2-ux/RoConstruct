// from server: 100% by auto
// roc 2008-06 005f82f0  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f82f0
//
// 005f82f0  55                   push ebp
// 005f82f1  8bec                 mov ebp, esp
// 005f82f3  6aff                 push -1
// 005f82f5  6870797d00           push 0x7d7970
// 005f82fa  64a100000000         mov eax, dword ptr fs:[0]
// 005f8300  50                   push eax
// 005f8301  64892500000000       mov dword ptr fs:[0], esp
// 005f8308  51                   push ecx
// 005f8309  53                   push ebx
// 005f830a  56                   push esi
// 005f830b  57                   push edi
// 005f830c  8b7d08               mov edi, dword ptr [ebp + 8]
// 005f830f  8965f0               mov dword ptr [ebp - 0x10], esp
// 005f8312  57                   push edi
// 005f8313  8bf1                 mov esi, ecx
// 005f8315  e896ceffff           call 0x5f51b0
// 005f831a  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 005f8320  57                   push edi
// 005f8321  50                   push eax
// 005f8322  83c640               add esi, 0x40
// 005f8325  56                   push esi
// 005f8326  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005f832d  e8ceebffff           call 0x5f6f00
// 005f8332  83c40c               add esp, 0xc
// 005f8335  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005f8338  5f                   pop edi
// 005f8339  5e                   pop esi
// 005f833a  64890d00000000       mov dword ptr fs:[0], ecx
// 005f8341  5b                   pop ebx
// 005f8342  8be5                 mov esp, ebp
// 005f8344  5d                   pop ebp
// 005f8345  c20400               ret 4
// library templates-boost-1_34_1/roc_boost_resume_916365a4f87a380b.cpp (function ?close@?$indirect_streambuf@V?$basic_gzip_compressor@V?$allocator@D@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@MAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_boost_resume_916365a4f87a380b.cpp
