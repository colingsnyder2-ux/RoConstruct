// from server: 100% by atomic.potato
struct CPropertyGridItemBrickColor
{
    int vtable;
    int unused0[66];
    int field10c;
    int field110;

    void unused();
};

void CPropertyGridItemBrickColor::unused()
{
    int value = field110;
    if (value != 0 && *(int *)value != field10c)
        (*(void (__thiscall **)(CPropertyGridItemBrickColor *, int))(*(int *)this + 0xe4))(this, *(int *)value);
}
