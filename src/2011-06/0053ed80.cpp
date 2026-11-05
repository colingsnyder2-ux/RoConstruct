// from server: 100% by auto
// roc 2011-06 0053ed80  unit: G3D::MemoryManager  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053ed80
//
// 0053ed80  83ec10               sub esp, 0x10
// 0053ed83  53                   push ebx
// 0053ed84  8b442418             mov eax, dword ptr [esp + 0x18]
// 0053ed88  b900000000           mov ecx, 0
// 0053ed8d  0fa2                 cpuid 
// 0053ed8f  89442404             mov dword ptr [esp + 4], eax
// 0053ed93  895c2408             mov dword ptr [esp + 8], ebx
// 0053ed97  894c240c             mov dword ptr [esp + 0xc], ecx
// 0053ed9b  89542410             mov dword ptr [esp + 0x10], edx
// 0053ed9f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053eda3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0053eda7  8b542420             mov edx, dword ptr [esp + 0x20]
// 0053edab  8908                 mov dword ptr [eax], ecx
// 0053edad  8b442408             mov eax, dword ptr [esp + 8]
// 0053edb1  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0053edb5  8902                 mov dword ptr [edx], eax
// 0053edb7  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0053edbb  8b442428             mov eax, dword ptr [esp + 0x28]
// 0053edbf  8911                 mov dword ptr [ecx], edx
// 0053edc1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0053edc5  8908                 mov dword ptr [eax], ecx
// 0053edc7  5b                   pop ebx
// 0053edc8  83c410               add esp, 0x10
// 0053edcb  c3                   ret 
// library rbx2016-g3d/System.cpp (function ?cpuid@System@G3D@@CAXW4CPUIDFunction@12@AAI111@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d System.cpp
