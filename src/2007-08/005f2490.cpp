// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_boost133_family_70a0c3edfba9fbed.cpp

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
#include "v8datamodel/BrickColor.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Color3.h"
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

namespace RBX { class Instance; namespace Reflection { class PropertyDescriptor; } }
template<int N, class Signature> struct SignalAdapterAccess : RBX::Reflection::SignalDescImpl<N,Signature> { typedef typename RBX::Reflection::SignalDescImpl<N,Signature>::GenericSlotAdapter type; };
typedef SignalAdapterAccess<1,void(std::string)>::type NativeAdapter0;
template struct recovered_boost133::functor_manager<NativeAdapter0,std::allocator<void> >;
typedef SignalAdapterAccess<2,void(std::string,boost::shared_ptr<RBX::Instance>)>::type NativeAdapter1;
template struct recovered_boost133::functor_manager<NativeAdapter1,std::allocator<void> >;
typedef SignalAdapterAccess<1,void(float)>::type NativeAdapter2;
template struct recovered_boost133::functor_manager<NativeAdapter2,std::allocator<void> >;
typedef SignalAdapterAccess<1,void(boost::shared_ptr<RBX::Instance>)>::type NativeAdapter3;
template struct recovered_boost133::functor_manager<NativeAdapter3,std::allocator<void> >;
typedef SignalAdapterAccess<2,void(std::string,int)>::type NativeAdapter4;
template struct recovered_boost133::functor_manager<NativeAdapter4,std::allocator<void> >;
typedef SignalAdapterAccess<0,void()>::type NativeAdapter5;
template struct recovered_boost133::functor_manager<NativeAdapter5,std::allocator<void> >;
typedef SignalAdapterAccess<2,void(std::string,bool)>::type NativeAdapter6;
template struct recovered_boost133::functor_manager<NativeAdapter6,std::allocator<void> >;
typedef SignalAdapterAccess<2,void(float,float)>::type NativeAdapter7;
template struct recovered_boost133::functor_manager<NativeAdapter7,std::allocator<void> >;
typedef SignalAdapterAccess<1,void(const RBX::Reflection::PropertyDescriptor*)>::type NativeAdapter8;
template struct recovered_boost133::functor_manager<NativeAdapter8,std::allocator<void> >;
typedef SignalAdapterAccess<1,void(bool)>::type NativeAdapter9;
template struct recovered_boost133::functor_manager<NativeAdapter9,std::allocator<void> >;
typedef SignalAdapterAccess<2,void(boost::shared_ptr<RBX::Instance>,float)>::type NativeAdapter10;
template struct recovered_boost133::functor_manager<NativeAdapter10,std::allocator<void> >;
typedef SignalAdapterAccess<1,void(int)>::type NativeAdapter11;
template struct recovered_boost133::functor_manager<NativeAdapter11,std::allocator<void> >;
typedef SignalAdapterAccess<1,void(G3D::Vector3)>::type NativeAdapter12;
template struct recovered_boost133::functor_manager<NativeAdapter12,std::allocator<void> >;
typedef SignalAdapterAccess<1,void(G3D::CoordinateFrame)>::type NativeAdapter13;
template struct recovered_boost133::functor_manager<NativeAdapter13,std::allocator<void> >;
typedef SignalAdapterAccess<1,void(G3D::Color3)>::type NativeAdapter14;
template struct recovered_boost133::functor_manager<NativeAdapter14,std::allocator<void> >;
typedef SignalAdapterAccess<1,void(RBX::BrickColor)>::type NativeAdapter15;
template struct recovered_boost133::functor_manager<NativeAdapter15,std::allocator<void> >;
