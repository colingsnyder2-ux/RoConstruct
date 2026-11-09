// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value();
extern void* stored;
void func_009cf1e0() { stored = get_value(); }
