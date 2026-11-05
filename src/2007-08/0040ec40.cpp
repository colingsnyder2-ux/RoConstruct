// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00412b90  unit: CRbxChildFrame  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00412b90
//
// 00412b90  8b442404             mov eax, dword ptr [esp + 4]
// 00412b94  53                   push ebx
// 00412b95  50                   push eax
// 00412b96  8bd9                 mov ebx, ecx
// 00412b98  e87be22800           call 0x6a0e18
// 00412b9d  83f8ff               cmp eax, -1
// 00412ba0  7506                 jne 0x412ba8
// 00412ba2  0bc0                 or eax, eax
// 00412ba4  5b                   pop ebx
// 00412ba5  c20400               ret 4
// 00412ba8  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 00412bab  56                   push esi
// 00412bac  57                   push edi
// 00412bad  6a00                 push 0
// 00412baf  51                   push ecx
// 00412bb0  c783e800000000000000 mov dword ptr [ebx + 0xe8], 0
// 00412bba  ff15042e8000         call dword ptr [0x802e04]
// 00412bc0  50                   push eax
// 00412bc1  e85ce12800           call 0x6a0d22
// 00412bc6  8b3d082e8000         mov edi, dword ptr [0x802e08]
// 00412bcc  6a00                 push 0
// 00412bce  8bf0                 mov esi, eax
// 00412bd0  8b5604               mov edx, dword ptr [esi + 4]
// 00412bd3  6820f10000           push 0xf120
// 00412bd8  52                   push edx
// 00412bd9  ffd7                 call edi
// 00412bdb  8b4604               mov eax, dword ptr [esi + 4]
// 00412bde  6a00                 push 0
// 00412be0  6820f00000           push 0xf020
// 00412be5  50                   push eax
// 00412be6  ffd7                 call edi
// 00412be8  8b4e04               mov ecx, dword ptr [esi + 4]
// 00412beb  6a00                 push 0
// 00412bed  6830f00000           push 0xf030
// 00412bf2  51                   push ecx
// 00412bf3  ffd7                 call edi
// 00412bf5  8b5604               mov edx, dword ptr [esi + 4]
// 00412bf8  6a00                 push 0
// 00412bfa  6810f00000           push 0xf010
// 00412bff  52                   push edx
// 00412c00  ffd7                 call edi
// 00412c02  8b4604               mov eax, dword ptr [esi + 4]
// 00412c05  6a00                 push 0
// 00412c07  6800f00000           push 0xf000
// 00412c0c  50                   push eax
// 00412c0d  ffd7                 call edi
// 00412c0f  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 00412c12  6a01                 push 1
// 00412c14  6800e90000           push 0xe900
// 00412c19  51                   push ecx
// 00412c1a  e809e12800           call 0x6a0d28
// 00412c1f  6a00                 push 0
// 00412c21  8bf0                 mov esi, eax
// 00412c23  6a00                 push 0
// 00412c25  6800008000           push 0x800000
// 00412c2a  8bce                 mov ecx, esi
// 00412c2c  e8e1e12800           call 0x6a0e12
// 00412c31  6a20                 push 0x20
// 00412c33  6a00                 push 0
// 00412c35  6800020000           push 0x200
// 00412c3a  8bce                 mov ecx, esi
// 00412c3c  e8f7df2800           call 0x6a0c38
// 00412c41  5f                   pop edi
// 00412c42  5e                   pop esi
// 00412c43  33c0                 xor eax, eax
// 00412c45  5b                   pop ebx
// 00412c46  c20400               ret 4

typedef void* HANDLE;
typedef unsigned int UINT;
typedef unsigned long DWORD;

extern "C" HANDLE (__stdcall *GetSystemMenu)(HANDLE, int);
extern "C" int (__stdcall *RemoveMenu)(HANDLE, UINT, UINT);

struct Menu {
    DWORD unused;
    HANDLE handle;
    static Menu* __stdcall FromHandle(HANDLE);
};

struct Window {
    char padding[0x20];
    HANDLE handle;
    char padding2[0xC4];
    int autoMenuEnable;

    int OnCreate(void*);
    static Window* __stdcall GetDlgItem(HANDLE, int, int);
    int ModifyStyle(DWORD, DWORD, UINT);
    long SendMessage(UINT, unsigned int, long);
};

struct ChildFrame : Window {
    int OnCreate(void*);
};

int ChildFrame::OnCreate(void* create)
{
    int result = Window::OnCreate(create);
    if (result == -1)
        return result;

    autoMenuEnable = 0;
    Menu* menu = Menu::FromHandle(GetSystemMenu(handle, 0));
    int (__stdcall *remove)(HANDLE, UINT, UINT) = RemoveMenu;
    remove(menu->handle, 0xF120, 0);
    remove(menu->handle, 0xF020, 0);
    remove(menu->handle, 0xF030, 0);
    remove(menu->handle, 0xF010, 0);
    remove(menu->handle, 0xF000, 0);

    Window* window = Window::GetDlgItem(handle, 0xE900, 1);
    window->ModifyStyle(0x800000, 0, 0);
    window->SendMessage(0x200, 0, 0x20);
    return 0;
}
