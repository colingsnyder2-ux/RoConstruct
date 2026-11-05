// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_009cf200();
extern void* stored_009cf200;
void func_009cf200() { stored_009cf200 = get_value_009cf200(); }
