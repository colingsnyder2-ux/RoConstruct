// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
namespace G3D {
template<class T> class Array {
public:
    int num;
    int numAllocated;
    T* data;
    T& operator[](int n);
};
}
struct P8{int a,b;};
int toIndex(int x, int sx, int y, int sy);
class Grid2D {
public:
    int sizeX;
    int sizeY;
    G3D::Array<P8> cells;
    G3D::Array<P8>& getCells();
    P8& get(int x, int y);
};
P8& Grid2D::get(int x, int y)
{
    return getCells()[toIndex(x, sizeX, y, sizeY)];
}
