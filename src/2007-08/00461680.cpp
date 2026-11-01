// from server: 100% by colin
struct RBX_Instance {
    char pad[0xbc];
    RBX_Instance* m_child;
};

extern "C" void* __cdecl sub_630D36(RBX_Instance* self, int, void*, void*, int);

extern "C" void* __fastcall sub_450D00(void* self);

RBX_Instance* __cdecl sub_461680(RBX_Instance* inst)
{
    while (inst != 0) {
        void* result = sub_630D36(inst, 0, (void*)0x881f4c, (void*)0x884e04, 0);
        if (result != 0) {
            return (RBX_Instance*)sub_450D00(result);
        }
        inst = inst->m_child;
    }
    return 0;
}
