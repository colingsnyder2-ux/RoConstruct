// from server: 71% by Intel




struct VInstance {
    int vftable;
    int field_4;

    int sub_545840(int arg);
};

extern "C" void __stdcall sub_9831f5(int);

unsigned char g_flag_e21634;
int g_ptr_e21628;
int g_ptr_e2162c;
int g_ptr_e21630;

int VInstance::sub_545840(int arg) {
    int eax = 1;
    VInstance* esi = this;

    if (!g_flag_e21634) {
        g_flag_e21634 = 1;
        sub_9831f5(0xB13950);
        g_ptr_e21628 = 0xD824DC;
        g_ptr_e21630 = 0x5708D0;
        g_ptr_e2162c = 0x59A790;
    }

    if (esi->vftable == (int)&g_ptr_e21628) {
        int* arg_ptr = (int*)(arg);
        esi->field_4 = *arg_ptr;
        return (int)esi;
    }

    if (esi->vftable) {
        int (__thiscall *func)(VInstance*, int) = (int (__thiscall*)(VInstance*, int))(*(int*)(esi->vftable + 4));
        func(esi, arg);
        esi->vftable = 0;
    }

    if (&esi->field_4) {
        int* arg_ptr = (int*)(arg);
        esi->field_4 = *arg_ptr;
    }

    esi->vftable = (int)&g_ptr_e21628;
    return (int)esi;
}
