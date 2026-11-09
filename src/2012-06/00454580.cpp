// from server: 100% by auto
// roc 2012-06 00454580  unit: XVCProgressDialog::XV?$mf1::V?$bind_t::?$thread_data  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00454580
//
// 00454580  0f57c0               xorps xmm0, xmm0
// 00454583  8bc1                 mov eax, ecx
// 00454585  f30f1100             movss dword ptr [eax], xmm0
// 00454589  f30f114004           movss dword ptr [eax + 4], xmm0
// 0045458e  f30f114008           movss dword ptr [eax + 8], xmm0
// 00454593  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ??0Vector3@G3D@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
