// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_004c4460();
void* func_004c4460() {
    static void* value = make_value_004c4460();
    return value;
}
