// from server: 93% by EspClaude
// from server: 100% by colin
// roc 2008-06 00422030  unit: CSettingsExplorer  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00422030
//
// 00422030  55                   push ebp
// 00422031  8bec                 mov ebp, esp
// 00422033  6aff                 push -1
// 00422035  6810428d00           push 0x8d4210
// 0042203a  6812156a00           push 0x6a1512
// 0042203f  64a100000000         mov eax, dword ptr fs:[0]
// 00422045  50                   push eax
// 00422046  64892500000000       mov dword ptr fs:[0], esp
// 0042204d  83ec14               sub esp, 0x14
// 00422050  53                   push ebx
// 00422051  56                   push esi
// 00422052  57                   push edi
// 00422053  8bf1                 mov esi, ecx
// 00422055  33db                 xor ebx, ebx
// 00422057  895de4               mov dword ptr [ebp - 0x1c], ebx
// 0042205a  8d45e4               lea eax, [ebp - 0x1c]
// 0042205d  50                   push eax
// 0042205e  e8c3e82700           call 0x6a0926
// 00422063  8b889c000000         mov ecx, dword ptr [eax + 0x9c]
// 00422069  51                   push ecx
// 0042206a  e8c7ed2700           call 0x6a0e36
// 0042206f  8bf8                 mov edi, eax
// 00422071  897de0               mov dword ptr [ebp - 0x20], edi
// 00422074  3bfb                 cmp edi, ebx
// 00422076  742f                 je 0x4220a7
// 00422078  895dfc               mov dword ptr [ebp - 4], ebx
// 0042207b  8d55dc               lea edx, [ebp - 0x24]
// 0042207e  52                   push edx
// 0042207f  8bce                 mov ecx, esi
// 00422081  e87affffff           call 0x422000
// 00422086  8b7668               mov esi, dword ptr [esi + 0x68]
// 00422089  33c0                 xor eax, eax
// 0042208b  3bf3                 cmp esi, ebx
// 0042208d  0f95c0               setne al
// 00422090  3bc3                 cmp eax, ebx
// 00422092  7505                 jne 0x422099
// 00422094  e8abe82700           call 0x6a0944
// 00422099  ffd6                 call esi
// 0042209b  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 004220a2  e814000000           call 0x4220bb
// 004220a7  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 004220aa  64890d00000000       mov dword ptr fs:[0], ecx
// 004220b1  5f                   pop edi
// 004220b2  5e                   pop esi
// 004220b3  5b                   pop ebx
// 004220b4  8be5                 mov esp, ebp
// 004220b6  5d                   pop ebp
// 004220b7  c3                   ret 

// 00422030 endDrag v1: __try/__finally with inline-called funclet.
// roc-lang: cpp
// roc-cl: 50727

struct ModuleState {
    char padding[0x9c];
    void* context;
};

extern "C" ModuleState* __stdcall getState(int* state);
extern "C" unsigned long __stdcall activateContext(void* context);
extern "C" void __stdcall deactivateContext(int flag, int state);
extern "C" void __stdcall reportMissingProcedure();

struct CSettingsExplorer {
    char padding[0x68];
    void* procedure;
    void** getProcedure(void** result);
    void endDrag();
};

void CSettingsExplorer::endDrag() {
    int state = 0;
    unsigned long cookie = activateContext(getState(&state)->context);
    if (cookie) {
        __try {
            void* result;
            getProcedure(&result);
            void (__stdcall *function)() =
                reinterpret_cast<void (__stdcall *)()>(procedure);
            int valid = function != 0;
            if (!valid)
                reportMissingProcedure();
            function();
        }
        __finally {
            if (cookie != 2)
                deactivateContext(0, state);
        }
    }
}
