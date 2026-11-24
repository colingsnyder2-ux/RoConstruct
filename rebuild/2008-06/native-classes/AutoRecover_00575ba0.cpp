// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: structs below are layout analogs derived from the disassembly offsets.
namespace RBX { double getRealTime(); }

struct GuiEvent {
    int type;
    int a4;
    int a8;
    int ac;
    short x;
    short y;
    void* source;
};

struct GuiResponse {
    void* handled;
    void* target;
};

struct GuiHandler {
    virtual GuiResponse* process(GuiResponse* out, const GuiEvent* ev);
};

extern float g_guiMouseX;  // 0x974d78
extern float g_guiMouseY;  // 0x974d7c
extern "C" void* __fastcall fn_00575890(void* self, int unusedEdx, GuiResponse* out, const GuiEvent* ev);
extern "C" int __fastcall fn_00492320(void* self, int unusedEdx, int a1);

#define FIELD(T, p, off) (*(T*)((char*)(p) + (off)))

extern "C" void __fastcall fn_00575ba0(void* self, int unusedEdx, const GuiEvent* ev)
{
    double t0 = RBX::getRealTime();

    if (ev->type >= 1 && ev->type <= 7) {
        g_guiMouseX = (float)ev->x;
        g_guiMouseY = (float)ev->y;
    }

    GuiEvent e;
    e.type = ev->type;
    e.a4 = ev->a4;
    e.a8 = ev->a8;
    e.ac = ev->ac;
    e.x = ev->x;
    e.y = ev->y;
    e.source = self ? (char*)self + 0x1f0 : 0;

    GuiResponse tmp;
    GuiResponse* r;
    GuiHandler* cur = FIELD(GuiHandler*, self, 0x22c);
    if (cur) {
        r = cur->process(&tmp, &e);
    } else {
        tmp.handled = 0;
        tmp.target = 0;
        r = &tmp;
    }
    void* handled = r->handled;
    void* target = r->target;

    if (!handled) {
        r = ((GuiHandler*)((char*)FIELD(void*, self, 0x224) + 0x130))->process(&tmp, &e);
        handled = r->handled; target = r->target;
        if (!handled) {
            r = ((GuiHandler*)((char*)FIELD(void*, self, 0x21c) + 0x130))->process(&tmp, &e);
            handled = r->handled; target = r->target;
            if (!handled) {
                r = ((GuiHandler*)((char*)FIELD(void*, self, 0x1fc) + 0x130))->process(&tmp, &e);
                handled = r->handled; target = r->target;
                if (!handled) {
                    r = (GuiResponse*)fn_00575890(self, 0, &tmp, &e);
                    handled = r->handled; target = r->target;
                }
            }
        }
    }

    bool flag = false;
    if (handled) {
        void* p = FIELD(void*, self, 0x204);
        void* cmp = p ? (char*)p + 0x2e8 : 0;
        flag = FIELD(void*, self, 0x22c) != cmp;
    }
    FIELD(char, self, 0x230) = flag;

    if (!handled) {
        void* p = FIELD(void*, self, 0x204);
        r = ((GuiHandler*)((char*)p + 0x2e8))->process(&tmp, &e);
        handled = r->handled;
        target = r->target;
    }

    int t = ev->type;
    if ((t >= 1 && t <= 7) || t == 10)
        fn_00492320(self, 0, 0);

    FIELD(void*, self, 0x22c) = target;
    void* timer = FIELD(void*, self, 0x20c);
    FIELD(double, timer, 0x1e0) += RBX::getRealTime() - t0;
}
