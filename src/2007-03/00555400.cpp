// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_00555400();
void* func_00555400() {
    static void* value = make_value_00555400();
    return value;
}
