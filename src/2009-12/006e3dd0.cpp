// from server: 83% by atomic.potato
struct Humanoid
{
    char pad[0x1db];
    unsigned char field_1db;
    void sub_006e3dd0();
};

struct C1 { int f(int); };
struct C2 { unsigned char f(int); };
struct C3 { unsigned char f(int); };

extern "C" int __cdecl sub_006e3250();

void Humanoid::sub_006e3dd0()
{
    int *p = (int *)sub_006e3250();
    if (p)
    {
        int v = ((C1 *)p[0x168 / sizeof(int)])->f(0);
        if (v)
        {
            unsigned char a = ((C2 *)v)->f(0);
            a = (a == 0);
            if (a)
            {
                unsigned char b = ((C3 *)p)->f(0);
                b = (b == 0);
                field_1db = b;
            }
            return;
        }
    }
    field_1db = 0;
}
