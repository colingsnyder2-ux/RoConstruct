// from server: 100% by atomic.potato
struct MergedFilter {
    void* field0;
    void* field4;
    void* field8;
    int check(void* arg);
};

int MergedFilter::check(void* arg) {
    if (field4 != 0) {
        int r = (*(int (__thiscall**)(void*, void*))*(void**)field4)(field4, arg);
        if (r != 2)
            return r;
    }
    if (field8 != 0) {
        int r = (*(int (__thiscall**)(void*, void*))*(void**)field8)(field8, arg);
        if (r != 2)
            return r;
    }
    return 2;
}
