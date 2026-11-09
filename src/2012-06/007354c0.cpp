// from server: 100% by tajop
// Destructor body of a multiple-inheritance class: six vftable stores
// (offsets 0, 4, 0x18, 0x1c, 0x80, 0x84 from the target) then a tail call
// to the base-class destructor at 0x735270.
extern const void* vft_ba7fd4[];
extern const void* vft_ba7fcc[];
extern const void* vft_ba7fc0[];
extern const void* vft_ba7fb4[];
extern const void* vft_ba7fa4[];
extern const void* vft_ba7f78[];

struct Base_735270 {
    void dtor_735270();
};

struct S_func_007354c0 : Base_735270 {
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

void S_func_007354c0::f()
{
    m_0 = vft_ba7fd4;
    m_4 = vft_ba7fcc;
    m_18 = vft_ba7fc0;
    m_1c = vft_ba7fb4;
    m_80 = vft_ba7fa4;
    m_84 = vft_ba7f78;
    dtor_735270();
}