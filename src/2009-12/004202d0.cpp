// from server: 48% by atomic.potato
struct CSelectionTreeCtrl {
    int GetValue();
};

int CSelectionTreeCtrl::GetValue()
{
    int value = *(int*)((char*)this + 0x12c);
    if (value)
        return value;
    return 0;
}
