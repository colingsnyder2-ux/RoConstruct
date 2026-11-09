// from server: 100% by colin
struct DataModel {
    char pad[0x188];
    void* field_188;
    char pad2[0x1b4 - 0x18c];
    unsigned char field_1b4;
    void func(void* arg);
};

void DataModel::func(void* arg)
{
    if (arg) {
        char* p = (char*)field_188;
        void** vtbl = *(void***)(p + 0x158);
        typedef void (__thiscall *Fn)(void*, void*);
        ((Fn)vtbl[3])(p + 0x158, arg);
        if (field_1b4 == 0) {
            char* q = (char*)field_188;
            char* r = *(char**)(q + 0x318);
            void** vtbl2 = *(void***)(r + 4);
            ((Fn)vtbl2[3])(r + 4, arg);
        }
    }
}
