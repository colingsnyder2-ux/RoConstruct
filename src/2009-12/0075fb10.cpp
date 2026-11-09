// from server: 33% by atomic.potato
// roc 2009-12 0075fb10  unit: RBX::VGuiBase3d::?$NonFactoryProduct  size: 167 bytes

extern "C" int __cdecl sub_67EAF0();
extern "C" int __cdecl sub_64EB90();
extern "C" int __cdecl sub_7F385A(int);
extern "C" int __cdecl sub_7F3860(int);

struct VGuiBase3d {
    void* vfptr0;
    char pad0[0x18];
    void* field1c;
    void* field20;
    void construct(int, int, int, int, int, int, int, int);
};

void VGuiBase3d::construct(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    int v1 = sub_67EAF0();
    int v2 = sub_64EB90();
    sub_7F385A(0);
    int* p = (int*)sub_7F385A(0);
    int v3 = *p;
    *p = 0;
    this->field20 = (void*)v3;
    this->vfptr0 = (void*)0x9e74c4;
    this->field1c = (void*)0x9e74bc;
    sub_7F385A(0);
}
