// from server: 24% by Intel
struct String {
    char _buf[28];
};

struct Copyable {
    virtual void copy(void* dest, const void* src) = 0;
};

struct EventDesc {
    char pad[0x1c];
    String name;
    int field_20;
    Copyable* field_24;
    char field_28[40];

    EventDesc(const EventDesc& other);
};

extern "C" void __stdcall string_copy_ctor(String* this_ptr, const String* other);

EventDesc::EventDesc(const EventDesc& other) {
    string_copy_ctor(&name, &other.name);
    field_20 = other.field_20;
    field_24 = 0;
    if (other.field_24) {
        other.field_24->copy(&field_28, &other.field_28);
    }
    field_24 = other.field_24;
}
