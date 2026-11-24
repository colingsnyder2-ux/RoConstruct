// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is std::vector<ConvexClipper<float>::Vertex>::_Ufill(dest, count, val),
// returning dest + count. Vertex is 4 bytes (the return uses a *4 scale).
// The allocator lives at this+8; the debug-iterator proxy is not modelled.
struct Vertex
{
    int v;
};

struct VertexAllocator
{
    char dummy;
};

struct VertexVector
{
    int pad0;
    int pad1;
    VertexAllocator alloc; // at +8
};

// std::_Uninit / unchecked_uninitialized_fill_n<Vertex*, unsigned, Vertex, allocator<Vertex>>
extern "C" void fn_00545f50(Vertex* first, unsigned int count, const Vertex* val, VertexAllocator* al);

extern "C" Vertex* __fastcall fn_00541540(VertexVector* self, int unusedEdx, Vertex* first, unsigned int count, const Vertex* val)
{
    fn_00545f50(first, count, val, &self->alloc);
    return first + count;
}
