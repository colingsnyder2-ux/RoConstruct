// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00467bf0  unit: DxUserInput  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00467bf0
//
// 00467bf0  83ec08               sub esp, 8
// 00467bf3  56                   push esi
// 00467bf4  57                   push edi
// 00467bf5  8bf1                 mov esi, ecx
// 00467bf7  8d7e34               lea edi, [esi + 0x34]
// 00467bfa  57                   push edi
// 00467bfb  ff15d4228000         call dword ptr [0x8022d4]
// 00467c01  8d442408             lea eax, [esp + 8]
// 00467c05  50                   push eax
// 00467c06  ff159c2d8000         call dword ptr [0x802d9c]
// 00467c0c  8b966c010000         mov edx, dword ptr [esi + 0x16c]
// 00467c12  8b4220               mov eax, dword ptr [edx + 0x20]
// 00467c15  8d4c2408             lea ecx, [esp + 8]
// 00467c19  51                   push ecx
// 00467c1a  50                   push eax
// 00467c1b  ff15a02d8000         call dword ptr [0x802da0]
// 00467c21  db442408             fild dword ptr [esp + 8]
// 00467c25  8b742414             mov esi, dword ptr [esp + 0x14]
// 00467c29  57                   push edi
// 00467c2a  d91e                 fstp dword ptr [esi]
// 00467c2c  db442410             fild dword ptr [esp + 0x10]
// 00467c30  d95e04               fstp dword ptr [esi + 4]
// 00467c33  ff15f4218000         call dword ptr [0x8021f4]
// 00467c39  5f                   pop edi
// 00467c3a  8bc6                 mov eax, esi
// 00467c3c  5e                   pop esi
// 00467c3d  83c408               add esp, 8
// 00467c40  c20400               ret 4

struct Point {
    long x;
    long y;
};

struct Vector2 {
    float x;
    float y;
};

extern "C" {
    extern void (__stdcall *EnterCriticalSection)(void*);
    extern void (__stdcall *LeaveCriticalSection)(void*);
    extern int (__stdcall *GetCursorPos)(Point*);
    extern int (__stdcall *ScreenToClient)(void*, Point*);
}

struct Window {
    char padding[0x20];
    void* handle;
};

struct DxUserInput {
    char padding0[0x2c];
    char criticalSection[0x18];
    char padding1[0x120];
    Window* window;

    Vector2 getCursorPosition();
};

Vector2 DxUserInput::getCursorPosition()
{
    EnterCriticalSection(criticalSection);

    Point point;
    GetCursorPos(&point);
    ScreenToClient(window->handle, &point);

    Vector2 result;
    result.x = (float)point.x;
    result.y = (float)point.y;

    LeaveCriticalSection(criticalSection);
    return result;
}
