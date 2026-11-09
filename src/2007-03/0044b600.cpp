// from server: 100% by tester
struct CRobloxControlColorSelector {
    char pad[0xd0];
    unsigned int flags;
    char pad2[0x158 - 0xd0 - 4];
    void* ptr;
    int IsSomething(unsigned int mask);
};

int CRobloxControlColorSelector::IsSomething(unsigned int mask) {
    if (ptr != 0 && *(int*)((char*)ptr + 0x3c) == 0)
        return 0;
    unsigned int v = flags & ~mask;
    return v == 0;
}
