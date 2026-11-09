// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_004a4720();
void* func_004a4720() {
    static void* value = make_value_004a4720();
    return value;
}
