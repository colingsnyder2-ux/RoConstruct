// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_00425c60();
void* func_00425c60() {
    static void* value = make_value_00425c60();
    return value;
}
