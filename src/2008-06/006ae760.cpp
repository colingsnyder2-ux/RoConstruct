// from server: 100% by tester
struct CXTPPaintManager {
    int sub_63CD70(int);
    int sub_63A580();
    int method(int);
};

int CXTPPaintManager::method(int arg) {
    int eax = *(int*)(arg + 0x9c);
    if (eax == -1) {
        int ecx = *(int*)(arg + 0x15c);
        if (ecx != 0) {
            eax = ((CXTPPaintManager*)ecx)->sub_63A580();
        }
    }
    int val = (eax != 0) ? 0x5 : 0xf;
    return sub_63CD70(val);
}
