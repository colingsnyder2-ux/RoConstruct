// from server: 77% by atomic.potato
struct CXTPPropExchangeXMLNode {
    int field_14;
    int field_18;
    int field_28;
    int field_2c;
    
    CXTPPropExchangeXMLNode* method_86C0(unsigned short arg_0);
};

extern "C" int __stdcall sub_982C5A(int, int);
extern "C" int __stdcall sub_A9968C(CXTPPropExchangeXMLNode*);
extern "C" int (__thiscall *g_b24798)(int*);

CXTPPropExchangeXMLNode* CXTPPropExchangeXMLNode::method_86C0(unsigned short arg_0) {
    unsigned int eax = this->field_18;
    eax = ~eax;
    if ((eax & 1) == 0) {
        int* ecx = &this->field_14;
        int eax = g_b24798(ecx);
        sub_982C5A(2, eax);
    }
    
    int ecx = this->field_28 + 2;
    if (ecx > this->field_2c) {
        sub_A9968C(this);
    }
    
    unsigned short* edx = (unsigned short*)this->field_28;
    *edx = arg_0;
    this->field_28 += 2;
    return this;
}
