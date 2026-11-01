// from server: 100% by auto
// roc 2009-12 008f3f90  unit: CXTCaptionButtonTheme  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f3f90
//
// 008f3f90  56                   push esi
// 008f3f91  8bf1                 mov esi, ecx
// 008f3f93  e8f80af6ff           call 0x854a90
// 008f3f98  e803d6f3ff           call 0x8315a0
// 008f3f9d  6820299f00           push 0x9f2920
// 008f3fa2  6a00                 push 0
// 008f3fa4  8d4e74               lea ecx, [esi + 0x74]
// 008f3fa7  e8547df7ff           call 0x86bd00
// 008f3fac  e81fbaf3ff           call 0x82f9d0
// 008f3fb1  6a0f                 push 0xf
// 008f3fb3  8bc8                 mov ecx, eax
// 008f3fb5  e846b1f3ff           call 0x82f100
// 008f3fba  894624               mov dword ptr [esi + 0x24], eax
// 008f3fbd  e80ebaf3ff           call 0x82f9d0
// 008f3fc2  6a12                 push 0x12
// 008f3fc4  8bc8                 mov ecx, eax
// 008f3fc6  e835b1f3ff           call 0x82f100
// 008f3fcb  894630               mov dword ptr [esi + 0x30], eax
// 008f3fce  e8fdb9f3ff           call 0x82f9d0
// 008f3fd3  6a11                 push 0x11
// 008f3fd5  8bc8                 mov ecx, eax
// 008f3fd7  e824b1f3ff           call 0x82f100
// 008f3fdc  89463c               mov dword ptr [esi + 0x3c], eax
// 008f3fdf  e8ecb9f3ff           call 0x82f9d0
// 008f3fe4  6a0f                 push 0xf
// 008f3fe6  8bc8                 mov ecx, eax
// 008f3fe8  e813b1f3ff           call 0x82f100
// 008f3fed  894648               mov dword ptr [esi + 0x48], eax
// 008f3ff0  e8dbb9f3ff           call 0x82f9d0
// 008f3ff5  6a10                 push 0x10
// 008f3ff7  8bc8                 mov ecx, eax
// 008f3ff9  e802b1f3ff           call 0x82f100
// 008f3ffe  894654               mov dword ptr [esi + 0x54], eax
// 008f4001  e8cab9f3ff           call 0x82f9d0
// 008f4006  6a14                 push 0x14
// 008f4008  8bc8                 mov ecx, eax
// 008f400a  e8f1b0f3ff           call 0x82f100
// 008f400f  894660               mov dword ptr [esi + 0x60], eax
// 008f4012  e8b9b9f3ff           call 0x82f9d0
// 008f4017  6a15                 push 0x15
// 008f4019  8bc8                 mov ecx, eax
// 008f401b  e8e0b0f3ff           call 0x82f100
// 008f4020  89466c               mov dword ptr [esi + 0x6c], eax
// 008f4023  5e                   pop esi
// 008f4024  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?RefreshMetrics@CXTButtonTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
