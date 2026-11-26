// from server: 100% by Xemicl
// roc 2012-06 0042a970  unit: CEnabledCmdUI  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042a970
//
// 0042a970  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042a974  8b542404             mov edx, dword ptr [esp + 4]
// 0042a978  56                   push esi
// 0042a979  8bf1                 mov esi, ecx
// 0042a97b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0042a97f  50                   push eax
// 0042a980  51                   push ecx
// 0042a981  52                   push edx
// 0042a982  8d4e54               lea ecx, [esi + 0x54]
// 0042a985  e8e6685900           call 0x9c1270
// 0042a98a  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0042a98d  8d44240c             lea eax, [esp + 0xc]
// 0042a991  50                   push eax
// 0042a992  51                   push ecx
// 0042a993  ff15dc3ab200         call dword ptr [0xb23adc]
// 0042a999  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042a99d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042a9a1  52                   push edx
// 0042a9a2  50                   push eax
// 0042a9a3  8bce                 mov ecx, esi
// 0042a9a5  e816feffff           call 0x42a7c0
// 0042a9aa  5e                   pop esi
// 0042a9ab  c20c00               ret 0xc
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