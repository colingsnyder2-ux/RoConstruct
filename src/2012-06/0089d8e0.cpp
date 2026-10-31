// from server: 37% by Intel
extern "C" unsigned char g_e580b3;
extern "C" int g_e5809c;
extern "C" float g_b5abe8;
extern "C" const char str_b460cc[];
extern "C" const char str_bdcca0[];
extern "C" const char str_bdd86c[];
extern "C" const char str_bdd8a8[];
extern "C" const char str_bdd7d8[];
extern "C" const char str_bdd4f4[];
extern "C" const char str_bdd6f8[];
extern "C" const char str_bdd640[];
extern "C" const char str_bdd758[];

extern "C" char (__cdecl *g_e5809c_func)(const char*, const char*, unsigned int);
extern "C" void __cdecl sub_972290(unsigned char, const char*);
extern "C" float* __cdecl sub_62e740();
extern "C" int __cdecl sub_7be130(float*, float*, float*);
extern "C" float* __cdecl sub_89c6e0(float*, float*);
extern "C" char __cdecl sub_89ccb0(int, int);
extern "C" int __cdecl sub_89d440(int, int, int);

struct Vector3 {
    float x, y, z;
};

struct FactoryProduct {
    int field_0;
    int field_4;
    int field_8;

    int __cdecl method(Vector3* a2, Vector3* a3, Vector3* a4);
};

int FactoryProduct::method(Vector3* a2, Vector3* a3, Vector3* a4)
{
    if (field_4 == 0)
    {
        if (g_e580b3 != 0)
        {
            if (g_e5809c != 0)
            {
                if (g_e5809c_func(str_b460cc, str_bdcca0, 0x148))
                {
                    goto LABEL_COPY_RESULT;
                }
            }
            sub_972290(g_e580b3, str_bdd8a8);
        }
        float* v5 = sub_62e740();
        int v6 = v5[0];
        int v7 = v5[1];
        int v8 = v5[2];
        a2->x = v5[0];
        a2->y = v5[1];
        a2->z = v5[2];
        return (int)a2;
    }

    if (g_e580b3 != 0)
    {
        float v10 = g_b5abe8;
        float v11;
        int v12 = sub_7be130(&v11, &v10, &a3->x);
        if (a3->x == *(float*)v12 && a3->y == *(float*)(v12 + 4) && a3->z == *(float*)(v12 + 8))
        {
            goto LABEL_COPY_RESULT;
        }
        if (g_e5809c != 0)
        {
            if (g_e5809c_func(str_bdd86c, str_bdcca0, 0x14c))
            {
                goto LABEL_COPY_RESULT;
            }
        }
        sub_972290(g_e580b3, str_bdd7d8);
    }

    float* v13 = sub_62e740();
    float v14[3] = { v13[0], v13[1], v13[2] };
    float* v15 = sub_62e740();
    if (a3->x == v15[0] && a3->y == v15[1] && a3->z == v15[2])
    {
        goto LABEL_COPY_RESULT;
    }

    int v16 = sub_89d440((int)a3, (int)&v14, (int)a2);
    if (g_e580b3 != 0)
    {
        float* v17 = sub_89c6e0((float*)(v16 + 4), (float*)(v16 + 8));
        if (v17[0] == v14[0] && v17[1] == v14[1] && v17[2] == v14[2])
        {
            goto LABEL_COPY_RESULT;
        }
        if (g_e5809c != 0)
        {
            if (g_e5809c_func(str_bdd4f4, str_bdcca0, 0x157))
            {
                goto LABEL_COPY_RESULT;
            }
        }
        sub_972290(g_e580b3, str_bdd758);
    }

    if (g_e580b3 != 0)
    {
        float* v18 = sub_62e740();
        if (v14[0] == v18[0] && v14[1] == v18[1] && v14[2] == v18[2])
        {
            goto LABEL_COPY_RESULT;
        }
        if (sub_89ccb0((int)a4, (int)a2))
        {
            if (g_e5809c != 0)
            {
                if (g_e5809c_func(str_bdd6f8, str_bdcca0, 0x15a))
                {
                    goto LABEL_COPY_RESULT;
                }
            }
            sub_972290(g_e580b3, str_bdd640);
        }
    }

LABEL_COPY_RESULT:
    a2->x = v14[0];
    a2->y = v14[1];
    a2->z = v14[2];
    return (int)a2;
}
