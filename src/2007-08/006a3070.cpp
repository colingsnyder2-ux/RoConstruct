// from server: 100% by colin
struct CHookSink {
    void* FindHook(int);
    void RemoveHook(int);
    void DoRemove(int);
};

void CHookSink::DoRemove(int a) {
    void* p = FindHook(a);
    if (p) {
        RemoveHook(a);
        void** vt = *(void***)p;
        void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))vt[1];
        fn(p, 1);
    }
}
