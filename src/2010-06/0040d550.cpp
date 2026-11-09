// from server: 100% by Yeetserama
// roc 2010-06 0040d550  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040d550
//
// 0040d550  53                   push ebx
// 0040d551  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0040d555  55                   push ebp
// 0040d556  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0040d55a  56                   push esi
// 0040d55b  8bf1                 mov esi, ecx
// 0040d55d  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0040d563  57                   push edi
// 0040d564  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0040d568  85c9                 test ecx, ecx
// 0040d56a  741d                 je 0x40d589
// 0040d56c  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040d570  57                   push edi
// 0040d571  53                   push ebx
// 0040d572  55                   push ebp
// 0040d573  50                   push eax
// 0040d574  e817ce3b00           call 0x7ca390
// 0040d579  85c0                 test eax, eax
// 0040d57b  740c                 je 0x40d589
// 0040d57d  5f                   pop edi
// 0040d57e  5e                   pop esi
// 0040d57f  5d                   pop ebp
// 0040d580  b801000000           mov eax, 1
// 0040d585  5b                   pop ebx
// 0040d586  c21000               ret 0x10
// 0040d589  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0040d58d  57                   push edi
// 0040d58e  53                   push ebx
// 0040d58f  55                   push ebp
// 0040d590  51                   push ecx
// 0040d591  8bce                 mov ecx, esi
// 0040d593  e882a53900           call 0x7a7b1a
// 0040d598  5f                   pop edi
// 0040d599  5e                   pop esi
// 0040d59a  5d                   pop ebp
// 0040d59b  5b                   pop ebx
// 0040d59c  c21000               ret 0x10
// copied from an identical function in another client (function ?OnCmdMsg@View@ns_ROCX00001f@@QAEHIHPAX0@Z)

namespace ns_ROCX00001f {
// from server: 100% by king_originala
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
