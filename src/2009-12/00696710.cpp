// from server: 66% by atomic.potato
struct ArrowTool
{
};

int __cdecl getValue(ArrowTool *root)
{
    ArrowTool *p = *(ArrowTool **)((char *)root + 76);
    ArrowTool *q = *(ArrowTool **)((char *)p + 76);

    while (*(ArrowTool **)((char *)q + 76) != 0)
        q = *(ArrowTool **)((char *)q + 76);

    return *(int *)((char *)p + 320);
}
