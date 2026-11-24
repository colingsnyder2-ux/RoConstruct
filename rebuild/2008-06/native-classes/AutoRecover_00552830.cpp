// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the second stack argument is used both as a RakNet::BitStream (GetWriteOffset)
// and as a DataStructures::List<RegisteredCommand> (Size). This is probably COMDAT-folded
// code, so the argument is treated as an opaque pointer.
extern "C" int __fastcall fn_0071f210(void* self, int unusedEdx);   // BitStream::GetWriteOffset
extern "C" unsigned int __fastcall fn_00442cd0(void* self, int unusedEdx); // List<RegisteredCommand>::Size
extern "C" int __fastcall fn_00552860(void* self, int unusedEdx, int a1, int a2, int a3);

extern "C" int __fastcall fn_00552830(void* self, int unusedEdx, int arg1, void* arg2)
{
    int writeOffset = fn_0071f210(arg2, 0);
    unsigned int size = fn_00442cd0(arg2, 0);
    return fn_00552860(self, 0, arg1, (int)size, writeOffset);
}
