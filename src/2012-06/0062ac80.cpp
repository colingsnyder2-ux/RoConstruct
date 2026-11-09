// from server: 100% by auto
// roc 2012-06 0062ac80  unit: G3D::MemoryManager  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062ac80
//
// 0062ac80  83ec10               sub esp, 0x10
// 0062ac83  53                   push ebx
// 0062ac84  8b442418             mov eax, dword ptr [esp + 0x18]
// 0062ac88  b900000000           mov ecx, 0
// 0062ac8d  0fa2                 cpuid 
// 0062ac8f  89442404             mov dword ptr [esp + 4], eax
// 0062ac93  895c2408             mov dword ptr [esp + 8], ebx
// 0062ac97  894c240c             mov dword ptr [esp + 0xc], ecx
// 0062ac9b  89542410             mov dword ptr [esp + 0x10], edx
// 0062ac9f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0062aca3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0062aca7  8b542420             mov edx, dword ptr [esp + 0x20]
// 0062acab  8908                 mov dword ptr [eax], ecx
// 0062acad  8b442408             mov eax, dword ptr [esp + 8]
// 0062acb1  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0062acb5  8902                 mov dword ptr [edx], eax
// 0062acb7  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0062acbb  8b442428             mov eax, dword ptr [esp + 0x28]
// 0062acbf  8911                 mov dword ptr [ecx], edx
// 0062acc1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0062acc5  8908                 mov dword ptr [eax], ecx
// 0062acc7  5b                   pop ebx
// 0062acc8  83c410               add esp, 0x10
// 0062accb  c3                   ret 
// library rbx2016-g3d/System.cpp (function ?cpuid@System@G3D@@CAXW4CPUIDFunction@12@AAI111@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d System.cpp
