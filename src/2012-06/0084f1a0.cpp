// from server: 20% by 41k
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct PAUTuple {
    struct sp_ms_deleter {
        template <typename T>
        void operator()(T* ptr) const {
            delete ptr;
        }
    };

    struct variant {
        // Define variant members as needed
    };

    struct vector {
        // Define vector members as needed
    };

    struct allocator {
        // Define allocator members as needed
    };

    struct sp_counted_impl_pd {
        long use_count;
        long weak_count;
        sp_ms_deleter deleter;

        void add_ref() {
            if (_InterlockedExchangeAdd(&use_count, 1) == 0) {
                deleter(this);
            }
        }

        void release() {
            if (_InterlockedExchangeAdd(&use_count, -1) == 1) {
                deleter(this);
            }
        }

        void add_weak() {
            if (_InterlockedExchangeAdd(&weak_count, 1) == 0) {
                deleter(this);
            }
        }

        void release_weak() {
            if (_InterlockedExchangeAdd(&weak_count, -1) == 1) {
                deleter(this);
            }
        }
    };
};

void some_function(PAUTuple::sp_counted_impl_pd* this_ptr) {
    this_ptr->use_count = 0;
    this_ptr->weak_count = 0;
    this_ptr->deleter = PAUTuple::sp_ms_deleter();

    this_ptr->add_ref();
    this_ptr->release();
    this_ptr->add_weak();
    this_ptr->release_weak();
}
