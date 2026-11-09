// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_espeon_aug2007_boost133_bound_9e93600a7321e147.cpp

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
#ifndef _MT
#define _MT
#endif
#include "boost/bind.hpp"
#include "boost/thread/tss.hpp"
#include "boost/algorithm/string/finder.hpp"
#include "boost/algorithm/string/classification.hpp"
#include "security/SecurityContext.h"
#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/Tool.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/Seat.h"
#include "Network/Player.h"
#include "Replicator.h"
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

class ThreadLogManager; class DHTMLWindow; class CLuaHtmlView;
typedef boost::shared_ptr<RBX::Instance> SharedInstance;
typedef boost::function0<void,std::allocator<boost::function_base> > OldVoidFunction;
typedef boost::function1<void,CLuaHtmlView*,std::allocator<boost::function_base> > OldHtmlFunction;
typedef void (*WeakCallback)(boost::weak_ptr<RBX::Instance>);
typedef void (*MessageCallback)(const OldVoidFunction&,RBX::MessageType,bool);
typedef boost::detail::tss_adapter<ThreadLogManager> NativeBound0;
template struct recovered_boost133::functor_manager<NativeBound0,std::allocator<void> >;
typedef boost::detail::tss_adapter<RBX::Security::Context> NativeBound1;
template struct recovered_boost133::functor_manager<NativeBound1,std::allocator<void> >;
typedef boost::detail::tss_adapter<std::string> NativeBound2;
template struct recovered_boost133::functor_manager<NativeBound2,std::allocator<void> >;
typedef boost::algorithm::detail::token_finderF<boost::algorithm::detail::is_any_ofF<char> > NativeBound3;
template struct recovered_boost133::functor_manager<NativeBound3,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf0<void,RBX::Network::Player>,boost::_bi::list1<boost::_bi::value<boost::shared_ptr<RBX::Network::Player> > > > NativeBound4;
template struct recovered_boost133::functor_manager<NativeBound4,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf0<void,RBX::Flag>,boost::_bi::list1<boost::_bi::value<boost::shared_ptr<RBX::Flag> > > > NativeBound5;
template struct recovered_boost133::functor_manager<NativeBound5,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf0<void,DHTMLWindow>,boost::_bi::list1<boost::_bi::value<boost::shared_ptr<DHTMLWindow> > > > NativeBound6;
template struct recovered_boost133::functor_manager<NativeBound6,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::Accoutrement,SharedInstance>,boost::_bi::list2<boost::_bi::value<RBX::Accoutrement*>,boost::arg<1> > > NativeBound7;
template struct recovered_boost133::functor_manager<NativeBound7,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::SpawnLocation,SharedInstance>,boost::_bi::list2<boost::_bi::value<RBX::SpawnLocation*>,boost::arg<1> > > NativeBound8;
template struct recovered_boost133::functor_manager<NativeBound8,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::Tool,SharedInstance>,boost::_bi::list2<boost::_bi::value<RBX::Tool*>,boost::arg<1> > > NativeBound9;
template struct recovered_boost133::functor_manager<NativeBound9,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::Flag,SharedInstance>,boost::_bi::list2<boost::_bi::value<RBX::Flag*>,boost::arg<1> > > NativeBound10;
template struct recovered_boost133::functor_manager<NativeBound10,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::FlagStand,SharedInstance>,boost::_bi::list2<boost::_bi::value<RBX::FlagStand*>,boost::arg<1> > > NativeBound11;
template struct recovered_boost133::functor_manager<NativeBound11,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::Seat,SharedInstance>,boost::_bi::list2<boost::_bi::value<RBX::Seat*>,boost::arg<1> > > NativeBound12;
template struct recovered_boost133::functor_manager<NativeBound12,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::Seat,bool>,boost::_bi::list2<boost::_bi::value<RBX::Seat*>,boost::arg<1> > > NativeBound13;
template struct recovered_boost133::functor_manager<NativeBound13,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf2<void,RBX::Network::Replicator,SharedInstance,const RBX::Reflection::PropertyDescriptor*>,boost::_bi::list3<boost::_bi::value<RBX::Network::Replicator*>,boost::_bi::value<SharedInstance>,boost::arg<1> > > NativeBound14;
template struct recovered_boost133::functor_manager<NativeBound14,std::allocator<void> >;
typedef boost::_bi::bind_t<void,WeakCallback,boost::_bi::list1<boost::_bi::value<SharedInstance> > > NativeBound15;
template struct recovered_boost133::functor_manager<NativeBound15,std::allocator<void> >;
typedef boost::_bi::bind_t<void,MessageCallback,boost::_bi::list3<boost::_bi::value<OldVoidFunction>,boost::_bi::value<RBX::MessageType>,boost::_bi::value<bool> > > NativeBound16;
template struct recovered_boost133::functor_manager<NativeBound16,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf2<void,DHTMLWindow,int,int>,boost::_bi::list3<boost::_bi::value<boost::shared_ptr<DHTMLWindow> >,boost::_bi::value<int>,boost::_bi::value<int> > > NativeBound17;
template struct recovered_boost133::functor_manager<NativeBound17,std::allocator<void> >;
typedef boost::_bi::bind_t<void,boost::_mfi::mf1<void,DHTMLWindow,OldHtmlFunction>,boost::_bi::list2<boost::_bi::value<boost::shared_ptr<DHTMLWindow> >,boost::_bi::value<void(CLuaHtmlView::*)()> > > NativeBound18;
template struct recovered_boost133::functor_manager<NativeBound18,std::allocator<void> >;
