// from server: 100% by Yeetserama
// roc 2010-06 0040d4c0  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040d4c0
//
// 0040d4c0  53                   push ebx
// 0040d4c1  56                   push esi
// 0040d4c2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0040d4c6  8b4604               mov eax, dword ptr [esi + 4]
// 0040d4c9  57                   push edi
// 0040d4ca  8bd9                 mov ebx, ecx
// 0040d4cc  3d00010000           cmp eax, 0x100
// 0040d4d1  723c                 jb 0x40d50f
// 0040d4d3  3d09010000           cmp eax, 0x109
// 0040d4d8  7735                 ja 0x40d50f
// 0040d4da  8b4608               mov eax, dword ptr [esi + 8]
// 0040d4dd  83f80d               cmp eax, 0xd
// 0040d4e0  742d                 je 0x40d50f
// 0040d4e2  83f809               cmp eax, 9
// 0040d4e5  7428                 je 0x40d50f
// 0040d4e7  83f81b               cmp eax, 0x1b
// 0040d4ea  7423                 je 0x40d50f
// 0040d4ec  ff1580ba9e00         call dword ptr [0x9eba80]
// 0040d4f2  50                   push eax
// 0040d4f3  e872a73900           call 0x7a7c6a
// 0040d4f8  8bf8                 mov edi, eax
// 0040d4fa  85ff                 test edi, edi
// 0040d4fc  7411                 je 0x40d50f
// 0040d4fe  e8dd673a00           call 0x7b3ce0
// 0040d503  50                   push eax
// 0040d504  8bcf                 mov ecx, edi
// 0040d506  e81daa3900           call 0x7a7f28
// 0040d50b  85c0                 test eax, eax
// 0040d50d  752b                 jne 0x40d53a
// 0040d50f  56                   push esi
// 0040d510  8bcb                 mov ecx, ebx
// 0040d512  e80baa3900           call 0x7a7f22
// 0040d517  85c0                 test eax, eax
// 0040d519  740b                 je 0x40d526
// 0040d51b  5f                   pop edi
// 0040d51c  5e                   pop esi
// 0040d51d  b801000000           mov eax, 1
// 0040d522  5b                   pop ebx
// 0040d523  c20400               ret 4
// 0040d526  8b8bf8000000         mov ecx, dword ptr [ebx + 0xf8]
// 0040d52c  85c9                 test ecx, ecx
// 0040d52e  740a                 je 0x40d53a
// 0040d530  56                   push esi
// 0040d531  e80acc3b00           call 0x7ca140
// 0040d536  85c0                 test eax, eax
// 0040d538  75e1                 jne 0x40d51b
// 0040d53a  5f                   pop edi
// 0040d53b  5e                   pop esi
// 0040d53c  33c0                 xor eax, eax
// 0040d53e  5b                   pop ebx
// 0040d53f  c20400               ret 4
// copied from an identical function in another client (function ?PreTranslateMessage@View@ns_ROCX00001e@@QAEHPAUMessage@2@@Z)

namespace ns_ROCX00001e {
// from server: 100% by king_originala
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
