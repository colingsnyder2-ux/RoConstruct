// from server: 100% by king_originala
struct String {
    char padding[20];
    unsigned int length;
};

extern void (__cdecl *sub_802890)();
extern unsigned int (__thiscall *sub_802358)(String*);

struct LuaWriter {
    String* ptr;
    unsigned int pos;
    LuaWriter& put();
};

LuaWriter& LuaWriter::put()
{
    if (ptr != (String*)-4) {
        void (__cdecl *invalid)() = sub_802890;
        if (ptr == 0)
            invalid();

        if (pos >= sub_802358(ptr) + ptr->length)
            invalid();
    }
    ++pos;
    return *this;
}
