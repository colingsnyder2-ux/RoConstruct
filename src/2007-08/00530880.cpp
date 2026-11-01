// from server: 100% by colin
struct VModelInstance {
    char pad[0xbc];
    void* field_bc;
    int isModel();
};

extern "C" void* __cdecl sub_630d36(void* a, void* b, void* c, void* d, void* e);
extern "C" void* __fastcall sub_52ff30(VModelInstance* self);

int VModelInstance::isModel()
{
    void* p = sub_630d36(field_bc, 0, (void*)0x881f4c, (void*)0x898fc0, 0);
    if (p != 0) {
        void* saved = field_bc;
        void* r = sub_52ff30(this);
        if (r != saved) {
            return 0;
        }
    }
    return 1;
}
