// from server: 37% by colin
struct Adorn {
    void* vtable;
    void* field4;
    void* field8;
};

struct AdornBillboarder {
    void* vtable;
    void* field4;
    Adorn* field8;
    void destructor();
};

void __stdcall sub_6bbc40(void*);
void __cdecl sub_7a799a(void*);

void AdornBillboarder::destructor()
{
    Adorn* p = field8;
    sub_6bbc40(&field8);
    sub_7a799a(p);
}
