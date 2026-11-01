// from server: 100% by king_originala
#pragma optimize("", off)

extern int __cdecl clampValue(int value, int minimum, int maximum);

struct Values {
    int size();
};

struct Mesh {
    char padding[12];
    Values values;
    int index(double fraction);
};

int Mesh::index(double fraction)
{
    return clampValue((int)(values.size() * fraction), 0, values.size() - 1);
}
