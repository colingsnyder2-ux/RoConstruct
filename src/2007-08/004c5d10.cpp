// from server: 100% by colin
struct RakPeer {
    int field0;
    int field4;
    unsigned int field8;
    void func();
};

extern "C" void __stdcall func_00630af7(void*, int, int, void*);
extern "C" void __cdecl func_0062fc62(void*);

void RakPeer::func()
{
    if (field8 > 0) {
        int* p = (int*)field0;
        if (p != 0) {
            int n = *(int*)((char*)p - 4);
            func_00630af7(p, 8, n, (void*)0x40cc20);
            func_0062fc62((char*)p - 4);
        }
    }
}
