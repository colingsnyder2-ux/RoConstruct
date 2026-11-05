// from server: 20% by colin
struct Vector3 {
    float x, y, z;
};

struct Vector2 {
    float x, y;
};

struct Instance {
    void* vtable;
};

struct GroupDragTool {
    char pad0[0x10];
    Instance* workspace;
    char pad1[0x10];
    Instance* dragInstances;
    char pad2[0x0c];
    Vector3 lastHit;
    char pad3[0x08];
    void* megaDragger;
    Vector2 downPoint;
    bool dragging;
    char pad4[0x03];
    Vector3 hitWorld;
    char pad5[0x04];

    void sub_62C360();
    void sub_62B520(const Vector3* v);
    void sub_62C190(void* a, void* b);
    void sub_62CCF0();
    bool sub_62D110(void* p);
    bool sub_62C960();
    bool sub_62BCA0();
    void sub_62D2B0(void* p);
    void sub_62CBF0();

    bool onMouseDown(Instance* hitPart, const Vector3& hitWorld,
                     const void* dragInstances, Instance* inputObject,
                     Instance* workspace, Instance* selectIfNoDrag);
};

extern "C" {
    void __stdcall sub_4FF810(void* p);
    void __stdcall sub_5095D0(void* p, void* q);
    void __stdcall sub_530100(void* p);
    void __stdcall sub_574370(void* p, int a, int b);
    void __stdcall sub_574CD0(void* p, void* q);
    bool __stdcall sub_6003B0(void* p, void* q, float f);
}

bool GroupDragTool::onMouseDown(Instance* hitPart, const Vector3& hitWorld,
                                const void* dragInstances, Instance* inputObject,
                                Instance* workspace, Instance* selectIfNoDrag)
{
    sub_62C360();

    this->hitWorld = hitWorld;

    Instance* ws = this->workspace;
    Instance* cam = *(Instance**)((char*)ws + 0x64);
    sub_530100(cam);

    void* camBase = (char*)cam + 0x84;
    char mat[0x24];
    sub_5095D0(mat, camBase);

    void* listData = 0;
    int listSize = 0;
    int listCap = 0;

    if (this->megaDragger != 0) {
        sub_62B520(&this->lastHit);
    } else {
        void* tmp1;
        void* tmp2;
        sub_62C190(&tmp1, &tmp2);
        this->megaDragger = *(void**)tmp1;
        this->downPoint.x = *(float*)((char*)tmp1 + 4);
        this->downPoint.y = *(float*)((char*)tmp1 + 8);
        this->dragging = *(bool*)((char*)tmp1 + 0x0c);
        this->lastHit.x = *(float*)((char*)tmp1 + 0x10);
        this->lastHit.y = *(float*)((char*)tmp1 + 0x14);
        this->lastHit.z = *(float*)((char*)tmp1 + 0x18);
        this->hitWorld.x = *(float*)((char*)tmp1 + 0x1c);
    }

    while (this->megaDragger != 0) {
        int i = 0;
        while (i < listSize) {
            if (*(void**)((char*)listData + i * 4) == this->megaDragger)
                break;
            i++;
        }
        if (i != listSize) {
            if (listSize < listCap) {
                if (listData != 0) {
                    *(void**)((char*)listData + listSize * 4) = this->megaDragger;
                }
                listSize++;
            } else {
                if (listData != 0 && (char*)listData + listSize * 4 > (char*)listData) {
                    void* tmp = this->megaDragger;
                    sub_574CD0(&listData, &tmp);
                } else {
                    sub_574370(&listData, listSize + 1, 0);
                    *(void**)((char*)listData + listSize * 4) = this->megaDragger;
                    listSize++;
                }
            }
        }

        sub_62CCF0();

        bool flag = false;
        sub_62D110(&flag);

        if (!flag) {
            Instance* ws2 = this->workspace;
            float f = *(float*)0x7a837c;
            void* p = *(void**)((char*)ws2 + 0x27c);
            void* q = *(void**)((char*)p + 0x30);
            Instance* cam2 = this->workspace;
            if (!sub_6003B0(q, cam2, f)) {
                if (!sub_62C960()) {
                    if (!sub_62BCA0()) {
                        sub_62CBF0();
                        sub_4FF810(listData);
                        return false;
                    }
                }
            }
        }

        void* tmp1;
        void* tmp2;
        sub_62C190(&tmp1, &tmp2);
        this->megaDragger = *(void**)tmp1;
        this->downPoint.x = *(float*)((char*)tmp1 + 4);
        this->downPoint.y = *(float*)((char*)tmp1 + 8);
        this->dragging = *(bool*)((char*)tmp1 + 0x0c);
        this->lastHit.x = *(float*)((char*)tmp1 + 0x10);
        this->lastHit.y = *(float*)((char*)tmp1 + 0x14);
        this->lastHit.z = *(float*)((char*)tmp1 + 0x18);
        this->hitWorld.x = *(float*)((char*)tmp1 + 0x1c);
    }

    sub_62D2B0(mat);
    sub_62CBF0();
    sub_4FF810(listData);
    return false;
}
