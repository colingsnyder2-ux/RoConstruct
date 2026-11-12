// from server: 81% by EspClaude
// from server: 43% by colin
// roc 2007-08 00715560  unit: CXTCaptionButton  size: 339 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00715560
// Shape (read off target): 16-byte value type (ctor 0x648580, copy 0x6485e0, dtor 0x6496a0,
// assign 0x649680/0x649660, test 0x648600); 8-byte helper {vptr 0x788300, data} with
// out-of-line base dtor 0x41f680; 4-byte temp (ctor 0x67f2c0, getter 0x6820a0); tail call 0x715440.
struct Value16 {
    int d[4];
    Value16();
    Value16(const Value16&);
    ~Value16();
    void Assign(const void* p);       // 0x649680
    void AssignOther(const void* p);  // 0x649660
    int Test();                       // 0x648600
};

struct HelperBase {
    void* data;
    HelperBase() : data(0) {}
    virtual ~HelperBase();
};
struct Helper : HelperBase {
    Helper() {}
    virtual ~Helper() {}
    void Load(const void* p);         // 0x630238
};

struct Temp4 {
    void* p;
    Temp4(void* d);                   // 0x67f2c0
    const void* Get();                // 0x6820a0
};

extern "C" const void* __cdecl sub_64AFA0(unsigned short id, int* out);

struct CXTCaptionButton {
    int sub_715440(int a0, int a1, Value16 v, Value16 w, int a3);
    int sub_715560(int a0, int a1, unsigned short id, int a3);
};

int CXTCaptionButton::sub_715560(int a0, int a1, unsigned short id, int a3)
{
    Value16 str;
    int out = 0;
    const void* r = sub_64AFA0(id, &out);
    if (r == 0)
        return 0;
    if (out != 0) {
        str.Assign(r);
    } else {
        Helper h;
        h.Load(r);
        str.AssignOther(Temp4(h.data).Get());
    }
    if (str.Test() != 0)
        return 0;
    return sub_715440(a0, a1, str, Value16(), a3);
}
