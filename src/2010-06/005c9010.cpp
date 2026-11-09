// from server: 25% by atomic.potato
struct PropDesc {
    char pad0[8];
    char pad8[0x10];
    int field18;
    int field1c;
};

struct Inner {
    char pad0[4];
    char pad4[4];
    char pad8[4];
    int fieldc;
};

struct TypeInfo {
    int before(TypeInfo const&) const;
};

struct Base {
    int field0;
    char pad4[4];
    char pad8[4];
    char padc[4];
    char pad10[4];
    char pad14[1];
    char field15;
};

struct S {
    int field0;
    char pad4[4];
    char pad8[0x10];
    int field18;
    int field1c;
    int f(int, int, int, int);
};

extern "C" int __stdcall sub_78b030();
extern "C" int __stdcall sub_5c8e40();
extern "C" int __stdcall sub_709c40();
extern "C" int __stdcall sub_4e5860();
extern "C" int __stdcall sub_466f80();
extern "C" int __stdcall sub_6e79e0();
extern "C" int __stdcall sub_9ea774();
extern "C" int __stdcall sub_9ea90c();

int S::f(int a, int b, int c, int d)
{
    if (field1c == 0)
    {
        sub_78b030();
        return a;
    }

    int* p18 = (int*)field18;
    int v = *p18;
    int t = field0;

    if (b != 0 && b == t)
    {
    }
    else
    {
        sub_9ea90c();
        b = c;
    }

    if (c == v)
    {
        int r = sub_9ea774();
        if (r == 0)
            goto fail;
        sub_78b030();
        return a;
    }

    int* p18b = (int*)field18;
    int t2 = field0;
    if (b != 0 && b == t2)
    {
    }
    else
    {
        sub_9ea90c();
        b = c;
    }

    if (c == *p18b)
    {
        int r = sub_9ea774();
        if (r == 0)
            goto fail;
        sub_78b030();
        return a;
    }

    {
        int r = sub_9ea774();
        if (r != 0)
        {
            int tmp[2];
            tmp[0] = b;
            tmp[1] = c;
            sub_709c40();
            int* pb = (int*)tmp[1];
            int r2 = sub_4e5860();
            if (r2 != 0)
            {
                Base* bb = (Base*)pb[2];
                if (bb->field15 != 0)
                {
                    sub_78b030();
                    return a;
                }
                sub_78b030();
                return a;
            }
        }
    }

    {
        int r = sub_9ea774();
        if (r == 0)
            goto fail;
        int tmp[4];
        tmp[0] = b;
        tmp[1] = c;
        tmp[2] = field18;
        tmp[3] = field0;
        sub_6e79e0();
        sub_466f80();
        int* pb = (int*)tmp[0];
        if (pb != 0)
        {
            int r2 = sub_4e5860();
            if (r2 == 0)
                goto fail;
        }
        Base* bb = (Base*)tmp[1];
        if (bb->field15 != 0)
        {
            sub_78b030();
            return a;
        }
        sub_78b030();
        return a;
    }

fail:
    {
        int tmp[2];
        sub_5c8e40();
        int* r = (int*)tmp[0];
        *(int*)a = r[0];
        *(int*)(a + 4) = r[1];
        return a;
    }
}
