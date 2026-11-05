// from server: 100% by colin
// roc 2007-08 006b2c10  unit: CXTPResourceManager  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006b2c10
//
// 006b2c10  a138938c00           mov eax, dword ptr [0x8c9338]
// 006b2c15  c3                   ret 

struct CXTPResourceManager {
    // Assuming the function is a member function based on the context
    int f();
};

extern int G_0x8c9338;

int CXTPResourceManager::f() {
    return G_0x8c9338;
}
