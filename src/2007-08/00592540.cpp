// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_espeon_aug2007_boost133_small15143dc5673bbbab.cpp

// Candidate translation unit (score above; library headers required).
#define _MT 1
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
#include <boost/bind.hpp>
#include "script/ScriptContext.h"
#include "util/RunStateOwner.h"
#include "util/ContentProvider.h"
#include "v8datamodel/Feature.h"
#include "v8world/World.h"
#include "Replicator.h"
#include "util/boost.hpp"
class ThreadLogManager;
class DHTMLWindow;
// 00415d00 clones a four-byte boost::_mfi::mf0<void,CLuaHtmlView>.
// This proves the single-inheritance member-pointer representation; no object layout is modeled.
class __single_inheritance CLuaHtmlView { public: class Binder; };
namespace G3D { class Stopwatch; }
namespace RBX { namespace View { class View; class PartChunk; class Decal; class Texture; }
namespace Network { class Server; } }

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

// 00415d00 target RTTI
template struct recovered_boost133::functor_manager< boost::_mfi::mf0<void,CLuaHtmlView>, std::allocator<void> >;
// 00416ae0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,DHTMLWindow,RBX::Lua::FunctionRef>,boost::_bi::list2<boost::_bi::value<boost::shared_ptr<DHTMLWindow> >,boost::_bi::value<RBX::Lua::FunctionRef> > >, std::allocator<void> >;
// 00416b70 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,DHTMLWindow,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::list2<boost::_bi::value<boost::shared_ptr<DHTMLWindow> >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >, std::allocator<void> >;
// 00417570 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf3<void,DHTMLWindow,boost::shared_ptr<RBX::Instance>,RBX::Reflection::PropertyDescriptor const &,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::list4<boost::_bi::value<boost::shared_ptr<DHTMLWindow> >,boost::_bi::value<boost::shared_ptr<RBX::Instance> >,boost::reference_wrapper<RBX::Reflection::PropertyDescriptor const >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >, std::allocator<void> >;
// 00427ed0 target RTTI
template struct recovered_boost133::functor_manager< void (__cdecl*)(ThreadLogManager *), std::allocator<void> >;
// 0042b3a0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<bool,boost::_mfi::mf0<bool,CLuaHtmlView::Binder>,boost::_bi::list1<boost::_bi::value<CLuaHtmlView::Binder *> > >, std::allocator<void> >;
// 0042b460 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,void (__cdecl*)(RBX::Reflection::PropertyDescriptor const *,RBX::Reflection::PropertyDescriptor const &,CLuaHtmlView::Binder *),boost::_bi::list3<boost::arg<1>,boost::reference_wrapper<RBX::Reflection::PropertyDescriptor const >,boost::_bi::value<CLuaHtmlView::Binder *> > >, std::allocator<void> >;
// 0042c6f0 target RTTI
template struct recovered_boost133::functor_manager< bool (__cdecl*)(void), std::allocator<void> >;
// 004489e0 target RTTI
template struct recovered_boost133::functor_manager< void (__cdecl*)(RBX::Security::Context *), std::allocator<void> >;
// 00459600 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<G3D::Stopwatch const &,G3D::Stopwatch const & (__cdecl*)(G3D::Stopwatch const *),boost::_bi::list1<boost::_bi::value<G3D::Stopwatch const *> > >, std::allocator<void> >;
// 00459660 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<int const &,int const & (__cdecl*)(int const *),boost::_bi::list1<boost::_bi::value<int const *> > >, std::allocator<void> >;
// 00493b10 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<RBX::worker_thread::work_result,RBX::worker_thread::work_result (__cdecl*)(boost::shared_ptr<RBX::Network::AbuseReporter::data>,std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list2<boost::_bi::value<boost::shared_ptr<RBX::Network::AbuseReporter::data> >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >, std::allocator<void> >;
// 0049dbe0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<RBX::worker_thread::work_result,RBX::worker_thread::work_result (__cdecl*)(boost::weak_ptr<RBX::Network::Server>,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list4<boost::_bi::value<boost::weak_ptr<RBX::Network::Server> >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::value<int>,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >, std::allocator<void> >;
// 004a9140 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::Network::Replicator,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::Network::Replicator *>,boost::arg<1> > >, std::allocator<void> >;
// 004a91a0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<bool const &,bool const & (__cdecl*)(bool const *),boost::_bi::list1<boost::_bi::value<bool const *> > >, std::allocator<void> >;
// 004cdae0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::View,bool>,boost::_bi::list2<boost::_bi::value<RBX::View::View *>,boost::arg<1> > >, std::allocator<void> >;
// 004cdb40 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::View,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::View::View *>,boost::arg<1> > >, std::allocator<void> >;
// 004d2350 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::PartChunk,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::View::PartChunk *>,boost::arg<1> > >, std::allocator<void> >;
// 004d23b0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::PartChunk,RBX::Reflection::PropertyDescriptor const *>,boost::_bi::list2<boost::_bi::value<RBX::View::PartChunk *>,boost::arg<1> > >, std::allocator<void> >;
// 004d2410 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf0<void,RBX::View::PartChunk>,boost::_bi::list1<boost::_bi::value<RBX::View::PartChunk *> > >, std::allocator<void> >;
// 004d2470 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::Decal,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::View::Decal *>,boost::arg<1> > >, std::allocator<void> >;
// 004d24d0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::Decal,RBX::Reflection::PropertyDescriptor const *>,boost::_bi::list2<boost::_bi::value<RBX::View::Decal *>,boost::arg<1> > >, std::allocator<void> >;
// 004d2530 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::Texture,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::View::Texture *>,boost::arg<1> > >, std::allocator<void> >;
// 004d2590 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::View::Texture,RBX::Reflection::PropertyDescriptor const *>,boost::_bi::list2<boost::_bi::value<RBX::View::Texture *>,boost::arg<1> > >, std::allocator<void> >;
// 0052e4a0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::RunService,boost::shared_ptr<RBX::DataModel> >,boost::_bi::list2<boost::_bi::value<boost::shared_ptr<RBX::RunService> >,boost::_bi::value<boost::shared_ptr<RBX::DataModel> > > >, std::allocator<void> >;
// 00537cc0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<unsigned int,boost::_mfi::cmf0<unsigned int,RBX::ScriptContext>,boost::_bi::list1<boost::_bi::value<RBX::ScriptContext *> > >, std::allocator<void> >;
// 00537d40 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<unsigned int,unsigned int (__cdecl*)(lua_State *),boost::_bi::list1<boost::arg<1> > >, std::allocator<void> >;
// 00537dc0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,void (__cdecl*)(lua_State *,unsigned int),boost::_bi::list2<boost::arg<1>,boost::arg<2> > >, std::allocator<void> >;
// 00537e20 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<unsigned int,unsigned int (__cdecl*)(std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> > const &,lua_State *),boost::_bi::list2<boost::reference_wrapper<std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> > const >,boost::arg<1> > >, std::allocator<void> >;
// 00537e80 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,void (__cdecl*)(std::auto_ptr<std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> > > &,lua_State *,unsigned int),boost::_bi::list3<boost::reference_wrapper<std::auto_ptr<std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> > > >,boost::arg<1>,boost::arg<2> > >, std::allocator<void> >;
// 005463c0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<RBX::worker_thread::work_result,boost::_mfi::mf0<RBX::worker_thread::work_result,RBX::ContentProvider>,boost::_bi::list1<boost::_bi::value<RBX::ContentProvider *> > >, std::allocator<void> >;
// 00559840 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > (__cdecl*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list2<boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >, std::allocator<void> >;
// 00559990 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > (__cdecl*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list1<boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >, std::allocator<void> >;
// 00570f20 target RTTI
template struct recovered_boost133::functor_manager< void (__cdecl*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> > *), std::allocator<void> >;
// 00571c60 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,void (__cdecl*)(boost::function0<void,std::allocator<boost::function_base> > const &,std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list2<boost::_bi::value<boost::function0<void,std::allocator<boost::function_base> > >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >, std::allocator<void> >;
// 0057bb90 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<double,double (__cdecl*)(RBX::Profiling::CodeProfiler *),boost::_bi::list1<boost::_bi::value<RBX::Profiling::CodeProfiler *> > >, std::allocator<void> >;
// 0057bbf0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<int,boost::_mfi::cmf0<int,RBX::World>,boost::_bi::list1<boost::_bi::value<RBX::World const *> > >, std::allocator<void> >;
// 00588e30 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<unsigned int const &,unsigned int const & (__cdecl*)(unsigned int const *),boost::_bi::list1<boost::_bi::value<unsigned int const *> > >, std::allocator<void> >;
// 00592540 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<RBX::worker_thread::work_result,RBX::worker_thread::work_result (__cdecl*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int),boost::_bi::list2<boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::value<int> > >, std::allocator<void> >;
// 005dadf0 target RTTI
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,boost::_mfi::mf0<void,RBX::VelocityMotor>,boost::_bi::list1<boost::_bi::value<RBX::VelocityMotor *> > >, std::allocator<void> >;

// Explicit instantiation may name the native private worker_thread::data type.
template struct recovered_boost133::functor_manager< boost::_bi::bind_t<void,void (__cdecl*)(boost::shared_ptr<RBX::worker_thread::data>,boost::function0<RBX::worker_thread::work_result,std::allocator<boost::function_base> > const &),boost::_bi::list2<boost::_bi::value<boost::shared_ptr<RBX::worker_thread::data> >,boost::_bi::value<boost::function0<RBX::worker_thread::work_result,std::allocator<boost::function_base> > > > >, std::allocator<void> >;
