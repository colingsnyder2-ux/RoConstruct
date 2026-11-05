// from server: 24% by Intel
struct VWinHttpRequest_stream_buffer
{
    unsigned char padding0[0x14];
    void* field_14;
    unsigned char padding1[0x10];
    void* field_24;
    unsigned char padding2[0x20];
    void* field_48;

    void f();
};

extern "C" void __cdecl sub_85A760(void* dest, void* src, int count, void* context);
extern "C" void __stdcall MSVCP90_pubsync(void*);

void VWinHttpRequest_stream_buffer::f()
{
    void* v24 = field_24;
    void* v14 = field_14;
    int count = *static_cast<int*>(v24) - *static_cast<int*>(v14);
    if (count > 0)
    {
        void* v48 = field_48;
        unsigned char* context = reinterpret_cast<unsigned char*>(this) + 0x40;
        sub_85A760(v48, v14, count, context);
    }
    void* v48_2 = field_48;
    if (v48_2)
    {
        MSVCP90_pubsync(v48_2);
    }
}
