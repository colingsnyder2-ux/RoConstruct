// from server: 93% by colin
// roc 2007-08 006a3060  unit: CXTPHookManager::CHookSink  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a3060
//
// 006a3060  7700                 ja 0x6a3062
// 006a3062  e8bcdcf8ff           call 0x630d23
// 006a3067  83c404               add esp, 4
// 006a306a  b8f0928c00           mov eax, 0x8c92f0
// 006a306f  c3                   ret

extern "C" void __cdecl sub_630d23(int);

struct CXTPHookManager__CHookSink {
    void* method();
};

void* CXTPHookManager__CHookSink::method() {
    sub_630d23(0);
    return (void*)0x8c92f0;
}
