// from server: 100% by EspClaude
// roc 2009-06 0040d0c0  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040d0c0
//
// 0040d0c0  53                   push ebx
// 0040d0c1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0040d0c5  55                   push ebp
// 0040d0c6  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0040d0ca  56                   push esi
// 0040d0cb  8bf1                 mov esi, ecx
// 0040d0cd  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0040d0d3  57                   push edi
// 0040d0d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0040d0d8  85c9                 test ecx, ecx
// 0040d0da  741d                 je 0x40d0f9
// 0040d0dc  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040d0e0  57                   push edi
// 0040d0e1  53                   push ebx
// 0040d0e2  55                   push ebp
// 0040d0e3  50                   push eax
// 0040d0e4  e827e53100           call 0x72b610
// 0040d0e9  85c0                 test eax, eax
// 0040d0eb  740c                 je 0x40d0f9
// 0040d0ed  5f                   pop edi
// 0040d0ee  5e                   pop esi
// 0040d0ef  5d                   pop ebp
// 0040d0f0  b801000000           mov eax, 1
// 0040d0f5  5b                   pop ebx
// 0040d0f6  c21000               ret 0x10
// 0040d0f9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0040d0fd  57                   push edi
// 0040d0fe  53                   push ebx
// 0040d0ff  55                   push ebp
// 0040d100  51                   push ecx
// 0040d101  8bce                 mov ecx, esi
// 0040d103  e8aaba3000           call 0x718bb2
// 0040d108  5f                   pop edi
// 0040d109  5e                   pop esi
// 0040d10a  5d                   pop ebp
// 0040d10b  5b                   pop ebx
// 0040d10c  c21000               ret 0x10
// copied from an identical function in another client (function ?OnCmdMsg@View@ns_ROCX000001@@QAEHIHPAX0@Z)

namespace ns_ROCX000001 {
struct CommandBars {
    int OnCmdMsg(unsigned int id, int code, void* extra, void* handlerInfo);
};

struct View {
    char reserved[0xF8];
    CommandBars* commandBars;

    int OnCmdMsg(unsigned int id, int code, void* extra, void* handlerInfo);
    int BaseOnCmdMsg(unsigned int id, int code, void* extra, void* handlerInfo);
};

int View::OnCmdMsg(unsigned int id, int code, void* extra, void* handlerInfo)
{
    if (commandBars && commandBars->OnCmdMsg(id, code, extra, handlerInfo))
        return 1;

    return BaseOnCmdMsg(id, code, extra, handlerInfo);
}
}
