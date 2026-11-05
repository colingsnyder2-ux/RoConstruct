// from server: 59% by tester
struct EnumDescriptor
{
    void* getItem(int index);
};

struct EnumDesc
{
    void* field_0;
    void construct(int index);
};

extern "C" void* __stdcall sub_734890(int* p);
extern "C" void __stdcall sub_76a190(void* self, void** p);

void EnumDesc::construct(int index)
{
    int* p = (int*)((char*)&index + 4);
    void* r = sub_734890(p);
    void* v = *(void**)r;
    sub_76a190(this, &v);
}
