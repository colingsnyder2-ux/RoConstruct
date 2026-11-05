// from server: 100% by atomic.potato
struct UnifiedWidget {
    void SetValue(int value);
    char pad0[168];
    int m_value;
};

typedef void (__thiscall *WidgetCallback)(UnifiedWidget *);

void UnifiedWidget::SetValue(int value)
{
    if (m_value != value) {
        m_value = value;
        WidgetCallback callback = *(WidgetCallback *)((*(int **)this) + 0x70 / sizeof(int));
        callback(this);
    }
}
