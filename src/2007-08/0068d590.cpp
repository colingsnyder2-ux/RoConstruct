// from server: 100% by tajop
// roc 2007-08 0068d590  unit: CXTPTabClientWnd::CSingleWorkspace  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0068d590

extern "C" __declspec(dllimport) int __stdcall IsWindow(void*);
extern "C" __declspec(dllimport) int __stdcall SendMessageA(void*, unsigned int, unsigned int, int);

struct CSingleWorkspace {
    char pad_0x00[0x20];
    int field_0x20;
    char pad_0x24[0x44];
    int field_0x68;
    char pad_0x6c[0x10];
    int field_0x7c;
    char pad_0x80[0x4];
    int field_0x84;
    char pad_0x88[0x10];
    int field_0x98;
    char pad_0x9c[0x50];
    int field_0xec;
    char pad_0xf0[0x2c];
    int field_0x11c;

    int Method();
    int GetCount();
    int GetItem(int);
    void sub_6fe640();
    void sub_6ffab0(int, int);
    void sub_738a2a();
};

int CSingleWorkspace::Method() {
    if (this->field_0x84 == 0)
        return 0;

    if (this->field_0xec != 0) {
        int* p = (int*)this->field_0xec;
        int* vt = (int*)*p;
        ((void (__thiscall*)(void*))vt[0x58/4])((void*)this->field_0xec);
    }

    if (this->field_0x7c != 0) {
        *(int*)(this->field_0x7c + 0x8c) = 0;
        ((CSingleWorkspace*)this->field_0x7c)->sub_6fe640();
    } else {
        int i = 0;
        int n = this->GetCount();
        while (i < n) {
            int item = this->GetItem(i);
            if (item != 0) {
                int* vt = (int*)*(int*)item;
                ((void (__thiscall*)(void*, int))vt[1])((void*)item, 1);
            }
            i++;
            n = this->GetCount();
        }
    }

    ((CSingleWorkspace*)((char*)this + 0x68))->sub_6ffab0(0, -1);

    int saved = this->field_0x20;
    this->field_0x98 = 0;
    this->sub_738a2a();

    int hwnd = this->field_0x84;
    if (hwnd != 0)
        hwnd = *(int*)(hwnd + 0x20);

    if (IsWindow((void*)hwnd) != 0) {
        int* p = (int*)this->field_0x84;
        int* vt = (int*)*p;
        ((void (__thiscall*)(void*, int))vt[0x150/4])((void*)this->field_0x84, 1);
    }

    int hwnd2 = this->field_0x11c;
    this->field_0x84 = 0;
    SendMessageA((void*)saved, (unsigned int)hwnd2, 0, 0);

    return 1;
}
