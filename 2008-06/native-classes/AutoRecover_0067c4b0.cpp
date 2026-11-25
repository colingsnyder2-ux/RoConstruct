// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the Ogre headers pulled in by OgreRbx/VisualEngine2008.h are not on
// the include path (OgrePrerequisites.h is missing), so the real header cannot
// be included. The VisualEngine destructor at 0x0067a130 is declared as an
// extern "C" __thiscall helper instead.
// INFERRED: the target is the compiler-generated scalar deleting destructor of
// VisualEngine (or a subclass with an empty destructor). It calls
// ~VisualEngine, then the global operator delete when bit 0 of the flags is set.

extern "C" void __fastcall fn_0067a130(void* self, int unusedEdx);

extern "C" void* __fastcall fn_0067c4b0(void* self, int unusedEdx, unsigned int flags)
{
    fn_0067a130(self, unusedEdx);
    if (flags & 1)
    {
        ::operator delete(self);
    }
    return self;
}
