// from server: 39% by atomic.potato
struct VColor3 {
    char pad[0x1c];
    void* field_1c;
    void get(void* out, void* arg);
};

void* __stdcall sub_5a5dd0();
void __stdcall sub_4e85b0(void*);

void VColor3::get(void* out, void* arg)
{
    void** vtbl = *(void***)field_1c;
    void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vtbl[3];
    fn(field_1c, out, arg);
    ++*(int*)0xc1833c;
    void* r = sub_5a5dd0();
    *(void**)out = r;
    sub_4e85b0((char*)out + 4);
}
