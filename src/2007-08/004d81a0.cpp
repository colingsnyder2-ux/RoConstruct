// from server: 34% by colin
// roc 2007-08 004d81a0  unit: RBX::View::MegaTextureProxy  size: 881 bytes

extern "C" {
    __declspec(dllimport) void* __stdcall InterlockedIncrement(void*);
    __declspec(dllimport) void* __stdcall InterlockedDecrement(void*);
    __declspec(dllimport) void __stdcall _invalid_parameter_noinfo();
}

struct S {
    char pad0[0x0c];
    int field0c;
    char pad10[0x1c];
    int field28;
    char pad2c[0x0c];
    int field38;
    char field2c;
    int method(int, int);
};

extern "C" void* __stdcall sub_586610();
extern "C" void __stdcall sub_586b80(void*, void*);
extern "C" void __stdcall sub_5069c0(void*, void*, int);
extern "C" void __stdcall sub_5069f0(void*, void*);
extern "C" void __stdcall sub_505790(void*, int, int, int);
extern "C" void __stdcall sub_4fa500(void*, void*);
extern "C" void __stdcall sub_46f6a0(void*);
extern "C" void* __stdcall sub_4d8150(void*, void*, int, int, void*);
extern "C" void __stdcall sub_5053c0(void*);
extern "C" void __stdcall sub_457dd0();
extern "C" void __stdcall sub_62fc62(void*);

extern "C" void* __stdcall sub_77e6d8();
extern "C" void* __stdcall sub_77e698(void*, const char*);
extern "C" void* __stdcall sub_77e6ac(void*);
extern "C" void* __stdcall sub_77d2e8();
extern "C" void* __stdcall sub_77d2ec();

extern int dword_79efd8;
extern int dword_79f254;
extern int dword_8bdb9c;

int S::method(int a, int b)
{
    if (field2c != 0)
    {
        int* out = (int*)b;
        *out = 0;
        if (field28)
        {
            *out = field28;
            InterlockedIncrement((void*)(field28 + 4));
        }
        return (int)out;
    }

    int count = 0;
    {
        int* p = (int*)sub_586610();
        int c = p[1];
        if (c == 0)
        {
            count = 0;
        }
        else
        {
            int n = (p[2] - c) >> 2;
            if (n >= 0x20)
                count = dword_79efd8;
            else
                count = n;
        }
    }

    int local0c = 0;
    int local10 = 0;
    sub_5069c0(&local0c, &field0c, 8);
    int v24 = local0c;
    int v28 = local10;

    int local30 = 0;
    sub_505790(&local30, v24 << 5, v28, 3);

    int i = 0;
    if (count > 0)
    {
        do
        {
            int* p = (int*)sub_586610();
            int c = p[1];
            if (c == 0 || i >= ((p[2] - c) >> 2))
                sub_77e6d8();
            int* e = (int*)(p[1] + i * 4);
            char buf[0x100 * 3];
            sub_586b80(buf, e);
            sub_5069f0(&local0c, buf);

            char table[0x100 * 3];
            for (int k = 0; k < 0x100; ++k)
            {
                table[k * 3 + 0] = 0;
                table[k * 3 + 1] = 0;
                table[k * 3 + 2] = 0;
            }
            for (int k = 0; k < 0x100; ++k)
            {
                char tmp[3];
                tmp[0] = 0;
                tmp[1] = 0;
                tmp[2] = 0;
                sub_4fa500(&tmp, &local0c);
                table[k * 3 + 0] = tmp[0];
                table[k * 3 + 1] = tmp[1];
                table[k * 3 + 2] = tmp[2];
            }

            int rows = local0c;
            int cols = local10;
            for (int r = 0; r < rows; ++r)
            {
                for (int c2 = 0; c2 < cols; ++c2)
                {
                    int idx = r * cols + c2;
                    unsigned char v = ((unsigned char*)&local30)[idx];
                    char* dst = (char*)&local30 + idx * 3;
                    dst[0] = table[v * 3 + 0];
                    dst[1] = table[v * 3 + 1];
                    dst[2] = table[v * 3 + 2];
                }
            }
            ++i;
        } while (i < count);
    }

    char strbuf[0x20];
    sub_46f6a0(strbuf);
    sub_77e698(&strbuf, "MegaTexture");
    sub_4d8150(&local0c, &local30, dword_8bdb9c, 2, &strbuf);

    int* newp = (int*)local0c;
    int old = field28;
    if (newp != (int*)old)
    {
        if (old)
        {
            if (InterlockedDecrement((void*)(old + 4)) == 0)
            {
                sub_457dd0();
                if (field28)
                {
                    int* vt = (int*)field28;
                    (*(void(**)(int))(*vt))(1);
                }
            }
            field28 = 0;
        }
        if (newp)
        {
            field28 = (int)newp;
            InterlockedIncrement((void*)((int)newp + 4));
        }
    }

    if (local0c)
    {
        if (InterlockedDecrement((void*)(local0c + 4)) == 0)
        {
            int* p = (int*)local0c;
            int* node = (int*)p[2];
            while (node)
            {
                int* vt = (int*)node[0];
                (*(void(**)(void))(vt[0] + 4))();
                int* next = (int*)node[1];
                sub_62fc62(node);
                node = next;
            }
            if (local0c)
            {
                int* vt = (int*)local0c;
                (*(void(**)(int))(*vt))(1);
            }
        }
        local0c = 0;
    }

    sub_77e6ac(&local0c);

    if (field38)
    {
        if (InterlockedDecrement((void*)(field38 + 4)) == 0)
        {
            sub_457dd0();
            if (field38)
            {
                int* vt = (int*)field38;
                (*(void(**)(int))(*vt))(1);
            }
        }
        field38 = 0;
    }

    field2c = 1;
    sub_5053c0(&local30);
    sub_5053c0(&local0c);

    int* out = (int*)b;
    *out = 0;
    if (field28)
    {
        *out = field28;
        InterlockedIncrement((void*)(field28 + 4));
    }
    return (int)out;
}
