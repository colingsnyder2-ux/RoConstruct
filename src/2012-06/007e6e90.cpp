// from server: 54% by colin
// roc 2012-06 007e6e90  unit: RBX::GuiTarget  size: 91 bytes
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD

extern "C" int __cdecl sub_6ce4b0();

int g_6ceae4 = 0;
int g_6ceae8 = 0;

int sub_7e6e90()
{
    __try
    {
        if (!(g_6ceae8 & 1))
        {
            g_6ceae8 |= 1;
            g_6ceae4 = sub_6ce4b0();
        }
    }
    __except (1)
    {
    }
    return g_6ceae4;
}
