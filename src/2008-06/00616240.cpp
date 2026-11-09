// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_00616240();
void* func_00616240() {
    static void* value = make_value_00616240();
    return value;
}
