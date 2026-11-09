// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_00413a70();
void* func_00413a70() {
    static void* value = make_value_00413a70();
    return value;
}
