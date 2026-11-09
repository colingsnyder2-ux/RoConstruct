// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_004a3e90();
void* func_004a3e90() {
    static void* value = make_value_004a3e90();
    return value;
}
