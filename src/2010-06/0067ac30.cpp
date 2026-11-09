// from server: 24% by atomic.potato
extern "C" void __stdcall G1_9ea40c(void*);

struct VPseudoPlayer {
    void* field_1C;
    void* field_20;
};

void* VPseudoPlayer_BoundFuncDesc(VPseudoPlayer* this_, VPseudoPlayer* arg) {
    void* fs0 = *(void**)0;
    *(void**)0 = &fs0 + 1;
    
    void* result = 0;
    G1_9ea40c(arg);
    
    this_->field_1C = arg->field_1C;
    void* vtableEntry = arg->field_20;
    
    if (vtableEntry) {
        void* vtable = *(void**)vtableEntry;
        result = ((void*(__thiscall*)(void*))(*(void**)((char*)vtable + 8)))(vtableEntry);
    }
    
    this_->field_20 = result;
    *(void**)0 = fs0;
    return this_;
}
