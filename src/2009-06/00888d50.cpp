// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct Kernel { void* self(); };
extern Kernel g_kernel_888d50;
void __cdecl dtor_888d50() { g_kernel_888d50.self(); }
