// from server: 68% by Intel
// Forward declarations for the callee functions
// They are member functions taking 'this' in ecx, returning bool
struct SomeClass; // The class at offset 0x80

// Since we don't know the exact class, but the callees are called with 'this' = esi = this + 0x80
// We can declare them as member functions of a dummy struct, or as free functions taking a pointer
// But since they're called with 'mov ecx, esi' then 'call', they're thiscall member functions

// Let's declare a struct for the subobject at offset 0x80
struct SubObject {
    bool func1();  // 0x479fa0
    bool func2();  // 0x509d50
};

// Main class
struct KeyframeSequenceProvider {
    char pad[0x80];
    SubObject sub;
    
    bool func_00790990();
};

bool KeyframeSequenceProvider::func_00790990() {
    if (sub.func1())
        return false;
    if (sub.func2())
        return false;
    return true;
}
