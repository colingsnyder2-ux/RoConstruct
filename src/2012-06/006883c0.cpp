// from server: 57% by atomic.potato
struct RBX_HeartbeatInstance {
    char pad0[4];
    int* begin;
    int* end;
    void sub_446340(int);
    int get(int);
};

int RBX_HeartbeatInstance::get(int idx) {
    int* b = begin;
    int* e = end;
    int count = (int)((e - b) / 96);
    if ((unsigned)count <= (unsigned)idx) {
        sub_446340(idx);
    }
    return (int)(b + idx * 96);
}
