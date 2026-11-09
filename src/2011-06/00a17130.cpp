// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a17130();
extern void* stored_00a17130;
void func_00a17130() { stored_00a17130 = get_value_00a17130(); }
