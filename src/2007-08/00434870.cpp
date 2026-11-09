// from server: 100% by Yeetserama
// roc 2007-08 00434870  unit: CObjectBrowser  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434870
//
// 00434870  6aff                 push -1
// 00434872  6808e07300           push 0x73e008
// 00434877  64a100000000         mov eax, dword ptr fs:[0]
// 0043487d  50                   push eax
// 0043487e  83ec08               sub esp, 8
// 00434881  a188518b00           mov eax, dword ptr [0x8b5188]
// 00434886  33c4                 xor eax, esp
// 00434888  50                   push eax
// 00434889  8d44240c             lea eax, [esp + 0xc]
// 0043488d  64a300000000         mov dword ptr fs:[0], eax
// 00434893  6a01                 push 1
// 00434895  6a00                 push 0
// 00434897  6a19                 push 0x19
// 00434899  6a10                 push 0x10
// 0043489b  6a10                 push 0x10
// 0043489d  8bce                 mov ecx, esi
// 0043489f  e8febb1f00           call 0x6304a2
// 004348a4  85c0                 test eax, eax
// 004348a6  7510                 jne 0x4348b8
// 004348a8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004348ac  64890d00000000       mov dword ptr fs:[0], ecx
// 004348b3  59                   pop ecx
// 004348b4  83c414               add esp, 0x14
// 004348b7  c3                   ret 
// 004348b8  c744240800000000     mov dword ptr [esp + 8], 0
// 004348c0  c744240400837800     mov dword ptr [esp + 4], 0x788300
// 004348c8  0fb744241c           movzx eax, word ptr [esp + 0x1c]
// 004348cd  50                   push eax
// 004348ce  6a02                 push 2
// 004348d0  50                   push eax
// 004348d1  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004348d9  e89abb1f00           call 0x630478
// 004348de  50                   push eax
// 004348df  ff15a8ed7700         call dword ptr [0x77eda8]
// 004348e5  50                   push eax
// 004348e6  8d4c2408             lea ecx, [esp + 8]
// 004348ea  e849b91f00           call 0x630238
// 004348ef  33c9                 xor ecx, ecx
// 004348f1  33c0                 xor eax, eax
// 004348f3  51                   push ecx
// 004348f4  50                   push eax
// 004348f5  8d44240c             lea eax, [esp + 0xc]
// 004348f9  50                   push eax
// 004348fa  e8815f2100           call 0x64a880
// 004348ff  8b542414             mov edx, dword ptr [esp + 0x14]
// 00434903  8b4e04               mov ecx, dword ptr [esi + 4]
// 00434906  83c40c               add esp, 0xc
// 00434909  50                   push eax
// 0043490a  52                   push edx
// 0043490b  51                   push ecx
// 0043490c  e8f1b51f00           call 0x62ff02
// 00434911  8b8094000000         mov eax, dword ptr [eax + 0x94]
// 00434917  8b08                 mov ecx, dword ptr [eax]
// 00434919  e892a5feff           call 0x41eeb0
// 0043491e  8d4c2404             lea ecx, [esp + 4]
// 00434922  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0043492a  c7442404c8647800     mov dword ptr [esp + 4], 0x7864c8
// 00434932  e8f5b81f00           call 0x63022c
// 00434937  b801000000           mov eax, 1
// 0043493c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00434940  64890d00000000       mov dword ptr fs:[0], ecx
// 00434947  59                   pop ecx
// 00434948  83c414               add esp, 0x14
// 0043494b  c3                   ret 
// copied from an identical function in another client (function ?createBitmap@ns_ROCX00000c@@YAHPAUS@1@G@Z)

namespace ns_ROCX00000c {
// from server: 100% by king_originala
// from server: 82% by colin
typedef void* HANDLE;

extern "C" __declspec(dllimport) HANDLE __stdcall LoadBitmapA(HANDLE, const char*);
extern "C" HANDLE __stdcall FindResourceModule(const char*, const char*);

struct GdiObject
{
    HANDLE handle;

    GdiObject() : handle(0) {}
    virtual ~GdiObject() { release(); }

    int attach(HANDLE);
    void release();
};

struct Bitmap : GdiObject {};

struct Point { int x, y; Point(int a, int b) : x(a), y(b) {} };
extern "C" int __cdecl PrepareBitmap(Bitmap*, Point);

struct ImageManager
{
    void install(HANDLE, HANDLE, int);
};

struct ModuleState
{
    unsigned char padding[0x94];
    ImageManager** manager;
};

extern "C" ModuleState* __cdecl GetModuleState();

struct S
{
    void* vtable;
    HANDLE handle;

    int create(int, int, unsigned int, int, int);
    int f(unsigned short);
};

static __declspec(noinline) int createBitmap(S* self, unsigned short resource)
{
    if (!self->create(16, 16, 0x19, 0, 1))
        return 0;

    Bitmap bitmap;
    bitmap.attach(LoadBitmapA(
        FindResourceModule((const char*)(unsigned int)resource,
                           (const char*)2),
        (const char*)(unsigned int)resource));

    int value = PrepareBitmap(&bitmap, Point(0, 0));
    HANDLE imageList = self->handle;
    (*GetModuleState()->manager)->install(imageList, bitmap.handle, value);
    return 1;
}

int invoke(S* self, unsigned short resource) { return createBitmap(self, resource); }
}
