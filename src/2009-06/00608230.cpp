// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00574170  unit: RBX::UnifiedWidget  size: 267 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00574170
//
// 00574170  83ec20               sub esp, 0x20
// 00574173  53                   push ebx
// 00574174  56                   push esi
// 00574175  57                   push edi
// 00574176  8bf9                 mov edi, ecx
// 00574178  83bf4401000000       cmp dword ptr [edi + 0x144], 0
// 0057417f  743a                 je 0x5741bb
// 00574181  b801000000           mov eax, 1
// 00574186  84053c4e9700         test byte ptr [0x974e3c], al
// 0057418c  7526                 jne 0x5741b4
// 0057418e  d905b8888200         fld dword ptr [0x8288b8]
// 00574194  09053c4e9700         or dword ptr [0x974e3c], eax
// 0057419a  d9152c4e9700         fst dword ptr [0x974e2c]
// 005741a0  d915304e9700         fst dword ptr [0x974e30]
// 005741a6  d91d344e9700         fstp dword ptr [0x974e34]
// 005741ac  d9e8                 fld1 
// 005741ae  d91d384e9700         fstp dword ptr [0x974e38]
// 005741b4  b82c4e9700           mov eax, 0x974e2c
// 005741b9  eb23                 jmp 0x5741de
// 005741bb  e8a008faff           call 0x514a60
// 005741c0  d900                 fld dword ptr [eax]
// 005741c2  d95c240c             fstp dword ptr [esp + 0xc]
// 005741c6  d94004               fld dword ptr [eax + 4]
// 005741c9  d95c2410             fstp dword ptr [esp + 0x10]
// 005741cd  d94008               fld dword ptr [eax + 8]
// 005741d0  8d44240c             lea eax, [esp + 0xc]
// 005741d4  d95c2414             fstp dword ptr [esp + 0x14]
// 005741d8  d9e8                 fld1 
// 005741da  d95c2418             fstp dword ptr [esp + 0x18]
// 005741de  8b742430             mov esi, dword ptr [esp + 0x30]
// 005741e2  8b1e                 mov ebx, dword ptr [esi]
// 005741e4  50                   push eax
// 005741e5  8d442420             lea eax, [esp + 0x20]
// 005741e9  50                   push eax
// 005741ea  8bcf                 mov ecx, edi
// 005741ec  e86ff7ffff           call 0x573960
// 005741f1  8b532c               mov edx, dword ptr [ebx + 0x2c]
// 005741f4  50                   push eax
// 005741f5  8bce                 mov ecx, esi
// 005741f7  ffd2                 call edx
// 005741f9  e8f207faff           call 0x5149f0
// 005741fe  d900                 fld dword ptr [eax]
// 00574200  8b1e                 mov ebx, dword ptr [esi]
// 00574202  d95c240c             fstp dword ptr [esp + 0xc]
// 00574206  d94004               fld dword ptr [eax + 4]
// 00574209  d95c2410             fstp dword ptr [esp + 0x10]
// 0057420d  d94008               fld dword ptr [eax + 8]
// 00574210  8d44240c             lea eax, [esp + 0xc]
// 00574214  d95c2414             fstp dword ptr [esp + 0x14]
// 00574218  50                   push eax
// 00574219  d9e8                 fld1 
// 0057421b  51                   push ecx
// 0057421c  d9542420             fst dword ptr [esp + 0x20]
// 00574220  8d4c2424             lea ecx, [esp + 0x24]
// 00574224  d91c24               fstp dword ptr [esp]
// 00574227  51                   push ecx
// 00574228  8bcf                 mov ecx, edi
// 0057422a  e831f7ffff           call 0x573960
// 0057422f  8b5328               mov edx, dword ptr [ebx + 0x28]
// 00574232  50                   push eax
// 00574233  8bce                 mov ecx, esi
// 00574235  ffd2                 call edx
// 00574237  e8b407faff           call 0x5149f0
// 0057423c  d900                 fld dword ptr [eax]
// 0057423e  d95c240c             fstp dword ptr [esp + 0xc]
// 00574242  6a02                 push 2
// 00574244  d94004               fld dword ptr [eax + 4]
// 00574247  d95c2414             fstp dword ptr [esp + 0x14]
// 0057424b  d94008               fld dword ptr [eax + 8]
// 0057424e  d95c2418             fstp dword ptr [esp + 0x18]
// 00574252  d9e8                 fld1 
// 00574254  d95c241c             fstp dword ptr [esp + 0x1c]
// 00574258  e8b36c2400           call 0x7baf10
// 0057425d  50                   push eax
// 0057425e  8d442414             lea eax, [esp + 0x14]
// 00574262  50                   push eax
// 00574263  8d8f10010000         lea ecx, [edi + 0x110]
// 00574269  51                   push ecx
// 0057426a  56                   push esi
// 0057426b  8bcf                 mov ecx, edi
// 0057426d  e8eef0ffff           call 0x573360
// 00574272  5f                   pop edi
// 00574273  5e                   pop esi
// 00574274  5b                   pop ebx
// 00574275  83c420               add esp, 0x20
// 00574278  c20400               ret 4

struct Vec3 {
    float x, y, z;
};

struct Color4 {
    float r, g, b, a;
    Color4() {}
    Color4(float R, float G, float B, float A)
        : r(R), g(G), b(B), a(A) {}
    Color4(const Vec3& v, float A)
        : r(v.x), g(v.y), b(v.z), a(A) {}
};

extern const Vec3& __cdecl black();
extern const Vec3& __cdecl white();
extern int __cdecl style();

struct Renderer;
struct RenderTable {
    void* unused[10];
    void (__thiscall* outline)(Renderer*, const Color4&);
    void (__thiscall* fill)(Renderer*, const Color4&);
};

struct Renderer {
    RenderTable* table;
};

struct S {
    char padding[0x54];
    char textData[0x34];
    char exePad2009[0x18];
    int selected;

    Color4 transform(const Color4&);
    Color4 transform(float, const Color4&);
    void drawText(Renderer*, const void*, const Color4&, int, int);
    void f(Renderer*);
};

void S::f(Renderer* renderer)
{
    {
        Color4 temporary;
        const Color4* color;
        if (selected) {
            static Color4 selectedColor(0.7f, 0.7f, 0.7f, 1.0f);
            color = &selectedColor;
        } else {
            const Vec3& v = white();
            temporary.r = v.x;
            temporary.g = v.y;
            temporary.b = v.z;
            temporary.a = 1.0f;
            color = &temporary;
        }
        renderer->table->fill(renderer, transform(*color));
    }
    renderer->table->outline(renderer, transform(1.0f, Color4(black(), 1.0f)));
    drawText(renderer, textData, Color4(black(), 1.0f), style(), 2);
}
