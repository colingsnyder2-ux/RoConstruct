// from server: 56% by Intel
// Forward declaration for the external function
extern "C" void __stdcall sub_45a030(void* arg);

// Interface for the objects in the array
struct Interface {
    // At offset 0x10c, there's a function pointer
    // We'll model this as a virtual function at that offset
    // But since we don't know the full vtable, we can use a function pointer member
    // Actually, the code does: eax = [esi], ecx = eax + 0x10c, eax = [ecx], edx = [eax], call edx
    // This means: object->vtable[0x10c/4]() 
    // So it's a virtual function at index 0x10c/4 = 67
    // But we can't easily model that without the full vtable
    // Instead, we can use a function pointer at offset 0x10c
};

struct AxesItem {
    // Members before offset 0x1c...
    // At offset 0x1c: array of 3 pointers
    void* items[3];  // This is at offset 0x1c
    
    void func(void* arg);
};

void AxesItem::func(void* arg) {
    sub_45a030(arg);
    
    // items is at this + 0x1c
    for (int i = 0; i < 3; ++i) {
        void* item = items[i];
        if (item) {
            // Call virtual function at offset 0x10c
            // The assembly: lea ecx, [eax + 0x10c], mov eax, [ecx], mov edx, [eax], call edx
            // This means: *(void**)(*(void**)(item + 0x10c))(arg)
            // Or: item->vtable[67](arg) if vtable starts at item
            // Actually: item is a pointer to object. Object has vtable at offset 0.
            // At offset 0x10c from object, there's a pointer to a function (or vtable entry)
            // The code reads [item + 0x10c] -> gets a pointer, then dereferences that to get function pointer
            // So it's a double indirection: function pointer stored at item + 0x10c
            
            typedef void (__stdcall *FuncPtr)(void*);
            FuncPtr* funcPtrPtr = (FuncPtr*)((char*)item + 0x10c);
            FuncPtr funcPtr = *funcPtrPtr;
            funcPtr(arg);
        }
    }
}
