// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_00575630();
void* func_00575630() {
    static void* value = make_value_00575630();
    return value;
}
