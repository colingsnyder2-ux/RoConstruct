// from server: 33% by colin
struct VPlayersBoundFuncDesc {
    void construct(int a, int b, int c, int d, int e, int f);
};

extern "C" int __stdcall sub_494E80(int, int);
extern "C" void __stdcall sub_570DB0(int);
extern "C" void __stdcall sub_56D3C0(int);
extern "C" void __stdcall sub_491660(int, int);

void VPlayersBoundFuncDesc::construct(int a, int b, int c, int d, int e, int f) {
    int r = sub_494E80(e, f);
    sub_570DB0(r);
    *(int*)this = 0x79bbd4;
    *(int*)((char*)this + 0x28) = c;
    *(int*)((char*)this + 0x2c) = d;
    sub_56D3C0((int)((char*)this + 0x30));
    sub_56D3C0((int)((char*)this + 0x38));
    sub_491660(a, b);
}
