// from server: 100% by king_originala
struct Color
{
    unsigned int value;
    unsigned int getClosestPaletteIndex() const;
};

struct Source
{
    Color* getColor(Color* result) const;
};

struct Writer
{
    void write(const unsigned int* value, int bits, int count);
};

void func_004a7570(Source* source, Writer* writer)
{
    Color temporary;
    Color color = *source->getColor(&temporary);
    unsigned int index = color.getClosestPaletteIndex();
    writer->write(&index, 5, 1);
}
