// from server: 100% by EspClaude
// roc 2009-06 0040d030  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040d030
//
// 0040d030  53                   push ebx
// 0040d031  56                   push esi
// 0040d032  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0040d036  8b4604               mov eax, dword ptr [esi + 4]
// 0040d039  57                   push edi
// 0040d03a  8bd9                 mov ebx, ecx
// 0040d03c  3d00010000           cmp eax, 0x100
// 0040d041  723c                 jb 0x40d07f
// 0040d043  3d09010000           cmp eax, 0x109
// 0040d048  7735                 ja 0x40d07f
// 0040d04a  8b4608               mov eax, dword ptr [esi + 8]
// 0040d04d  83f80d               cmp eax, 0xd
// 0040d050  742d                 je 0x40d07f
// 0040d052  83f809               cmp eax, 9
// 0040d055  7428                 je 0x40d07f
// 0040d057  83f81b               cmp eax, 0x1b
// 0040d05a  7423                 je 0x40d07f
// 0040d05c  ff1578ee8900         call dword ptr [0x89ee78]
// 0040d062  50                   push eax
// 0040d063  e89abc3000           call 0x718d02
// 0040d068  8bf8                 mov edi, eax
// 0040d06a  85ff                 test edi, edi
// 0040d06c  7411                 je 0x40d07f
// 0040d06e  e88ddc3000           call 0x71ad00
// 0040d073  50                   push eax
// 0040d074  8bcf                 mov ecx, edi
// 0040d076  e839bf3000           call 0x718fb4
// 0040d07b  85c0                 test eax, eax
// 0040d07d  752b                 jne 0x40d0aa
// 0040d07f  56                   push esi
// 0040d080  8bcb                 mov ecx, ebx
// 0040d082  e827bf3000           call 0x718fae
// 0040d087  85c0                 test eax, eax
// 0040d089  740b                 je 0x40d096
// 0040d08b  5f                   pop edi
// 0040d08c  5e                   pop esi
// 0040d08d  b801000000           mov eax, 1
// 0040d092  5b                   pop ebx
// 0040d093  c20400               ret 4
// 0040d096  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 0040d09c  85c9                 test ecx, ecx
// 0040d09e  740a                 je 0x40d0aa
// 0040d0a0  56                   push esi
// 0040d0a1  e81ae33100           call 0x72b3c0
// 0040d0a6  85c0                 test eax, eax
// 0040d0a8  75e1                 jne 0x40d08b
// 0040d0aa  5f                   pop edi
// 0040d0ab  5e                   pop esi
// 0040d0ac  33c0                 xor eax, eax
// 0040d0ae  5b                   pop ebx
// 0040d0af  c20400               ret 4
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
