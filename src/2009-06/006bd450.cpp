// from server: 100% by EspClaude
// from server: 100% by atomic.potato
// roc 2008-06 0061bcb0  unit: RBX::Lua::LuaArguments  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0061bcb0
//
// 0061bcb0  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0061bcb3  8b442408             mov eax, dword ptr [esp + 8]
// 0061bcb7  03542404             add edx, dword ptr [esp + 4]
// 0061bcbb  6a01                 push 1
// 0061bcbd  50                   push eax
// 0061bcbe  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0061bcc1  52                   push edx
// 0061bcc2  50                   push eax
// 0061bcc3  e8b816f9ff           call 0x5ad380
// 0061bcc8  83c410               add esp, 0x10
// 0061bccb  c20800               ret 8

extern "C" void __cdecl Function005ad380(int, int, int, int);

struct LuaArguments
{
    void f(int, int);
};

void LuaArguments::f(int a, int b)
{
    Function005ad380(*(int*)((char*)this + 0x10), *(int*)((char*)this + 0x0c) + a, b, 1);
}
