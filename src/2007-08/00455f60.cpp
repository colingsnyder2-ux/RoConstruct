// from server: 40% by 41k
struct InsertModelFromRobloxVerb {
    void* vtable;
    char pad[0xc];
    double field_10;
    void Run(int arg);
    double sub_4FFEF0();
};

extern "C" void* __stdcall sub_77E698(void*, const char*);
extern "C" void __stdcall sub_564C50(void*, void*);


void InsertModelFromRobloxVerb::Run(int arg)
{
    char buf[0x1c];
    sub_77E698(buf, "TogglePlayMode");
    sub_564C50(this, buf);
    vtable = (void*)0x792b04;
    field_10 = sub_4FFEF0();
}
