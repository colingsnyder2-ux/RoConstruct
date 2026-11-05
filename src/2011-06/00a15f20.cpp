// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a15f20();
extern void* stored_00a15f20;
void func_00a15f20() { stored_00a15f20 = get_value_00a15f20(); }
