// from server: 100% by colin
struct ScriptContext {
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
    field0 = 0x7a5df4;
    field4 = 0x7a5dec;
    field10 = 0x7a5de4;
    field14 = 0x7a5dd4;
    field2C = 0x7a5dc4;
    field44 = 0x7a5db4;
    field5C = 0x7a5da4;
    field74 = 0x7a5d94;
    field8C = 0x7a5d84;
    return this;
}
