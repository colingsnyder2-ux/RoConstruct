// from server: 48% by Intel



struct std_exception {
    void *vtable;
};

struct std_string {
    void *vtable;
    char _buf[28];
};

struct Ubad_day_of_year {
    void *vtable;
    std_exception base;
    std_string msg;
    void dtor();
};

extern "C" void __stdcall std_string_dtor(std_string *);
extern "C" void __stdcall std_exception_dtor(std_exception *);
extern "C" void __stdcall Ubad_day_of_year_scalar_deleting_destructor(Ubad_day_of_year *);

void Ubad_day_of_year::dtor()
{
    vtable = (void *)0xB53160;
    msg.vtable = (void *)0xB53158;
    msg.vtable = (void *)0xB43E60;
    std_string_dtor(&msg);
    vtable = (void *)0xB42EA0;
    std_exception_dtor(&base);
    Ubad_day_of_year_scalar_deleting_destructor(this);
}
