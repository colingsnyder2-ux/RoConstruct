// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0045b010  unit: CRobloxWnd  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045b010
//
// 0045b010  83ec18               sub esp, 0x18
// 0045b013  56                   push esi
// 0045b014  8bf1                 mov esi, ecx
// 0045b016  83beb800000000       cmp dword ptr [esi + 0xb8], 0
// 0045b01d  0f849a000000         je 0x45b0bd
// 0045b023  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0045b026  57                   push edi
// 0045b027  8d442410             lea eax, [esp + 0x10]
// 0045b02b  50                   push eax
// 0045b02c  51                   push ecx
// 0045b02d  ff15842d8000         call dword ptr [0x802d84]
// 0045b033  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0045b039  8b700c               mov esi, dword ptr [eax + 0xc]
// 0045b03c  8b16                 mov edx, dword ptr [esi]
// 0045b03e  8b7808               mov edi, dword ptr [eax + 8]
// 0045b041  8b82c4000000         mov eax, dword ptr [edx + 0xc4]
// 0045b047  8bce                 mov ecx, esi
// 0045b049  ffd0                 call eax
// 0045b04b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0045b04f  2b4c2414             sub ecx, dword ptr [esp + 0x14]
// 0045b053  7454                 je 0x45b0a9
// 0045b055  85ff                 test edi, edi
// 0045b057  7450                 je 0x45b0a9
// 0045b059  8b16                 mov edx, dword ptr [esi]
// 0045b05b  8b420c               mov eax, dword ptr [edx + 0xc]
// 0045b05e  53                   push ebx
// 0045b05f  8b1f                 mov ebx, dword ptr [edi]
// 0045b061  8bce                 mov ecx, esi
// 0045b063  ffd0                 call eax
// 0045b065  8944240c             mov dword ptr [esp + 0xc], eax
// 0045b069  db44240c             fild dword ptr [esp + 0xc]
// 0045b06d  85c0                 test eax, eax
// 0045b06f  7d06                 jge 0x45b077
// 0045b071  d80578978100         fadd dword ptr [0x819778]
// 0045b077  8b16                 mov edx, dword ptr [esi]
// 0045b079  d95c240c             fstp dword ptr [esp + 0xc]
// 0045b07d  8b4210               mov eax, dword ptr [edx + 0x10]
// 0045b080  8bce                 mov ecx, esi
// 0045b082  ffd0                 call eax
// 0045b084  89442410             mov dword ptr [esp + 0x10], eax
// 0045b088  db442410             fild dword ptr [esp + 0x10]
// 0045b08c  85c0                 test eax, eax
// 0045b08e  7d06                 jge 0x45b096
// 0045b090  d80578978100         fadd dword ptr [0x819778]
// 0045b096  d87c240c             fdivr dword ptr [esp + 0xc]
// 0045b09a  8b932c010000         mov edx, dword ptr [ebx + 0x12c]
// 0045b0a0  51                   push ecx
// 0045b0a1  8bcf                 mov ecx, edi
// 0045b0a3  d91c24               fstp dword ptr [esp]
// 0045b0a6  ffd2                 call edx
// 0045b0a8  5b                   pop ebx
// 0045b0a9  d9ee                 fldz 
// 0045b0ab  8d442408             lea eax, [esp + 8]
// 0045b0af  50                   push eax
// 0045b0b0  d95c240c             fstp dword ptr [esp + 0xc]
// 0045b0b4  8bcf                 mov ecx, edi
// 0045b0b6  ff15b04e8000         call dword ptr [0x804eb0]
// 0045b0bc  5f                   pop edi
// 0045b0bd  5e                   pop esi
// 0045b0be  83c418               add esp, 0x18
// 0045b0c1  c20c00               ret 0xc

#pragma float_control(precise, off)

struct Rect {
    long left, top, right, bottom;
};

extern "C" int (__stdcall *GetClientRect)(void *, Rect *);

#define V(n) virtual void slot##n();
#define V10(a,b,c,d,e,f,g,h,i,j) V(a) V(b) V(c) V(d) V(e) V(f) V(g) V(h) V(i) V(j)

struct Viewport {
    V(0) V(1) V(2)
    virtual unsigned int getWidth();
    virtual unsigned int getHeight();
    V(5) V(6) V(7) V(8) V(9)
    V10(10,11,12,13,14,15,16,17,18,19)
    V10(20,21,22,23,24,25,26,27,28,29)
    V10(30,31,32,33,34,35,36,37,38,39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48)
    virtual void update();
};

namespace Ogre {
    struct Radian {
        float value;
        Radian() : value(0.0f) {}
    };

    struct Camera {
        V10(0,1,2,3,4,5,6,7,8,9)
        V10(10,11,12,13,14,15,16,17,18,19)
        V10(20,21,22,23,24,25,26,27,28,29)
        V10(30,31,32,33,34,35,36,37,38,39)
        V10(40,41,42,43,44,45,46,47,48,49)
        V10(50,51,52,53,54,55,56,57,58,59)
        V10(60,61,62,63,64,65,66,67,68,69)
        V(70) V(71) V(72) V(73) V(74)
        virtual void setAspectRatio(float);
    };

    extern void (__thiscall *yaw)(Camera *, const Radian &);
}

#undef V10
#undef V

struct Context {
    char padding[0x14];
    Ogre::Camera *camera;
    Viewport *viewport;
};

struct CRobloxWnd {
    char padding0[0x20];
    void *window;
    char padding1[0xdc];
    Context *context;
    void resize(unsigned int, unsigned int, unsigned int);
};

void CRobloxWnd::resize(unsigned int, unsigned int, unsigned int)
{
    if (context) {
        Rect rect;
        GetClientRect(window, &rect);
        Viewport *viewport = context->viewport;
        Ogre::Camera *camera = context->camera;
        viewport->update();

        if (rect.bottom - rect.top && camera)
            camera->setAspectRatio((float)viewport->getWidth() /
                                   (float)viewport->getHeight());

        Ogre::yaw(camera, Ogre::Radian());
    }
}


