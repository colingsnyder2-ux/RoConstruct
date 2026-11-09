// from server: 40% by atomic.potato
struct PriorityThreadPoolData {
    char pad0[0x2c];
    void* field2c;
    void cleanup();
    void destroy();
};

extern "C" void __stdcall sub_6ec460(void*, void*);
extern "C" void __stdcall sub_6edd80(void*);

void PriorityThreadPoolData::destroy()
{
    void* local = 0;
    sub_6ec460((char*)field2c + 0x34, &local);
    cleanup();
    if (local) {
        void* vt = *(void**)local;
        if (vt) {
            void* p = &local;
            ((void (__stdcall*)(void*, void*, int))vt)(p, p, 2);
        }
    }
}
