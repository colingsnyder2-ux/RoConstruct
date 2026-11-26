// from server: 100% by Xemicl
// roc 2012-06 00418560  unit: CRbxChildFrame  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00418560
//
// 00418560  8b442404             mov eax, dword ptr [esp + 4]
// 00418564  53                   push ebx
// 00418565  50                   push eax
// 00418566  8bd9                 mov ebx, ecx
// 00418568  e8f1a25600           call 0x98285e
// 0041856d  83f8ff               cmp eax, -1
// 00418570  7506                 jne 0x418578
// 00418572  0bc0                 or eax, eax
// 00418574  5b                   pop ebx
// 00418575  c20400               ret 4
// 00418578  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 0041857b  56                   push esi
// 0041857c  57                   push edi
// 0041857d  6a00                 push 0
// 0041857f  51                   push ecx
// 00418580  c783e800000000000000 mov dword ptr [ebx + 0xe8], 0
// 0041858a  ff15e03bb200         call dword ptr [0xb23be0]
// 00418590  50                   push eax
// 00418591  e8d2a15600           call 0x982768
// 00418596  8b3de43bb200         mov edi, dword ptr [0xb23be4]
// 0041859c  6a00                 push 0
// 0041859e  8bf0                 mov esi, eax
// 004185a0  8b5604               mov edx, dword ptr [esi + 4]
// 004185a3  6820f10000           push 0xf120
// 004185a8  52                   push edx
// 004185a9  ffd7                 call edi
// 004185ab  8b4604               mov eax, dword ptr [esi + 4]
// 004185ae  6a00                 push 0
// 004185b0  6820f00000           push 0xf020
// 004185b5  50                   push eax
// 004185b6  ffd7                 call edi
// 004185b8  8b4e04               mov ecx, dword ptr [esi + 4]
// 004185bb  6a00                 push 0
// 004185bd  6830f00000           push 0xf030
// 004185c2  51                   push ecx
// 004185c3  ffd7                 call edi
// 004185c5  8b5604               mov edx, dword ptr [esi + 4]
// 004185c8  6a00                 push 0
// 004185ca  6810f00000           push 0xf010
// 004185cf  52                   push edx
// 004185d0  ffd7                 call edi
// 004185d2  8b4604               mov eax, dword ptr [esi + 4]
// 004185d5  6a00                 push 0
// 004185d7  6800f00000           push 0xf000
// 004185dc  50                   push eax
// 004185dd  ffd7                 call edi
// 004185df  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 004185e2  6a01                 push 1
// 004185e4  6800e90000           push 0xe900
// 004185e9  51                   push ecx
// 004185ea  e87fa15600           call 0x98276e
// 004185ef  6a00                 push 0
// 004185f1  8bf0                 mov esi, eax
// 004185f3  6a00                 push 0
// 004185f5  6800008000           push 0x800000
// 004185fa  8bce                 mov ecx, esi
// 004185fc  e857a25600           call 0x982858
// 00418601  6a20                 push 0x20
// 00418603  6a00                 push 0
// 00418605  6800020000           push 0x200
// 0041860a  8bce                 mov ecx, esi
// 0041860c  e8a3a05600           call 0x9826b4
// 00418611  5f                   pop edi
// 00418612  5e                   pop esi
// 00418613  33c0                 xor eax, eax
// 00418615  5b                   pop ebx
// 00418616  c20400               ret 4
// copied from an identical function in another client (function ?OnCreate@ChildFrame@ns_ROCX00000b@@QAEHPAX@Z)

namespace ns_ROCX00000b {
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
}