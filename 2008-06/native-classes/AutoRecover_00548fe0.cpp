// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly reads [ebp+8] and [ebp+0xc], so this is a cdecl
// function taking two stack arguments (an object and a RenderDevice*),
// even though the task header says 0 stack dwords.
// INFERRED: all types below are file-local stand-ins, since no headers were shown.
struct RenderDeviceOpaque;
struct IndexHolder;

// DataStructures::List<RegisteredCommand>::Size (thiscall, ecx = list), 0x00442cd0
extern "C" unsigned int __fastcall fn_00442cd0(void* list, int unusedEdx);

// G3D::RenderDevice::sendIndices<int>(Primitive, const Array<int>&) (thiscall), 0x005029c0
extern "C" void __fastcall fn_005029c0(RenderDeviceOpaque* rd, int unusedEdx, int primitive, void* indexArray);

// INFERRED: global byte flag at 0x009738a1 (a skip/disable flag)
extern "C" unsigned char g_flag_009738a1;

extern "C" void fn_00548fe0(IndexHolder* self, RenderDeviceOpaque* rd)
{
    if (g_flag_009738a1)
        return;
    if (!self)
        return;

    char* base = reinterpret_cast<char*>(self);
    int count = (int)fn_00442cd0(base + 0xc, 0);
    if (count > 0) {
        fn_005029c0(rd, 0, *reinterpret_cast<int*>(base + 0x18), base + 0xc);
    }
}
