// from server: 100% by colin
struct Text {
    char storage[20];
    unsigned int length;
    unsigned int capacity;
    ~Text();
};

extern void (__thiscall *destroyText)(Text *);
extern Text (__cdecl *prependText)(const char *, const Text &);
extern const char prefix[];

inline Text::~Text()
{
    destroyText(this);
}

struct Point {
    float x, y;
};

struct Rectangle {
    Point first, second;
};

extern void __cdecl makeRectangle(Rectangle *, const Point *, const Point *);
extern float *__cdecl activeColor();
extern float *__cdecl inactiveColor();
extern float *__cdecl backgroundColor();
extern void *__cdecl selectFont();

inline void copyRectangle(Rectangle *destination, const Rectangle &source)
{
    makeRectangle(destination, &source.first, &source.second);
}

struct Context;
struct Action;

struct ContextTable {
    void *slots[11];
    void (__thiscall *paint)(Context *, const Rectangle *, float *);
};

struct Context {
    ContextTable *table;
};

struct ActionTable {
    void *slots[3];
    bool (__thiscall *checked)(Action *);
};

struct Action {
    ActionTable *table;
};

struct MenuItem {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual Text caption();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual bool enabled();

    char storage[0x140];
    int state;
    Action *action;
    Text text;

    Rectangle bounds();
    void drawText(Context *, const Text &, float *, void *, int);
    void render(Context *);
};

void MenuItem::render(Context *context)
{
    if (state == 1 || state == 2) {
        Rectangle rectangle;
        copyRectangle(&rectangle, bounds());
        context->table->paint(context, &rectangle, backgroundColor());
    }

    enabled();
    float *color = enabled() ? activeColor() : inactiveColor();
    Action *currentAction = action;

    drawText(context,
             currentAction && currentAction->table->checked(currentAction)
                 ? prependText(prefix, caption())
                 : caption(),
             color, selectFont(), 1);

    if (text.length > 0) {
        float *secondColor = enabled() ? activeColor() : inactiveColor();
        drawText(context, text, secondColor, selectFont(), 0);
    }
}
