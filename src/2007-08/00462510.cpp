// from server: 52% by colin
struct EventData {
    void* vtable;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void* field18;
    void destroy();
    ~EventData();
};

extern "C" void __cdecl func_00462210();
extern "C" void __cdecl func_00433660(void*);
extern "C" void __cdecl func_0062fc62(void*);

void EventData::destroy()
{
    func_00462210();
    func_00433660(field18);
    if (field8) {
        func_0062fc62(field8);
    }
    field8 = 0;
    fieldC = 0;
    field10 = 0;
    vtable = (void*)0x788338;
}

EventData::~EventData()
{
    vtable = (void*)0x795308;
    destroy();
}
