// from server: 100% by atomic.potato
typedef int HWND;
typedef unsigned int UINT;
typedef const char *LPCSTR;

extern "C" HWND __declspec(dllimport) __stdcall GetDlgItem(HWND, int);
extern "C" int __declspec(dllimport) __stdcall SetWindowTextA(HWND, LPCSTR);

struct CProgressDialog
{
    int unused;
    HWND hWnd;
    void f(LPCSTR);
};

void CProgressDialog::f(LPCSTR text)
{
    HWND control = GetDlgItem(hWnd, 0x414);
    SetWindowTextA(control, text);
}
