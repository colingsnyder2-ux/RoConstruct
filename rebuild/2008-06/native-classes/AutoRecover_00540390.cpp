// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided. The object is a G3D::ReferenceCountedObject
// subclass with a DataStructures::RangeNode<unsigned int> member at +0xC.
// The base and member constructors are called through fn_ externs.

struct Fn00540390Object;

extern "C" void __fastcall fn_00472990(void* self, int unusedEdx); // G3D::ReferenceCountedObject::ReferenceCountedObject
extern "C" void __fastcall fn_007188c0(void* self, int unusedEdx); // DataStructures::RangeNode<unsigned int>::RangeNode
extern "C" int __fastcall fn_00540560(void* self, int unusedEdx);

// INFERRED: vtable of the derived class (unknown symbol), declared as an unknown global.
extern "C" void* g_0082cef0[];

extern "C" Fn00540390Object* __fastcall fn_00540390(Fn00540390Object* self, int unusedEdx)
{
    char* p = reinterpret_cast<char*>(self);
    fn_00472990(p, 0);
    fn_007188c0(p + 0xc, 0);
    *reinterpret_cast<void***>(p) = g_0082cef0;
    fn_00540560(p + 0xc, 0);
    return self;
}
