// from server: 35% by colin
extern "C" {
int __stdcall GetClientRect(void*, void*);
void* __stdcall CreateCompatibleBitmap(void*, int, int);
int __stdcall SetPixelV(void*, int, int, unsigned long);
int __stdcall DrawStateA(void*, void*, int, int, int, int, int, int, int, int);
}

struct CXTColorWnd {
    char pad0[0x20];
    void* hdc;
    char pad24[0x30];
    void* field54;
    void* field58;

    void func_0070e670();
};

extern void func_00630490(void*, void*);
extern void func_00630238(void*, void*, int, int, int);
extern void func_0063048a(void*);
extern void func_00630a1e();
extern void func_006802f0(void*, void*);
extern void func_00680430(void*);
extern void func_00680800(void*, void*, void*);
extern void func_00680880(void*);
extern void func_0070c620(double, double, double, double, double, double);
extern void func_0070ce10(void*, void*);

void CXTColorWnd::func_0070e670()
{
    char buf[0x128];
    void* rect[4];
    void* tmp;
    void* bmp;
    int w, h;
    int i, j;

    func_00630490(buf, this);
    GetClientRect(this->hdc, rect);
    w = (int)rect[2] - (int)rect[0];
    h = (int)rect[3] - (int)rect[1];
    if (this->field54 == 0 || this->field58 == 0) {
        bmp = CreateCompatibleBitmap(this->hdc, w, h);
        func_00630238(this->field54, bmp, w, h, 0);
        tmp = this->field54;
        if (tmp) tmp = *(void**)((char*)tmp + 4);
        func_00680800(buf, rect, tmp);
        for (i = 0; i < w; i++) {
            for (j = 0; j < h; j++) {
                double a = (double)i / (double)w;
                double b = (double)j / (double)h;
                func_0070c620(a, b, 0.0, 0.0, 0.0, 0.0);
                SetPixelV(buf, i, j, 0);
            }
        }
        func_00680880(buf);
    }
    tmp = this->field54;
    if (tmp) tmp = *(void**)((char*)tmp + 4);
    DrawStateA(this->hdc, 0, 0, 0, 0, 0, 0, 0, 0, 4);
    func_0070ce10(this, rect);
    func_00680430(rect);
    func_0063048a(buf);
}
