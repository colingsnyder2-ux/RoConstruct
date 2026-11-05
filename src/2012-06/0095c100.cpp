// from server: 53% by atomic.potato
struct AdvRunDragger {
    char pad0[0x50];
    int field50;
    char pad54[0xc];
    int field60;
    int field64;
    int field68;
    float field6c;
    float field70;
    float field74;
    float field78;
    float field7c;
    float field80;
    char pad84[0x20];
    int fielda4;

    bool sub_95c100(int* arg);
    void sub_95b500();
};

struct Vec4 {
    int a;
    int b;
    int c;
    float d;
    float e;
    float f;
    float g;
    float h;
    float i;
};

extern "C" int __stdcall sub_7b9450(int);
extern "C" void __stdcall sub_7219d0(void*);
extern "C" void __stdcall sub_81cf90(void*);
extern "C" void __stdcall sub_868720(void*, int, int);
extern "C" void __stdcall sub_8e2eb0(void*, void*);
extern "C" bool __stdcall sub_8f1ea0(int, int, int, int, float);
extern "C" Vec4* __stdcall sub_95a370(AdvRunDragger*, Vec4*, int*);

bool AdvRunDragger::sub_95c100(int* arg)
{
    if (sub_7b9450(this->field60) == 0xa)
        return false;

    int local[3];
    sub_7219d0(local);

    bool flag = false;
    if (this->field60 != 0) {
        bool* out = (bool*)arg;
        while (sub_7b9450(this->field60) != 0xa) {
            if (!sub_8f1ea0(this->field60, this->field68, this->field50, this->fielda4, 1.0f))
                break;

            if (local[1] < local[2]) {
                int* p = (int*)(local[0] + local[1] * 4);
                if (p != 0) {
                    *p = this->field68;
                    local[1]++;
                }
            } else {
                int* base = (int*)local[0];
                int idx = local[1];
                if (&this->field68 < base + idx && &this->field68 >= base) {
                    int tmp = this->field68;
                    sub_8e2eb0(local, &tmp);
                } else {
                    sub_868720(local, idx + 1, 0);
                    int* p = (int*)local[0];
                    p[local[1] - 1] = this->field68;
                }
            }

            Vec4 tmp;
            Vec4* r = sub_95a370(this, &tmp, local);
            this->field60 = r->a;
            this->field64 = r->b;
            this->field68 = r->c;
            this->field6c = r->d;
            this->field70 = r->e;
            this->field74 = r->f;
            this->field78 = r->g;
            this->field7c = r->h;
            this->field80 = r->i;

            if (this->field60 == 0)
                break;
            this->sub_95b500();
            *out = true;
            if (this->field60 == 0)
                break;
        }
    }

    flag = (this->field60 == 0);
    sub_81cf90(local);
    return flag;
}
