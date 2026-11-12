// from server: 100% by EspClaude
// from server: 74% by EspClaude
// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_claude_0941538dc6145742.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#define NDEBUG 1
// Boost.Function as of boost 1.33.1 (function0 = manager +0, functor +4, invoker +8: the 2007-08 call reads [f+4] and calls [f+8]).
// Boost.Function library

//  Copyright Douglas Gregor 2001-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org

#ifndef BOOST_FUNCTION_BASE_HEADER
#define BOOST_FUNCTION_BASE_HEADER

#include <stdexcept>
#include <string>
#include <memory>
#include <new>
#include <typeinfo>
#include <boost/config.hpp>
#include <boost/assert.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/type_traits/composite_traits.hpp>
#include <boost/type_traits/is_stateless.hpp>
#include <boost/ref.hpp>
#include <boost/pending/ct_if.hpp>
#include <boost/detail/workaround.hpp>
#ifndef BOOST_NO_SFINAE
#  include "boost/utility/enable_if.hpp"
#else
#  include "boost/mpl/bool.hpp"
#endif
#include <boost/function_equal.hpp>

// Borrowed from Boost.Python library: determines the cases where we
// need to use std::type_info::name to compare instead of operator==.
# if (defined(__GNUC__) && __GNUC__ >= 3) \
 || defined(_AIX) \
 || (   defined(__sgi) && defined(__host_mips))
#  include <cstring>
#  define BOOST_FUNCTION_COMPARE_TYPE_ID(X,Y) \
     (std::strcmp((X).name(),(Y).name()) == 0)
# else
#  define BOOST_FUNCTION_COMPARE_TYPE_ID(X,Y) ((X)==(Y))
#endif

#if defined(BOOST_MSVC) && BOOST_MSVC <= 1300 || defined(__ICL) && __ICL <= 600 || defined(__MWERKS__) && __MWERKS__ < 0x2406 && !defined(BOOST_STRICT_CONFIG)
#  define BOOST_FUNCTION_TARGET_FIX(x) x
#else
#  define BOOST_FUNCTION_TARGET_FIX(x)
#endif // not MSVC

#if defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 730 && !defined(BOOST_STRICT_CONFIG)
// Work around a compiler bug.
// boost::python::objects::function has to be seen by the compiler before the
// boost::function class template.
namespace boost { namespace python { namespace objects {
  class function;
}}}
#endif

#if defined (BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)                    \
 || defined(BOOST_BCB_PARTIAL_SPECIALIZATION_BUG)                         \
 || !(BOOST_STRICT_CONFIG || !defined(__SUNPRO_CC) || __SUNPRO_CC > 0x540)
#  define BOOST_FUNCTION_NO_FUNCTION_TYPE_SYNTAX
#endif

#if !BOOST_WORKAROUND(__BORLANDC__, < 0x600)
#  define BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor,Type)              \
      typename ::boost::enable_if_c<(::boost::type_traits::ice_not<          \
                            (::boost::is_integral<Functor>::value)>::value), \
                           Type>::type
#else
// BCC doesn't recognize this depends on a template argument and complains
// about the use of 'typename'
#  define BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor,Type)     \
      ::boost::enable_if_c<(::boost::type_traits::ice_not<          \
                   (::boost::is_integral<Functor>::value)>::value), \
                       Type>::type
#endif

#if !defined(BOOST_FUNCTION_NO_FUNCTION_TYPE_SYNTAX)
namespace boost {

#if defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 730 && !defined(BOOST_STRICT_CONFIG)
// The library shipping with MIPSpro 7.3.1.3m has a broken allocator<void>
class function_base;

template<typename Signature,
         typename Allocator = std::allocator<function_base> >
class function;
#else
template<typename Signature, typename Allocator = std::allocator<void> >
class function;
#endif

template<typename Signature, typename Allocator>
inline void swap(function<Signature, Allocator>& f1,
                 function<Signature, Allocator>& f2)
{
  f1.swap(f2);
}

} // end namespace boost
#endif // have partial specialization

namespace boost {
  namespace detail {
    namespace function {
      /**
       * A union of a function pointer and a void pointer. This is necessary
       * because 5.2.10/6 allows reinterpret_cast<> to safely cast between
       * function pointer types and 5.2.9/10 allows static_cast<> to safely
       * cast between a void pointer and an object pointer. But it is not legal
       * to cast between a function pointer and a void* (in either direction),
       * so function requires a union of the two. */
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

      /**
       * The unusable class is a placeholder for unused function arguments
       * It is also completely unusable except that it constructable from
       * anything. This helps compilers without partial specialization to
       * handle Boost.Function objects returning void.
       */
      struct unusable
      {
        unusable() {}
        template<typename T> unusable(const T&) {}
      };

      /* Determine the return type. This supports compilers that do not support
       * void returns or partial specialization by silently changing the return
       * type to "unusable".
       */
      template<typename T> struct function_return_type { typedef T type; };

      template<>
      struct function_return_type<void>
      {
        typedef unusable type;
      };

      // The operation type to perform on the given functor/function pointer
      enum functor_manager_operation_type {
        clone_functor_tag,
        destroy_functor_tag,
        check_functor_type_tag
      };

      // Tags used to decide between different types of functions
      struct function_ptr_tag {};
      struct function_obj_tag {};
      struct member_ptr_tag {};
      struct function_obj_ref_tag {};
      struct stateless_function_obj_tag {};

      template<typename F>
      class get_function_tag
      {
        typedef typename ct_if<(is_pointer<F>::value),
                            function_ptr_tag,
                            function_obj_tag>::type ptr_or_obj_tag;

        typedef typename ct_if<(is_member_pointer<F>::value),
                            member_ptr_tag,
                            ptr_or_obj_tag>::type ptr_or_obj_or_mem_tag;

        typedef typename ct_if<(is_reference_wrapper<F>::value),
                             function_obj_ref_tag,
                             ptr_or_obj_or_mem_tag>::type or_ref_tag;

      public:
        typedef typename ct_if<(is_stateless<F>::value),
                            stateless_function_obj_tag,
                            or_ref_tag>::type type;
      };

      // The trivial manager does nothing but return the same pointer (if we
      // are cloning) or return the null pointer (if we are deleting).
      template<typename F>
      struct trivial_manager
      {
        static inline any_pointer
        get(any_pointer f, functor_manager_operation_type op)
        {
          switch (op) {
          case clone_functor_tag: return f;

          case destroy_functor_tag:
            return make_any_pointer(reinterpret_cast<void*>(0));

          case check_functor_type_tag:
            {
              std::type_info* t = static_cast<std::type_info*>(f.obj_ptr);
              return BOOST_FUNCTION_COMPARE_TYPE_ID(typeid(F), *t)?
                f
                : make_any_pointer(reinterpret_cast<void*>(0));
            }
          }

          // Clears up a warning with GCC 3.2.3
          return make_any_pointer(reinterpret_cast<void*>(0));
        }
      };

      /**
       * The functor_manager class contains a static function "manage" which
       * can clone or destroy the given function/function object pointer.
       */
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

      // A type that is only used for comparisons against zero
      struct useless_clear_type {};

#ifdef BOOST_NO_SFINAE
      // These routines perform comparisons between a Boost.Function
      // object and an arbitrary function object (when the last
      // parameter is mpl::bool_<false>) or against zero (when the
      // last parameter is mpl::bool_<true>). They are only necessary
      // for compilers that don't support SFINAE.
      template<typename Function, typename Functor>
        bool
        compare_equal(const Function& f, const Functor&, int, mpl::bool_<true>)
        { return f.empty(); }

      template<typename Function, typename Functor>
        bool
        compare_not_equal(const Function& f, const Functor&, int,
                          mpl::bool_<true>)
        { return !f.empty(); }

      template<typename Function, typename Functor>
        bool
        compare_equal(const Function& f, const Functor& g, long,
                      mpl::bool_<false>)
        {
          if (const Functor* fp = f.template target<Functor>())
            return function_equal(*fp, g);
          else return false;
        }

      template<typename Function, typename Functor>
        bool
        compare_equal(const Function& f, const reference_wrapper<Functor>& g,
                      int, mpl::bool_<false>)
        {
          if (const Functor* fp = f.template target<Functor>())
            return fp == g.get_pointer();
          else return false;
        }

      template<typename Function, typename Functor>
        bool
        compare_not_equal(const Function& f, const Functor& g, long,
                          mpl::bool_<false>)
        {
          if (const Functor* fp = f.template target<Functor>())
            return !function_equal(*fp, g);
          else return true;
        }

      template<typename Function, typename Functor>
        bool
        compare_not_equal(const Function& f,
                          const reference_wrapper<Functor>& g, int,
                          mpl::bool_<false>)
        {
          if (const Functor* fp = f.template target<Functor>())
            return fp != g.get_pointer();
          else return true;
        }
#endif // BOOST_NO_SFINAE
    } // end namespace function
  } // end namespace detail

/**
 * The function_base class contains the basic elements needed for the
 * function1, function2, function3, etc. classes. It is common to all
 * functions (and as such can be used to tell if we have one of the
 * functionN objects).
 */
class function_base
{
public:
  function_base() : manager(0)
  {
    functor.obj_ptr = 0;
  }

  // Is this function empty?
  bool empty() const { return !manager; }

  template<typename Functor>
    Functor* target()
    {
      if (!manager) return 0;

      detail::function::any_pointer result =
        manager(detail::function::make_any_pointer(&typeid(Functor)),
                detail::function::check_functor_type_tag);
      if (!result.obj_ptr) return 0;
      else {
        typedef typename detail::function::get_function_tag<Functor>::type tag;
        return get_functor_pointer<Functor>(tag(), 0);
      }
    }

  template<typename Functor>

#if defined(BOOST_MSVC) && BOOST_WORKAROUND(BOOST_MSVC, < 1300)
    const Functor* target( Functor * = 0 ) const
#else
    const Functor* target() const
#endif
    {
      if (!manager) return 0;

      detail::function::any_pointer result =
        manager(detail::function::make_any_pointer(&typeid(Functor)),
                detail::function::check_functor_type_tag);
      if (!result.obj_ptr) return 0;
      else {
        typedef typename detail::function::get_function_tag<Functor>::type tag;

#if defined(BOOST_MSVC) && BOOST_WORKAROUND(BOOST_MSVC, < 1300)
        return get_functor_pointer(tag(), 0, (Functor*)0);
#else
        return get_functor_pointer<Functor>(tag(), 0);
#endif
      }
    }

  template<typename F>
    bool contains(const F& f) const
    {
#if defined(BOOST_MSVC) && BOOST_WORKAROUND(BOOST_MSVC, < 1300)
      if (const F* fp = this->target( (F*)0 )) {
#else
      if (const F* fp = this->template target<F>()) {
#endif
        return function_equal(*fp, f);
      } else {
        return false;
      }
    }

#if defined(__GNUC__) && __GNUC__ == 3 && __GNUC_MINOR__ <= 3
  // GCC 3.3 and newer cannot copy with the global operator==, due to
  // problems with instantiation of function return types before it
  // has been verified that the argument types match up.
  template<typename Functor>
    BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor, bool)
    operator==(Functor g) const
    {
      if (const Functor* fp = target<Functor>())
        return function_equal(*fp, g);
      else return false;
    }

  template<typename Functor>
    BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor, bool)
    operator!=(Functor g) const
    {
      if (const Functor* fp = target<Functor>())
        return !function_equal(*fp, g);
      else return true;
    }
#endif

public: // should be protected, but GCC 2.95.3 will fail to allow access
  detail::function::any_pointer (*manager)(
    detail::function::any_pointer,
    detail::function::functor_manager_operation_type);
  detail::function::any_pointer functor;

private:
  template<typename Functor>
#if defined(BOOST_MSVC) && BOOST_WORKAROUND(BOOST_MSVC, < 1300)
    Functor* get_functor_pointer(detail::function::function_ptr_tag, int, Functor * = 0)
#else
    Functor* get_functor_pointer(detail::function::function_ptr_tag, int)
#endif
    { return reinterpret_cast<Functor*>(&functor.func_ptr); }

  template<typename Functor, typename Tag>
#if defined(BOOST_MSVC) && BOOST_WORKAROUND(BOOST_MSVC, < 1300)
    Functor* get_functor_pointer(Tag, long, Functor * = 0)
#else
    Functor* get_functor_pointer(Tag, long)
#endif
    { return static_cast<Functor*>(functor.obj_ptr); }

  template<typename Functor>
    const Functor*
#if defined(BOOST_MSVC) && BOOST_WORKAROUND(BOOST_MSVC, < 1300)
    get_functor_pointer(detail::function::function_ptr_tag, int, Functor * = 0) const
#else
    get_functor_pointer(detail::function::function_ptr_tag, int) const
#endif
    { return reinterpret_cast<const Functor*>(&functor.func_ptr); }

  template<typename Functor, typename Tag>
#if defined(BOOST_MSVC) && BOOST_WORKAROUND(BOOST_MSVC, < 1300)
    const Functor* get_functor_pointer(Tag, long, Functor * = 0) const
#else
    const Functor* get_functor_pointer(Tag, long) const
#endif
    { return static_cast<const Functor*>(functor.const_obj_ptr); }
};

/**
 * The bad_function_call exception class is thrown when a boost::function
 * object is invoked
 */
class bad_function_call : public std::runtime_error
{
public:
  bad_function_call() : std::runtime_error("call to empty boost::function") {}
};

#ifndef BOOST_NO_SFINAE
inline bool operator==(const function_base& f,
                       detail::function::useless_clear_type*)
{
  return f.empty();
}

inline bool operator!=(const function_base& f,
                       detail::function::useless_clear_type*)
{
  return !f.empty();
}

inline bool operator==(detail::function::useless_clear_type*,
                       const function_base& f)
{
  return f.empty();
}

inline bool operator!=(detail::function::useless_clear_type*,
                       const function_base& f)
{
  return !f.empty();
}
#endif

#ifdef BOOST_NO_SFINAE
// Comparisons between boost::function objects and arbitrary function objects
template<typename Functor>
  inline bool operator==(const function_base& f, Functor g)
  {
    typedef mpl::bool_<(is_integral<Functor>::value)> integral;
    return detail::function::compare_equal(f, g, 0, integral());
  }

template<typename Functor>
  inline bool operator==(Functor g, const function_base& f)
  {
    typedef mpl::bool_<(is_integral<Functor>::value)> integral;
    return detail::function::compare_equal(f, g, 0, integral());
  }

template<typename Functor>
  inline bool operator!=(const function_base& f, Functor g)
  {
    typedef mpl::bool_<(is_integral<Functor>::value)> integral;
    return detail::function::compare_not_equal(f, g, 0, integral());
  }

template<typename Functor>
  inline bool operator!=(Functor g, const function_base& f)
  {
    typedef mpl::bool_<(is_integral<Functor>::value)> integral;
    return detail::function::compare_not_equal(f, g, 0, integral());
  }
#else

#  if !(defined(__GNUC__) && __GNUC__ == 3 && __GNUC_MINOR__ <= 3)
// Comparisons between boost::function objects and arbitrary function
// objects. GCC 3.3 and before has an obnoxious bug that prevents this
// from working.
template<typename Functor>
  BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor, bool)
  operator==(const function_base& f, Functor g)
  {
    if (const Functor* fp = f.template target<Functor>())
      return function_equal(*fp, g);
    else return false;
  }

template<typename Functor>
  BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor, bool)
  operator==(Functor g, const function_base& f)
  {
    if (const Functor* fp = f.template target<Functor>())
      return function_equal(g, *fp);
    else return false;
  }

template<typename Functor>
  BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor, bool)
  operator!=(const function_base& f, Functor g)
  {
    if (const Functor* fp = f.template target<Functor>())
      return !function_equal(*fp, g);
    else return true;
  }

template<typename Functor>
  BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor, bool)
  operator!=(Functor g, const function_base& f)
  {
    if (const Functor* fp = f.template target<Functor>())
      return !function_equal(g, *fp);
    else return true;
  }
#  endif

template<typename Functor>
  BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor, bool)
  operator==(const function_base& f, reference_wrapper<Functor> g)
  {
    if (const Functor* fp = f.template target<Functor>())
      return fp == g.get_pointer();
    else return false;
  }

template<typename Functor>
  BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor, bool)
  operator==(reference_wrapper<Functor> g, const function_base& f)
  {
    if (const Functor* fp = f.template target<Functor>())
      return g.get_pointer() == fp;
    else return false;
  }

template<typename Functor>
  BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor, bool)
  operator!=(const function_base& f, reference_wrapper<Functor> g)
  {
    if (const Functor* fp = f.template target<Functor>())
      return fp != g.get_pointer();
    else return true;
  }

template<typename Functor>
  BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL(Functor, bool)
  operator!=(reference_wrapper<Functor> g, const function_base& f)
  {
    if (const Functor* fp = f.template target<Functor>())
      return g.get_pointer() != fp;
    else return true;
  }

#endif // Compiler supporting SFINAE

namespace detail {
  namespace function {
    inline bool has_empty_target(const function_base* f)
    {
      return f->empty();
    }

#if BOOST_WORKAROUND(BOOST_MSVC, <= 1310)
    inline bool has_empty_target(const void*)
    {
      return false;
    }
#else
    inline bool has_empty_target(...)
    {
      return false;
    }
#endif
  } // end namespace function
} // end namespace detail
} // end namespace boost

#undef BOOST_FUNCTION_ENABLE_IF_NOT_INTEGRAL
#undef BOOST_FUNCTION_COMPARE_TYPE_ID

#endif // BOOST_FUNCTION_BASE_HEADER

#define BOOST_FUNCTION_NUM_ARGS 0
// Boost.Function library

//  Copyright Douglas Gregor 2001-2003. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org

// Note: this header is a header template and must NOT have multiple-inclusion
// protection.
#include <boost/function/detail/prologue.hpp>

#define BOOST_FUNCTION_TEMPLATE_PARMS BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS, typename T)

#define BOOST_FUNCTION_TEMPLATE_ARGS BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS, T)

#define BOOST_FUNCTION_PARM(J,I,D) BOOST_PP_CAT(T,I) BOOST_PP_CAT(a,I)

#define BOOST_FUNCTION_PARMS BOOST_PP_ENUM(BOOST_FUNCTION_NUM_ARGS,BOOST_FUNCTION_PARM,BOOST_PP_EMPTY)

#define BOOST_FUNCTION_ARGS BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS, a)

#define BOOST_FUNCTION_ARG_TYPE(J,I,D) \
  typedef BOOST_PP_CAT(T,I) BOOST_PP_CAT(arg, BOOST_PP_CAT(BOOST_PP_INC(I),_type));

#define BOOST_FUNCTION_ARG_TYPES BOOST_PP_REPEAT(BOOST_FUNCTION_NUM_ARGS,BOOST_FUNCTION_ARG_TYPE,BOOST_PP_EMPTY)

// Type of the default allocator
#ifndef BOOST_NO_STD_ALLOCATOR
#  define BOOST_FUNCTION_DEFAULT_ALLOCATOR std::allocator<function_base>
#else
#  define BOOST_FUNCTION_DEFAULT_ALLOCATOR int
#endif // BOOST_NO_STD_ALLOCATOR

// Comma if nonzero number of arguments
#if BOOST_FUNCTION_NUM_ARGS == 0
#  define BOOST_FUNCTION_COMMA
#else
#  define BOOST_FUNCTION_COMMA ,
#endif // BOOST_FUNCTION_NUM_ARGS > 0

// Class names used in this version of the code
#define BOOST_FUNCTION_FUNCTION BOOST_JOIN(function,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_FUNCTION_INVOKER \
  BOOST_JOIN(function_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_VOID_FUNCTION_INVOKER \
  BOOST_JOIN(void_function_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_FUNCTION_OBJ_INVOKER \
  BOOST_JOIN(function_obj_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_VOID_FUNCTION_OBJ_INVOKER \
  BOOST_JOIN(void_function_obj_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_STATELESS_FUNCTION_OBJ_INVOKER \
  BOOST_JOIN(stateless_function_obj_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_STATELESS_VOID_FUNCTION_OBJ_INVOKER \
  BOOST_JOIN(stateless_void_function_obj_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_GET_FUNCTION_INVOKER \
  BOOST_JOIN(get_function_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_GET_FUNCTION_OBJ_INVOKER \
  BOOST_JOIN(get_function_obj_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_GET_STATELESS_FUNCTION_OBJ_INVOKER \
  BOOST_JOIN(get_stateless_function_obj_invoker,BOOST_FUNCTION_NUM_ARGS)

#ifndef BOOST_NO_VOID_RETURNS
#  define BOOST_FUNCTION_VOID_RETURN_TYPE void
#  define BOOST_FUNCTION_RETURN(X) X
#else
#  define BOOST_FUNCTION_VOID_RETURN_TYPE ::boost::detail::function::unusable
#  define BOOST_FUNCTION_RETURN(X) X; return BOOST_FUNCTION_VOID_RETURN_TYPE ()
#endif

namespace boost {
  namespace detail {
    namespace function {
      template<
        typename FunctionPtr,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
        >
      struct BOOST_FUNCTION_FUNCTION_INVOKER
      {
        static R invoke(any_pointer function_ptr BOOST_FUNCTION_COMMA
                        BOOST_FUNCTION_PARMS)
        {
          FunctionPtr f = reinterpret_cast<FunctionPtr>(function_ptr.func_ptr);
          return f(BOOST_FUNCTION_ARGS);
        }
      };

      template<
        typename FunctionPtr,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
        >
      struct BOOST_FUNCTION_VOID_FUNCTION_INVOKER
      {
        static BOOST_FUNCTION_VOID_RETURN_TYPE
        invoke(any_pointer function_ptr BOOST_FUNCTION_COMMA
               BOOST_FUNCTION_PARMS)

        {
          FunctionPtr f = reinterpret_cast<FunctionPtr>(function_ptr.func_ptr);
          BOOST_FUNCTION_RETURN(f(BOOST_FUNCTION_ARGS));
        }
      };

      template<
        typename FunctionObj,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
      >
      struct BOOST_FUNCTION_FUNCTION_OBJ_INVOKER
      {
        static R invoke(any_pointer function_obj_ptr BOOST_FUNCTION_COMMA
                        BOOST_FUNCTION_PARMS)

        {
          FunctionObj* f = (FunctionObj*)(function_obj_ptr.obj_ptr);
          return (*f)(BOOST_FUNCTION_ARGS);
        }
      };

      template<
        typename FunctionObj,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
      >
      struct BOOST_FUNCTION_VOID_FUNCTION_OBJ_INVOKER
      {
        static BOOST_FUNCTION_VOID_RETURN_TYPE
        invoke(any_pointer function_obj_ptr BOOST_FUNCTION_COMMA
               BOOST_FUNCTION_PARMS)

        {
          FunctionObj* f = (FunctionObj*)(function_obj_ptr.obj_ptr);
          BOOST_FUNCTION_RETURN((*f)(BOOST_FUNCTION_ARGS));
        }
      };

      template<
        typename FunctionObj,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
      >
      struct BOOST_FUNCTION_STATELESS_FUNCTION_OBJ_INVOKER
      {
        static R invoke(any_pointer BOOST_FUNCTION_COMMA BOOST_FUNCTION_PARMS)
        {
          FunctionObj f = FunctionObj();
          return f(BOOST_FUNCTION_ARGS);
        }
      };

      template<
        typename FunctionObj,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
      >
      struct BOOST_FUNCTION_STATELESS_VOID_FUNCTION_OBJ_INVOKER
      {
        static BOOST_FUNCTION_VOID_RETURN_TYPE
        invoke(any_pointer BOOST_FUNCTION_COMMA BOOST_FUNCTION_PARMS)

        {
          FunctionObj f = FunctionObj();
          BOOST_FUNCTION_RETURN(f(BOOST_FUNCTION_ARGS));
        }
      };

      template<
        typename FunctionPtr,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
      >
      struct BOOST_FUNCTION_GET_FUNCTION_INVOKER
      {
        typedef typename ct_if<(is_void<R>::value),
                            BOOST_FUNCTION_VOID_FUNCTION_INVOKER<
                            FunctionPtr,
                            R BOOST_FUNCTION_COMMA
                            BOOST_FUNCTION_TEMPLATE_ARGS
                          >,
                          BOOST_FUNCTION_FUNCTION_INVOKER<
                            FunctionPtr,
                            R BOOST_FUNCTION_COMMA
                            BOOST_FUNCTION_TEMPLATE_ARGS
                          >
                       >::type type;
      };

      template<
        typename FunctionObj,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
       >
      struct BOOST_FUNCTION_GET_FUNCTION_OBJ_INVOKER
      {
        typedef typename ct_if<(is_void<R>::value),
                            BOOST_FUNCTION_VOID_FUNCTION_OBJ_INVOKER<
                            FunctionObj,
                            R BOOST_FUNCTION_COMMA
                            BOOST_FUNCTION_TEMPLATE_ARGS
                          >,
                          BOOST_FUNCTION_FUNCTION_OBJ_INVOKER<
                            FunctionObj,
                            R BOOST_FUNCTION_COMMA
                            BOOST_FUNCTION_TEMPLATE_ARGS
                          >
                       >::type type;
      };

      template<
        typename FunctionObj,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
       >
      struct BOOST_FUNCTION_GET_STATELESS_FUNCTION_OBJ_INVOKER
      {
        typedef typename ct_if<(is_void<R>::value),
                            BOOST_FUNCTION_STATELESS_VOID_FUNCTION_OBJ_INVOKER<
                            FunctionObj,
                            R BOOST_FUNCTION_COMMA
                            BOOST_FUNCTION_TEMPLATE_ARGS
                          >,
                          BOOST_FUNCTION_STATELESS_FUNCTION_OBJ_INVOKER<
                            FunctionObj,
                            R BOOST_FUNCTION_COMMA
                            BOOST_FUNCTION_TEMPLATE_ARGS
                          >
                       >::type type;
      };

    } // end namespace function
  } // end namespace detail

  template<
    typename R BOOST_FUNCTION_COMMA
    BOOST_FUNCTION_TEMPLATE_PARMS,
    typename Allocator = BOOST_FUNCTION_DEFAULT_ALLOCATOR
  >
  class BOOST_FUNCTION_FUNCTION : public function_base
  {
  public:
#ifndef BOOST_NO_VOID_RETURNS
    typedef R         result_type;
#else
    typedef  typename detail::function::function_return_type<R>::type
      result_type;
#endif // BOOST_NO_VOID_RETURNS

  private:
    struct clear_type {};

  public:
    BOOST_STATIC_CONSTANT(int, args = BOOST_FUNCTION_NUM_ARGS);

    // add signature for boost::lambda
    template<typename Args>
    struct sig
    {
      typedef result_type type;
    };

#if BOOST_FUNCTION_NUM_ARGS == 1
    typedef T0 argument_type;
#elif BOOST_FUNCTION_NUM_ARGS == 2
    typedef T0 first_argument_type;
    typedef T1 second_argument_type;
#endif

    BOOST_STATIC_CONSTANT(int, arity = BOOST_FUNCTION_NUM_ARGS);
    BOOST_FUNCTION_ARG_TYPES

    typedef Allocator allocator_type;
    typedef BOOST_FUNCTION_FUNCTION self_type;

    BOOST_FUNCTION_FUNCTION() : function_base()
                              , invoker(0) {}

    // MSVC chokes if the following two constructors are collapsed into
    // one with a default parameter.
    template<typename Functor>
    BOOST_FUNCTION_FUNCTION(Functor BOOST_FUNCTION_TARGET_FIX(const &) f
#ifndef BOOST_NO_SFINAE
                            ,typename enable_if_c<
                            (::boost::type_traits::ice_not<
                             (is_integral<Functor>::value)>::value),
                                        int>::type = 0
#endif // BOOST_NO_SFINAE
                            ) :
      function_base(),
      invoker(0)
    {
      this->assign_to(f);
    }

#ifndef BOOST_NO_SFINAE
    BOOST_FUNCTION_FUNCTION(clear_type*) : function_base(), invoker(0) {}
#else
    BOOST_FUNCTION_FUNCTION(int zero) : function_base(), invoker(0)
    {
      BOOST_ASSERT(zero == 0);
    }
#endif

    BOOST_FUNCTION_FUNCTION(const BOOST_FUNCTION_FUNCTION& f) :
      function_base(),
      invoker(0)
    {
      this->assign_to_own(f);
    }

    ~BOOST_FUNCTION_FUNCTION() { clear(); }

#if BOOST_WORKAROUND(BOOST_MSVC, <= 1200)
    // MSVC 6.0 and prior require all definitions to be inline, but
    // these definitions can become very costly.
    result_type operator()(BOOST_FUNCTION_PARMS) const
    {
      if (this->empty())
        boost::throw_exception(bad_function_call());

      return invoker(this->functor BOOST_FUNCTION_COMMA BOOST_FUNCTION_ARGS);
    }
#else
    result_type operator()(BOOST_FUNCTION_PARMS) const;
#endif

    // The distinction between when to use BOOST_FUNCTION_FUNCTION and
    // when to use self_type is obnoxious. MSVC cannot handle self_type as
    // the return type of these assignment operators, but Borland C++ cannot
    // handle BOOST_FUNCTION_FUNCTION as the type of the temporary to
    // construct.
    template<typename Functor>
#ifndef BOOST_NO_SFINAE
    typename enable_if_c<
               (::boost::type_traits::ice_not<
                 (is_integral<Functor>::value)>::value),
               BOOST_FUNCTION_FUNCTION&>::type
#else
    BOOST_FUNCTION_FUNCTION&
#endif
    operator=(Functor BOOST_FUNCTION_TARGET_FIX(const &) f)
    {
      self_type(f).swap(*this);
      return *this;
    }

#ifndef BOOST_NO_SFINAE
    BOOST_FUNCTION_FUNCTION& operator=(clear_type*)
    {
      this->clear();
      return *this;
    }
#else
    BOOST_FUNCTION_FUNCTION& operator=(int zero)
    {
      BOOST_ASSERT(zero == 0);
      this->clear();
      return *this;
    }
#endif

    // Assignment from another BOOST_FUNCTION_FUNCTION
    BOOST_FUNCTION_FUNCTION& operator=(const BOOST_FUNCTION_FUNCTION& f)
    {
      if (&f == this)
        return *this;

      self_type(f).swap(*this);
      return *this;
    }

    void swap(BOOST_FUNCTION_FUNCTION& other)
    {
      if (&other == this)
        return;

      std::swap(this->manager, other.manager);
      std::swap(this->functor, other.functor);
      std::swap(invoker, other.invoker);
    }

    // Clear out a target, if there is one
    void clear()
    {
      if (this->manager) {
        function_base::functor =
          this->manager(this->functor, detail::function::destroy_functor_tag);
      }

      this->manager = 0;
      invoker = 0;
    }

#if (defined __SUNPRO_CC) && (__SUNPRO_CC <= 0x530) && !(defined BOOST_NO_COMPILER_CONFIG)
    // Sun C++ 5.3 can't handle the safe_bool idiom, so don't use it
    operator bool () const { return !this->empty(); }
#else
  private:
    struct dummy {
      void nonnull() {};
    };

    typedef void (dummy::*safe_bool)();

  public:
    operator safe_bool () const
      { return (this->empty())? 0 : &dummy::nonnull; }

    bool operator!() const
      { return this->empty(); }
#endif

  private:
    void assign_to_own(const BOOST_FUNCTION_FUNCTION& f)
    {
      if (!f.empty()) {
        invoker = f.invoker;
        this->manager = f.manager;
        this->functor =
          f.manager(f.functor, detail::function::clone_functor_tag);
      }
    }

    template<typename Functor>
    void assign_to(Functor f)
    {
      typedef typename detail::function::get_function_tag<Functor>::type tag;
      this->assign_to(f, tag());
    }

    template<typename FunctionPtr>
    void assign_to(FunctionPtr f, detail::function::function_ptr_tag)
    {
      clear();

      if (f) {
        typedef typename detail::function::BOOST_FUNCTION_GET_FUNCTION_INVOKER<
                           FunctionPtr,
                           R BOOST_FUNCTION_COMMA
                           BOOST_FUNCTION_TEMPLATE_ARGS
                         >::type
          actual_invoker_type;

        invoker = &actual_invoker_type::invoke;
        this->manager =
          &detail::function::functor_manager<FunctionPtr, Allocator>::manage;
        this->functor =
          this->manager(detail::function::make_any_pointer(
                            // should be a reinterpret cast, but some compilers
                            // insist on giving cv-qualifiers to free functions
                            (void (*)())(f)
                          ),
                          detail::function::clone_functor_tag);
      }
    }

#if BOOST_FUNCTION_NUM_ARGS > 0
    template<typename MemberPtr>
    void assign_to(MemberPtr f, detail::function::member_ptr_tag)
    {
      this->assign_to(mem_fn(f));
    }
#endif // BOOST_FUNCTION_NUM_ARGS > 0

    template<typename FunctionObj>
    void assign_to(FunctionObj f, detail::function::function_obj_tag)
    {
      if (!detail::function::has_empty_target(boost::addressof(f))) {
        typedef
          typename detail::function::BOOST_FUNCTION_GET_FUNCTION_OBJ_INVOKER<
                                       FunctionObj,
                                       R BOOST_FUNCTION_COMMA
                                       BOOST_FUNCTION_TEMPLATE_ARGS
                                     >::type
          actual_invoker_type;

        invoker = &actual_invoker_type::invoke;
        this->manager = &detail::function::functor_manager<
                                    FunctionObj, Allocator>::manage;
#ifndef BOOST_NO_STD_ALLOCATOR
        typedef typename Allocator::template rebind<FunctionObj>::other
          rebound_allocator_type;
        typedef typename rebound_allocator_type::pointer pointer_type;
        rebound_allocator_type allocator;
        pointer_type copy = allocator.allocate(1);
        allocator.construct(copy, f);

        // Get back to the original pointer type
        FunctionObj* new_f = static_cast<FunctionObj*>(copy);
#else
        FunctionObj* new_f = new FunctionObj(f);
#endif // BOOST_NO_STD_ALLOCATOR
        this->functor =
          detail::function::make_any_pointer(static_cast<void*>(new_f));
      }
    }

    template<typename FunctionObj>
    void assign_to(const reference_wrapper<FunctionObj>& f,
                   detail::function::function_obj_ref_tag)
    {
      if (!detail::function::has_empty_target(f.get_pointer())) {
        typedef
          typename detail::function::BOOST_FUNCTION_GET_FUNCTION_OBJ_INVOKER<
                                       FunctionObj,
                                       R BOOST_FUNCTION_COMMA
                                       BOOST_FUNCTION_TEMPLATE_ARGS
                                     >::type
          actual_invoker_type;

        invoker = &actual_invoker_type::invoke;
        this->manager = &detail::function::trivial_manager<FunctionObj>::get;
        this->functor =
          this->manager(
            detail::function::make_any_pointer(
              const_cast<FunctionObj*>(f.get_pointer())),
            detail::function::clone_functor_tag);
      }
    }

    template<typename FunctionObj>
    void assign_to(FunctionObj, detail::function::stateless_function_obj_tag)
    {
      typedef
          typename detail::function::
                     BOOST_FUNCTION_GET_STATELESS_FUNCTION_OBJ_INVOKER<
                       FunctionObj,
                       R BOOST_FUNCTION_COMMA
                       BOOST_FUNCTION_TEMPLATE_ARGS
                     >::type
          actual_invoker_type;
      invoker = &actual_invoker_type::invoke;
      this->manager = &detail::function::trivial_manager<FunctionObj>::get;
      this->functor = detail::function::make_any_pointer(this);
    }

    typedef result_type (*invoker_type)(detail::function::any_pointer
                                        BOOST_FUNCTION_COMMA
                                        BOOST_FUNCTION_TEMPLATE_ARGS);

    invoker_type invoker;
  };

  template<typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS ,
           typename Allocator>
  inline void swap(BOOST_FUNCTION_FUNCTION<
                     R BOOST_FUNCTION_COMMA
                     BOOST_FUNCTION_TEMPLATE_ARGS ,
                     Allocator
                   >& f1,
                   BOOST_FUNCTION_FUNCTION<
                     R BOOST_FUNCTION_COMMA
                     BOOST_FUNCTION_TEMPLATE_ARGS,
                     Allocator
                   >& f2)
  {
    f1.swap(f2);
  }

#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1200)
  template<typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS,
           typename Allocator>
  typename BOOST_FUNCTION_FUNCTION<
      R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_ARGS, 
      Allocator>::result_type
   BOOST_FUNCTION_FUNCTION<R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_ARGS,

                           Allocator>
  ::operator()(BOOST_FUNCTION_PARMS) const
  {
    if (this->empty())
      boost::throw_exception(bad_function_call());
    
    return invoker(this->functor BOOST_FUNCTION_COMMA BOOST_FUNCTION_ARGS);
  }
#endif

// Poison comparisons between boost::function objects of the same type.
template<typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS ,
         typename Allocator>
  void operator==(const BOOST_FUNCTION_FUNCTION<
                          R BOOST_FUNCTION_COMMA
                          BOOST_FUNCTION_TEMPLATE_ARGS ,
                          Allocator>&,
                  const BOOST_FUNCTION_FUNCTION<
                          R BOOST_FUNCTION_COMMA
                          BOOST_FUNCTION_TEMPLATE_ARGS ,
                  Allocator>&);
template<typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS ,
         typename Allocator>
  void operator!=(const BOOST_FUNCTION_FUNCTION<
                          R BOOST_FUNCTION_COMMA
                          BOOST_FUNCTION_TEMPLATE_ARGS ,
                          Allocator>&,
                  const BOOST_FUNCTION_FUNCTION<
                          R BOOST_FUNCTION_COMMA
                          BOOST_FUNCTION_TEMPLATE_ARGS ,
                  Allocator>&);

#if !defined(BOOST_FUNCTION_NO_FUNCTION_TYPE_SYNTAX)

#if BOOST_FUNCTION_NUM_ARGS == 0
#define BOOST_FUNCTION_PARTIAL_SPEC R (void)
#else
#define BOOST_FUNCTION_PARTIAL_SPEC R (BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,T))
#endif

template<typename R BOOST_FUNCTION_COMMA
         BOOST_FUNCTION_TEMPLATE_PARMS,
         typename Allocator>
class function<BOOST_FUNCTION_PARTIAL_SPEC, Allocator>
  : public BOOST_FUNCTION_FUNCTION<R, BOOST_FUNCTION_TEMPLATE_ARGS
                                   BOOST_FUNCTION_COMMA Allocator>
{
  typedef BOOST_FUNCTION_FUNCTION<R, BOOST_FUNCTION_TEMPLATE_ARGS
                                  BOOST_FUNCTION_COMMA Allocator> base_type;
  typedef function self_type;

  struct clear_type {};

public:
  typedef typename base_type::allocator_type allocator_type;

  function() : base_type() {}

  template<typename Functor>
  function(Functor f
#ifndef BOOST_NO_SFINAE
           ,typename enable_if_c<
                            (::boost::type_traits::ice_not<
                          (is_integral<Functor>::value)>::value),
                       int>::type = 0
#endif
           ) :
    base_type(f)
  {
  }

#ifndef BOOST_NO_SFINAE
  function(clear_type*) : base_type() {}
#endif

  function(const self_type& f) : base_type(static_cast<const base_type&>(f)){}

  function(const base_type& f) : base_type(static_cast<const base_type&>(f)){}

  self_type& operator=(const self_type& f)
  {
    self_type(f).swap(*this);
    return *this;
  }

  template<typename Functor>
#ifndef BOOST_NO_SFINAE
  typename enable_if_c<
                            (::boost::type_traits::ice_not<
                         (is_integral<Functor>::value)>::value),
                      self_type&>::type
#else
  self_type&
#endif
  operator=(Functor f)
  {
    self_type(f).swap(*this);
    return *this;
  }

#ifndef BOOST_NO_SFINAE
  self_type& operator=(clear_type*)
  {
    this->clear();
    return *this;
  }
#endif

  self_type& operator=(const base_type& f)
  {
    self_type(f).swap(*this);
    return *this;
  }
};

#undef BOOST_FUNCTION_PARTIAL_SPEC
#endif // have partial specialization

} // end namespace boost

// Cleanup after ourselves...
#undef BOOST_FUNCTION_DEFAULT_ALLOCATOR
#undef BOOST_FUNCTION_COMMA
#undef BOOST_FUNCTION_FUNCTION
#undef BOOST_FUNCTION_FUNCTION_INVOKER
#undef BOOST_FUNCTION_VOID_FUNCTION_INVOKER
#undef BOOST_FUNCTION_FUNCTION_OBJ_INVOKER
#undef BOOST_FUNCTION_VOID_FUNCTION_OBJ_INVOKER
#undef BOOST_FUNCTION_STATELESS_FUNCTION_OBJ_INVOKER
#undef BOOST_FUNCTION_STATELESS_VOID_FUNCTION_OBJ_INVOKER
#undef BOOST_FUNCTION_GET_FUNCTION_INVOKER
#undef BOOST_FUNCTION_GET_FUNCTION_OBJ_INVOKER
#undef BOOST_FUNCTION_GET_STATELESS_FUNCTION_OBJ_INVOKER
#undef BOOST_FUNCTION_GET_MEM_FUNCTION_INVOKER
#undef BOOST_FUNCTION_TEMPLATE_PARMS
#undef BOOST_FUNCTION_TEMPLATE_ARGS
#undef BOOST_FUNCTION_PARMS
#undef BOOST_FUNCTION_PARM
#undef BOOST_FUNCTION_ARGS
#undef BOOST_FUNCTION_ARG_TYPE
#undef BOOST_FUNCTION_ARG_TYPES
#undef BOOST_FUNCTION_VOID_RETURN_TYPE
#undef BOOST_FUNCTION_RETURN

#undef BOOST_FUNCTION_NUM_ARGS
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
struct State {
 boost::mutex mutex;
 boost::condition condition;
 bool stopped;
 bool running() const { if(stopped) return false; return true; }
};
void __cdecl worker(boost::shared_ptr<State> state, const boost::function0<int>& function) {
 for(;;) {
  if(!state->running()) break;
  if(function()==1) continue;
  boost::mutex::scoped_lock lock(state->mutex);
  state->condition.wait(lock);
 }
}
