// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c8e70  unit: RBX::LaserTool  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c8e70
//
// 005c8e70  51                   push ecx
// 005c8e71  56                   push esi
// 005c8e72  8bf1                 mov esi, ecx
// 005c8e74  8b06                 mov eax, dword ptr [esi]
// 005c8e76  8b5040               mov edx, dword ptr [eax + 0x40]
// 005c8e79  c744240400000000     mov dword ptr [esp + 4], 0
// 005c8e81  ffd2                 call edx
// 005c8e83  81c638010000         add esi, 0x138
// 005c8e89  56                   push esi
// 005c8e8a  8b742410             mov esi, dword ptr [esp + 0x10]
// 005c8e8e  8bce                 mov ecx, esi
// 005c8e90  ff155c248000         call dword ptr [0x80245c]
// 005c8e96  8bc6                 mov eax, esi
// 005c8e98  5e                   pop esi
// 005c8e99  59                   pop ecx
// 005c8e9a  c20400               ret 4

struct String;

extern void (__thiscall *copyString)(String *, const String *);

struct LaserTool {
    String *getValue(String *result);
};

String *LaserTool::getValue(String *result)
{
    volatile int state = 0;
    (*(void (__thiscall **)(LaserTool *))(*(char **)this + 0x44))(this);
    copyString(result, (const String *)((char *)this + 0x98));
    return result;
}
