// from server: 100% by colin
struct CXTPBitmapDC
{
    void* vtable;
    int field4;
    int field8;
    int fieldC;
    CXTPBitmapDC(int a, int b);
};

extern "C" int __stdcall sub_67F2F0(int);

CXTPBitmapDC::CXTPBitmapDC(int a, int b)
{
    field4 = a;
    vtable = (void*)0x7cecd8;
    field8 = 0;
    fieldC = -1;
    if (b != 0)
        sub_67F2F0(b);
}
