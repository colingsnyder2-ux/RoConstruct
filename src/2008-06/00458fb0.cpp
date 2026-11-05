// from server: 100% by atomic.potato
extern "C" int __declspec(dllimport) __stdcall PostMessageA(void*, unsigned int, unsigned int, long);

struct InsertModelFromRobloxVerb
{
    char pad[0xc];
    struct Info
    {
        char pad2[0x20];
        void* handle;
    };
    Info* info;
    void f(unsigned int);
};

void InsertModelFromRobloxVerb::f(unsigned int value)
{
    PostMessageA(this->info->handle, 0x111, 0x80fe, 0);
}
