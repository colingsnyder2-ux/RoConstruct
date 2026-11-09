// from server: 30% by colin
struct CXTPOffice2007Image
{
    int field_8;
    int sub_70F690(void*, void*);
    void* sub_7102A0(void*);
};

extern "C" void* __stdcall func_77ddb8(void*, const char*);
extern "C" void __stdcall func_77d678(void*);
extern "C" void __stdcall func_77ddac(void*);
extern "C" int __stdcall func_77e1b0(void*);
extern "C" int __stdcall func_77e160(void*, int, int);
extern "C" void __stdcall func_77d92c(void*, void*, int);
extern "C" void __stdcall func_77d434(void*, void*);
extern "C" void __stdcall func_77ddbc(void*);
extern "C" int __stdcall func_77dcd0(void*);
extern "C" void __stdcall func_77d578(void*, int);
extern "C" int __stdcall func_77dcc8(void*);
extern "C" void __stdcall func_77dc3c(void*, void*, int, int);
extern "C" void __stdcall func_77dd98(void*);
extern "C" int __stdcall func_77dcb8(void*, void*);
extern "C" void __stdcall func_77e3dc(void*);
extern "C" void __stdcall func_77e11c(void*, void*, int);
extern "C" void __stdcall func_77dd74(void*, void*);

void* CXTPOffice2007Image::sub_7102A0(void* arg)
{
    void* result;
    char buf1[8];
    char buf2[8];
    char buf3[8];
    char buf4[8];
    int flag = 0;
    int state = 1;

    if (this->field_8 == 0)
    {
        result = func_77ddb8(arg, (const char*)0x785954);
        return result;
    }

    func_77d678(buf1);
    func_77d678(buf2);

    int local = this->field_8;
    func_77ddac(buf3);

    while (this->sub_70F690(buf4, &local))
    {
        func_77e1b0(buf3);
        int n = func_77e160(buf4, 0, 0x3b);
        if (n == 0)
            break;

        if (n > 0)
        {
            func_77d92c(buf4, buf1, n);
            func_77d434(buf2, buf1);
            func_77ddbc(buf1);
        }

        if (func_77dcd0(buf4))
            break;

        func_77d678(buf4);
        func_77d578(buf4, 0);

        if (*(char*)buf4 == '[')
        {
            if (flag != 0)
                break;

            int len = func_77dcc8(buf4) - 2;
            func_77dc3c(buf1, buf2, 1, len);
            func_77dd98(buf3);
            if (func_77dcb8(buf2, buf3) == 0)
                flag = 1;
            func_77ddbc(buf1);
        }
        else
        {
            if (flag == 0)
                break;

            int m = func_77e160(buf4, 0, 0x3d);
            if (m <= 0)
                break;

            func_77d92c(buf4, buf1, m);
            func_77e3dc(buf1);
            func_77dd98(buf2);
            if (func_77dcb8(buf1, buf2) == 0)
            {
                m++;
                func_77e11c(buf1, buf2, m);
                func_77e1b0(buf1);
                func_77e3dc(buf1);
                func_77dd74(arg, buf1);
                func_77ddbc(buf1);
                func_77ddbc(buf2);
                continue;
            }
            func_77ddbc(buf1);
        }
    }

    result = func_77ddb8(arg, (const char*)0x785954);
    func_77ddbc(buf3);
    func_77ddbc(buf1);
    func_77ddbc(buf2);
    return result;
}
