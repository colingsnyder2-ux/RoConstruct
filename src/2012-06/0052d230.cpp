// from server: 81% by Intel
extern "C" {
    void __cdecl func_4015a0(void*, void*);
    void __cdecl func_9831f5(void*);
}

unsigned char g_initFlag = 0;
int g_data_e200e0 = 0;
int g_data_e200e4 = 0;

int* getEventDesc() {
    func_4015a0((void*)0x52d200, (void*)0xe200ec);
    
    int flag = 1;
    if (g_initFlag & flag) {
        return &g_data_e200e0;
    }
    
    g_initFlag |= flag;
    flag = 0;
    g_data_e200e0 = flag;
    g_data_e200e4 = flag;
    func_9831f5((void*)0xb12de0);
    
    return &g_data_e200e0;
}
