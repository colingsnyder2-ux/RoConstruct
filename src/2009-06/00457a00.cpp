// from server: 100% by tester
struct InsertModelFromRobloxVerb {
    char pad[0xc];
    void** field_c;
    void Run(int arg);
};

extern "C" int (__stdcall *PostMessageA)(void*, unsigned int, unsigned int, long);

void InsertModelFromRobloxVerb::Run(int)
{
    PostMessageA(field_c[8], 0x111, 0x80fe, 0);
}
