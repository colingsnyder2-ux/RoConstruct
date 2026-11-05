// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_00411490();
void* func_00411490() {
    static void* value = make_value_00411490();
    return value;
}
