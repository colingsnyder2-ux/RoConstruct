// from server: 83% by atomic.potato
struct CXTColorHex
{
    int OnInit(int);
    int (**vtable)();
};

int CXTColorHex::OnInit(int)
{
    int result = OnInit(0);
    if (result == -1)
        return result;

    vtable[83]();
    return 0;
}
