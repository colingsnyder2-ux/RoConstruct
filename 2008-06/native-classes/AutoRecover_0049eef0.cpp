// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the body at 0x49eef0 only runs the Network::Peer base constructor and stores vtable
// pointers, so it is not the real ScriptContext (005ae490). It is written as a raw-offset helper
// using the fn_<addr> convention. The Peer ctor is declared with a single __fastcall parameter
// (ecx only) because the original does not set edx before the call.
extern "C" void __fastcall fn_004b4640(void* self); // RBX::Network::Peer::Peer()

struct Local_0049eef0;

extern "C" Local_0049eef0* __fastcall fn_0049eef0(Local_0049eef0* self, int unusedEdx)
{
    char* p = (char*)self;
    fn_004b4640(self);
    *(void**)(p + 0x00) = (void*)0x822e44;
    *(void**)(p + 0x10) = (void*)0x822e38;
    *(void**)(p + 0x14) = (void*)0x822e30;
    *(void**)(p + 0x20) = (void*)0x822e28;
    *(void**)(p + 0x24) = (void*)0x822e18;
    *(void**)(p + 0x44) = (void*)0x822e08;
    *(void**)(p + 0x64) = (void*)0x822df8;
    *(void**)(p + 0x84) = (void*)0x822de8;
    *(void**)(p + 0xa4) = (void*)0x822dd8;
    *(void**)(p + 0xc4) = (void*)0x822dc8;
    *(void**)(p + 0x130) = (void*)0x822d98;
    *(void**)(p + 0x134) = (void*)0x822d8c;
    return self;
}
