// from server: 58% by 41k
struct RBX_Network_VClient {
    int factoryProduct(int param);
};

extern "C" int __stdcall func_0054b060(int param);
extern "C" int __stdcall func_006c8100(int param);

int RBX_Network_VClient::factoryProduct(int param) {
    int eax = param;
    if (eax) {
        int esi = eax + 0x1c;
        if (esi) {
            int edi = *(int*)(esi + 0xc);
            int result = func_0054b060(edi);
            if (result) {
                eax = esi - 0x1c;
                int ecx = 0;
                if (eax) {
                    ecx = 1;
                }
                return ecx;
            }
        }
    }
    eax = 0;
    int ecx = 0;
    if (eax) {
        ecx = 1;
    }
    return ecx;
}
