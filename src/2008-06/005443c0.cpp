// from server: 100% by king_originala
#pragma optimize("", off)

struct VChunk;

extern "C" void (__cdecl *invalid_parameter_noinfo)();
extern "C" char* __cdecl left_slot(VChunk*);
extern "C" char* __cdecl flag_slot(VChunk*);
extern "C" char* __cdecl parent_slot(VChunk*);
extern "C" VChunk* __cdecl next_slot(VChunk*);

struct S {
    void* container;
    VChunk* node;

    bool __thiscall has_container() const;
    void __thiscall decrement();
};

void S::decrement()
{
    if (!has_container())
        invalid_parameter_noinfo();

    do {
    } while (false);

    if (*flag_slot(node))
        invalid_parameter_noinfo();
    else if (!*flag_slot(*reinterpret_cast<VChunk**>(left_slot(node))))
        node = next_slot(*reinterpret_cast<VChunk**>(left_slot(node)));
    else {
        VChunk* parent;
        while (!*flag_slot(parent = *reinterpret_cast<VChunk**>(parent_slot(node)))
            && node == *reinterpret_cast<VChunk**>(left_slot(parent)))
            node = parent;
        node = parent;
    }
}
