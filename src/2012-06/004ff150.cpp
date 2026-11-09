// from server: 14% by atomic.potato
struct NedPoolingImpl {
    static void* allocBytes(unsigned int, const char*, int, const char*);
};

struct HardwareIndexBufferSharedPtr {
    void* p;
    HardwareIndexBufferSharedPtr();
    ~HardwareIndexBufferSharedPtr();
    HardwareIndexBufferSharedPtr& operator=(const HardwareIndexBufferSharedPtr&);
};

struct HardwareBufferManager {
    static HardwareBufferManager& getSingleton();
    void createHardwareIndexBuffer(int, unsigned int, int, void*);
};

struct SubMesh {
    char pad0[0x40];
    int indexCount;
};

struct Mesh {
    SubMesh* createSubMesh();
};

struct VertexData {
    char pad0[0x10];
    int vertexCount;
    char pad1[0x14];
    int indexCount;
};

struct AxisAlignedBox {
    float minX, minY, minZ;
    float maxX, maxY, maxZ;
    void setExtents(const float* min, const float* max);
};

struct UTVertexPositionNormalStudsTex {
    char pad0[8];
    VertexData* vertexData;
    HardwareIndexBufferSharedPtr indexBuffer;
    char pad1[0x20];
    AxisAlignedBox bounds;
    char pad2[0x10];
    int subMeshIndexCount;
    char pad3[0x10];
    int field_0x40;

    void* SpecializedMeshGen(int, int, int, int, int, int, int, int);
};

extern "C" {
    void __stdcall sub_4F7D50();
    void __stdcall sub_4F7E80();
    void __stdcall sub_4FE9E0();
    void __stdcall sub_5CA000();
}

void* UTVertexPositionNormalStudsTex::SpecializedMeshGen(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    HardwareIndexBufferSharedPtr local;
    SubMesh* subMesh;
    int numVerts = a2;
    int numIndices = a3;
    int i;
    float minX, minY, minZ;
    float maxX, maxY, maxZ;
    float* pMin;
    float* pMax;
    float* verts;
    float half = 0.5f;
    float fmin = 3.402823466e+38f;
    float fmax = -3.402823466e+38f;

    if (a1 != 0) {
        sub_4F7D50();
    } else {
        void* mem = NedPoolingImpl::allocBytes(0xcc, 0, 0, 0);
        if (mem != 0) {
            sub_4F7D50();
        } else {
            mem = 0;
        }
        *(int*)((char*)mem + 0x40) = 0;
    }

    if (*(char*)0xe31ab8 != 0) {
        sub_5CA000();
    }

    subMesh = ((Mesh*)a4)->createSubMesh();
    *(int*)((char*)subMesh + 8) = 0;
    *(char*)subMesh = 0;

    numIndices = numIndices * 3;

    HardwareBufferManager::getSingleton().createHardwareIndexBuffer(5, numIndices, 0, &local);

    int count = a5;
    if (count == 0) {
        count = a6;
    }

    void* vb = *(void**)((char*)this + 4);
    void* ib = *(void**)this;
    (*(void(__thiscall*)(void*, int, void*, int, int))(*(int*)((char*)ib + 0x18)))(ib, 0, vb, count, 1);

    sub_4FE9E0();

    *(int*)((char*)this->vertexData + 0x14) = numIndices;
    *(int*)((char*)this->vertexData + 0x10) = 0;

    minX = fmin; minY = fmin; minZ = fmin;
    maxX = fmax; maxY = fmax; maxZ = fmax;

    verts = (float*)a4;
    i = 0;
    if (numVerts >= 4) {
        int n = (numVerts - 4) >> 2;
        n++;
        i = n * 4;
        float* p = verts + 2;
        do {
            float x0 = p[-2], y0 = p[-1], z0 = p[0];
            if (minX > x0) minX = x0;
            if (minY > y0) minY = y0;
            if (minZ > z0) minZ = z0;
            if (x0 > maxX) maxX = x0;
            if (y0 > maxY) maxY = y0;
            if (z0 > maxZ) maxZ = z0;

            float x1 = p[7], y1 = p[8], z1 = p[9];
            if (minX > x1) minX = x1;
            if (minY > y1) minY = y1;
            if (minZ > z1) minZ = z1;
            if (x1 > maxX) maxX = x1;
            if (y1 > maxY) maxY = y1;
            if (z1 > maxZ) maxZ = z1;

            float x2 = p[16], y2 = p[17], z2 = p[18];
            if (minX > x2) minX = x2;
            if (minY > y2) minY = y2;
            if (minZ > z2) minZ = z2;
            if (x2 > maxX) maxX = x2;
            if (y2 > maxY) maxY = y2;
            if (z2 > maxZ) maxZ = z2;

            float x3 = p[25], y3 = p[26], z3 = p[27];
            if (minX > x3) minX = x3;
            if (minY > y3) minY = y3;
            if (minZ > z3) minZ = z3;
            if (x3 > maxX) maxX = x3;
            if (y3 > maxY) maxY = y3;
            if (z3 > maxZ) maxZ = z3;

            p += 36;
            n--;
        } while (n != 0);
    }

    if (i < numVerts) {
        float* p = verts + i * 9 + 2;
        int n = numVerts - i;
        do {
            float x0 = p[-2], y0 = p[-1], z0 = p[0];
            if (minX > x0) minX = x0;
            if (minY > y0) minY = y0;
            if (minZ > z0) minZ = z0;
            if (x0 > maxX) maxX = x0;
            if (y0 > maxY) maxY = y0;
            if (z0 > maxZ) maxZ = z0;
            p += 9;
            n--;
        } while (n != 0);
    }

    pMin = (float*)a7;
    pMin[0] = minX;
    pMin[1] = minY;
    pMin[2] = minZ;

    pMax = (float*)a8;
    pMax[0] = maxX;
    pMax[1] = maxY;
    pMax[2] = maxZ;

    float cx = (maxX + minX) * half;
    float cy = (maxY + minY) * half;
    float cz = (maxZ + minZ) * half;

    float center[3];
    center[0] = cx;
    center[1] = cy;
    center[2] = cz;

    this->bounds.setExtents(center, center);

    local.~HardwareIndexBufferSharedPtr();

    return subMesh;
}
