// from server: 28% by atomic.potato
struct CleanStage {
    void* field0;
    void* field4;
    int f(void* arg);
};

int CleanStage::f(void* arg) {
    if (field4 == 0)
        return 0;
    if (arg == 0)
        return 0;
    void* p = field4;
    int a = (*(int (__thiscall**)(void*))p)(p);
    int b = (*(int (__thiscall**)(void*))arg)(arg);
    return a >= b;
}
