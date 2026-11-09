// from server: 55% by atomic.potato
// roc 2012-06 0091a960  unit: RBX::Assembly  size: 255 bytes
// library v8world/TerrainPartition.cpp

extern "C" {
    int __cdecl sub_972290(int, const char*);
}

extern unsigned char byte_E580B3;
extern int dword_E5809C;

struct TerrainPartition {
    char pad0[4];
    int* field4;
    char pad8[0x30 - 8];
    unsigned char field30;
    char pad31[1];
    unsigned short field32;
    void method_91a390(int, int, int);
    int method_91a2f0(int, int);
    void method_91a960(int);
};

void TerrainPartition::method_91a960(int a2)
{
    if (byte_E580B3 != 0 && field30 == 0) {
        if (dword_E5809C != 0) {
            if (((int (__cdecl*)(int, const char*, const char*))dword_E5809C)(0xea,
                    "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\v8world\\TerrainPartition.cpp",
                    "initialPartitioningBuilt") != 0)
                goto skip;
        }
        sub_972290(byte_E580B3,
            "initialPartitioningBuilt file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\v8world\\TerrainPartition.cpp line: 234");
    }
skip:
    int i = 0;
    if ((short)i >= (short)field32)
        return;
    do {
        unsigned short v1 = 0;
        unsigned short v2 = 0;
        unsigned short v3 = 0;
        method_91a390(a2, (int)&v1, (int)&v2);
        int* p = (int*)((char*)field4 + (short)i * 20);
        int r = method_91a2f0((int)&v3, (int)&v1);
        int* edx = (int*)p[2];
        int ecx = 0;
        if (r != 0) {
            if (r >= 0) {
                ecx = (unsigned)r >> 5;
                edx = (int*)((char*)edx + ecx * 4);
            } else {
                ecx = -r;
                if (ecx != 0) {
                    ecx = 0xffffffff;
                    ecx = ecx - r;
                    ecx = ecx >> 5;
                    ecx = ecx + ecx;
                    ecx = ecx + ecx;
                    int edi = 0xfffffffc;
                    edi = edi - ecx;
                    edx = (int*)((char*)edx + edi);
                }
            }
            ecx = r & 0x1f;
        }
        *edx |= 1 << ecx;
        i++;
    } while ((short)i < (short)field32);
}
