// from server: 100% by EspClaude
// roc 2009-06 00410e70  unit: CRbxChildFrame  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00410e70
//
// 00410e70  8b442404             mov eax, dword ptr [esp + 4]
// 00410e74  53                   push ebx
// 00410e75  50                   push eax
// 00410e76  8bd9                 mov ebx, ecx
// 00410e78  e83b833000           call 0x7191b8
// 00410e7d  83f8ff               cmp eax, -1
// 00410e80  7506                 jne 0x410e88
// 00410e82  0bc0                 or eax, eax
// 00410e84  5b                   pop ebx
// 00410e85  c20400               ret 4
// 00410e88  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 00410e8b  56                   push esi
// 00410e8c  57                   push edi
// 00410e8d  6a00                 push 0
// 00410e8f  51                   push ecx
// 00410e90  c783e800000000000000 mov dword ptr [ebx + 0xe8], 0
// 00410e9a  ff1570ee8900         call dword ptr [0x89ee70]
// 00410ea0  50                   push eax
// 00410ea1  e81c823000           call 0x7190c2
// 00410ea6  8b3d74ee8900         mov edi, dword ptr [0x89ee74]
// 00410eac  6a00                 push 0
// 00410eae  8bf0                 mov esi, eax
// 00410eb0  8b5604               mov edx, dword ptr [esi + 4]
// 00410eb3  6820f10000           push 0xf120
// 00410eb8  52                   push edx
// 00410eb9  ffd7                 call edi
// 00410ebb  8b4604               mov eax, dword ptr [esi + 4]
// 00410ebe  6a00                 push 0
// 00410ec0  6820f00000           push 0xf020
// 00410ec5  50                   push eax
// 00410ec6  ffd7                 call edi
// 00410ec8  8b4e04               mov ecx, dword ptr [esi + 4]
// 00410ecb  6a00                 push 0
// 00410ecd  6830f00000           push 0xf030
// 00410ed2  51                   push ecx
// 00410ed3  ffd7                 call edi
// 00410ed5  8b5604               mov edx, dword ptr [esi + 4]
// 00410ed8  6a00                 push 0
// 00410eda  6810f00000           push 0xf010
// 00410edf  52                   push edx
// 00410ee0  ffd7                 call edi
// 00410ee2  8b4604               mov eax, dword ptr [esi + 4]
// 00410ee5  6a00                 push 0
// 00410ee7  6800f00000           push 0xf000
// 00410eec  50                   push eax
// 00410eed  ffd7                 call edi
// 00410eef  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 00410ef2  6a01                 push 1
// 00410ef4  6800e90000           push 0xe900
// 00410ef9  51                   push ecx
// 00410efa  e8c9813000           call 0x7190c8
// 00410eff  6a00                 push 0
// 00410f01  8bf0                 mov esi, eax
// 00410f03  6a00                 push 0
// 00410f05  6800008000           push 0x800000
// 00410f0a  8bce                 mov ecx, esi
// 00410f0c  e8a1823000           call 0x7191b2
// 00410f11  6a20                 push 0x20
// 00410f13  6a00                 push 0
// 00410f15  6800020000           push 0x200
// 00410f1a  8bce                 mov ecx, esi
// 00410f1c  e8b7803000           call 0x718fd8
// 00410f21  5f                   pop edi
// 00410f22  5e                   pop esi
// 00410f23  33c0                 xor eax, eax
// 00410f25  5b                   pop ebx
// 00410f26  c20400               ret 4
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
