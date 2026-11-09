// from server: 69% by atomic.potato
struct VClient_FactoryProduct {
    int f_0055aad0(int a1, int a2);
    int f_0055ad10();
    int f_570bc0();
    char f_0055adb0(int a1);
};

char VClient_FactoryProduct::f_0055adb0(int a1)
{
    int result1 = f_0055aad0(a1, 1);
    if (!result1)
        return 1;
    
    int result2 = ((VClient_FactoryProduct*)result1)->f_0055ad10();
    if (!result2)
        return 1;
    
    int result3 = ((VClient_FactoryProduct*)result2)->f_570bc0();
    if (!result3)
        return 1;
    
    return *(char*)(result3 + 0x88);
}
