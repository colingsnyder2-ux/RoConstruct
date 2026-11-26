// from server: 100% by Xemicl
// roc 2012-06 00864600  unit: VWiniInetRequest_source::?$stream_buffer  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00864600
//
// 00864600  56                   push esi
// 00864601  8b742408             mov esi, dword ptr [esp + 8]
// 00864605  8b06                 mov eax, dword ptr [esi]
// 00864607  85c0                 test eax, eax
// 00864609  7418                 je 0x864623
// 0086460b  8b00                 mov eax, dword ptr [eax]
// 0086460d  8d4e08               lea ecx, [esi + 8]
// 00864610  85c0                 test eax, eax
// 00864612  7409                 je 0x86461d
// 00864614  6a02                 push 2
// 00864616  51                   push ecx
// 00864617  51                   push ecx
// 00864618  ffd0                 call eax
// 0086461a  83c40c               add esp, 0xc
// 0086461d  c70600000000         mov dword ptr [esi], 0
// 00864623  5e                   pop esi
// 00864624  c20400               ret 4
// copied from an identical function in another client (function ??RClearer@@QAEXPAUfunction_base@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
union any_pointer { void* obj_ptr; double d; };
struct vtable_base {
    void (*manager)(const any_pointer&, any_pointer&, int);
    void clear(any_pointer& functor) { if (manager) manager(functor, functor, 2); }
};
struct function_base {
    vtable_base* vtable;
    any_pointer functor;
    void clear() { if (vtable) { vtable->clear(functor); vtable = 0; } }
};
struct Clearer {
    void operator()(function_base* f);
};
void Clearer::operator()(function_base* f) { f->clear(); }