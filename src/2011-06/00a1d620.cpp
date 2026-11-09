// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a1d620();
extern void* stored_00a1d620;
void func_00a1d620() { stored_00a1d620 = get_value_00a1d620(); }
