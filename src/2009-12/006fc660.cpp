// from server: 43% by atomic.potato
struct StarterGuiService {
    char pad[0x15];
    bool flag;
    void sub_6fc490(void*, void*);
    void f(void*);
};

void StarterGuiService::f(void* a) {
    if (flag) {
        void* local = a;
        sub_6fc490(&local, &a);
    }
}
