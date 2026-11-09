// from server: 100% by tajop
// Destructor body of a multiple-inheritance class: six vftable stores
// (offsets 0, 4, 0x18, 0x1c, 0x80, 0x84 from the target) then a tail call
// to the base-class destructor at 0x735660.
extern const void* vft_bd7754[];
extern const void* vft_bd774c[];
extern const void* vft_bd7740[];
extern const void* vft_bd7734[];
extern const void* vft_bd7724[];
extern const void* vft_bd76f8[];

struct Base_735660 {
    void dtor_735660();
};

struct S_func_008761e0 : Base_735660 {
    const void** m_0;
    const void** m_4;
    char pad8[16];
    const void** m_18;
    const void** m_1c;
    char pad20[96];
    const void** m_80;
    const void** m_84;

    void f();
};

void S_func_008761e0::f()
{
    m_0 = vft_bd7754;
    m_4 = vft_bd774c;
    m_18 = vft_bd7740;
    m_1c = vft_bd7734;
    m_80 = vft_bd7724;
    m_84 = vft_bd76f8;
    dtor_735660();
}