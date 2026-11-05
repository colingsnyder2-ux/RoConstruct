// from server: 8% by Intel
struct VScriptContext;

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);
extern "C" void __stdcall RBX_VScriptContext_EventDesc_ctor(void* thisptr, VScriptContext* context, int a3);
extern "C" void __stdcall RBX_VScriptContext_AddEventDesc(void* thisptr, void* eventDesc);
extern "C" void __stdcall RBX_RefCounted_AddRef(void* ptr);

struct VScriptContext {
    void* vftable;
    char pad[0x1C];
    void* eventList;
};

void* __stdcall VScriptContext_CreateEventDesc(VScriptContext* thisptr, int a2, int a3, void** outPtr) {
    void* allocated = operator_new(0x38);
    if (allocated) {
        RBX_VScriptContext_EventDesc_ctor(allocated, thisptr, a3);
        *(int*)allocated = 0xB94BC4;
        *(int*)((char*)allocated + 8) = 0xB94BBC;
    } else {
        allocated = 0;
    }
    RBX_VScriptContext_AddEventDesc(thisptr, allocated);
    *outPtr = allocated;
    if (allocated) {
        RBX_RefCounted_AddRef((char*)allocated + 5);
    }
    return outPtr;
}
