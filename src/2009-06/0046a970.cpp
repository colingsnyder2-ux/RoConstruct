// from server: 97% by EspClaude
// from server: 100% by EspClaude
// roc 2008-06 004680c0  unit: DxUserInput  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004680c0
//
// 004680c0  6aff                 push -1
// 004680c2  688e367c00           push 0x7c368e
// 004680c7  64a100000000         mov eax, dword ptr fs:[0]
// 004680cd  50                   push eax
// 004680ce  64892500000000       mov dword ptr fs:[0], esp
// 004680d5  83ec10               sub esp, 0x10
// 004680d8  56                   push esi
// 004680d9  8bf1                 mov esi, ecx
// 004680db  8b8678010000         mov eax, dword ptr [esi + 0x178]
// 004680e1  8b08                 mov ecx, dword ptr [eax]
// 004680e3  8b5120               mov edx, dword ptr [ecx + 0x20]
// 004680e6  57                   push edi
// 004680e7  50                   push eax
// 004680e8  ffd2                 call edx
// 004680ea  8d442410             lea eax, [esp + 0x10]
// 004680ee  50                   push eax
// 004680ef  8bce                 mov ecx, esi
// 004680f1  e85afaffff           call 0x467b50
// 004680f6  d9442414             fld dword ptr [esp + 0x14]
// 004680fa  e8f1962300           call 0x6a17f0
// 004680ff  d9442410             fld dword ptr [esp + 0x10]
// 00468103  8bf8                 mov edi, eax
// 00468105  e8e6962300           call 0x6a17f0
// 0046810a  89442408             mov dword ptr [esp + 8], eax
// 0046810e  8b866c010000         mov eax, dword ptr [esi + 0x16c]
// 00468114  8d4c2408             lea ecx, [esp + 8]
// 00468118  897c240c             mov dword ptr [esp + 0xc], edi
// 0046811c  8b5020               mov edx, dword ptr [eax + 0x20]
// 0046811f  51                   push ecx
// 00468120  52                   push edx
// 00468121  ff15802d8000         call dword ptr [0x802d80]
// 00468127  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046812b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0046812f  50                   push eax
// 00468130  51                   push ecx
// 00468131  ff15002d8000         call dword ptr [0x802d00]
// 00468137  f605e0df960001       test byte ptr [0x96dfe0], 1
// 0046813e  7526                 jne 0x468166
// 00468140  830de0df960001       or dword ptr [0x96dfe0], 1
// 00468147  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0046814f  e8d2872300           call 0x6a0926
// 00468154  68007f0000           push 0x7f00
// 00468159  6a00                 push 0
// 0046815b  ff15d02d8000         call dword ptr [0x802dd0]
// 00468161  a3dcdf9600           mov dword ptr [0x96dfdc], eax
// 00468166  8b15dcdf9600         mov edx, dword ptr [0x96dfdc]
// 0046816c  52                   push edx
// 0046816d  ff15042d8000         call dword ptr [0x802d04]
// 00468173  8b866c010000         mov eax, dword ptr [esi + 0x16c]
// 00468179  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0046817c  6a01                 push 1
// 0046817e  6a00                 push 0
// 00468180  51                   push ecx
// 00468181  ff15182e8000         call dword ptr [0x802e18]
// 00468187  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0046818b  c6869201000000       mov byte ptr [esi + 0x192], 0
// 00468192  c6465900             mov byte ptr [esi + 0x59], 0
// 00468196  5f                   pop edi
// 00468197  5e                   pop esi
// 00468198  64890d00000000       mov dword ptr fs:[0], ecx
// 0046819f  83c41c               add esp, 0x1c
// 004681a2  c3                   ret 

// from server: 92% by Espeon
// roc 2008-06 004680c0  unit: DxUserInput  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004680c0
//
// 004680c0  6aff                 push -1
// 004680c2  688e367c00           push 0x7c368e
// 004680c7  64a100000000         mov eax, dword ptr fs:[0]
// 004680cd  50                   push eax
// 004680ce  64892500000000       mov dword ptr fs:[0], esp
// 004680d5  83ec10               sub esp, 0x10
// 004680d8  56                   push esi
// 004680d9  8bf1                 mov esi, ecx
// 004680db  8b8678010000         mov eax, dword ptr [esi + 0x178]
// 004680e1  8b08                 mov ecx, dword ptr [eax]
// 004680e3  8b5120               mov edx, dword ptr [ecx + 0x20]
// 004680e6  57                   push edi
// 004680e7  50                   push eax
// 004680e8  ffd2                 call edx
// 004680ea  8d442410             lea eax, [esp + 0x10]
// 004680ee  50                   push eax
// 004680ef  8bce                 mov ecx, esi
// 004680f1  e85afaffff           call 0x467b50
// 004680f6  d9442414             fld dword ptr [esp + 0x14]
// 004680fa  e8f1962300           call 0x6a17f0
// 004680ff  d9442410             fld dword ptr [esp + 0x10]
// 00468103  8bf8                 mov edi, eax
// 00468105  e8e6962300           call 0x6a17f0
// 0046810a  89442408             mov dword ptr [esp + 8], eax
// 0046810e  8b866c010000         mov eax, dword ptr [esi + 0x16c]
// 00468114  8d4c2408             lea ecx, [esp + 8]
// 00468118  897c240c             mov dword ptr [esp + 0xc], edi
// 0046811c  8b5020               mov edx, dword ptr [eax + 0x20]
// 0046811f  51                   push ecx
// 00468120  52                   push edx
// 00468121  ff15802d8000         call dword ptr [0x802d80]
// 00468127  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046812b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0046812f  50                   push eax
// 00468130  51                   push ecx
// 00468131  ff15002d8000         call dword ptr [0x802d00]
// 00468137  f605e0df960001       test byte ptr [0x96dfe0], 1
// 0046813e  7526                 jne 0x468166
// 00468140  830de0df960001       or dword ptr [0x96dfe0], 1
// 00468147  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0046814f  e8d2872300           call 0x6a0926
// 00468154  68007f0000           push 0x7f00
// 00468159  6a00                 push 0
// 0046815b  ff15d02d8000         call dword ptr [0x802dd0]
// 00468161  a3dcdf9600           mov dword ptr [0x96dfdc], eax
// 00468166  8b15dcdf9600         mov edx, dword ptr [0x96dfdc]
// 0046816c  52                   push edx
// 0046816d  ff15042d8000         call dword ptr [0x802d04]
// 00468173  8b866c010000         mov eax, dword ptr [esi + 0x16c]
// 00468179  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0046817c  6a01                 push 1
// 0046817e  6a00                 push 0
// 00468180  51                   push ecx
// 00468181  ff15182e8000         call dword ptr [0x802e18]
// 00468187  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0046818b  c6869201000000       mov byte ptr [esi + 0x192], 0
// 00468192  c6465900             mov byte ptr [esi + 0x59], 0
// 00468196  5f                   pop edi
// 00468197  5e                   pop esi
// 00468198  64890d00000000       mov dword ptr fs:[0], ecx
// 0046819f  83c41c               add esp, 0x1c
// 004681a2  c3                   ret 

// from server: 82% by king_originala
struct Point {
    int x;
    int y;
};

struct Vec2 {
    float x;
    float y;
};

extern "C" __declspec(dllimport) int __stdcall ClientToScreen(void *, Point *);
extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int, int);
extern "C" __declspec(dllimport) void* __stdcall LoadCursorA(void *, const char *);
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void *);
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(void *, const void *, int);

extern void initializeCursor();

struct Device;
struct DeviceTable {
    void *slots[8];
    long (__stdcall *unacquire)(Device *);
};

struct Device {
    DeviceTable *table;
};

struct Window {
    char padding[0x20];
    void *handle;
    void clientToScreen(Point *p) { ClientToScreen(handle, p); }
};

struct DxUserInput {
    char padding0[0x59];
    unsigned char flag59;
    char padding1[0x112];
    Window *window;
    char padding2[8];
    Device *device;
    char padding3[0x16];
    unsigned char flag192;

    Vec2 *getPosition(Vec2 *);
    void *getHandle() const { return window->handle; }
    void releaseInput();
};

void DxUserInput::releaseInput()
{
    device->table->unacquire(device);

    Vec2 position;
    getPosition(&position);

    Point point;
    int y = (int)position.y;
    point.x = (int)position.x;
    point.y = y;

    window->clientToScreen(&point);
    SetCursorPos(point.x, point.y);

    static void *cursor =
        (initializeCursor(), LoadCursorA(0, (const char *)0x7f00));

    SetCursor(cursor);
    InvalidateRect(getHandle(), 0, 1);
    flag192 = 0;
    flag59 = 0;
}
