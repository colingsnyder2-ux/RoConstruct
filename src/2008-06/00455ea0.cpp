// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_00455ea0();
void* func_00455ea0() {
    static void* value = make_value_00455ea0();
    return value;
}
