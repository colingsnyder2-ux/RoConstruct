// from server: 100% by colin
// roc 2007-08 0054cad0  unit: std::D::V?$allocator::V?$zlib_decompressor_impl::?$symmetric_filter::Uimpl::?$sp_counted_impl_p  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054cad0
//
// 0054cad0  6aff                 push -1
// 0054cad2  6808267500           push 0x752608
// 0054cad7  64a100000000         mov eax, dword ptr fs:[0]
// 0054cadd  50                   push eax
// 0054cade  64892500000000       mov dword ptr fs:[0], esp
// 0054cae5  51                   push ecx
// 0054cae6  56                   push esi
// 0054cae7  8bf1                 mov esi, ecx
// 0054cae9  89742404             mov dword ptr [esp + 4], esi
// 0054caed  ff1518e57700         call dword ptr [0x77e518]
// 0054caf3  33c0                 xor eax, eax
// 0054caf5  88463c               mov byte ptr [esi + 0x3c], al
// 0054caf8  884644               mov byte ptr [esi + 0x44], al
// 0054cafb  894648               mov dword ptr [esi + 0x48], eax
// 0054cafe  89464c               mov dword ptr [esi + 0x4c], eax
// 0054cb01  894650               mov dword ptr [esi + 0x50], eax
// 0054cb04  894654               mov dword ptr [esi + 0x54], eax
// 0054cb07  c7465810000000       mov dword ptr [esi + 0x58], 0x10
// 0054cb0e  8b542420             mov edx, dword ptr [esp + 0x20]
// 0054cb12  89442410             mov dword ptr [esp + 0x10], eax
// 0054cb16  8b442418             mov eax, dword ptr [esp + 0x18]
// 0054cb1a  c706fc797a00         mov dword ptr [esi], 0x7a79fc
// 0054cb20  8b08                 mov ecx, dword ptr [eax]
// 0054cb22  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0054cb26  52                   push edx
// 0054cb27  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0054cb2b  50                   push eax
// 0054cb2c  8d4c2420             lea ecx, [esp + 0x20]
// 0054cb30  51                   push ecx
// 0054cb31  8bce                 mov ecx, esi
// 0054cb33  e898f5ffff           call 0x54c0d0
// 0054cb38  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0054cb3c  8bc6                 mov eax, esi
// 0054cb3e  5e                   pop esi
// 0054cb3f  64890d00000000       mov dword ptr fs:[0], ecx
// 0054cb46  83c410               add esp, 0x10
// 0054cb49  c20c00               ret 0xc
// copied from an identical function in another client (function ??0?$stream_buffer@V?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@boost@@U?$char_traits@D@std@@V?$allocator@D@4@Uinput_seekable@iostreams@2@@iostreams@boost@@QAE@ABV?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@2@HH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp