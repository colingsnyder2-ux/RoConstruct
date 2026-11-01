// from server: 44% by atomic.potato
typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef int HDC;
typedef int COLORREF;

struct CXTPDockingPanePaintManager
{
    COLORREF GetXtremeColor(UINT index);
};

extern "C" int __stdcall SetPixel(HDC hdc, int x, int y, COLORREF color);

COLORREF CXTPDockingPanePaintManager::GetXtremeColor(UINT index)
{
    return SetPixel((HDC)index, 0, 0, 0);
}
