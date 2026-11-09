// from server: 26% by colin
struct DxUserInput {
    void sub_00463A00();
    void sub_004638C0(float*);
    void sub_00464050(int, float*);
    void sub_00464720();
    char pad[0x180];
    int field_180;

    void sub_00464850(int a1, int a2, int a3);
};

extern "C" int __cdecl sub_00465F80(int, int);
extern "C" int __cdecl sub_00630D60(float);
extern "C" int __cdecl sub_00630946(int);
extern "C" int __cdecl sub_00630940(int);
extern "C" double __cdecl sub_0078FEE0;

void DxUserInput::sub_00464850(int a1, int a2, int a3)
{
    unsigned int msg = (unsigned int)a1;
    if (msg > 0x20A) {
        if (msg == 0x211 || msg == 0x231) {
            sub_00464720();
        }
        return;
    }
    if (msg == 0x20A) {
        float x = (float)(short)(a3 & 0xFFFF);
        float y = (float)(short)((a3 >> 16) & 0xFFFF);
        float z = (float)a2;
        int code;
        if (z == sub_0078FEE0)
            code = 7;
        else
            code = 8;
        float pos[2];
        pos[0] = x;
        pos[1] = y;
        sub_00464050(code, pos);
        return;
    }
    if (msg > 0x202) {
        if (msg >= 0x204 && msg <= 0x205) {
            goto handle_mouse;
        }
        return;
    }
    if (msg >= 0x200) {
handle_mouse:
        {
            float x = (float)(short)(a3 & 0xFFFF);
            float y = (float)(short)((a3 >> 16) & 0xFFFF);
            float pos[2];
            pos[0] = x;
            pos[1] = y;
            int r = sub_00465F80(a1, a2);
            sub_00464050(r, pos);
            int a = sub_00630D60(pos[1]);
            int b = sub_00630D60(pos[0]);
            int tmp = sub_00630946(field_180);
            int (*fn)(int, int) = *(int (**)(int, int))(tmp + 0x5C);
            int ok = fn(b, a);
            if (ok) {
                sub_004638C0(pos);
            }
            sub_00630940(tmp);
        }
        return;
    }
    if (msg == 0x100) {
        sub_00463A00();
        return;
    }
}
