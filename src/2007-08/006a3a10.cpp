// from server: 100% by colin
struct HWND__;

struct CArray {
    void f(HWND__* hwnd);
};

struct Inner {
    int find(HWND__* hwnd);
    void removeAt(int index, int count);
};

extern "C" {
    int (__stdcall *GetCursorPos)(void* pt);
    int (__stdcall *SetCursorPos)(int x, int y);
}

void CArray::f(HWND__* hwnd) {
    int index = ((Inner*)((char*)this + 8))->find(hwnd);
    if (index != -1) {
        ((Inner*)((char*)this + 8))->removeAt(index, 1);
    }
    if (*(int*)((char*)this + 0x10) == 0) {
        int pt[2];
        GetCursorPos(pt);
        SetCursorPos(pt[0], pt[1]);
    }
    *(int*)((char*)this + 0x40) = 0;
}
