// from server: 72% by atomic.potato
struct VPlayer_EventDesc {
    char pad[0xc0];
    void* field_c0;
    void AddRef(VPlayer_EventDesc* other);
};

extern "C" int __stdcall sub_98B670(void*, void*);
extern "C" void __stdcall sub_98B69C(void*, void*);
extern "C" void __stdcall sub_40C080(void*, const char*);

void VPlayer_EventDesc::AddRef(VPlayer_EventDesc* other)
{
    if (sub_98B670(&field_c0, other)) {
        sub_98B69C(&field_c0, other);
        sub_40C080(this, (const char*)0xB7E7E8);
    }
}
