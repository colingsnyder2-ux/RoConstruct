// from server: 50% by colin
// roc 2007-08 00458ec0  unit: CRobloxWnd  size: 279 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00458ec0

extern "C" {
    int __stdcall GetClientRect(void* hWnd, void* lpRect);
}

struct CRobloxWnd {
    char pad[0x20];
    void* hWnd;
    char pad2[0x54];
    unsigned char flag78;
    void sub_458980(void* p);
    void sub_458ec0(int a, int b);
};

void sub_457d30(void* p);
void* sub_47f7a0(void* dst, void* src);
void sub_630946(void* p);
void sub_630940(void* p);
void sub_630a1e(void* p);
void sub_77e6ac(void* p);
void sub_77edf4(void* p, void* q);

extern unsigned int dword_8B5188;
extern unsigned int dword_888554;

void CRobloxWnd::sub_458ec0(int a, int b) {
    char buf[0x88];
    unsigned int cookie;

    cookie = dword_8B5188 ^ (unsigned int)&buf;
    *(unsigned int*)(buf + 0x84) = cookie;

    sub_457d30(buf + 0x2c);

    unsigned char f = flag78;
    int neg = -(int)f;
    unsigned int mask = (unsigned int)neg >> 31;
    unsigned int val = mask & 8;

    *(int*)(buf + 0x2c) = a;
    *(int*)(buf + 0x30) = b;
    *(int*)(buf + 0x4c) = 8;
    *(int*)(buf + 0x40) = 8;
    *(int*)(buf + 0x48) = val;
    *(int*)(buf + 0x4c) = 0x18;
    *(unsigned int*)(buf + 0x54) = dword_888554;

    sub_630946(buf + 0x0c);

    GetClientRect(hWnd, buf + 0x1c);

    void* p = *(void**)(buf + 0x0c);
    void* q = sub_47f7a0(buf + 0x30, p);
    sub_458980(q);

    sub_630940(buf + 0x08);
    sub_77e6ac(buf + 0x6c);

    unsigned int c = *(unsigned int*)(buf + 0x90);
    (void)c;
    sub_630a1e(buf + 0x08);
}
