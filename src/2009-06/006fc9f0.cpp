// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0066fe30  unit: RBX::AdornRbxGfx  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066fe30
//
// 0066fe30  8b442414             mov eax, dword ptr [esp + 0x14]
// 0066fe34  dd44240c             fld qword ptr [esp + 0xc]
// 0066fe38  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0066fe3c  50                   push eax
// 0066fe3d  83ec08               sub esp, 8
// 0066fe40  dd1c24               fstp qword ptr [esp]
// 0066fe43  51                   push ecx
// 0066fe44  8b0dac2d9600         mov ecx, dword ptr [0x962dac]
// 0066fe4a  8d54241c             lea edx, [esp + 0x1c]
// 0066fe4e  52                   push edx
// 0066fe4f  e8ec470100           call 0x684640
// 0066fe54  d944240c             fld dword ptr [esp + 0xc]
// 0066fe58  8b442404             mov eax, dword ptr [esp + 4]
// 0066fe5c  d918                 fstp dword ptr [eax]
// 0066fe5e  d9442410             fld dword ptr [esp + 0x10]
// 0066fe62  d95804               fstp dword ptr [eax + 4]
// 0066fe65  c21400               ret 0x14

struct Text;

struct Size {
    float x;
    float y;
};

struct Font {
    Size* measure(Size* result, const Text* text, double height, int mode);
};

extern Font* currentFont;

struct AdornRbxGfx {
    Size* measure(Size* result, const Text* text, double height, int mode);
};

Size* AdornRbxGfx::measure(Size* result, const Text* text, double height, int mode)
{
    Size* temporary = reinterpret_cast<Size*>(&height);
    currentFont->measure(temporary, text, height, mode);
    result->x = temporary->x;
    result->y = temporary->y;
    return result;
}
