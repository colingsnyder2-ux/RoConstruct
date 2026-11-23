// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: import thunk for Ogre::MemoryDataStream::read (thiscall, via rgmain.dll IAT slot 0x804e54).
// Forwarding ecx/edx/stack args unchanged lets the compiler emit a tail-call jmp through the IAT.
extern "C" __declspec(dllimport) unsigned int __fastcall Ogre_MemoryDataStream_read(void* self, int unusedEdx, void* buf, unsigned int count);

extern "C" unsigned int __fastcall fn_0069fc7e(void* self, int unusedEdx, void* buf, unsigned int count)
{
    return Ogre_MemoryDataStream_read(self, unusedEdx, buf, count);
}
