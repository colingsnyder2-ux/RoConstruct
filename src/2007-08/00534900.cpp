// from server: 100% by colin
struct ScriptContext {
    void construct(int);
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    ScriptContext* init(int);
};

extern "C" void __stdcall sub_5426B0(int);

ScriptContext* ScriptContext::init(int a) {
    sub_5426B0(a);
    field0 = 0x79328c;
    field4 = 0x793284;
    field10 = 0x79327c;
    field14 = 0x79326c;
    field2C = 0x79325c;
    field44 = 0x79324c;
    field5C = 0x79323c;
    field74 = 0x79322c;
    field8C = 0x79321c;
    return this;
}
