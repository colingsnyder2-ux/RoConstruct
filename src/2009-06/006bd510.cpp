// from server: 100% by EspClaude
// from server: 100% by atomic.potato
// roc 2008-06 0061c790  unit: RBX::Lua::LuaArguments  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0061c790
//
// 0061c790  8b442408             mov eax, dword ptr [esp + 8]
// 0061c794  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0061c798  6a00                 push 0
// 0061c79a  50                   push eax
// 0061c79b  51                   push ecx
// 0061c79c  e86f58ffff           call 0x612010
// 0061c7a1  83c40c               add esp, 0xc
// 0061c7a4  85c0                 test eax, eax
// 0061c7a6  7505                 jne 0x61c7ad
// 0061c7a8  a1ccb19500           mov eax, dword ptr [0x95b1cc]
// 0061c7ad  c3                   ret 

typedef int FunctionType(int, int, int);

extern FunctionType g_function;
extern int g_value;

struct S
{
};

int __cdecl f(int a, int b)
{
    int result = g_function(a, b, 0);
    if (!result)
        result = g_value;
    return result;
}
