// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_005ccc40();
void* func_005ccc40() {
    static void* value = make_value_005ccc40();
    return value;
}
