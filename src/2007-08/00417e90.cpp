// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_boost133_signal_de5c8dd16a4762cb.cpp

// Candidate translation unit (score above; library headers required).
// Boost.Function library

//  Copyright Douglas Gregor 2001-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org


// Authentic Boost 1.33.1 manager, isolated to coexist with newer native headers.
// Source: https://raw.githubusercontent.com/boostorg/function/boost-1.33.1/include/boost/function/function_base.hpp
#ifndef _DLL
#define _DLL
#endif
#include "reflection/signal.h"
#define BOOST_FUNCTION_COMPARE_TYPE_ID(X,Y) ((X)==(Y))
namespace recovered_boost133 {
using namespace boost::detail::function;
      union any_pointer
      {
        void* obj_ptr;
        const void* const_obj_ptr;
        void (*func_ptr)();
        char data[1];
      };

      inline any_pointer make_any_pointer(void* o)
      {
        any_pointer p;
        p.obj_ptr = o;
        return p;
      }

      inline any_pointer make_any_pointer(const void* o)
      {
        any_pointer p;
        p.const_obj_ptr = o;
        return p;
      }

      inline any_pointer make_any_pointer(void (*f)())
      {
        any_pointer p;
        p.func_ptr = f;
        return p;
      }

      template<typename Functor, typename Allocator>
      struct functor_manager
      {
      private:
        typedef Functor functor_type;

        // For function pointers, the manager is trivial
        static inline any_pointer
        manager(any_pointer function_ptr,
                functor_manager_operation_type op,
                function_ptr_tag)
        {
          if (op == clone_functor_tag)
            return function_ptr;
          else
            return make_any_pointer(static_cast<void (*)()>(0));
        }

        // For function object pointers, we clone the pointer to each
        // function has its own version.
        static inline any_pointer
        manager(any_pointer function_obj_ptr,
                functor_manager_operation_type op,
                function_obj_tag)
        {
#ifndef BOOST_NO_STD_ALLOCATOR
        typedef typename Allocator::template rebind<functor_type>::other
          allocator_type;
        typedef typename allocator_type::pointer pointer_type;
#else
        typedef functor_type* pointer_type;
#endif // BOOST_NO_STD_ALLOCATOR

#  ifndef BOOST_NO_STD_ALLOCATOR
          allocator_type allocator;
#  endif // BOOST_NO_STD_ALLOCATOR

          if (op == clone_functor_tag) {
            functor_type* f =
              static_cast<functor_type*>(function_obj_ptr.obj_ptr);

            // Clone the functor
#  ifndef BOOST_NO_STD_ALLOCATOR
            pointer_type copy = allocator.allocate(1);
            allocator.construct(copy, *f);

            // Get back to the original pointer type
            functor_type* new_f = static_cast<functor_type*>(copy);
#  else
            functor_type* new_f = new functor_type(*f);
#  endif // BOOST_NO_STD_ALLOCATOR
            return make_any_pointer(static_cast<void*>(new_f));
          }
          else {
            /* Cast from the void pointer to the functor pointer type */
            functor_type* f =
              reinterpret_cast<functor_type*>(function_obj_ptr.obj_ptr);

#  ifndef BOOST_NO_STD_ALLOCATOR
            /* Cast from the functor pointer type to the allocator's pointer
               type */
            pointer_type victim = static_cast<pointer_type>(f);

            // Destroy and deallocate the functor
            allocator.destroy(victim);
            allocator.deallocate(victim, 1);
#  else
            delete f;
#  endif // BOOST_NO_STD_ALLOCATOR

            return make_any_pointer(static_cast<void*>(0));
          }
        }
      public:
        /* Dispatch to an appropriate manager based on whether we have a
           function pointer or a function object pointer. */
        static any_pointer
        manage(any_pointer functor_ptr, functor_manager_operation_type op)
        {
          if (op == check_functor_type_tag) {
            std::type_info* type =
              static_cast<std::type_info*>(functor_ptr.obj_ptr);
            return (BOOST_FUNCTION_COMPARE_TYPE_ID(typeid(Functor), *type)?
                    functor_ptr
                    : make_any_pointer(reinterpret_cast<void*>(0)));
          }
          else {
            typedef typename get_function_tag<functor_type>::type tag_type;
            return manager(functor_ptr, op, tag_type());
          }
        }
      };


}
typedef RBX::Reflection::SignalDescImpl<1,void(std::string)>::GenericSlotAdapter NativeAdapter;
template struct recovered_boost133::functor_manager<NativeAdapter,std::allocator<void> >;
