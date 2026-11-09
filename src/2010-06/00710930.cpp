// from server: 53% by atomic.potato
struct UnifiedImageWidget
{
    UnifiedImageWidget *f();
};

extern "C" void __cdecl sub_70E870(UnifiedImageWidget *, int, void *, int);

UnifiedImageWidget *UnifiedImageWidget::f()
{
    int value = 0;
    sub_70E870(this, *(int *)this, &value, 0x13);
    return this;
}
