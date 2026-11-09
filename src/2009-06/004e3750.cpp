// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_004e3750();
void* func_004e3750() {
    static void* value = make_value_004e3750();
    return value;
}
