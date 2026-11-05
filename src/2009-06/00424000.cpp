// from server: 100% by EspClaude
// roc 2009-06 00424000  unit: MainLogManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424000
//
// 00424000  56                   push esi
// 00424001  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00424005  56                   push esi
// 00424006  6a01                 push 1
// 00424008  e8d3edffff           call 0x422de0
// 0042400d  8b442418             mov eax, dword ptr [esp + 0x18]
// 00424011  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00424015  83c408               add esp, 8
// 00424018  50                   push eax
// 00424019  6880128f00           push 0x8f1280
// 0042401e  6a00                 push 0
// 00424020  6a00                 push 0
// 00424022  56                   push esi
// 00424023  51                   push ecx
// 00424024  e867feffff           call 0x423e90
// 00424029  5e                   pop esi
// 0042402a  c3                   ret 
// copied from an identical function in another client (function ?logMessage@ns_ROCX0000ad@@YAXHHH@Z)

namespace ns_ROCX0000ad {
extern "C" void __cdecl prepareLog(int, int);
extern "C" void __stdcall writeLog(int, int, int, int, const char*, int);
extern const char logFormat[];

void __cdecl logMessage(int context, int value, int argument)
{
    prepareLog(1, value);
    writeLog(context, value, 0, 0, logFormat, argument);
}
}
