// from server: 32% by Intel
struct EventReplicator {
    // field at offset 0x2c
    char pad[0x2c];
    void* field_2c; // or some type
    
    // The function
    void* func(void* arg1, int arg2, void* arg3);
};

void* EventReplicator::func(void* arg1, int arg2, void* arg3) {
    if (arg2 == 0) {
        *static_cast<int*>(arg1) = 0; // or *static_cast<void**>(arg1) = 0?
        return arg1;
    }
    
    // Compute this for the call: field_2c + arg2 - 0x1c
    // Call the function at 0x8d9c20 with (arg1, arg3) and this = computed
    // The called function is a member function of whatever type field_2c points to
    
    // We need to declare the called function
    // It takes two arguments (arg1, arg3) and returns void? The return value is ignored.
    // Actually, the call result is ignored, we return arg1.
    
    // Let's declare the callee type
    // The callee is at 0x8d9c20, but we don't know its class. 
    // Since we're calling it with a computed this pointer, it's a member function of some class.
    // But we can just declare it as a function pointer or extern function with thiscall.
    
    // In MSVC, we can't easily do thiscall with arbitrary this. But we can use a member function pointer or just declare a function that takes this as first argument.
    // However, the assembly uses `call` with ecx set, which is thiscall.
    // For matching, we need to replicate the exact call.
    
    // Since we can't do inline asm, we need to structure it so the compiler generates the same code.
    // The key is: the function at 0x8d9c20 is called with ecx = this->field_2c + arg2 - 0x1c, and two stack args.
    
    // We can declare a helper struct for the target of field_2c.
}
