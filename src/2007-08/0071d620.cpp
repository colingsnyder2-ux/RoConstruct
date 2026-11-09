// from server: 100% by tajop
extern "C" {
    __declspec(dllimport) unsigned int __stdcall KillTimer(void*, unsigned int);
    __declspec(dllimport) int __stdcall ReleaseCapture();
}

struct CXTPScrollBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    int pad[23];
    int field_60;
    void func(int);
};

void CXTPScrollBase::func(int arg) {
    int* p = (int*)field_60;
    if (p) {
        p[5] = 0;
        ReleaseCapture();
        if (p[12]) {
            if (arg) {
                p[9] = *(int*)(p[13] + 12);
            }
            v5(4, p[9]);
            v6();
        } else if (p[6]) {
            KillTimer((void*)p[11], p[6]);
            p[6] = 0;
        }
        v5(8, 0);
    }
}
