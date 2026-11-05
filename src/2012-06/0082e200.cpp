// from server: 47% by atomic.potato
// roc 2012-06 0082e200  unit: RBX::BallBlockContact  size: 362 bytes

struct SpatialNode {
    char pad0[0x34];
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
};

struct Vec3 {
    int x, y, z;
};

struct BallBlockContact {
    int method(SpatialNode* node);
};

extern "C" int __stdcall sub_7b9450(int);
extern "C" int __stdcall sub_50c4b0(int);
extern "C" int __stdcall sub_7bb0f0(int);
extern "C" void __stdcall sub_50d1b0(int, int);
extern "C" int __stdcall sub_828a10(int, int, int);
extern "C" void __stdcall sub_7c0860(int, int, int, int);
extern "C" void __stdcall sub_50c990(int, int, int);
extern "C" void __stdcall sub_82de70(int, int, int, int);
extern "C" void __stdcall sub_972290(int, int);

extern unsigned char byte_e580b3;
extern int dword_e5809c;

int BallBlockContact::method(SpatialNode* node)
{
    int result;
    int local1;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    int level;

    result = sub_7b9450((int)node);
    if (result == 10)
        return 0;

    if (byte_e580b3 != 0) {
        int r = sub_50c4b0((int)&node->field34);
        if (r != -1) {
            if (dword_e5809c != 0) {
                if (((int (__stdcall*)(int, int, int))dword_e5809c)(0xb6d538, 0xbce148, 0x220) != 0)
                    goto skip1;
            }
            sub_972290(byte_e580b3, 0xbcfa18);
        }
    }
skip1:
    level = sub_7bb0f0((int)node);
    sub_50d1b0((int)&local1, level);

    result = sub_828a10((int)this, (int)node, (int)&local1);

    v1.x = 0; v1.y = 0; v1.z = 0;
    v2.x = 0; v2.y = 0; v2.z = 0;
    v3.x = 0; v3.y = 0; v3.z = 0;

    sub_7c0860(result, (int)&v3, (int)&v2, (int)&v1);
    node->field4c = result;

    sub_50c990((int)&v3, (int)&v2, (int)&v1);

    node->field34 = v3.x;
    node->field38 = v3.y;
    node->field3c = v3.z;
    node->field40 = v2.x;
    node->field44 = v2.y;
    node->field48 = v2.z;

    sub_82de70((int)node, (int)&v3, 0, (int)&v3);

    if (byte_e580b3 != 0) {
        int r2 = sub_50c4b0((int)&node->field34);
        if (r2 != result) {
            if (dword_e5809c != 0) {
                if (((int (__stdcall*)(int, int, int))dword_e5809c)(0xb6d484, 0xbce148, 0x22e) != 0)
                    return 0;
            }
            sub_972290(byte_e580b3, 0xbcf980);
        }
    }
    return 0;
}
