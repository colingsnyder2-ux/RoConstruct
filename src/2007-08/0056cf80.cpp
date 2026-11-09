// from server: 100% by colin
struct LuaFunctionRef {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void* field18;
    void* field1C;
    void* field20;
    void* field24;

    void sub_56CC00(void*);
    LuaFunctionRef* sub_56CF80(void*);
};

extern "C" void __cdecl sub_5BEE10(void*, int, void*);
extern "C" void __cdecl sub_5BDEA0(void*, int, void*);
extern "C" void* __cdecl sub_5BED60(void*, int);

LuaFunctionRef* LuaFunctionRef::sub_56CF80(void* arg) {
    void* p18 = this->field18;
    if (p18 != 0) {
        sub_5BEE10(p18, -10000, this->field20);
    }
    this->sub_56CC00(arg);
    void* p18b = this->field18;
    if (p18b == 0) {
        this->field20 = p18b;
        return this;
    }
    void* p20 = *(void**)((char*)arg + 0x20);
    sub_5BDEA0(p18b, -10000, p20);
    void* p18c = this->field18;
    void* result = sub_5BED60(p18c, -10000);
    this->field20 = result;
    return this;
}
