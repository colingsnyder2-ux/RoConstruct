// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_00557860();
void* func_00557860() {
    static void* value = make_value_00557860();
    return value;
}
