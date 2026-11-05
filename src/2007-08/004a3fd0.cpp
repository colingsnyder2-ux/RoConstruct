// from server: 39% by colin
// roc 2007-08 004a3fd0  unit: RBX::IdManager::UItem::?$TItem  size: 292 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a3fd0

extern "C" void __stdcall _invalid_parameter_noinfo();
extern "C" void* __cdecl operator_new(unsigned int);

struct Item;

struct EnumDescriptor {
    Item** begin_;
    Item** end_;
    Item** cap_;

    Item* getItem(unsigned int idx);
    void grow();
};

struct Item {
    int value;
    unsigned int index;
    EnumDescriptor* owner;

    Item* init();
};

extern unsigned int g_counter;
extern unsigned int g_cached;
extern unsigned int g_flag;

Item* EnumDescriptor::getItem(unsigned int idx)
{
    unsigned int cur;
    if ((g_flag & 1) == 0) {
        cur = g_counter;
        g_cached = cur;
        g_counter = cur + 1;
        g_flag |= 1;
    } else {
        cur = g_cached;
    }

    if (idx > cur) {
        if ((g_flag & 1) == 0) {
            cur = g_counter;
            g_cached = cur;
            g_counter = cur + 1;
            g_flag |= 1;
        } else {
            cur = g_cached;
        }
        if (begin_ == 0 || cur >= (unsigned int)(end_ - begin_)) {
            _invalid_parameter_noinfo();
        }
        Item** slot = begin_ + cur;
        if (*slot == 0) {
            Item* p = (Item*)operator_new(0x18);
            if (p) {
                p = p->init();
                *slot = p;
                return (Item*)((char*)p + 4);
            }
            *slot = 0;
        }
        return (Item*)((char*)*slot + 4);
    }

    if (begin_ == 0) {
        cur = 0;
    } else {
        cur = (unsigned int)(end_ - begin_);
    }

    if (begin_ != 0 && cur < (unsigned int)(cap_ - begin_)) {
        *end_ = 0;
        end_++;
        return getItem(idx);
    }

    if (begin_ > end_) {
        _invalid_parameter_noinfo();
    }
    grow();
    return getItem(idx);
}
