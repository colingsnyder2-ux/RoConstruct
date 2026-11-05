// from server: 34% by colin
extern "C" {
    int __stdcall func_006303fa(int, int);
    void __stdcall func_006301e4(int);
    int __stdcall func_0067bd90(int, int);
    int __stdcall func_006b3010();
    void __stdcall func_0077d2ec(int);
    int __stdcall func_0077dd94(int, int, int);
    int __stdcall func_0077dd98(int);
    int __stdcall func_0077ddac(int);
    int __stdcall func_0077ddbc(int);
}

struct CXTPToolBar {
    char pad0[0xf8];
    struct Inner* inner;
    void func_0066b4e0(int, int);
};

struct Inner {
    char pad0[0x3c];
    int field_3c;
};

void CXTPToolBar::func_0066b4e0(int a, int b)
{
    int* p = (int*)this->inner;
    int edi = p[0x3c / 4];
    if (edi == 0) goto loc_64c;
    {
        int* q = (int*)this->inner;
        if (q[0x3c / 4] == 0) goto loc_64c;
        if (func_0067bd90(q[0x3c / 4], edi) != 0) goto loc_64c;
    }
    if (b != 0) goto loc_68f;
    {
        int* q = (int*)this->inner;
        if (func_0067bd90(edi, (int)q) != 0) goto loc_68f;
    }
    {
        int local1;
        int local2;
        func_0077ddac((int)&local1);
        local2 = 0;
        func_0077ddac((int)&local2);
        {
            int obj = func_006b3010();
            int* vt = *(int**)obj;
            int (*fn)(int, int, int) = (int (*)(int, int, int))vt[1];
            fn(obj, (int)&local1, 0x23d9);
        }
        {
            int x = func_0077dd98((int)this + 0xf0);
            int y = func_0077dd98((int)&local1);
            int z;
            func_0077dd94((int)&z, y, x);
        }
        {
            int w = func_0077dd98((int)&local1);
            int r = func_006303fa(w, 0x24);
            if (r == 7) {
                int* q = (int*)this->inner;
                int old = q[0x3c / 4];
                if (old != 0) {
                    func_0077d2ec(old + 4);
                }
                {
                    int* vt = *(int**)this;
                    int (*fn)(CXTPToolBar*, int, int) = (int (*)(CXTPToolBar*, int, int))vt[0x1c8 / 4];
                    fn(this, b, 0);
                }
                {
                    int* q2 = (int*)this->inner;
                    int v = q2[0x3c / 4];
                    if (v != 0) {
                        func_006301e4(v);
                        int* q3 = (int*)this->inner;
                        q3[0x3c / 4] = 0;
                    }
                    int* q4 = (int*)this->inner;
                    q4[0x3c / 4] = old;
                }
            }
        }
        func_0077ddbc((int)&local2);
        func_0077ddbc((int)&local1);
    }
    goto loc_68f;

loc_64c:
    {
        int* q = (int*)this->inner;
        if (q[0x3c / 4] != 0) {
            edi = 0;
        } else {
            int* q2 = (int*)this->inner;
            edi = q2[0x3c / 4];
            if (edi != 0) {
                func_0077d2ec(edi + 4);
            }
        }
        {
            int* vt = *(int**)this;
            int (*fn)(CXTPToolBar*, int, int) = (int (*)(CXTPToolBar*, int, int))vt[0x1c8 / 4];
            fn(this, b, 0);
        }
        if (edi != 0) {
            int* q3 = (int*)this->inner;
            q3[0x3c / 4] = edi;
        }
    }

loc_68f:
    ;
}
