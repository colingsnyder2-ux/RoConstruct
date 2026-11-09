// from server: 54% by atomic.potato
// roc 2011-06 0043f610  unit: CDeclarationView  size: 135 bytes
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp

extern "C" unsigned int __stdcall SendMessageA(void*, unsigned int, unsigned int, unsigned int);
extern "C" int __cdecl sub_43f570(unsigned int, unsigned int, unsigned int*);

struct CDeclarationView {
    char pad0[0x20];
    unsigned int hwnd;
    char pad1[0xac - 0x24];
    unsigned int field_ac;
    int f(unsigned int* arg);
};

int CDeclarationView::f(unsigned int* arg) {
    unsigned int local[8];
    SendMessageA((void*)hwnd, 0x1101, 0, 0xffff0000);
    field_ac = *arg;
    unsigned int a = arg[7];
    unsigned int b = arg[6];
    local[0] = 0x43e3f0;
    local[1] = 0;
    local[2] = (unsigned int)this;
    local[3] = arg[1];
    sub_43f570(a, b, local);
    local[4] = 0xffff0000;
    local[5] = 0x43dc20;
    SendMessageA((void*)hwnd, 0x1115, 0, (unsigned int)&local[4]);
    return 0;
}
