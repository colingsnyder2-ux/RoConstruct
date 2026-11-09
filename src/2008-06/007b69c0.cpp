// from server: 42% by king_originala




struct Pair {
    float x, y;
};

struct S {
    char header[12];
    int advance[128];
    int cellWidth;
    int cellHeight;

    Pair f(const char* text, int count, Pair* out,
           double x, double y, float scaleX, float scaleY,
           int fixed, int fixedAdvance);
};

Pair S::f(const char* text, int count, Pair* out,
          double x, double y, float scaleX, float scaleY,
          int fixed, int fixedAdvance)
{
    const double width = cellWidth * (double)scaleX;
    const double height = cellHeight * (double)scaleY;
    const double rightOffset = (cellWidth - 1) * (double)scaleX;
    const float step = fixedAdvance * scaleX;

    for (int i = 0; i < count; ++i) {
        signed char ch = text[i];
        int column = (char)ch & 15;
        int row = (char)ch >> 4;

        double inset;
        if (fixed)
            inset = (width - step) * 0.5;
        else
            inset = 0.0;

        const double left = x - inset;

        out->x = (float)(cellWidth * column);
        out->y = (float)(cellHeight * row + 1);
        ++out;
        out->x = (float)left;
        out->y = (float)(y + scaleY);
        ++out;

        out->x = (float)(cellWidth * column);
        out->y = (float)(cellHeight * (row + 1) - 2);
        ++out;
        out->x = (float)left;
        out->y = (float)(y + height - 2.0 * scaleY);
        ++out;

        out->x = (float)(cellWidth * (column + 1) - 1);
        out->y = (float)(cellHeight * (row + 1) - 2);
        ++out;
        out->x = (float)(left + rightOffset);
        out->y = (float)(y + height - 2.0 * scaleY);
        ++out;

        out->x = (float)(cellWidth * (column + 1) - 1);
        out->y = (float)(cellHeight * row + 1);
        ++out;
        out->x = (float)(left + rightOffset);
        out->y = (float)(y + scaleY);
        ++out;

        if (!fixed)
            x += advance[ch] * (double)scaleX;
        else
            x += step;
    }

    Pair result;
    result.x = (float)x;
    result.y = (float)height;
    return result;
}
