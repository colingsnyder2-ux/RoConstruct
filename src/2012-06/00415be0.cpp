// from server: 100% by Xemicl
// roc 2012-06 00415be0  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00415be0
//
// 00415be0  53                   push ebx
// 00415be1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00415be5  55                   push ebp
// 00415be6  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00415bea  56                   push esi
// 00415beb  8bf1                 mov esi, ecx
// 00415bed  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 00415bf3  57                   push edi
// 00415bf4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00415bf8  85c9                 test ecx, ecx
// 00415bfa  741d                 je 0x415c19
// 00415bfc  8b442414             mov eax, dword ptr [esp + 0x14]
// 00415c00  57                   push edi
// 00415c01  53                   push ebx
// 00415c02  55                   push ebp
// 00415c03  50                   push eax
// 00415c04  e807e85800           call 0x9a4410
// 00415c09  85c0                 test eax, eax
// 00415c0b  740c                 je 0x415c19
// 00415c0d  5f                   pop edi
// 00415c0e  5e                   pop esi
// 00415c0f  5d                   pop ebp
// 00415c10  b801000000           mov eax, 1
// 00415c15  5b                   pop ebx
// 00415c16  c21000               ret 0x10
// 00415c19  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00415c1d  57                   push edi
// 00415c1e  53                   push ebx
// 00415c1f  55                   push ebp
// 00415c20  51                   push ecx
// 00415c21  8bce                 mov ecx, esi
// 00415c23  e86cc65600           call 0x982294
// 00415c28  5f                   pop edi
// 00415c29  5e                   pop esi
// 00415c2a  5d                   pop ebp
// 00415c2b  5b                   pop ebx
// 00415c2c  c21000               ret 0x10
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