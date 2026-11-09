// from server: 44% by colin
struct RBX_Visit_uploadUrl_holder
{
    char pad[0x1c];
    void* field_0x1c;
};

extern "C" void* __stdcall sub_77E69C();
extern "C" void* __stdcall sub_77E6AC();

struct RBX_Visit_ctor_helper
{
    void* field_0x00;
    void* field_0x04;
    void* field_0x08;
    void* field_0x0c;
    void* field_0x10;
    void* field_0x14;
    void* field_0x18;
    void* field_0x1c;
};

extern "C" void __cdecl sub_5920B0(void* dst, void* src);

struct RBX_Visit
{
    void construct();
};

void RBX_Visit::construct()
{
    char local_0x00[0x34];
    RBX_Visit_uploadUrl_holder* self = (RBX_Visit_uploadUrl_holder*)this;
    void* p;

    sub_77E69C();
    sub_5920B0(local_0x00, (char*)this + 0x34);
    p = *(void**)(local_0x00 + 0x10);
    self->field_0x1c = *(void**)(local_0x00 + 0x1c);
    sub_77E69C();
    sub_77E6AC();
    sub_77E6AC();
}
