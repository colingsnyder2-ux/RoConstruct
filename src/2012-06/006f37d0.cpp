// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_006f37d0();
void* func_006f37d0() {
    static void* value = make_value_006f37d0();
    return value;
}
