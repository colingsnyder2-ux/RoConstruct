// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a15d80();
extern void* stored_00a15d80;
void func_00a15d80() { stored_00a15d80 = get_value_00a15d80(); }
