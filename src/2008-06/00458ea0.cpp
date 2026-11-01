// from server: 100% by king_originala
extern "C" int (__stdcall *PostMessageA)(void *, unsigned int, unsigned int, long);

struct CRobloxView {
    void notify(unsigned int, long);
};

void CRobloxView::notify(unsigned int, long)
{
    void *window = *reinterpret_cast<void **>(
        reinterpret_cast<char *>(this) - 0x88);
    PostMessageA(window, 0x46B, 0, 0);
}
