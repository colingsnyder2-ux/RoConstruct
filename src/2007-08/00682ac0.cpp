// from server: 100% by colin
struct CXTPPropertyGrid
{
    char pad[0x14c];
    int* field_14c;
    int get();
};

extern int __cdecl helper_0064dfd0();

int CXTPPropertyGrid::get()
{
    if (field_14c == 0)
        return helper_0064dfd0();
    return (int)field_14c;
}
