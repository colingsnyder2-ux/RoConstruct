// from server: 40% by atomic.potato
struct StarterGuiService {
    char pad[0x15];
    bool flag;
    void method(int);
};

extern "C" void __stdcall sub_00666b60(void*, void*);

void StarterGuiService::method(int arg)
{
    if (flag) {
        void* p = &arg;
        void* q = &p;
        sub_00666b60((char*)this - 0x98, q);
    }
}
