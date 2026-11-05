// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a15d40();
extern void* stored_00a15d40;
void func_00a15d40() { stored_00a15d40 = get_value_00a15d40(); }
