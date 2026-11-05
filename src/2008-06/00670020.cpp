// from server: 100% by colin
// from server: 95% by king_originala
// roc 2008-06 00670020  unit: RBX::AdornRbxGfx  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00670020
//
// 00670020  83ec10               sub esp, 0x10
// 00670023  8b4104               mov eax, dword ptr [ecx + 4]
// 00670026  56                   push esi
// 00670027  8b7010               mov esi, dword ptr [eax + 0x10]
// 0067002a  8bce                 mov ecx, esi
// 0067002c  ff15604c8000         call dword ptr [0x804c60]
// 00670032  89442404             mov dword ptr [esp + 4], eax
// 00670036  db442404             fild dword ptr [esp + 4]
// 0067003a  8bce                 mov ecx, esi
// 0067003c  d95c240c             fstp dword ptr [esp + 0xc]
// 00670040  ff15644c8000         call dword ptr [0x804c64]
// 00670046  89442404             mov dword ptr [esp + 4], eax
// 0067004a  db442404             fild dword ptr [esp + 4]
// 0067004e  8bce                 mov ecx, esi
// 00670050  d95c2408             fstp dword ptr [esp + 8]
// 00670054  ff15804c8000         call dword ptr [0x804c80]
// 0067005a  89442404             mov dword ptr [esp + 4], eax
// 0067005e  db442404             fild dword ptr [esp + 4]
// 00670062  8bce                 mov ecx, esi
// 00670064  d95c2410             fstp dword ptr [esp + 0x10]
// 00670068  ff157c4c8000         call dword ptr [0x804c7c]
// 0067006e  8b742418             mov esi, dword ptr [esp + 0x18]
// 00670072  89442404             mov dword ptr [esp + 4], eax
// 00670076  db442404             fild dword ptr [esp + 4]
// 0067007a  83ec10               sub esp, 0x10
// 0067007d  d9442418             fld dword ptr [esp + 0x18]
// 00670081  d9c0                 fld st(0)
// 00670083  dec2                 faddp st(2)
// 00670085  d9c9                 fxch st(1)
// 00670087  d95c240c             fstp dword ptr [esp + 0xc]
// 0067008b  d944241c             fld dword ptr [esp + 0x1c]
// 0067008f  d9442420             fld dword ptr [esp + 0x20]
// 00670093  d8c1                 fadd st(1)
// 00670095  d95c2408             fstp dword ptr [esp + 8]
// 00670099  d9c9                 fxch st(1)
// 0067009b  d95c2404             fstp dword ptr [esp + 4]
// 0067009f  d91c24               fstp dword ptr [esp]
// 006700a2  56                   push esi
// 006700a3  e8a8b8deff           call 0x45b950
// 006700a8  83c414               add esp, 0x14
// 006700ab  8bc6                 mov eax, esi
// 006700ad  5e                   pop esi
// 006700ae  83c410               add esp, 0x10
// 006700b1  c20400               ret 4


#pragma float_control(precise, off)

struct Rect {
    float x0, y0, x1, y1;
    Rect(const Rect&);
};

typedef int (__thiscall *ViewportQuery)(const void*);
extern ViewportQuery getActualLeft;
extern ViewportQuery getActualTop;
extern ViewportQuery getActualWidth;
extern ViewportQuery getActualHeight;

extern Rect __cdecl makeRect(float, float, float, float);

struct S {
    char pad[4];
    void* context;
    Rect f() const;
};

// G3D Rect2D::xywh
inline Rect xywh(float x, float y, float w, float h) { return makeRect(x, y, x + w, y + h); }
Rect S::f() const {
    const void* viewport = *(void**)((char*)context + 0x10);
    return xywh((float)getActualLeft(viewport), (float)getActualTop(viewport),
                (float)getActualWidth(viewport), (float)getActualHeight(viewport));
}
