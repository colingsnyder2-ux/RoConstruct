// from server: 87% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct DHTMLWindow {
    char pad0[8];
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    DHTMLWindow* init();
};

extern int g_8c23f8;
extern int g_8c23fc;

DHTMLWindow* DHTMLWindow::init()
{
    DHTMLWindow* self = this;
    int zero = 0;
    self->field8 = zero;
    self->fieldc = zero;
    self->field10 = zero;
    self->field14 = 0x787200;
    self->field18 = g_8c23f8;
    int v = g_8c23fc;
    self->field1c = v;
    if (v == zero) {
        _InterlockedExchangeAdd((volatile long*)(v + 4), 1);
    }
    self->field20 = zero;
    self->field24 = zero;
    self->field28 = zero;
    self->field2c = zero;
    self->field30 = zero;
    self->field14 = 0x787208;
    self->field34 = zero;
    return self;
}
