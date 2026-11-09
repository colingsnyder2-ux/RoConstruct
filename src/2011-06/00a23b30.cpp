// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a23b30();
extern void* stored_00a23b30;
void func_00a23b30() { stored_00a23b30 = get_value_00a23b30(); }
