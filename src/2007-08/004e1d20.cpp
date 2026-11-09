// from server: 29% by colin
// roc 2007-08 004e1d20  unit: PBBBuilder  size: 773 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e1d20

extern "C" void __cdecl sub_5b9970(void*, void*);
extern "C" void* __cdecl sub_62ff32(unsigned int);
extern "C" void* __cdecl sub_501570();
extern "C" void __cdecl sub_4f5360(void*, void*, void*, int);
extern "C" void __cdecl sub_4eee30(void*, int, int, int, int);
extern "C" void __cdecl sub_4f54e0(void*);
extern "C" void __cdecl sub_62ff26(void*);

struct PBBBuilder {
    void func(float a, float b, float c, float d, float e, float f, float g, float h,
              float i, float j, float k, float l, float m, int n, int o, int p, int q);
};

void PBBBuilder::func(float a, float b, float c, float d, float e, float f, float g, float h,
                      float i, float j, float k, float l, float m, int n, int o, int p, int q)
{
    char buf[0x54];
    sub_5b9970(buf, (char*)this + 4);

    int si = (short)o;
    int bx = (short)p;

    float f0 = b - a;
    float f1 = d - c;
    float f2 = f - e;
    float f3 = h - g;

    float r0 = f0 / (float)(si + 1);
    float r1 = f1 / (float)(bx + 1);
    float r2 = j / i;
    float r3 = l / k;

    int total = (si + 1) * (bx + 1);
    void** arr = (void**)sub_62ff32(total * 4);

    float base0 = a;
    float base1 = e;
    float base2 = i;
    float base3 = k;

    if (si >= 0) {
        float cur0 = base0;
        float cur1 = base1;
        float cur2 = base2;
        float cur3 = base3;
        int row = 0;
        for (int y = 0; y <= si; y++) {
            float cx = cur0;
            float cy = cur1;
            float cz = cur2;
            float cw = cur3;
            if (bx >= 0) {
                int col = 0;
                for (int x = 0; x <= bx; x++) {
                    float px = cx;
                    float py = cy;
                    float pz = cz;
                    float pw = cw;

                    float t;
                    if (pw != 0.0f) {
                        float diff = px - pw;
                        float ad = diff < 0 ? -diff : diff;
                        t = (1.0f - ad) * c;
                    } else {
                        t = px + pw;
                        if (t >= 0.0f) {
                            t = t - pw;
                        } else {
                            t = t + pw;
                        }
                    }

                    float* v = (float*)sub_501570();
                    if (v[0] == i && v[1] == k) {
                        px = e;
                        py = g;
                    }

                    float vx = px * 0.5f;
                    float vy = py * 0.5f;
                    float vz = 1.0f;

                    float out[3];
                    sub_5b9970(out, &vx);

                    float out2[3];
                    sub_5b9970(out2, &t);

                    void* obj;
                    sub_4f5360(&obj, out2, out, 1);
                    arr[row + col] = obj;

                    cx = cx + r0;
                    cy = cy + r1;
                    col++;
                }
            }
            cur0 = cur0 + r2;
            cur1 = cur1 + r3;
            row += bx + 1;
        }
    }

    if (total > 0) {
        int idx = 0;
        for (int y = 0; y < si; y++) {
            for (int x = 0; x < bx; x++) {
                sub_4eee30(this, (int)arr[idx], (int)arr[idx + 1],
                           (int)arr[idx + bx + 1], (int)arr[idx + bx + 2]);
                idx++;
            }
            idx++;
        }
    }

    for (unsigned int i2 = 0; i2 < (unsigned int)total; i2++) {
        sub_4f54e0(arr[i2]);
    }
    sub_62ff26(arr);
}
