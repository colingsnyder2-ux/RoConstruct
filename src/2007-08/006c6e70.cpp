// from server: 43% by colin
struct CXTPCustomizeSheet_CCustomizeEdit {
    void SetSomething(int* p);
};

extern "C" int __stdcall sub_6C6E10(int* p);
extern "C" void __stdcall sub_630016(int* p, int a);
extern "C" int __stdcall sub_77DD98();
extern "C" int __stdcall sub_77DCB8(int a, int b);
extern "C" void __stdcall sub_77DDBC(int* p);
extern "C" void __stdcall sub_77D434(int* p, int a);

void CXTPCustomizeSheet_CCustomizeEdit::SetSomething(int* p)
{
    int local;
    char flag;
    int* q;
    int r;

    flag = 0;
    q = *(int**)((char*)this + 0x168);
    if (q == 0 && *(int*)((char*)q + 0x20) != 0) {
        r = sub_6C6E10(&local);
        flag = 1;
        int v = sub_77DD98();
        int w = sub_77DCB8(r, v);
        if (w != 0) {
            flag = 1;
        } else {
            flag = 0;
        }
    }
    if (flag & 1) {
        sub_77DDBC(&local);
    }
    if (flag != 0) {
        int* q2 = *(int**)((char*)this + 0x168);
        sub_630016(q2, 0);
        int v2 = sub_77DD98();
        int* q3 = *(int**)((char*)this + 0x168);
        sub_630016(q3, v2);
    }
    sub_77D434((int*)((char*)this + 0x18c), (int)p);
    *(int*)((char*)this + 0x190) = 0;
}
