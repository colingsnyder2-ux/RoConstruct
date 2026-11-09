// from server: 100% by colin
// from server: 95% by king_originala
// roc 2008-06 007ad8a0  unit: RBX::RenderNew::Material  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007ad8a0
//
// 007ad8a0  6aff                 push -1
// 007ad8a2  68d8d87e00           push 0x7ed8d8
// 007ad8a7  64a100000000         mov eax, dword ptr fs:[0]
// 007ad8ad  50                   push eax
// 007ad8ae  64892500000000       mov dword ptr fs:[0], esp
// 007ad8b5  83ec38               sub esp, 0x38
// 007ad8b8  d9442460             fld dword ptr [esp + 0x60]
// 007ad8bc  56                   push esi
// 007ad8bd  83ec1c               sub esp, 0x1c
// 007ad8c0  d95c2418             fstp dword ptr [esp + 0x18]
// 007ad8c4  8bc4                 mov eax, esp
// 007ad8c6  d944247c             fld dword ptr [esp + 0x7c]
// 007ad8ca  89a42480000000       mov dword ptr [esp + 0x80], esp
// 007ad8d1  d95c2414             fstp dword ptr [esp + 0x14]
// 007ad8d5  8bf1                 mov esi, ecx
// 007ad8d7  d9442478             fld dword ptr [esp + 0x78]
// 007ad8db  d95c2410             fstp dword ptr [esp + 0x10]
// 007ad8df  d9442474             fld dword ptr [esp + 0x74]
// 007ad8e3  d95c240c             fstp dword ptr [esp + 0xc]
// 007ad8e7  51                   push ecx
// 007ad8e8  d944246c             fld dword ptr [esp + 0x6c]
// 007ad8ec  8d4c2424             lea ecx, [esp + 0x24]
// 007ad8f0  d918                 fstp dword ptr [eax]
// 007ad8f2  89a42484000000       mov dword ptr [esp + 0x84], esp
// 007ad8f9  d9442470             fld dword ptr [esp + 0x70]
// 007ad8fd  d95804               fstp dword ptr [eax + 4]
// 007ad900  d9442474             fld dword ptr [esp + 0x74]
// 007ad904  d95808               fstp dword ptr [eax + 8]
// 007ad907  8bc4                 mov eax, esp
// 007ad909  c70000000000         mov dword ptr [eax], 0
// 007ad90f  e81cf9ffff           call 0x7ad230
// 007ad914  83c60c               add esi, 0xc
// 007ad917  50                   push eax
// 007ad918  8bce                 mov ecx, esi
// 007ad91a  c744244800000000     mov dword ptr [esp + 0x48], 0
// 007ad922  e839fdffff           call 0x7ad660
// 007ad927  8d4c2404             lea ecx, [esp + 4]
// 007ad92b  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 007ad933  e8d8f9ffff           call 0x7ad310
// 007ad938  8b4604               mov eax, dword ptr [esi + 4]
// 007ad93b  8b16                 mov edx, dword ptr [esi]
// 007ad93d  8d0cc500000000       lea ecx, [eax*8]
// 007ad944  2bc8                 sub ecx, eax
// 007ad946  8d44cac8             lea eax, [edx + ecx*8 - 0x38]
// 007ad94a  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 007ad94e  64890d00000000       mov dword ptr fs:[0], ecx
// 007ad955  5e                   pop esi
// 007ad956  83c444               add esp, 0x44
// 007ad959  c21c00               ret 0x1c

struct Color3 {
    float r, g, b;
    Color3(const Color3& c) : r(c.r), g(c.g), b(c.b) {}
};

struct Handle {
    void* pointer;
    Handle() : pointer(0) {}
    Handle(const Handle& h) : pointer(h.pointer) {}
};

struct Pass {
    unsigned char data[56];
    Pass(Handle, Color3, float, float, float, float);
    ~Pass();
};

struct Level {
    Pass* passes;
    unsigned int count;
    void append(const Pass&);
    Level* add(const Pass& p) { append(p); return this; }
};

struct Material {
    unsigned char padding[12];
    Level level;
    Pass* addPass(Color3, float, float, float, float);
};

Pass* Material::addPass(Color3 color, float a, float b, float c, float d)
{
    Level* l = level.add(Pass(Handle(), color, a, b, c, d));
    return l->passes + l->count - 1;
}
