// from server: 96% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00582700  unit: RBX::RunCommand  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00582700
//
// 00582700  56                   push esi
// 00582701  57                   push edi
// 00582702  8bf1                 mov esi, ecx
// 00582704  6a01                 push 1
// 00582706  8d4e10               lea ecx, [esi + 0x10]
// 00582709  e8f2f4ffff           call 0x581c00
// 0058270e  8bb8b4010000         mov edi, dword ptr [eax + 0x1b4]
// 00582714  8b460c               mov eax, dword ptr [esi + 0xc]
// 00582717  6a01                 push 1
// 00582719  50                   push eax
// 0058271a  e84137f1ff           call 0x495e60
// 0058271f  83c408               add esp, 8
// 00582722  84c0                 test al, al
// 00582724  750d                 jne 0x582733
// 00582726  83ff01               cmp edi, 1
// 00582729  7408                 je 0x582733
// 0058272b  5f                   pop edi
// 0058272c  b801000000           mov eax, 1
// 00582731  5e                   pop esi
// 00582732  c3                   ret 
// 00582733  5f                   pop edi
// 00582734  33c0                 xor eax, eax
// 00582736  5e                   pop esi
// 00582737  c3                   ret 

struct State {
    char padding[0x1B4];
    int value;
};

struct Handle {
    State* get(int);
};

extern "C" bool __cdecl check(void*, int);

struct RunCommand {
    char padding[0x0C];
    void* object;
    Handle handle;

    int enabled();
};

int RunCommand::enabled()
{
    int value = handle.get(1)->value;
    if (check(object, 1) || value == 1)
        return 0;
    return 1;
}
