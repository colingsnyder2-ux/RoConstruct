// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value();
void* func_004c7570() { static void* value = make_value(); return value; }
