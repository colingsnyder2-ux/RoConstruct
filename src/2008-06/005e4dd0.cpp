// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct ConnectorBase {
    unsigned int words[49];
    ConnectorBase();
};

struct Connector : ConnectorBase {
    float value;
    Connector() : ConnectorBase(), value(0.0f) {
        words[0] = 0x0083e17c;
    }
};

struct FactoryBase {
    unsigned int words[77];
    FactoryBase(ConnectorBase*);
};

struct Factory : FactoryBase {
    Factory();
};

Factory::Factory() : FactoryBase(new Connector) {
    words[0]  = 0x0083f5b4;
    words[4]  = 0x0083f5a8;
    words[5]  = 0x0083f5a0;
    words[8]  = 0x0083f598;
    words[9]  = 0x0083f588;
    words[17] = 0x0083f578;
    words[25] = 0x0083f568;
    words[33] = 0x0083f558;
    words[41] = 0x0083f548;
    words[49] = 0x0083f538;
    words[76] = 0x0083f520;
}
