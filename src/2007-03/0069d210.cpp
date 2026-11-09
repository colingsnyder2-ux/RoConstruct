// from server: 100% by Viper
struct S_func_0069d210 {
    int m_x;
    int f(int);
};

int S_func_0069d210::f(int ecx) {
    int eax = *(int*)((char*)this + 0x264);
    eax += 0x178;
    if (ecx < 0 || ecx >= *(int*)(eax + 0x54)) {
        return 0;
    }
    eax = *(int*)(eax + 0x50);
    eax = *(int*)(eax + ecx * 4);
    return eax;
}
