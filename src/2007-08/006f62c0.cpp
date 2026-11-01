// from server: 100% by colin
struct CXTPPropertyGridInplaceButtons
{
    char pad[0x70];
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    void sub_738382();
    void func();
};

typedef void (__thiscall *FnPtr)(void*);
extern FnPtr g_fn_77ddbc;

void CXTPPropertyGridInplaceButtons::func()
{
    g_fn_77ddbc(&field84);
    g_fn_77ddbc(&field80);
    g_fn_77ddbc(&field7c);
    g_fn_77ddbc(&field78);
    g_fn_77ddbc(&field74);
    g_fn_77ddbc(&field70);
    sub_738382();
}
