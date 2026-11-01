// from server: 100% by colin
// roc 2007-08 0054cc50  unit: std::D::V?$allocator::V?$zlib_decompressor_impl::?$symmetric_filter::Uimpl::?$sp_counted_impl_p  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054cc50
//
// 0054cc50  6aff                 push -1
// 0054cc52  6808267500           push 0x752608
// 0054cc57  64a100000000         mov eax, dword ptr fs:[0]
// 0054cc5d  50                   push eax
// 0054cc5e  64892500000000       mov dword ptr fs:[0], esp
// 0054cc65  51                   push ecx
// 0054cc66  56                   push esi
// 0054cc67  8bf1                 mov esi, ecx
// 0054cc69  89742404             mov dword ptr [esp + 4], esi
// 0054cc6d  ff1518e57700         call dword ptr [0x77e518]
// 0054cc73  33c0                 xor eax, eax
// 0054cc75  88463c               mov byte ptr [esi + 0x3c], al
// 0054cc78  884644               mov byte ptr [esi + 0x44], al
// 0054cc7b  894648               mov dword ptr [esi + 0x48], eax
// 0054cc7e  89464c               mov dword ptr [esi + 0x4c], eax
// 0054cc81  894650               mov dword ptr [esi + 0x50], eax
// 0054cc84  894654               mov dword ptr [esi + 0x54], eax
// 0054cc87  c7465810000000       mov dword ptr [esi + 0x58], 0x10
// 0054cc8e  8b542420             mov edx, dword ptr [esp + 0x20]
// 0054cc92  89442410             mov dword ptr [esp + 0x10], eax
// 0054cc96  8b442418             mov eax, dword ptr [esp + 0x18]
// 0054cc9a  c7065c7a7a00         mov dword ptr [esi], 0x7a7a5c
// 0054cca0  8b08                 mov ecx, dword ptr [eax]
// 0054cca2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0054cca6  52                   push edx
// 0054cca7  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0054ccab  50                   push eax
// 0054ccac  8d4c2420             lea ecx, [esp + 0x20]
// 0054ccb0  51                   push ecx
// 0054ccb1  8bce                 mov ecx, esi
// 0054ccb3  e8d8f4ffff           call 0x54c190
// 0054ccb8  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0054ccbc  8bc6                 mov eax, esi
// 0054ccbe  5e                   pop esi
// 0054ccbf  64890d00000000       mov dword ptr fs:[0], ecx
// 0054ccc6  83c410               add esp, 0x10
// 0054ccc9  c20c00               ret 0xc
// copied from an identical function in another client (function ??0?$stream_buffer@V?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@boost@@U?$char_traits@D@std@@V?$allocator@D@4@Uinput_seekable@iostreams@2@@iostreams@boost@@QAE@ABV?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@2@HH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp