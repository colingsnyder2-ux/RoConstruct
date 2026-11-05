// from server: 52% by colin
struct CScriptDoc {
    char pad0[0x128];
    void* field128;
    char pad12c[0x8];
    void* field134;
    char pad138[0xc];
    unsigned char field144;
    void* method_45d230(int);
    void method_45c8d0();
    int method_45cd20();
    void method_45ccd0(int, int);
    void method_45c070();
    void run();
};

extern "C" {
    void __stdcall sub_77ddac(void*);
    void __stdcall sub_77d560(void*, int, int);
    void __stdcall sub_77d55c(void*, int);
    void __stdcall sub_77dd98(void*);
    void __stdcall sub_77e698(void*, void*);
    void __stdcall sub_77e6ac(void*);
    void __stdcall sub_77ddbc(void*);
    void __stdcall sub_725750(void*);
    void __stdcall sub_725770(void*);
    void __stdcall sub_53de40(void*, void*);
}

void CScriptDoc::run()
{
    void* v1;
    void* v2;
    int n;
    char buf[0x28];

    v1 = this->method_45d230(1);
    ((CScriptDoc*)v1)->method_45c8d0();
    if (((CScriptDoc*)v1)->method_45cd20() == 0)
        return;
    if (this->field144 != 0)
        return;
    if (this->field134 != 0)
    {
        v2 = this->field128;
        sub_725750(v2);
        this->method_45d230(1);
        n = ((CScriptDoc*)v1)->method_45cd20();
        sub_77ddac(buf);
        n = n + 1;
        sub_77d560(buf, n, 1);
        sub_77d55c(buf, -1);
        sub_77dd98(buf);
        sub_77e698(buf, 0);
        sub_53de40(this->field134, buf);
        sub_77e6ac(buf);
        sub_77ddbc(buf);
        sub_725770(v2);
    }
    this->method_45d230(1);
    ((CScriptDoc*)v1)->method_45c070();
}
