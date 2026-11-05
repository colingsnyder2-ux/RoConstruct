// from server: 100% by colin
extern "C" int __cdecl sub_4fe620();

int g_4fe688;
int g_4fe68c;

void sub_4fe680()
{
    if (++g_4fe68c == 1)
        g_4fe688 = sub_4fe620();
}
