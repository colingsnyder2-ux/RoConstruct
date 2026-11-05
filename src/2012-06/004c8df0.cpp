// from server: 14% by tester
struct AdornRbxGfx {
    int render3dAdorn(int, int, int, int, int, int, int, int, int, int, int, int);
};

int AdornRbxGfx::render3dAdorn(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
    int (AdornRbxGfx::*fn)(int, int, int, int, int, int, int, int, int, int, int, int);
    fn = *(int (AdornRbxGfx::**)(int, int, int, int, int, int, int, int, int, int, int, int))(*(int*)this + 0x48);
    return (this->*fn)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}
