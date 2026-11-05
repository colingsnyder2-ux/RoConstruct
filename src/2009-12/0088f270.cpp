// from server: 59% by atomic.potato
extern "C" int __stdcall sub_80B8B0(int, int*, int*);
extern "C" void __stdcall sub_98D538(int*);

struct CXTPShortcutManager {
    int f(int, int);
};

int CXTPShortcutManager::f(int a, int b) {
    int local;
    if (sub_80B8B0(a, &local, &b) == 0)
        return 0;
    sub_98D538(&local);
    return 1;
}
