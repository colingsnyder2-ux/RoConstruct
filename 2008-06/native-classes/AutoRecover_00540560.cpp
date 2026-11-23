// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is the inlined std::vector<ConvexClipper<float>::Vertex> default
// constructor: build a temporary allocator, construct _Vector_val from it, then _Buy(0).

struct FakeAllocator {};

extern "C" void __fastcall fn_0054e310(FakeAllocator* self, int unusedEdx);
extern "C" void __fastcall fn_0054da40(void* self, int unusedEdx, FakeAllocator a);
extern "C" int __fastcall fn_005530e0(void* self, int unusedEdx, int a1);

extern "C" void* __fastcall fn_00540560(void* self, int unusedEdx)
{
    FakeAllocator alloc;
    fn_0054e310(&alloc, 0);
    fn_0054da40(self, 0, alloc);
    fn_005530e0(self, 0, 0);
    return self;
}
