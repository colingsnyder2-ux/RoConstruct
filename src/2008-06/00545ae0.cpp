// from server: 100% by tester
#pragma optimize("g", off)

struct VChunk;
extern "C" char* __cdecl next_slot(VChunk*);
extern "C" char* __cdecl flag_slot(VChunk*);

VChunk* __cdecl f(VChunk* p)
{
    while (*flag_slot(*reinterpret_cast<VChunk**>(next_slot(p))) == 0)
        p = *reinterpret_cast<VChunk**>(next_slot(p));
    return p;
}
