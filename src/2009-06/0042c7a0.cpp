// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00433130  unit: VCFrameWnd::?$CXTPCommandBarsSiteBase  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00433130
//
// 00433130  8b442404             mov eax, dword ptr [esp + 4]
// 00433134  56                   push esi
// 00433135  50                   push eax
// 00433136  8bf1                 mov esi, ecx
// 00433138  e821df2600           call 0x6a105e
// 0043313d  83f8ff               cmp eax, -1
// 00433140  7506                 jne 0x433148
// 00433142  0bc0                 or eax, eax
// 00433144  5e                   pop esi
// 00433145  c20400               ret 4
// 00433148  8b16                 mov edx, dword ptr [esi]
// 0043314a  8b4274               mov eax, dword ptr [edx + 0x74]
// 0043314d  57                   push edi
// 0043314e  8bce                 mov ecx, esi
// 00433150  ffd0                 call eax
// 00433152  8bf8                 mov edi, eax
// 00433154  85ff                 test edi, edi
// 00433156  7420                 je 0x433178
// 00433158  8b4f04               mov ecx, dword ptr [edi + 4]
// 0043315b  51                   push ecx
// 0043315c  ff15482d8000         call dword ptr [0x802d48]
// 00433162  85c0                 test eax, eax
// 00433164  7412                 je 0x433178
// 00433166  8bcf                 mov ecx, edi
// 00433168  e8b3dd2600           call 0x6a0f20
// 0043316d  8b16                 mov edx, dword ptr [esi]
// 0043316f  8b4278               mov eax, dword ptr [edx + 0x78]
// 00433172  6a00                 push 0
// 00433174  8bce                 mov ecx, esi
// 00433176  ffd0                 call eax
// 00433178  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0043317b  6a01                 push 1
// 0043317d  6800e90000           push 0xe900
// 00433182  51                   push ecx
// 00433183  e8a0db2600           call 0x6a0d28
// 00433188  6a20                 push 0x20
// 0043318a  8bf0                 mov esi, eax
// 0043318c  6a00                 push 0
// 0043318e  6800008000           push 0x800000
// 00433193  8bce                 mov ecx, esi
// 00433195  e878dc2600           call 0x6a0e12
// 0043319a  6a20                 push 0x20
// 0043319c  6a00                 push 0
// 0043319e  6800020000           push 0x200
// 004331a3  8bce                 mov ecx, esi
// 004331a5  e88eda2600           call 0x6a0c38
// 004331aa  5f                   pop edi
// 004331ab  33c0                 xor eax, eax
// 004331ad  5e                   pop esi
// 004331ae  c20400               ret 4

struct Menu {
    unsigned int reserved;
    void* handle;
    void Destroy();
};

struct Window {
    void ModifyStyle(unsigned long remove, unsigned long add, unsigned int flags);
    void ModifyStyleEx(unsigned long remove, unsigned long add, unsigned int flags);
};

extern "C" int (__stdcall *IsMenu)(void* menu);
extern "C" __declspec(dllimport) void* __stdcall OpenEventA(unsigned long, int, const char*);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
extern Window* __stdcall FindWindow(void* parent, int id, int recursive);

struct Frame {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual Menu* GetMenu();
    virtual void SetMenu(Menu* menu);

    unsigned char reserved[28];
    void* handle;

    int BaseCreate(void* create);
    int OnCreate(void* create);
};

int Frame::OnCreate(void* create)
{
    int result = BaseCreate(create);
    if (result == -1)
        return result;

    Menu* menu = GetMenu();
    if (menu && IsMenu(menu->handle)) {
        menu->Destroy();
        SetMenu(0);
    }

    Window* window = FindWindow(handle, 0xe900, 1);
    window->ModifyStyle(0x800000, 0, 0x20);
    window->ModifyStyleEx(0x200, 0, 0x20);
    void* event = OpenEventA(2, 0, "www.roblox.com/robloxStartedEvent");
    if (event) {
        SetEvent(event);
        CloseHandle(event);
    }
    return 0;
}
