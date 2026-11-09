// from server: 15% by colin
typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;
typedef void* HGDIOBJ;
typedef void* HBITMAP;
typedef void* HICON;
typedef void* HDC;

struct ICONINFO {
    BOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbmMask;
    HBITMAP hbmColor;
};

struct BITMAP {
    long bmType;
    long bmWidth;
    long bmHeight;
    long bmWidthBytes;
    WORD bmPlanes;
    WORD bmBitsPixel;
    void* bmBits;
};

extern "C" {
    __declspec(dllimport) HDC __stdcall CreateCompatibleDC(HDC);
    __declspec(dllimport) BOOL __stdcall DeleteObject(HGDIOBJ);
    __declspec(dllimport) int __stdcall GetObjectA(HGDIOBJ, int, void*);
    __declspec(dllimport) DWORD __stdcall GetPixel(HDC, int, int);
    __declspec(dllimport) DWORD __stdcall SetPixel(HDC, int, int, DWORD);
    __declspec(dllimport) BOOL __stdcall CreateIconIndirect(ICONINFO*);
    __declspec(dllimport) BOOL __stdcall GetIconInfo(HICON, ICONINFO*);
}

extern "C" {
    DWORD __stdcall ImageList_GetImageCount(void*);
    void* __stdcall ImageList_GetIcon(void*, int, DWORD);
}

struct CXTPImageManagerIcon {
    void sub_648600();
    void sub_648620();
    void sub_648630();
    void sub_649660();
    void sub_6498c0();
    void sub_64b280();
    void sub_680770();
    void sub_680880();
    void sub_7383d0();
    void sub_7383e2();
    void sub_738436();
    void sub_4605a0();
    void sub_63062e();
    void sub_63119e();
    void sub_62fc6e();
    void sub_64bec0(int, int, int, int);
};

void CXTPImageManagerIcon::sub_64bec0(int a1, int a2, int a3, int a4)
{
    void* pImageList = (void*)((char*)this + 0xa0);
    if (!ImageList_GetImageCount(pImageList))
        return;

    int bUseColor = 0;
    if (a3 != -1 && a4 != -1)
        bUseColor = 1;

    void* pImageList2 = (void*)((char*)this + 0x30);
    if (ImageList_GetImageCount(pImageList2) != 0)
    {
        HDC hdcScreen = CreateCompatibleDC(0);
        if (!hdcScreen)
            return;

        HICON hIcon = (HICON)ImageList_GetIcon(pImageList, a1, 0);
        ICONINFO iconInfo;
        GetIconInfo(hIcon, &iconInfo);

        BITMAP bm;
        GetObjectA(iconInfo.hbmColor, sizeof(BITMAP), &bm);

        int width = bm.bmWidth;
        int height = bm.bmHeight;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                DWORD pixel = GetPixel(hdcScreen, x, y);
                if (pixel == 0xFFFFFFFF)
                {
                    DWORD color;
                    if (bUseColor)
                    {
                        BYTE r = (BYTE)(pixel >> 16);
                        BYTE g = (BYTE)(pixel >> 8);
                        BYTE b = (BYTE)pixel;
                        color = ((DWORD)r << 16) | ((DWORD)g << 8) | b;
                    }
                    else
                    {
                        BYTE gray = (BYTE)((pixel & 0xff) * 0.299 + ((pixel >> 8) & 0xff) * 0.587 + ((pixel >> 16) & 0xff) * 0.114);
                        color = ((DWORD)gray << 16) | ((DWORD)gray << 8) | gray;
                    }
                    SetPixel(hdcScreen, x, y, color);
                }
            }
        }

        DeleteObject(iconInfo.hbmColor);
        DeleteObject(iconInfo.hbmMask);
        DeleteObject(hdcScreen);
    }
}
