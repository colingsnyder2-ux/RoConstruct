// from server: 100% by king_originala
struct Text;

extern const char authoring[];
extern int (__thiscall* compareText)(const Text*, const char*);
extern void (__thiscall* destroyText)(Text*);

struct Text {
    void* data;
    int compare(const char* s) const;
    ~Text();
};

inline int Text::compare(const char* s) const
{
    return compareText(this, s);
}

inline Text::~Text()
{
    destroyText(this);
}

struct Rect {
    int left;
    int top;
    int right;
    int bottom;
};

struct XBrickColorItem {
    Text getText();
    int baseAction(void* context, Rect bounds);
    int action(void* context, Rect bounds);
};

int XBrickColorItem::action(void* context, Rect bounds)
{
    if (getText().compare(authoring) == 0)
        return 0;
    return baseAction(context, bounds);
}
