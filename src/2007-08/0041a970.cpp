// from server: 46% by colin
struct BoundFuncDesc {
    void construct();
};

extern "C" void __stdcall sub_4183A0(void*, int, int);
extern "C" void __stdcall sub_415C40(void*, void*);

void BoundFuncDesc::construct()
{
    int* self = (int*)this;
    int v = self[4];
    sub_4183A0((void*)(self + 2), v, 0);
    sub_415C40(self, (void*)(self + 2));
}
