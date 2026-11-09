// from server: 100% by colin
struct Tool {
    char pad[0x118];
    void* field_118;
};

struct Helper {
    void* sub_5D2380();
    void* sub_4887E0();
    void sub_541630(void* arg);
};

void sub_5D2690(Tool* self)
{
    if (self == 0)
        return;
    void* p = self->field_118;
    if (p == 0)
        return;
    Helper* h = (Helper*)p;
    void* v = h->sub_5D2380();
    while (v != 0) {
        void* a = ((Helper*)self)->sub_4887E0();
        ((Helper*)v)->sub_541630(a);
        v = h->sub_5D2380();
    }
}
