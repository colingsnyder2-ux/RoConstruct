// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a15d50();
extern void* stored_00a15d50;
void func_00a15d50() { stored_00a15d50 = get_value_00a15d50(); }
