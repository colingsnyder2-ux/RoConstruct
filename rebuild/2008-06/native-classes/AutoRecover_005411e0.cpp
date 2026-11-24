// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this looks like a destructor body. It destroys a Wml ConvexHull3<float>::Triangle
// member at offset 0xc, then runs the base/cleanup helper fn_00540370 on the object.
// The original SEH frame (try level 0 then -1) comes from the member's unwind registration.
// This file does not reproduce that frame.

extern "C" void __fastcall fn_00540e20(void* self, int unusedEdx); // ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ
extern "C" int __fastcall fn_00540370(void* self, int unusedEdx);

extern "C" void __fastcall fn_005411e0(void* self, int unusedEdx)
{
    fn_00540e20(static_cast<char*>(self) + 0xc, 0);
    fn_00540370(self, 0);
}
