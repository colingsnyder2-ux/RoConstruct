// from server: 48% by atomic.potato
struct OgreString {
    char pad[0x1c];
    OgreString(const char*);
    ~OgreString();
};

struct OgreMaterialPtr {
    char pad[4];
    OgreMaterialPtr(const OgreMaterialPtr&);
    ~OgreMaterialPtr();
};

struct OgreMaterial {
    unsigned short getNumTechniques() const;
    void removeTechnique(unsigned short);
};

struct OgreMaterialManager {
    static OgreMaterialManager& getSingleton();
};

extern "C" {
    void __stdcall sub_5CA000(int, const char*, int, int, int);
}

struct VMegaClusterInstance {
    char pad0[0x40];
    int field40;
    int field44;
    char field48;
    char field49;
    char pad4a[2];
    int field4c;
    char pad50[4];
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    short field68;
    short field6a;
    short field6c;

    void sub_515400();
    void construct(int);
};

void VMegaClusterInstance::construct(int arg) {
    sub_515400();
    field40 = 0;
    field44 = 0;
    field54 = 0;
    field58 = 0;
    field5c = 0;
    field60 = arg;
    field68 = 0;
    field6a = 0;
    field6c = 0;

    int* p = *(int**)(arg + 0x4720);
    unsigned char b = *(unsigned char*)(*(int*)((char*)p + 0x874) + 0xe);
    field48 = b;
    if (b != 0) {
        int* p2 = *(int**)(arg + 0x4720);
        unsigned int v = *(unsigned int*)(*(int*)((char*)p2 + 0x874) + 0x34);
        unsigned int q = (unsigned int)(((unsigned long long)v * 0xAAAAAAABULL) >> 32) >> 2;
        int r;
        if (q > 0x4000)
            r = 0x10000;
        else
            r = 0x4000;
        field4c = r;
    } else {
        field4c = 0x4000;
    }

    int* p3 = *(int**)(arg + 0x4720);
    unsigned char c = *(unsigned char*)(*(int*)((char*)p3 + 0x85c) + 0x44);
    if (c != 0) {
        OgreString s1("MegaCluster_Water");
        OgreMaterialManager& mm = OgreMaterialManager::getSingleton();
        OgreMaterial* mat = 0;
        OgreMaterialPtr mp(*(OgreMaterialPtr*)&mat);
        unsigned short n = mat->getNumTechniques();
        while (n > 1) {
            mat->removeTechnique(0);
            n = mat->getNumTechniques();
        }
        field49 = 0;
        unsigned char g = *(unsigned char*)0xdac775;
        if (g != 0) {
            sub_5CA000(g, "Creating Mega Cluster: %d, %d", field48, field4c, 0);
        }
    } else {
        int* p4 = *(int**)(arg + 0x4720);
        float f = *(float*)(*(int*)((char*)p4 + 0x874) + 0x3c);
        if (f > *(float*)0xb53ac8)
            field49 = 1;
        else
            field49 = 0;
        unsigned char g = *(unsigned char*)0xdac775;
        if (g != 0) {
            sub_5CA000(g, "Creating Mega Cluster: %d, %d", field48, field4c, 0);
        }
    }

    field64 = *(int*)0xe1dda8;
    *(int*)0xe1dda8 = *(int*)0xe1dda8 + 1;
}
