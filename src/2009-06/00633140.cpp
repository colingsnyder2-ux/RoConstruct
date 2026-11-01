// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 005a86c0  unit: RBX::Log  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a86c0
//
// 005a86c0  8b8138010000         mov eax, dword ptr [ecx + 0x138]
// 005a86c6  85c0                 test eax, eax
// 005a86c8  740d                 je 0x5a86d7
// 005a86ca  6a00                 push 0
// 005a86cc  6a02                 push 2
// 005a86ce  50                   push eax
// 005a86cf  e8aca30600           call 0x612a80
// 005a86d4  83c40c               add esp, 0xc
// 005a86d7  c3                   ret 

struct Log {
    char pad[0x8c];
    void* stream;
    void closeStream();
};

extern "C" void __cdecl sub_612A80(void*, int, int);

void Log::closeStream() {
    if (stream) {
        sub_612A80(stream, 2, 0);
    }
}
