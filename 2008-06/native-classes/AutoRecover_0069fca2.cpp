// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x69fca2 is a linker import thunk, "jmp [IAT]" to rgmain!Ogre::MemoryDataStream::seek(unsigned).
// Model it as a tail call to a dllimport with the same args. The real import name is the mangled
// ?seek@MemoryDataStream@Ogre@@UAEXI@Z, which a C++ source cannot spell directly.
struct OgreMemoryDataStream;

extern "C" __declspec(dllimport) void __fastcall ogre_MemoryDataStream_seek(OgreMemoryDataStream* self, int unusedEdx, unsigned int pos);

extern "C" void __fastcall fn_0069fca2(OgreMemoryDataStream* self, int unusedEdx, unsigned int pos)
{
    ogre_MemoryDataStream_seek(self, unusedEdx, pos);
}
