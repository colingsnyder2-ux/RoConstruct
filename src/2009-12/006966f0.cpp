// from server: 67% by atomic.potato
struct ArrowTool
{
    ArrowTool* field_4c;

    ArrowTool* __cdecl get();
};

ArrowTool* __cdecl ArrowTool::get()
{
    ArrowTool* p = field_4c;
    ArrowTool* q = p->field_4c;

    while (q->field_4c != 0)
    {
        p = q;
        q = q->field_4c;
    }

    return p;
}
