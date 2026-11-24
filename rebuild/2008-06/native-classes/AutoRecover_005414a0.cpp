// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: Face type opaque; only pointers passed through to the callee.
struct ConvexClipperFace;

// Callee: std::_Destroy_range<Wml::ConvexClipper<float>::Face, std::allocator<Face>>(first, last, alloc&)
// Third arg is pointer to allocator (this+8), cdecl.
extern "C" void fn_00545f10(ConvexClipperFace* first, ConvexClipperFace* last, void* alloc);

// INFERRED: thiscall member of a std::vector-like container; self+8 is the embedded allocator.
extern "C" void __fastcall fn_005414a0(void* self, int unusedEdx, ConvexClipperFace* first, ConvexClipperFace* last)
{
    fn_00545f10(first, last, (char*)self + 8);
}
