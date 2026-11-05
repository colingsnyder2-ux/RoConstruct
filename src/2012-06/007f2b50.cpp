// from server: 100% by atomic.potato
extern "C" void __stdcall sub_414da0(const char* name);

struct EventDesc {
    unsigned char pad[0x1b8];
    int field_1b8;
    void update(int value);
};

void EventDesc::update(int value)
{
    if (field_1b8 != value) {
        field_1b8 = value;
        sub_414da0((const char*)0x00e4f228);
        void** vtable = *(void***)this;
        void (__thiscall *callback)(EventDesc*) =
            (void (__thiscall *)(EventDesc*))vtable[0x74 / sizeof(void*)];
        callback(this);
    }
}
