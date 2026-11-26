// from server: 100% by Xemicl
// roc 2012-06 00432940  unit: ThreadLogManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00432940
//
// 00432940  56                   push esi
// 00432941  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00432945  56                   push esi
// 00432946  6a01                 push 1
// 00432948  e823edffff           call 0x431670
// 0043294d  8b442418             mov eax, dword ptr [esp + 0x18]
// 00432951  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00432955  83c408               add esp, 8
// 00432958  50                   push eax
// 00432959  6868cdc000           push 0xc0cd68
// 0043295e  6a00                 push 0
// 00432960  6a00                 push 0
// 00432962  56                   push esi
// 00432963  51                   push ecx
// 00432964  e867feffff           call 0x4327d0
// 00432969  5e                   pop esi
// 0043296a  c3                   ret 
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