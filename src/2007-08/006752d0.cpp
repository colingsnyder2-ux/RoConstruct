// from server: 34% by colin
struct CXTPCustomizeSheet {
    char pad[0x20];
    int field_20;
    char pad2[0x18];
    int field_3c;
    int field_40;
    int field_44;
    char pad3[0x0c];
    int field_54;
    int field_58;
    int field_5c;
    char pad4[0x54];
    void* field_b4;
    void* field_b8;

    int func();
};

extern "C" {
    int __stdcall PropertySheetA(void*);
    void* __stdcall GetActiveWindow();
    void* __stdcall GetCapture();
    int __stdcall InvalidateRect(void*, const void*, int);
    int __stdcall SendMessageA(void*, unsigned int, unsigned int, int);
    void* __stdcall SetActiveWindow(void*);
    int __stdcall UnhookWindowsHookEx(void*);
}

extern int g_8c8f38;
extern int g_8b5188;

void __stdcall sub_634780(void*, int);
void __stdcall sub_73876c(int);
void __stdcall sub_738748(void*, int);
void __stdcall sub_738766(void*);
void __stdcall sub_738760();
int __stdcall sub_73875a(void*, int);
int __stdcall sub_738412(void*);
void __stdcall sub_6740e0(void*);
void __stdcall sub_674070(void*);
void __stdcall sub_630214(void*, int, int, int);
void* __stdcall sub_63096a(void*, int);
void __stdcall sub_63002e(void*, int, int, int, int, int, int);
int __stdcall sub_631e80(void*);
void __stdcall sub_633c70(void*);
void* __stdcall sub_62ff02();

int CXTPCustomizeSheet::func()
{
    int result;
    void* p;
    void* q;

    if (g_8c8f38 != 0) {
        return 2;
    }

    sub_634780(this->field_b8, 1);
    void* v = this->field_b8;
    *(void**)((char*)*(void**)((char*)v + 0x4c) + 0x14) = this;

    sub_73876c(0x10);

    void (__thiscall**vt)(void*) = *(void (__thiscall***)(void*))this;
    vt[0x148/4](this);

    void* r = sub_62ff02();
    p = *(void**)((char*)r + 4);
    if (p != 0) {
        sub_738748(p, 0);
    }

    if (this->field_b4 == 0) {
        q = 0;
    } else {
        q = *(void**)((char*)this->field_b4 + 0x20);
    }

    this->field_5c = (int)q;

    int local1c = 0;
    int local20 = 0x674130;
    int local24 = (int)this;
    int local28 = 0;
    int local2c = 0x6742f0;
    int local30 = (int)this;
    int local34 = 0;
    int local38 = 0x674380;
    int local3c = (int)this;

    g_8c8f38 = (int)&local1c;

    if (q != 0) {
        sub_6740e0(&local1c);
    }

    void* hwnd = GetActiveWindow();
    if (hwnd != 0) {
        SendMessageA(hwnd, 0x1f, 0, 0);
    }

    this->field_3c |= 0x10;
    this->field_44 = 0;
    sub_738766(this);

    this->field_58 |= 0x400;
    this->field_3c |= 0x10;
    result = InvalidateRect(&this->field_54, 0, 0);
    this->field_58 &= 0xfffffbff;
    sub_738760();

    if (result == 0 || result == -1) {
        this->field_3c &= 0xffffffef;
    }

    if (sub_631e80(this->field_b8)) {
        sub_630214(this, 0, 0x500000, 0x20);
        void* w = sub_63096a(this, 0x3020);
        if (w != 0) {
            sub_630214(w, 0, 0x400000, 0);
            SendMessageA(*(void**)((char*)w + 0x20), 1, 0, 0);
        }
    }

    void (__thiscall**vt2)(void*) = *(void (__thiscall***)(void*))this;
    int old = this->field_44;
    vt2[0x88/4](this);
    if (result != 0) {
        int n = 4;
        if (sub_738412(this) & 0x100) {
            n = 5;
        }
        old = sub_73875a(this, n);
    }

    if (this->field_20 != 0) {
        sub_63002e(this, 0, 0, 0, 0, 0, 0x97);
    }

    if (local1c != 0) {
        UnhookWindowsHookEx((void*)local1c);
        local1c = 0;
    }
    if (local28 != 0) {
        UnhookWindowsHookEx((void*)local28);
        local28 = 0;
    }
    if (local34 != 0) {
        UnhookWindowsHookEx((void*)local34);
        local34 = 0;
    }

    int cap = (int)GetCapture();
    int b = 0;
    if (cap != 0) {
        if (GetActiveWindow() == (void*)this->field_20) {
            b = 1;
        }
    }

    void (__thiscall**vt3)(void*) = *(void (__thiscall***)(void*))this;
    vt3[0x68/4](this);

    if (b) {
        SetActiveWindow((void*)cap);
    }

    if (p != 0) {
        sub_738748(p, 1);
    }

    sub_634780(this->field_b8, 0);
    void* v2 = this->field_b8;
    *(void**)((char*)*(void**)((char*)v2 + 0x4c) + 0x14) = 0;
    sub_633c70(this->field_b8);
    sub_674070(&local1c);

    return old;
}
