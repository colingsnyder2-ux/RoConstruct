// from server: 100% by colin
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
    char padding[8];
    Ogre::Camera *camera;
    Viewport *viewport;
};

struct CRobloxWnd {
    char padding0[0x20];
    void *window;
    char padding1[0x94];
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


