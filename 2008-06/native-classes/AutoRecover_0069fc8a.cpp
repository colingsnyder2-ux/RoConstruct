// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x69fc8a is an import thunk (jmp through the IAT) for rgmain!Ogre::DataStream::getLine.
// Plain C++ cannot write a bare jmp thunk, so this is a best-effort tail-call forwarder.
// INFERRED: getLine is __thiscall(this, std::string* ret, bool trimAfter); ecx and the two stack args pass through unchanged.
struct DataStream;
struct StdString;

extern "C" __declspec(dllimport) StdString* __fastcall Ogre_DataStream_getLine(DataStream* self, int unusedEdx, StdString* ret, bool trimAfter);

extern "C" StdString* __fastcall fn_0069fc8a(DataStream* self, int unusedEdx, StdString* ret, bool trimAfter)
{
    return Ogre_DataStream_getLine(self, unusedEdx, ret, trimAfter);
}
