// from server: 100% by king_originala
#pragma optimize("g", off)

struct VChunk {
    char pad[0x0c];
};

struct Container {
    char pad[0x18];
    VChunk* end;
};

extern "C" void (__cdecl *invalid_parameter_noinfo)();
char* __cdecl chunk_data(VChunk* p);

struct Iterator {
    void* owner;
    VChunk* current;

    bool __thiscall has_container() const;
    const Container* __thiscall get_container() const;
    char* __thiscall get();
};

char* Iterator::get()
{
    if (!has_container())
        invalid_parameter_noinfo();
    do {
    } while (false);

    if (current == get_container()->end)
        invalid_parameter_noinfo();
    do {
    } while (false);

    return chunk_data(current);
}
