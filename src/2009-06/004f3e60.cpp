// from server: 31% by atomic.potato
struct S_func_00677320 { virtual ~S_func_00677320(); };

struct S_func_004f3e60 {
    char pad[0x10];
    void* field_10;
    void destroy();
};

extern "C" void __stdcall func_00718a32(void*);
extern "C" void __stdcall func_004d1460(void*);

void S_func_004f3e60::destroy()
{
    void* p = field_10;
    if (p) {
        func_004d1460(p);
        func_00718a32(p);
    }
    ((S_func_00677320*)this)->~S_func_00677320();
}
