// from server: 36% by Intel
extern "C" void* __cdecl allocate_memory(unsigned int size);

struct InitializableObject {
    void initialize(void* param);
};

struct VAdvRotateTool_TToolVerb {
    void* field_C;
    void* func_008a5940();
};

void* VAdvRotateTool_TToolVerb::func_008a5940() {
    void* allocated = allocate_memory(0x104);
    
    if (!allocated) {
        return 0;
    }
    
    void* param = *reinterpret_cast<void**>(reinterpret_cast<char*>(field_C) + 0xAC4);
    reinterpret_cast<InitializableObject*>(allocated)->initialize(param);
    
    return allocated;
}
