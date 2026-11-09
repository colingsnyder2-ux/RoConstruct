// from server: 33% by colin
struct MenuItem {
    char pad[0xb0];
    void* field_b0;
    void destroy();
};

extern "C" void __stdcall sub_9EA400(void*);
extern "C" void __stdcall sub_70A880(MenuItem*);

void MenuItem::destroy()
{
    sub_9EA400(&field_b0);
    sub_70A880(this);
}
