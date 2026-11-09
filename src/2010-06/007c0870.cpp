// from server: 100% by auto
// roc 2010-06 007c0870  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c0870
//
// 007c0870  83ec0c               sub esp, 0xc
// 007c0873  53                   push ebx
// 007c0874  8bd9                 mov ebx, ecx
// 007c0876  8b432c               mov eax, dword ptr [ebx + 0x2c]
// 007c0879  f7d8                 neg eax
// 007c087b  1bc0                 sbb eax, eax
// 007c087d  89442404             mov dword ptr [esp + 4], eax
// 007c0881  7440                 je 0x7c08c3
// 007c0883  56                   push esi
// 007c0884  57                   push edi
// 007c0885  8d7b20               lea edi, [ebx + 0x20]
// 007c0888  eb06                 jmp 0x7c0890
// 007c088a  8d9b00000000         lea ebx, [ebx]
// 007c0890  8d442410             lea eax, [esp + 0x10]
// 007c0894  50                   push eax
// 007c0895  8d4c2418             lea ecx, [esp + 0x18]
// 007c0899  51                   push ecx
// 007c089a  8d542414             lea edx, [esp + 0x14]
// 007c089e  52                   push edx
// 007c089f  8bcf                 mov ecx, edi
// 007c08a1  e8eaf90a00           call 0x870290
// 007c08a6  8b742410             mov esi, dword ptr [esp + 0x10]
// 007c08aa  6a01                 push 1
// 007c08ac  8bce                 mov ecx, esi
// 007c08ae  e8bdfeffff           call 0x7c0770
// 007c08b3  8bce                 mov ecx, esi
// 007c08b5  e86276feff           call 0x7a7f1c
// 007c08ba  837c240c00           cmp dword ptr [esp + 0xc], 0
// 007c08bf  75cf                 jne 0x7c0890
// 007c08c1  5f                   pop edi
// 007c08c2  5e                   pop esi
// 007c08c3  8d4b20               lea ecx, [ebx + 0x20]
// 007c08c6  5b                   pop ebx
// 007c08c7  83c40c               add esp, 0xc
// 007c08ca  e9f1d0ffff           jmp 0x7bd9c0
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?RemoveAll@CXTPImageManagerIconSet@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
