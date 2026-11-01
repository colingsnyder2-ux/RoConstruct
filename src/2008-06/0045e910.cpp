// from server: 100% by king_originala
struct Rect {
    long left, top, right, bottom;
};

extern "C" {
    extern int (__stdcall *IsRectEmpty)(const Rect *);
    extern int (__stdcall *GetClientRect)(void *, Rect *);
    extern int (__stdcall *DrawTextA)(void *, const char *, int, Rect *, unsigned int);
}

struct Window;

struct PaintContext {
    unsigned char prefix[4];
    void *dc;
    unsigned char middle[20];
    Rect rect;
    unsigned char tail[40];

    PaintContext(Window *);
    ~PaintContext();
};

struct Guard {
    unsigned char storage[24];

    Guard(void *, int);
    ~Guard();
};

struct Image {
    void makeCurrent();
};

struct Renderer {
    void prepare();
    void render();
};

struct View {
    bool ready();
};

struct Service {
    virtual void slot0();
    virtual void slot1();
    virtual bool enabled(void *);
};

extern Service *service;
extern unsigned char changed;
extern void *getContext();
extern void notify();

struct Window {
    unsigned char pad0[0x20];
    void *handle;
    unsigned char pad24[0x4c];
    View *view;
    unsigned char pad74[0x0c];
    bool pending;
    unsigned char pad81[9];
    bool active;
    bool refresh;
    unsigned char pad8c[0x0c];
    void *lock;
    unsigned char pad9c[8];
    Image *image;
    unsigned char pada8[4];
    Renderer *renderer;

    bool draw();
    void update();
    void setMode(bool);
};

bool Window::draw()
{
    bool result = false;
    PaintContext paint(this);

    if (image && paint.dc && view && !IsRectEmpty(&paint.rect)) {
        image->makeCurrent();

        if (!renderer) {
            Rect rect;
            GetClientRect(handle, &rect);
            DrawTextA(paint.dc,
                      "Roblox can't run with your graphics driver",
                      -1, &rect, 0x8000);
        } else {
            void *guardLock = lock;
            Guard guard(guardLock, 1);
            update();
            renderer->prepare();
            setMode(true);
            result = true;
            renderer->render();
            active = true;

            if (!refresh) {
                void *context = getContext();
                void *argument = context
                    ? static_cast<unsigned char *>(context) + 0x14
                    : 0;
                if (!service->enabled(argument) || !view->ready()) {
                    update();
                    refresh = false;
                }
            } else {
                update();
                refresh = false;
            }

            if (pending) {
                pending = false;
                notify();
                changed = 1;
            }
        }
    }

    return result;
}
