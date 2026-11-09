// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_005e7460();
void* func_005e7460() {
    static void* value = make_value_005e7460();
    return value;
}
