// from server: 21% by colin
struct CXTSplitterWnd {
    char pad[0x54];
    void* m_pRow;

    void sub_690d10(int a, int b, int c);
};

extern "C" void* __stdcall sub_630652(void*, int, int);
extern "C" void* __stdcall sub_630520(void*);
extern "C" void* __stdcall sub_630202(void*);
extern "C" int __stdcall sub_6301f0(void*, int);
extern "C" void* __stdcall sub_7385b0(void*);
extern "C" void __stdcall sub_63064c(void*, int, int*, int*);
extern "C" void __stdcall sub_738af0(void*, int, int*, int*);
extern "C" void __stdcall sub_738436(void*);
extern "C" void* __stdcall sub_63052c(int);
extern "C" void __stdcall sub_62fc6e(void);
extern "C" void __stdcall sub_738424(void);
extern "C" void __stdcall sub_62ff4a(void*, int);
extern "C" void __stdcall sub_738ad2(void*, int);
extern "C" void __stdcall sub_6305aa(void*, int, int, int);
extern "C" void __stdcall sub_738aea(void*, int, int, int);

void CXTSplitterWnd::sub_690d10(int a, int b, int c)
{
    void* p1 = sub_630652(this, a, b);
    void* p2 = sub_630520(p1);
    void* p3 = sub_630202(p2);
    void* edi = p3;
    if (sub_6301f0(edi, c) != 0)
        return;
    void* ebx = *(void**)((char*)edi + 0x54);
    void* eax = sub_7385b0(edi);
    int v1, v2, v3, v4;
    sub_63064c(this, a, &v1, &v2);
    sub_738af0(this, b, &v3, &v4);
    int local[6];
    local[0] = c;
    local[1] = (int)ebx;
    local[2] = 0;
    local[3] = 0;
    local[4] = 0;
    local[5] = 0;
    if (ebx != 0)
        ebx = *(void**)((char*)ebx + 0x28);
    else
        ebx = 0;
    local[3] = (int)ebx;
    local[5] = 0;
    sub_738436(&local[0]);
    void* h = sub_63052c(c);
    if (h == 0)
        sub_62fc6e();
    sub_738424();
    void* vt = *(void**)h;
    int (*fn)(void*, int, int, int, int, int, int, int) = *(int (**)(void*, int, int, int, int, int, int, int))((char*)vt + 0x5c);
    int r;
    int tmp[4];
    tmp[0] = 0;
    tmp[1] = 0;
    tmp[2] = 0;
    tmp[3] = 0;
    r = fn(h, 0, 0, 0x50000000, (int)tmp, (int)this, (int)eax, (int)local);
    if (r == 0)
        return;
    sub_62ff4a(edi, 0);
    sub_738ad2(edi, 0);
    sub_6305aa(this, a, v1, v2);
    sub_738aea(this, b, v3, v4);
    void* vt2 = *(void**)this;
    int (*fn2)(void*) = *(int (**)(void*))((char*)vt2 + 0x148);
    fn2(this);
    void* p4 = sub_630652(this, a, b);
    void* p5 = sub_630520(p4);
    void* p6 = sub_630202(p5);
    void* vt3 = *(void**)p6;
    int (*fn3)(void*) = *(int (**)(void*))((char*)vt3 + 0x164);
    fn3(p6);
}
