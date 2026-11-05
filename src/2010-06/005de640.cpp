// from server: 75% by atomic.potato
struct UnifiedWidget {
    virtual char query();
    virtual void update(int);
    virtual void refresh(int);
};

void UnifiedWidget::refresh(int value) {
    if (query()) {
        update(value);
        refresh(value);
    }
}
