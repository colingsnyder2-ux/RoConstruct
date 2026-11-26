// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned int uintptr_t;
uintptr_t __cdecl __TBB_LockByte(unsigned char& flag);
namespace tbb {
class spin_mutex {
public:
    unsigned char flag;
    class scoped_lock {
        spin_mutex* my_mutex;
        uintptr_t my_unlock_value;
    public:
        scoped_lock(spin_mutex& m) {
            my_unlock_value = __TBB_LockByte(m.flag);
            my_mutex = &m;
        }
        ~scoped_lock() {
            if (my_mutex) {
                my_mutex->flag = static_cast<unsigned char>(my_unlock_value);
            }
        }
    };
};
}
class Owner {
public:
    char pad[0x20];
    tbb::spin_mutex mutex;
    void doIt(int a);
    void run(int a);
};
void Owner::run(int a)
{
    tbb::spin_mutex::scoped_lock lock(mutex);
    doIt(a);
}
