// from server: 100% by colin
struct Float3
{
    float r, g, b;
};

struct RGB
{
    unsigned char r, g, b;
    RGB() {}
    RGB(const Float3&);
};

struct PackedColor
{
    unsigned int value;
    Float3* getColor(Float3*);
};

extern PackedColor currentColor;
extern "C" unsigned int* __cdecl closestColor(unsigned int*, RGB);

struct CDataModelPropGrid
{
    void func_431160(int, int);
};

struct ColorDialog
{
    char padding[0x124];
    unsigned int color;
    char tail[4];

    ColorDialog(unsigned int, unsigned int, unsigned int,
                CDataModelPropGrid*);
    ~ColorDialog();
    int doModal();
};

struct MainFrame
{
    void updateColor(unsigned int);
};

extern MainFrame mainFrame;

void CDataModelPropGrid::func_431160(int, int)
{
    Float3 floats;
    RGB rgb(*PackedColor(currentColor).getColor(&floats));

    unsigned int color =
        ((static_cast<unsigned int>(rgb.b) << 8) | rgb.g) << 8 | rgb.r;

    ColorDialog dialog(color, color, 0x40, this);
    if (dialog.doModal() == 1)
    {
        RGB selected;
        selected.r = static_cast<unsigned char>(dialog.color);
        selected.g = static_cast<unsigned char>(dialog.color >> 8);
        selected.b = static_cast<unsigned char>(dialog.color >> 16);

        unsigned int result;
        unsigned int value = *closestColor(&result, selected);
        if (currentColor.value != value)
        {
            currentColor.value = value;
            mainFrame.updateColor(value);
        }
    }
}
