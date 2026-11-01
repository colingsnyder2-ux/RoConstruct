// from server: 100% by king_originala
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
