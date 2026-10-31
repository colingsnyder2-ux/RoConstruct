// from server: 100% by EspClaude
// roc 2009-06 0041cf70  unit: CEnabledCmdUI  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041cf70
//
// 0041cf70  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041cf74  8b542404             mov edx, dword ptr [esp + 4]
// 0041cf78  56                   push esi
// 0041cf79  8bf1                 mov esi, ecx
// 0041cf7b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041cf7f  50                   push eax
// 0041cf80  51                   push ecx
// 0041cf81  52                   push edx
// 0041cf82  8d4e54               lea ecx, [esi + 0x54]
// 0041cf85  e8d6b53300           call 0x758560
// 0041cf8a  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0041cf8d  8d44240c             lea eax, [esp + 0xc]
// 0041cf91  50                   push eax
// 0041cf92  51                   push ecx
// 0041cf93  ff1510ee8900         call dword ptr [0x89ee10]
// 0041cf99  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041cf9d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041cfa1  52                   push edx
// 0041cfa2  50                   push eax
// 0041cfa3  8bce                 mov ecx, esi
// 0041cfa5  e816feffff           call 0x41cdc0
// 0041cfaa  5e                   pop esi
// 0041cfab  c20c00               ret 0xc
// copied from an identical function in another client (function ?OnButton@S@ns_ROCX00007e@@QAEXIUPoint@2@@Z)

namespace ns_ROCX00007e {
struct Point {
    int x;
    int y;
};

extern "C" int (__stdcall *ClientToScreen)(void *, Point *);

struct Tree {
    void OnButton(unsigned int flags, Point point);
};

struct S {
    char padding0[0x20];
    void *window;
    char padding1[0x30];
    Tree tree;

    void OnButton(unsigned int flags, Point point);
    void ShowMenu(int x, int y);
};

void S::OnButton(unsigned int flags, Point point)
{
    tree.OnButton(flags, point);
    ClientToScreen(window, &point);
    ShowMenu(point.x, point.y);
}
}
