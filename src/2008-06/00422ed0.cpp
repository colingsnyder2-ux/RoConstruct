// from server: 100% by king_originala
typedef unsigned long Color;

struct ColorManager
{
    Color GetColor(int index);
    void SetColor(int index, Color color);
};

ColorManager* __cdecl GetColorManager();

struct S
{
    void f();
    void draw();
};

void S::f()
{
    ColorManager* manager = GetColorManager();
    Color oldColor = manager->GetColor(15);
    manager = GetColorManager();
    Color otherColor = manager->GetColor(13);

    unsigned int mixed = (unsigned char)(
        ((unsigned char)(otherColor >> 16) +
         (unsigned char)(oldColor >> 16)) / 2);

    mixed = (mixed << 8) | (unsigned char)(
        ((unsigned char)(otherColor >> 8) +
         (unsigned char)(oldColor >> 8)) / 2);

    mixed = (mixed << 8) | (unsigned char)(
        ((unsigned char)otherColor + (unsigned char)oldColor) / 2);

    GetColorManager()->SetColor(15, mixed);
    draw();
    GetColorManager()->SetColor(15, oldColor);
}
