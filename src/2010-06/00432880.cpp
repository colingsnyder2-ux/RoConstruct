// from server: 100% by atomic.potato
typedef unsigned int UINT;
typedef unsigned long WPARAM;
typedef long LPARAM;
typedef long LRESULT;
typedef void *HWND;

extern "C" LRESULT __declspec(dllimport) __stdcall SendMessageA(HWND, UINT, WPARAM, LPARAM);

struct CProgressDialog
{
    int unused;
    HWND m_hwnd;
    void Close(char value);
};

void CProgressDialog::Close(char value)
{
    SendMessageA(m_hwnd, 0x465, value != 0, 0);
}
