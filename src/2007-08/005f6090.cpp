// from server: 100% by colin
struct VColor3Value {
    char pad[0xe8];
    int field_e8;
    void sub_5f3b20(int* out, int val);
};

struct FactoryProduct {
    char pad[0xe8];
    int field_e8;
    void method(int arg);
};

struct GlobalObj {
    void* sub_570270(int* b);
};

extern GlobalObj g_obj;

void FactoryProduct::method(int arg)
{
    int* p;
    if (this != 0)
        p = (int*)((char*)this + 4);
    else
        p = 0;
    int v = this->field_e8;
    void* r = g_obj.sub_570270(p);
    if (r != 0)
    {
        char tmp[4];
        ((VColor3Value*)((char*)r + 0x10))->sub_5f3b20((int*)&tmp[3], v);
    }
}
