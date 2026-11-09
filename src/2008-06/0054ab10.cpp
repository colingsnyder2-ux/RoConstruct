// from server: 100% by king_originala
typedef void (__thiscall *DestructorCall)(void *);
extern DestructorCall destroyIndexData;

void __cdecl operator delete(void *);

struct Mesh
{
    Mesh *__thiscall destroy(unsigned int flags);
};

#pragma optimize("", off)
Mesh *__thiscall Mesh::destroy(unsigned int flags)
{
    destroyIndexData(this);
    if (flags & 1)
        operator delete(this);
    return this;
}
#pragma optimize("", on)
