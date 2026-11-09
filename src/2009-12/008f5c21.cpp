// from server: 21% by atomic.potato
struct CXTIconHandle {
    char pad0[0x14];
    char field14[0x18];
    int field2c;
    int field30;
    int field34;
    void ctor();
};

extern "C" void __stdcall DeleteCriticalSection(void*);

void CXTIconHandle::ctor()
{
    char* p = field14;
    *(int*)(p + 0) = 0;
    *(int*)(p + 4) = 0;
    *(int*)(p + 8) = 0;
    *(int*)(p + 12) = 0;
    *(int*)(p + 16) = 0;
    *(int*)(p + 20) = 0;
    field2c = 0;
    field30 = 0;
    field34 = 0;
}
