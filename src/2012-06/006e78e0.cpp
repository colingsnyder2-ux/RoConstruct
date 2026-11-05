// from server: 80% by atomic.potato
struct VServer_BoundFuncDesc {
    void* field_38;
    void* field_3C;
    
    void* __thiscall method_591EF0();
};

extern "C" void __cdecl sub_982114(void*);

VServer_BoundFuncDesc* __stdcall func_006E78E0(VServer_BoundFuncDesc* this_, int arg_0) {
    VServer_BoundFuncDesc* esi = this_;
    sub_982114(esi->field_3C);
    sub_982114(esi->field_38);
    esi->method_591EF0();
    
    if (arg_0 & 1) {
        sub_982114(esi);
    }
    
    return esi;
}
