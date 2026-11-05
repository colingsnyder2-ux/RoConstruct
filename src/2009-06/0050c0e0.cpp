// from server: 100% by why2
struct RoundRobinPhysicsSender {
    int isEnd();
    char pad[4];
    void* node;
};

int RoundRobinPhysicsSender::isEnd() {
    void** p = (void**)((char*)this + 4);
    void* v = *p;
    if (v != 0 && v != p)
        return 0;
    return 1;
}
