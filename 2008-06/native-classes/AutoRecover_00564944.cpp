// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x564944 is not a real function entry. It starts with a stray "ret" and
// then falls into the middle of a destructor body. This range is the tail of the
// destructor of a class derived from Reflection::EnumDescriptor.
// The original code depends on state set up by a prologue outside this range:
// esi = this, ebx = 0, and an SEH frame. C++ cannot express that, so this is a
// best-effort reconstruction of the tail only.
// The EH state writes (8, 1, 0, -1) and the fs:[0] restore are left to the compiler.
// operator delete (??3@YAXPAX@Z at 0x6a067a) is called directly through ::operator delete.

extern "C" void __fastcall fn_004077d0(void* vecStrings, int unusedEdx);   // vector<std::string>::_Tidy
extern "C" void __fastcall fn_00553d80(void* tree, int unusedEdx);         // map<BrickColor::Number, Color4uint8> tree dtor
extern "C" void __fastcall fn_0056c080(void* self, int unusedEdx);         // Reflection::EnumDescriptor::~EnumDescriptor

extern "C" void fn_00564944(char* self)
{
    // INFERRED: the first "je" tests the pointer at +0xac before freeing it.
    void* e0 = *(void**)(self + 0xac);
    if (e0)
        ::operator delete(e0);
    void* p0 = *(void**)(self + 0xa0);
    *(void**)(self + 0xac) = 0;
    *(void**)(self + 0xb0) = 0;
    *(void**)(self + 0xb4) = 0;
    ::operator delete(p0);

    // vector<std::string> at +0x88
    fn_004077d0(self + 0x88, 0);
    ::operator delete(*(void**)(self + 0x88));

    // buffer at +0x7c (freed only if non-null), then buffer at +0x70
    void* p1 = *(void**)(self + 0x7c);
    if (p1)
        ::operator delete(p1);
    void* p2 = *(void**)(self + 0x70);
    *(void**)(self + 0x7c) = 0;
    *(void**)(self + 0x80) = 0;
    *(void**)(self + 0x84) = 0;
    ::operator delete(p2);

    // two map trees
    fn_00553d80(self + 0x50, 0);
    fn_00553d80(self + 0x30, 0);

    // base class destructor
    fn_0056c080(self, 0);
}
