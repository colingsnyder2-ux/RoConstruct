// from server: 100% by king_originala
struct Entry {
    unsigned color;
    unsigned data[2];
};

extern Entry* entries_begin;
extern Entry* entries_end;
extern "C" void (__cdecl* invalid_parameter_noinfo)();

struct S {
    char padding[0x178];
    unsigned index;
    unsigned char selected;
    char padding2[3];
    unsigned color;

    void update();
    void finish();
};

void S::update()
{
    unsigned i = index;
    if (i != (unsigned)-1) {
        if (i >= (unsigned)(entries_end - entries_begin))
            invalid_parameter_noinfo();
        color = entries_begin[i].color;
        selected = 1;
    }
    finish();
}
