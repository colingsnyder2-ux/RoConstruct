// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct Kernel { void* self(); };
extern Kernel g_kernel_888be0;
void __cdecl dtor_888be0() { g_kernel_888be0.self(); }
