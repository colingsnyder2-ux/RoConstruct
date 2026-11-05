// from server: 100% by colin
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, int lParam);

struct CRobloxView
{
    void method(int a, int b);
};

void CRobloxView::method(int a, int b)
{
    PostMessageA(*(void**)((char*)this - 0x60), 0x46b, 0, 0);
}
