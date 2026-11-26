// from server: 100% by Xemicl
// roc 2012-06 00415b50  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00415b50
//
// 00415b50  53                   push ebx
// 00415b51  56                   push esi
// 00415b52  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00415b56  8b4604               mov eax, dword ptr [esi + 4]
// 00415b59  57                   push edi
// 00415b5a  8bd9                 mov ebx, ecx
// 00415b5c  3d00010000           cmp eax, 0x100
// 00415b61  723c                 jb 0x415b9f
// 00415b63  3d09010000           cmp eax, 0x109
// 00415b68  7735                 ja 0x415b9f
// 00415b6a  8b4608               mov eax, dword ptr [esi + 8]
// 00415b6d  83f80d               cmp eax, 0xd
// 00415b70  742d                 je 0x415b9f
// 00415b72  83f809               cmp eax, 9
// 00415b75  7428                 je 0x415b9f
// 00415b77  83f81b               cmp eax, 0x1b
// 00415b7a  7423                 je 0x415b9f
// 00415b7c  ff15e83bb200         call dword ptr [0xb23be8]
// 00415b82  50                   push eax
// 00415b83  e8deca5600           call 0x982666
// 00415b88  8bf8                 mov edi, eax
// 00415b8a  85ff                 test edi, edi
// 00415b8c  7411                 je 0x415b9f
// 00415b8e  e80d885700           call 0x98e3a0
// 00415b93  50                   push eax
// 00415b94  8bcf                 mov ecx, edi
// 00415b96  e8fbca5600           call 0x982696
// 00415b9b  85c0                 test eax, eax
// 00415b9d  752b                 jne 0x415bca
// 00415b9f  56                   push esi
// 00415ba0  8bcb                 mov ecx, ebx
// 00415ba2  e8e9ca5600           call 0x982690
// 00415ba7  85c0                 test eax, eax
// 00415ba9  740b                 je 0x415bb6
// 00415bab  5f                   pop edi
// 00415bac  5e                   pop esi
// 00415bad  b801000000           mov eax, 1
// 00415bb2  5b                   pop ebx
// 00415bb3  c20400               ret 4
// 00415bb6  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 00415bbc  85c9                 test ecx, ecx
// 00415bbe  740a                 je 0x415bca
// 00415bc0  56                   push esi
// 00415bc1  e8fae55800           call 0x9a41c0
// 00415bc6  85c0                 test eax, eax
// 00415bc8  75e1                 jne 0x415bab
// 00415bca  5f                   pop edi
// 00415bcb  5e                   pop esi
// 00415bcc  33c0                 xor eax, eax
// 00415bce  5b                   pop ebx
// 00415bcf  c20400               ret 4
// copied from an identical function in another client (function ?PreTranslateMessage@View@ns_ROCX000000@@QAEHPAUMessage@2@@Z)

namespace ns_ROCX000000 {
struct Message {
    void* window;
    unsigned int message;
    unsigned int wParam;
};

extern "C" void* (__stdcall *GetFocus)();
extern char* GetViewClass();

struct Window {
    static Window* __stdcall FromHandle(void* window);
    int IsKindOf(char* type);
};

struct CommandBars {
    int PreTranslateMessage(Message* message);
};

struct View {
    char reserved[0xF8];
    CommandBars* commandBars;

    int PreTranslateMessage(Message* message);
    int BasePreTranslateMessage(Message* message);
};

int View::PreTranslateMessage(Message* message)
{
    if (message->message >= 0x100 && message->message <= 0x109 &&
        message->wParam != 13 && message->wParam != 9 &&
        message->wParam != 27)
    {
        Window* focused = Window::FromHandle(GetFocus());
        if (focused && focused->IsKindOf(GetViewClass()))
            return 0;
    }

    if (BasePreTranslateMessage(message))
        return 1;

    if (commandBars && commandBars->PreTranslateMessage(message))
        return 1;

    return 0;
}
}