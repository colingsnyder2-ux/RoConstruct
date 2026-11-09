// from server: 56% by atomic.potato
struct Replicator {
    char pad[0x2688];
    void* field_2688;
    bool compare(void* arg);
};

extern "C" void* sub_004cd2a0(void*);
extern "C" bool sub_0041cff0(void*, void*);

bool Replicator::compare(void* arg)
{
    void* a = field_2688;
    void* b = *(void**)((char*)arg + 0x4c);
    if (a == b)
        return true;
    if (b != 0 && sub_0041cff0(a, b))
        return true;
    return arg == sub_004cd2a0(arg);
}
