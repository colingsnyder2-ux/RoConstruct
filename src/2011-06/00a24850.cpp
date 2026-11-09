// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a24850();
extern void* stored_00a24850;
void func_00a24850() { stored_00a24850 = get_value_00a24850(); }
