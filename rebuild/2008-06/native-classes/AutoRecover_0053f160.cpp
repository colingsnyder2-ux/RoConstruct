// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were available. This is the scalar body of a
// SceneManager-derived destructor. It sets the vtable, destroys three members
// in reverse order (offsets 0x48, 0x28, 0x08), then runs the base destructor.
// The disassembly shows the SEH unwind-state writes (2, 1, 0, -1), but plain
// C helpers cannot generate those, so they are not reproduced here.

struct SceneManagerDerived {
    void** vtable;   // +0x00
    // members live at +0x08, +0x28 and +0x48; accessed by offset below
};

// INFERRED: the derived class's vtable, referenced as an unknown global symbol.
extern "C" void* g_0082ced0[];

extern "C" void __fastcall fn_00540350(void* self, int unusedEdx); // Triangle dtor (ConvexHull3<float>)
extern "C" void __fastcall fn_00540330(void* self, int unusedEdx); // Triangle dtor (ConvexHull3<float>)
extern "C" void __fastcall fn_004d6f50(void* self, int unusedEdx); // RBX::RenderBase::SceneManager::~SceneManager

extern "C" void __fastcall fn_0053f160(SceneManagerDerived* self, int unusedEdx)
{
    self->vtable = g_0082ced0;
    fn_00540350(reinterpret_cast<char*>(self) + 0x48, 0);
    fn_00540350(reinterpret_cast<char*>(self) + 0x28, 0);
    fn_00540330(reinterpret_cast<char*>(self) + 0x08, 0);
    fn_004d6f50(self, 0);
}
