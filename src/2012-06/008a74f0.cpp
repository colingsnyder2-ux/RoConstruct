// from server: 50% by Intel
// Forward declarations for external functions
extern "C" void* __cdecl operator_new(unsigned int size);  // 0x98211a

// Vtable addresses (immediate values in assembly)
const int vtable1_addr = 0x00bdfb94;
const int vtable2_addr = 0x00bdfb68;

// The constructed object type (60 bytes, two vtables for multiple inheritance)
struct DropperCursor {
    void* vtable1;
    void* vtable2;
    char pad[60 - 8];
    
    // Constructor at 0x743150 - called with thiscall, one argument
    void __thiscall construct(void* arg);
};

// The class this method belongs to
struct VDropperTool {
    char pad_0[0xc];
    void* field_c;
    
    // The method we're reconstructing
    DropperCursor* __thiscall create_dropper_cursor();
};

// Implementation
DropperCursor* VDropperTool::create_dropper_cursor() {
    // Allocate 60 bytes
    void* mem = operator_new(0x3c);
    DropperCursor* obj = static_cast<DropperCursor*>(mem);
    
    if (obj != 0) {
        // Get the argument from this->field_c + 0xac4
        void* arg = *reinterpret_cast<void**>(reinterpret_cast<char*>(field_c) + 0xac4);
        
        // Call constructor
        obj->construct(arg);
        
        // Set vtables (immediate values from assembly)
        obj->vtable1 = reinterpret_cast<void*>(vtable1_addr);
        obj->vtable2 = reinterpret_cast<void*>(vtable2_addr);
    }
    
    return obj;
}
