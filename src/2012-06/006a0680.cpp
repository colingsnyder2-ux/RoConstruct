// from server: 52% by Intel
extern "C" int __stdcall func_0040f870(int);
extern "C" int __stdcall func_0054d2b0(int);
extern "C" void __stdcall func_006a01d0(int, int, int, int);
extern "C" void __stdcall func_00972290(int, int);

int __stdcall func_006a0680(int arg0, int arg1)
{
    int v_esi = arg1;
    char g_flag = *reinterpret_cast<char*>(0xE580B3);
    if (g_flag)
    {
        int v_ecx = *reinterpret_cast<int*>(v_esi + 8) - *reinterpret_cast<int*>(v_esi + 4);
        int v_eax = (v_ecx * 0x78787879) >> 32;
        v_eax = (v_eax >> 5) - (v_eax >> 31);
        if (v_eax != 3)
        {
            int (__stdcall *callback)(int, int, int) = reinterpret_cast<int (__stdcall*)(int, int, int)>(*reinterpret_cast<int*>(0xE5809C));
            if (callback)
            {
                if (callback(0xB710EC, 0xB70328, 0x130))
                    goto LABEL_EPILOG;
            }
            int v_ecx2 = *reinterpret_cast<unsigned char*>(0xE580B3);
            func_00972290(0xB71078, v_ecx2);
        }
    }
LABEL_EPILOG:
    int v_eax2 = arg0;
    int v_ebp = v_eax2 ? (v_eax2 - 0x1C) : 0;
    int v_eax3 = func_0054d2b0(*reinterpret_cast<int*>(v_esi + 4) + 0x8C);
    int v_edi = *reinterpret_cast<int*>(v_eax3);
    int v_eax4 = func_0040f870(*reinterpret_cast<int*>(v_esi + 4) + 0x48);
    int v_ebx = *reinterpret_cast<int*>(v_eax4);
    int v_esi2 = *reinterpret_cast<int*>(v_esi + 4) + 4;
    int v_eax5 = func_0040f870(v_esi2);
    int v_eax6 = *reinterpret_cast<int*>(v_eax5);
    func_006a01d0(v_edi, v_ebx, v_eax6, *reinterpret_cast<int*>(arg0 + 0x2C) + v_ebp);
    return 0;
}
