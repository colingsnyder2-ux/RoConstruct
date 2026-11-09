// from server: 100% by tajop
// Destructor body of a multiple-inheritance class: six vftable stores
// (offsets 0, 4, 0x18, 0x1c, 0x80, 0x84 from the target) then a tail call
// to the base-class destructor at 0x8d2f70.
extern const void* vft_becfb4[];
extern const void* vft_becfa8[];
extern const void* vft_becf9c[];
extern const void* vft_becf90[];
extern const void* vft_becf80[];
extern const void* vft_becf54[];

struct Base_8d2f70 {
    void dtor_8d2f70();
};

struct S_func_008e6e90 : Base_8d2f70 {
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

void S_func_008e6e90::f()
{
    m_0 = vft_becfb4;
    m_4 = vft_becfa8;
    m_18 = vft_becf9c;
    m_1c = vft_becf90;
    m_80 = vft_becf80;
    m_84 = vft_becf54;
    dtor_8d2f70();
}