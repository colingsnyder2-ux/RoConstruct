// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_004a1760();
void* func_004a1760() {
    static void* value = make_value_004a1760();
    return value;
}
