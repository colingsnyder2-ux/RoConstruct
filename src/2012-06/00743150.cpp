// from server: 35% by Intel
// Global references
extern "C" void __stdcall sub_5C9FE8(void* thisptr, int a2, int a3);
extern "C" void __cdecl sub_8677E0(int arg); // or whatever calling convention

// Global data
extern char byte_E31AA5;
extern int dword_BAA7CC;
extern int dword_BAA79C;
extern int dword_BAA820;

struct PartTool {
    // vtable pointers at offset 0 and 4
    void* vfptr1;
    void* vfptr2;
    // ... other members ...
    int field_34;
    int field_38;
    
    PartTool(int arg);
};

PartTool::PartTool(int arg) {
    // Call sub_8677E0 with arg
    sub_8677E0(arg);
    
    // Set vtable pointers
    vfptr1 = (void*)0xBAA7CC;
    vfptr2 = (void*)0xBAA79C;
    
    // Initialize fields
    field_34 = 0;
    field_38 = 0;
    
    // Check global byte
    if (byte_E31AA5 == 0) {
        sub_5C9FE8(this, 0xBAA820, byte_E31AA5);
    }
}
