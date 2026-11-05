// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_004a4600();
void* func_004a4600() {
    static void* value = make_value_004a4600();
    return value;
}
