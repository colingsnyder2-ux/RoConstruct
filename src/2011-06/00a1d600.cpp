// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a1d600();
extern void* stored_00a1d600;
void func_00a1d600() { stored_00a1d600 = get_value_00a1d600(); }
