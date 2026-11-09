// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD /Gr
struct RBX_VBasicPartInstance {
    // Assuming the structure layout based on the given assembly
    char _padding[0x90];
};

int func_005d7540(RBX_VBasicPartInstance* thisPtr) {
    return (int)((char*)thisPtr - 0x90);
}
