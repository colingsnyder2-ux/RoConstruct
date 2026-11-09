// from server: 19% by atomic.potato
extern "C" int __stdcall func_005235f0(int, int);
extern "C" int __stdcall func_00702890();
extern "C" void __stdcall func_006aa720();
extern "C" int __stdcall func_006aa690();
extern "C" int __stdcall func_00642fc0();
extern "C" int __stdcall func_006322e0(int, int, int);
extern "C" void __stdcall func_006aa7a0(int);

struct S {
    char pad0[0x14];
    int field14;
    char pad18[0x20];
    int field38;
    int field3c;
    char pad40[0x40];
    int field80;
    int method(int, int, int, int, int);
};

int S::method(int a1, int a2, int a3, int a4, int a5)
{
    int v = func_005235f0(a1, a2);
    func_00702890();
    this->field38 = a3;
    this->field3c = a4;
    this->field80 = 0;
    func_006aa720();
    this->field14 = func_006aa690();
    int r = func_00642fc0();
    int q = func_006322e0(a5, r, (int)&this->field80);
    func_006aa7a0(q);
    return (int)this;
}
