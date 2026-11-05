// from server: 19% by atomic.potato
struct P_func_006a4b30 { void g(); };
struct S_func_006a4b30 {
    char pad[264];
    P_func_006a4b30* m_p;
    void f();
};
void S_func_006a4b30::f()
{
    m_p->g();
}

extern "C" void __cdecl sub_7b9780(void*);
extern "C" void* __cdecl sub_6a4b30(void*);
extern "C" void __cdecl sub_542050(void*, void*, void*);
extern "C" void __cdecl sub_760310(void*, void*, void*);
extern "C" char __cdecl sub_6ceda0(void*, void*, void*);
extern "C" void* __cdecl sub_5428c0();
extern "C" float __cdecl sqrtf(float);

struct RBX_FilterDescendents {
    char pad[0x68];
    float m_68;
    float m_6c;
    float m_70;
    float m_74;
    char pad2[0x104 - 0x78];
    void* m_104;
    void getCameraSubject(void* out);
};

void RBX_FilterDescendents::getCameraSubject(void* out) {
    char local_a8[0x40];
    sub_7b9780(local_a8);

    void* src = m_104;
    float* p = (float*)((char*)src + 0x104);
    float v0 = p[1];
    float v1 = p[2];
    float v2 = p[3];

    float s = *(float*)0x00a75b68;
    v0 *= s;
    v1 *= s;
    v2 *= s;

    float t = *(float*)0x00a75cdc;
    float r0 = t - v0;
    float r1 = t - v1;
    float r2 = t - v2;

    float box[6];
    box[0] = r0;
    box[1] = r1;
    box[2] = r2;
    box[3] = v0;
    box[4] = v1;
    box[5] = v2;

    void* sphere = sub_6a4b30(local_a8);
    sub_542050(sphere, (char*)this + 0x68, local_a8);

    float bestDist = 0.0f;
    char found = 0;
    int i = 0;
    while (i < 6) {
        void* list = (void*)0;
        if (list != 0) {
            int n = *(int*)((char*)list + 4);
            int j = 0;
            while (j < n) {
                if (*(void**)(*(char**)list + j * 4) == 0) {
                    break;
                }
                j++;
            }
        }

        float dir[3];
        sub_760310(dir, box, 0);

        float dot = dir[0] * *(float*)(local_a8 + 0x00)
                  + dir[1] * *(float*)(local_a8 + 0x04)
                  + dir[2] * *(float*)(local_a8 + 0x08);
        if (dot < *(float*)(local_a8 + 0x0c)) {
            i++;
            continue;
        }

        float pt[3];
        pt[0] = 0.0f;
        pt[1] = 0.0f;
        pt[2] = 0.0f;
        if (!sub_6ceda0(local_a8, dir, pt)) {
            i++;
            continue;
        }

        float* m = (float*)sphere;
        float wx = m[0] * pt[0] + m[1] * pt[1] + m[2] * pt[2] + m[9];
        float wy = m[3] * pt[0] + m[4] * pt[1] + m[5] * pt[2] + m[10];
        float wz = m[6] * pt[0] + m[7] * pt[1] + m[8] * pt[2] + m[11];

        float dx = m_6c - wx;
        float dy = m_70 - wy;
        float dz = m_74 - wz;
        float dist = dx * dx + dy * dy + dz * dz;
        dist = sqrtf(dist);

        if (dist > bestDist) {
            bestDist = dist;
            *(void**)(local_a8 + 0x04) = 0;
            *(float*)(local_a8 + 0x0c) = wx;
            *(float*)(local_a8 + 0x10) = wy;
            *(float*)(local_a8 + 0x14) = wz;
            found = 1;
        }
        i++;
    }

    if (!found) {
        *(void**)(local_a8 + 0x00) = 0;
        *(int*)(local_a8 + 0x04) = 6;
        *(int*)(local_a8 + 0x08) = -1;
        void* a = sub_5428c0();
        *(float*)(local_a8 + 0x0c) = *(float*)((char*)a + 0);
        *(float*)(local_a8 + 0x10) = *(float*)((char*)a + 4);
        *(float*)(local_a8 + 0x14) = *(float*)((char*)a + 8);
        void* b = sub_5428c0();
        *(float*)(local_a8 + 0x18) = *(float*)((char*)b + 0);
        *(float*)(local_a8 + 0x1c) = *(float*)((char*)b + 4);
        *(float*)(local_a8 + 0x20) = *(float*)((char*)b + 8);
        void* c = sub_5428c0();
        *(float*)(local_a8 + 0x24) = *(float*)((char*)c + 0);
        *(float*)(local_a8 + 0x28) = *(float*)((char*)c + 4);
        *(float*)(local_a8 + 0x2c) = *(float*)((char*)c + 8);
    }

    char* dst = (char*)out;
    for (int k = 0; k < 12; k++) {
        *(int*)(dst + k * 4) = *(int*)(local_a8 + k * 4);
    }
}
