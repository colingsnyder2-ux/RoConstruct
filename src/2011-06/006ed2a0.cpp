// from server: 56% by atomic.potato
struct PriorityThreadPoolData {
    void construct(void*);
};

extern "C" void __stdcall sub_4101E0(void*, void*);
extern "C" void* __stdcall sub_673D20(void*, void*);
extern "C" bool __stdcall boost_timed_join(void*, const void*);

void PriorityThreadPoolData::construct(void* param)
{
    char buf[24];
    sub_4101E0(buf + 4, (void*)0x40da20);
    void* p = param;
    *(int*)(buf + 0) = *(int*)p;
    *(int*)(buf + 4) = *(int*)((char*)p + 4);
    void* r = sub_673D20(buf + 12, buf + 20);
    *(int*)(buf + 8) = *(int*)r;
    *(int*)(buf + 12) = *(int*)((char*)r + 4);
    boost_timed_join(this, buf + 4);
}
