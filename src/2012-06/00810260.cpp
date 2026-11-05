// from server: 100% by tajop
// Destructor body of a multiple-inheritance class: six vftable stores
// (offsets 0, 4, 0x18, 0x1c, 0x80, 0x84 from the target) then a tail call
// to the base-class destructor at 0x735270.
extern const void* vft_bc57a4[];
extern const void* vft_bc5798[];
extern const void* vft_bc578c[];
extern const void* vft_bc5780[];
extern const void* vft_bc5770[];
extern const void* vft_bc5744[];

struct Base_735270 {
    void dtor_735270();
};

struct S_func_00810260 : Base_735270 {
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

void S_func_00810260::f()
{
    m_0 = vft_bc57a4;
    m_4 = vft_bc5798;
    m_18 = vft_bc578c;
    m_1c = vft_bc5780;
    m_80 = vft_bc5770;
    m_84 = vft_bc5744;
    dtor_735270();
}