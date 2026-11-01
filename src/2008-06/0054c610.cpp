// from server: 100% by king_originala
struct VChunk { char pad[0xc]; };

extern char* __cdecl chunk_data(VChunk* p);
extern void* __cdecl convert_pointer(void* p);

#pragma optimize("", off)
void* __cdecl f(VChunk* p)
{
    return convert_pointer(chunk_data(p));
}
#pragma optimize("", on)
