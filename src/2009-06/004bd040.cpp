// from server: 35% by atomic.potato
struct VTimerService_FactoryProduct_Creator {
    void* field0;
    void construct(char* args);
};

extern "C" void __stdcall sub_4B7580(void*);
extern "C" void __stdcall sub_4BA650(void*);
extern "C" void __stdcall sub_4B4FC0(void*);

void VTimerService_FactoryProduct_Creator::construct(char* args) {
    char buf[0x30];
    void* local;
    field0 = 0;
    sub_4B7580(&local);
    sub_4BA650(this);
    sub_4B4FC0(buf);
}
