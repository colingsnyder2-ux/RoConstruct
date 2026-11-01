// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_bf139_3095a0e32ec5068e.cpp

// Candidate translation unit (score above; library headers required).
// Boost.Function from boost-1.39.0 (function_base.hpp, function_template.hpp verbatim) over boost 1.40.
#include <functional>
#include <boost/preprocessor/iterate.hpp>
#include <boost/detail/workaround.hpp>
#define BOOST_FUNCTION_MAX_ARGS 10
#include <boost/config.hpp>
#undef BOOST_NO_EXCEPTIONS
// Boost.Function library

//  Copyright Douglas Gregor 2001-2006
//  Copyright Emil Dotchevski 2007
//  Use, modification and distribution is subject to the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
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
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/type_traits/is_volatile.hpp>
#include <boost/type_traits/composite_traits.hpp>
#include <boost/type_traits/ice.hpp>
#include <boost/ref.hpp>
#include <boost/mpl/if.hpp>
#include <boost/detail/workaround.hpp>
#include <boost/type_traits/alignment_of.hpp>
#ifndef BOOST_NO_SFINAE
#  include "boost/utility/enable_if.hpp"
#else
#  include "boost/mpl/bool.hpp"
#endif
#include <boost/function_equal.hpp>
#include <boost/function/function_fwd.hpp>

#if defined(BOOST_MSVC)
#   pragma warning( push )
#   pragma warning( disable : 4793 ) // complaint about native code generation
#   pragma warning( disable : 4127 ) // "conditional expression is constant"
#endif       

// Define BOOST_FUNCTION_STD_NS to the namespace that contains type_info.
#ifdef BOOST_NO_EXCEPTION_STD_NAMESPACE
// Embedded VC++ does not have type_info in namespace std
#  define BOOST_FUNCTION_STD_NS
#else
#  define BOOST_FUNCTION_STD_NS std
#endif

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

#if !BOOST_WORKAROUND(__BORLANDC__, < 0x5A0)
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

namespace boost {
  namespace detail {
    namespace function {
      class X;

      /**
       * A buffer used to store small function objects in
       * boost::function. It is a union containing function pointers,
       * object pointers, and a structure that resembles a bound
       * member function pointer.
       */
      union function_buffer
      {
        // For pointers to function objects
        mutable void* obj_ptr;

        // For pointers to std::type_info objects
        struct type_t {
          // (get_functor_type_tag, check_functor_type_tag).
          const BOOST_FUNCTION_STD_NS::type_info* type;

          // Whether the type is const-qualified.
          bool const_qualified;
          // Whether the type is volatile-qualified.
          bool volatile_qualified;
        } type;

        // For function pointers of all kinds
        mutable void (*func_ptr)();

        // For bound member pointers
        struct bound_memfunc_ptr_t {
          void (X::*memfunc_ptr)(int);
          void* obj_ptr;
        } bound_memfunc_ptr;

        // For references to function objects. We explicitly keep
        // track of the cv-qualifiers on the object referenced.
        struct obj_ref_t {
          mutable void* obj_ptr;
          bool is_const_qualified;
          bool is_volatile_qualified;
        } obj_ref;

        // To relax aliasing constraints
        mutable char data;
      };

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
        move_functor_tag,
        destroy_functor_tag,
        check_functor_type_tag,
        get_functor_type_tag
      };

      // Tags used to decide between different types of functions
      struct function_ptr_tag {};
      struct function_obj_tag {};
      struct member_ptr_tag {};
      struct function_obj_ref_tag {};

      template<typename F>
      class get_function_tag
      {
        typedef typename mpl::if_c<(is_pointer<F>::value),
                                   function_ptr_tag,
                                   function_obj_tag>::type ptr_or_obj_tag;

        typedef typename mpl::if_c<(is_member_pointer<F>::value),
                                   member_ptr_tag,
                                   ptr_or_obj_tag>::type ptr_or_obj_or_mem_tag;

        typedef typename mpl::if_c<(is_reference_wrapper<F>::value),
                                   function_obj_ref_tag,
                                   ptr_or_obj_or_mem_tag>::type or_ref_tag;

      public:
        typedef or_ref_tag type;
      };

      // The trivial manager does nothing but return the same pointer (if we
      // are cloning) or return the null pointer (if we are deleting).
      template<typename F>
      struct reference_manager
      {
        static inline void
        manage(const function_buffer& in_buffer, function_buffer& out_buffer, 
               functor_manager_operation_type op)
        {
          switch (op) {
          case clone_functor_tag: 
            out_buffer.obj_ref.obj_ptr = in_buffer.obj_ref.obj_ptr;
            return;

          case move_functor_tag:
            out_buffer.obj_ref.obj_ptr = in_buffer.obj_ref.obj_ptr;
            in_buffer.obj_ref.obj_ptr = 0;
            return;

          case destroy_functor_tag:
            out_buffer.obj_ref.obj_ptr = 0;
            return;

          case check_functor_type_tag:
            {
              const BOOST_FUNCTION_STD_NS::type_info& check_type 
                = *out_buffer.type.type;

              // Check whether we have the same type. We can add
              // cv-qualifiers, but we can't take them away.
              if (BOOST_FUNCTION_COMPARE_TYPE_ID(check_type, typeid(F))
                  && (!in_buffer.obj_ref.is_const_qualified 
                      || out_buffer.type.const_qualified)
                  && (!in_buffer.obj_ref.is_volatile_qualified
                      || out_buffer.type.volatile_qualified))
                out_buffer.obj_ptr = in_buffer.obj_ref.obj_ptr;
              else
                out_buffer.obj_ptr = 0;
            }
            return;

          case get_functor_type_tag:
            out_buffer.type.type = &typeid(F);
            out_buffer.type.const_qualified = in_buffer.obj_ref.is_const_qualified;
            out_buffer.type.volatile_qualified = in_buffer.obj_ref.is_volatile_qualified;
            return;
          }
        }
      };

      /**
       * Determine if boost::function can use the small-object
       * optimization with the function object type F.
       */
      template<typename F>
      struct function_allows_small_object_optimization
      {
        BOOST_STATIC_CONSTANT
          (bool, 
           value = ((sizeof(F) <= sizeof(function_buffer) &&
                     (alignment_of<function_buffer>::value 
                      % alignment_of<F>::value == 0))));
      };

      template <typename F,typename A>
      struct functor_wrapper: public F, public A
      {
        functor_wrapper( F f, A a ):
          F(f),
          A(a)
        {
        }
      };

      /**
       * The functor_manager class contains a static function "manage" which
       * can clone or destroy the given function/function object pointer.
       */
      template<typename Functor>
      struct functor_manager_common
      {
        typedef Functor functor_type;

        // Function pointers
        static inline void
        manage_ptr(const function_buffer& in_buffer, function_buffer& out_buffer, 
                functor_manager_operation_type op)
        {
          if (op == clone_functor_tag)
            out_buffer.func_ptr = in_buffer.func_ptr;
          else if (op == move_functor_tag) {
            out_buffer.func_ptr = in_buffer.func_ptr;
            in_buffer.func_ptr = 0;
          } else if (op == destroy_functor_tag)
            out_buffer.func_ptr = 0;
          else if (op == check_functor_type_tag) {
            const BOOST_FUNCTION_STD_NS::type_info& check_type 
              = *out_buffer.type.type;
            if (BOOST_FUNCTION_COMPARE_TYPE_ID(check_type, typeid(Functor)))
              out_buffer.obj_ptr = &in_buffer.func_ptr;
            else
              out_buffer.obj_ptr = 0;
          } else /* op == get_functor_type_tag */ {
            out_buffer.type.type = &typeid(Functor);
            out_buffer.type.const_qualified = false;
            out_buffer.type.volatile_qualified = false;
          }
        }

        // Function objects that fit in the small-object buffer.
        static inline void
        manage_small(const function_buffer& in_buffer, function_buffer& out_buffer, 
                functor_manager_operation_type op)
        {
          if (op == clone_functor_tag || op == move_functor_tag) {
            const functor_type* in_functor = 
              reinterpret_cast<const functor_type*>(&in_buffer.data);
            new ((void*)&out_buffer.data) functor_type(*in_functor);

            if (op == move_functor_tag) {
              reinterpret_cast<functor_type*>(&in_buffer.data)->~Functor();
            }
          } else if (op == destroy_functor_tag) {
            // Some compilers (Borland, vc6, ...) are unhappy with ~functor_type.
            reinterpret_cast<functor_type*>(&out_buffer.data)->~Functor();
          } else if (op == check_functor_type_tag) {
            const BOOST_FUNCTION_STD_NS::type_info& check_type 
              = *out_buffer.type.type;
            if (BOOST_FUNCTION_COMPARE_TYPE_ID(check_type, typeid(Functor)))
              out_buffer.obj_ptr = &in_buffer.data;
            else
              out_buffer.obj_ptr = 0;
          } else /* op == get_functor_type_tag */ {
            out_buffer.type.type = &typeid(Functor);
            out_buffer.type.const_qualified = false;
            out_buffer.type.volatile_qualified = false;            
          }
        }
      };

      template<typename Functor>
      struct functor_manager
      {
      private:
        typedef Functor functor_type;

        // Function pointers
        static inline void
        manager(const function_buffer& in_buffer, function_buffer& out_buffer, 
                functor_manager_operation_type op, function_ptr_tag)
        {
          functor_manager_common<Functor>::manage_ptr(in_buffer,out_buffer,op);
        }

        // Function objects that fit in the small-object buffer.
        static inline void
        manager(const function_buffer& in_buffer, function_buffer& out_buffer, 
                functor_manager_operation_type op, mpl::true_)
        {
          functor_manager_common<Functor>::manage_small(in_buffer,out_buffer,op);
        }
        
        // Function objects that require heap allocation
        static inline void
        manager(const function_buffer& in_buffer, function_buffer& out_buffer, 
                functor_manager_operation_type op, mpl::false_)
        {
          if (op == clone_functor_tag) {
            // Clone the functor
            // GCC 2.95.3 gets the CV qualifiers wrong here, so we
            // can't do the static_cast that we should do.
            const functor_type* f =
              (const functor_type*)(in_buffer.obj_ptr);
            functor_type* new_f = new functor_type(*f);
            out_buffer.obj_ptr = new_f;
          } else if (op == move_functor_tag) {
            out_buffer.obj_ptr = in_buffer.obj_ptr;
            in_buffer.obj_ptr = 0;
          } else if (op == destroy_functor_tag) {
            /* Cast from the void pointer to the functor pointer type */
            functor_type* f =
              static_cast<functor_type*>(out_buffer.obj_ptr);
            delete f;
            out_buffer.obj_ptr = 0;
          } else if (op == check_functor_type_tag) {
            const BOOST_FUNCTION_STD_NS::type_info& check_type
              = *out_buffer.type.type;
            if (BOOST_FUNCTION_COMPARE_TYPE_ID(check_type, typeid(Functor)))
              out_buffer.obj_ptr = in_buffer.obj_ptr;
            else
              out_buffer.obj_ptr = 0;
          } else /* op == get_functor_type_tag */ {
            out_buffer.type.type = &typeid(Functor);
            out_buffer.type.const_qualified = false;
            out_buffer.type.volatile_qualified = false;
          }
        }

        // For function objects, we determine whether the function
        // object can use the small-object optimization buffer or
        // whether we need to allocate it on the heap.
        static inline void
        manager(const function_buffer& in_buffer, function_buffer& out_buffer, 
                functor_manager_operation_type op, function_obj_tag)
        {
          manager(in_buffer, out_buffer, op,
                  mpl::bool_<(function_allows_small_object_optimization<functor_type>::value)>());
        }

        // For member pointers, we use the small-object optimization buffer.
        static inline void
        manager(const function_buffer& in_buffer, function_buffer& out_buffer, 
                functor_manager_operation_type op, member_ptr_tag)
        {
          manager(in_buffer, out_buffer, op, mpl::true_());
        }

      public:
        /* Dispatch to an appropriate manager based on whether we have a
           function pointer or a function object pointer. */
        static inline void
        manage(const function_buffer& in_buffer, function_buffer& out_buffer, 
               functor_manager_operation_type op)
        {
          typedef typename get_function_tag<functor_type>::type tag_type;
          switch (op) {
          case get_functor_type_tag:
            out_buffer.type.type = &typeid(functor_type);
            out_buffer.type.const_qualified = false;
            out_buffer.type.volatile_qualified = false;
            return;

          default:
            manager(in_buffer, out_buffer, op, tag_type());
            return;
          }
        }
      };

      template<typename Functor, typename Allocator>
      struct functor_manager_a
      {
      private:
        typedef Functor functor_type;

        // Function pointers
        static inline void
        manager(const function_buffer& in_buffer, function_buffer& out_buffer, 
                functor_manager_operation_type op, function_ptr_tag)
        {
          functor_manager_common<Functor>::manage_ptr(in_buffer,out_buffer,op);
        }

        // Function objects that fit in the small-object buffer.
        static inline void
        manager(const function_buffer& in_buffer, function_buffer& out_buffer, 
                functor_manager_operation_type op, mpl::true_)
        {
          functor_manager_common<Functor>::manage_small(in_buffer,out_buffer,op);
        }
        
        // Function objects that require heap allocation
        static inline void
        manager(const function_buffer& in_buffer, function_buffer& out_buffer, 
                functor_manager_operation_type op, mpl::false_)
        {
          typedef functor_wrapper<Functor,Allocator> functor_wrapper_type;
          typedef typename Allocator::template rebind<functor_wrapper_type>::other
            wrapper_allocator_type;
          typedef typename wrapper_allocator_type::pointer wrapper_allocator_pointer_type;

          if (op == clone_functor_tag) {
            // Clone the functor
            // GCC 2.95.3 gets the CV qualifiers wrong here, so we
            // can't do the static_cast that we should do.
            const functor_wrapper_type* f =
              (const functor_wrapper_type*)(in_buffer.obj_ptr);
            wrapper_allocator_type wrapper_allocator(static_cast<Allocator const &>(*f));
            wrapper_allocator_pointer_type copy = wrapper_allocator.allocate(1);
            wrapper_allocator.construct(copy, *f);

            // Get back to the original pointer type
            functor_wrapper_type* new_f = static_cast<functor_wrapper_type*>(copy);
            out_buffer.obj_ptr = new_f;
          } else if (op == move_functor_tag) {
            out_buffer.obj_ptr = in_buffer.obj_ptr;
            in_buffer.obj_ptr = 0;
          } else if (op == destroy_functor_tag) {
            /* Cast from the void pointer to the functor_wrapper_type */
            functor_wrapper_type* victim =
              static_cast<functor_wrapper_type*>(in_buffer.obj_ptr);
            wrapper_allocator_type wrapper_allocator(static_cast<Allocator const &>(*victim));
            wrapper_allocator.destroy(victim);
            wrapper_allocator.deallocate(victim,1);
            out_buffer.obj_ptr = 0;
          } else if (op == check_functor_type_tag) {
            const BOOST_FUNCTION_STD_NS::type_info& check_type 
              = *out_buffer.type.type;
            if (BOOST_FUNCTION_COMPARE_TYPE_ID(check_type, typeid(Functor)))
              out_buffer.obj_ptr = in_buffer.obj_ptr;
            else
              out_buffer.obj_ptr = 0;
          } else /* op == get_functor_type_tag */ {
            out_buffer.type.type = &typeid(Functor);
            out_buffer.type.const_qualified = false;
            out_buffer.type.volatile_qualified = false;
          }
        }

        // For function objects, we determine whether the function
        // object can use the small-object optimization buffer or
        // whether we need to allocate it on the heap.
        static inline void
        manager(const function_buffer& in_buffer, function_buffer& out_buffer, 
                functor_manager_operation_type op, function_obj_tag)
        {
          manager(in_buffer, out_buffer, op,
                  mpl::bool_<(function_allows_small_object_optimization<functor_type>::value)>());
        }

      public:
        /* Dispatch to an appropriate manager based on whether we have a
           function pointer or a function object pointer. */
        static inline void
        manage(const function_buffer& in_buffer, function_buffer& out_buffer, 
               functor_manager_operation_type op)
        {
          typedef typename get_function_tag<functor_type>::type tag_type;
          switch (op) {
          case get_functor_type_tag:
            out_buffer.type.type = &typeid(functor_type);
            out_buffer.type.const_qualified = false;
            out_buffer.type.volatile_qualified = false;
            return;

          default:
            manager(in_buffer, out_buffer, op, tag_type());
            return;
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

      /**
       * Stores the "manager" portion of the vtable for a
       * boost::function object.
       */
      struct vtable_base
      {
        void (*manager)(const function_buffer& in_buffer, 
                        function_buffer& out_buffer, 
                        functor_manager_operation_type op);
      };
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
  function_base() : vtable(0) { }

  /** Determine if the function is empty (i.e., has no target). */
  bool empty() const { return !vtable; }

  /** Retrieve the type of the stored function object, or typeid(void)
      if this is empty. */
  const BOOST_FUNCTION_STD_NS::type_info& target_type() const
  {
    if (!vtable) return typeid(void);

    detail::function::function_buffer type;
    vtable->manager(functor, type, detail::function::get_functor_type_tag);
    return *type.type.type;
  }

  template<typename Functor>
    Functor* target()
    {
      if (!vtable) return 0;

      detail::function::function_buffer type_result;
      type_result.type.type = &typeid(Functor);
      type_result.type.const_qualified = is_const<Functor>::value;
      type_result.type.volatile_qualified = is_volatile<Functor>::value;
      vtable->manager(functor, type_result, 
                      detail::function::check_functor_type_tag);
      return static_cast<Functor*>(type_result.obj_ptr);
    }

  template<typename Functor>
#if defined(BOOST_MSVC) && BOOST_WORKAROUND(BOOST_MSVC, < 1300)
    const Functor* target( Functor * = 0 ) const
#else
    const Functor* target() const
#endif
    {
      if (!vtable) return 0;

      detail::function::function_buffer type_result;
      type_result.type.type = &typeid(Functor);
      type_result.type.const_qualified = true;
      type_result.type.volatile_qualified = is_volatile<Functor>::value;
      vtable->manager(functor, type_result, 
                      detail::function::check_functor_type_tag);
      // GCC 2.95.3 gets the CV qualifiers wrong here, so we
      // can't do the static_cast that we should do.
      return (const Functor*)(type_result.obj_ptr);
    }

  template<typename F>
    bool contains(const F& f) const
    {
#if defined(BOOST_MSVC) && BOOST_WORKAROUND(BOOST_MSVC, < 1300)
      if (const F* fp = this->target( (F*)0 ))
#else
      if (const F* fp = this->template target<F>())
#endif
      {
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
  detail::function::vtable_base* vtable;
  mutable detail::function::function_buffer functor;
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

#include <boost/function/detail/prologue.hpp>
#define BOOST_FUNCTION_NUM_ARGS 0
// Boost.Function library

//  Copyright Douglas Gregor 2001-2006
//  Copyright Emil Dotchevski 2007
//  Use, modification and distribution is subject to the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org

// Note: this header is a header template and must NOT have multiple-inclusion
// protection.
#include <boost/function/detail/prologue.hpp>

#if defined(BOOST_MSVC)
#   pragma warning( push )
#   pragma warning( disable : 4127 ) // "conditional expression is constant"
#endif       

#define BOOST_FUNCTION_TEMPLATE_PARMS BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS, typename T)

#define BOOST_FUNCTION_TEMPLATE_ARGS BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS, T)

#define BOOST_FUNCTION_PARM(J,I,D) BOOST_PP_CAT(T,I) BOOST_PP_CAT(a,I)

#define BOOST_FUNCTION_PARMS BOOST_PP_ENUM(BOOST_FUNCTION_NUM_ARGS,BOOST_FUNCTION_PARM,BOOST_PP_EMPTY)

#define BOOST_FUNCTION_ARGS BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS, a)

#define BOOST_FUNCTION_ARG_TYPE(J,I,D) \
  typedef BOOST_PP_CAT(T,I) BOOST_PP_CAT(BOOST_PP_CAT(arg, BOOST_PP_INC(I)),_type);

#define BOOST_FUNCTION_ARG_TYPES BOOST_PP_REPEAT(BOOST_FUNCTION_NUM_ARGS,BOOST_FUNCTION_ARG_TYPE,BOOST_PP_EMPTY)

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
#define BOOST_FUNCTION_FUNCTION_REF_INVOKER \
  BOOST_JOIN(function_ref_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_VOID_FUNCTION_REF_INVOKER \
  BOOST_JOIN(void_function_ref_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_MEMBER_INVOKER \
  BOOST_JOIN(function_mem_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_VOID_MEMBER_INVOKER \
  BOOST_JOIN(function_void_mem_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_GET_FUNCTION_INVOKER \
  BOOST_JOIN(get_function_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_GET_FUNCTION_OBJ_INVOKER \
  BOOST_JOIN(get_function_obj_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_GET_FUNCTION_REF_INVOKER \
  BOOST_JOIN(get_function_ref_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_GET_MEMBER_INVOKER \
  BOOST_JOIN(get_member_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_GET_INVOKER \
  BOOST_JOIN(get_invoker,BOOST_FUNCTION_NUM_ARGS)
#define BOOST_FUNCTION_VTABLE BOOST_JOIN(basic_vtable,BOOST_FUNCTION_NUM_ARGS)

#ifndef BOOST_NO_VOID_RETURNS
#  define BOOST_FUNCTION_VOID_RETURN_TYPE void
#  define BOOST_FUNCTION_RETURN(X) X
#else
#  define BOOST_FUNCTION_VOID_RETURN_TYPE boost::detail::function::unusable
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
        static R invoke(function_buffer& function_ptr BOOST_FUNCTION_COMMA
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
        invoke(function_buffer& function_ptr BOOST_FUNCTION_COMMA
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
        static R invoke(function_buffer& function_obj_ptr BOOST_FUNCTION_COMMA
                        BOOST_FUNCTION_PARMS)

        {
          FunctionObj* f;
          if (function_allows_small_object_optimization<FunctionObj>::value)
            f = reinterpret_cast<FunctionObj*>(&function_obj_ptr.data);
          else
            f = reinterpret_cast<FunctionObj*>(function_obj_ptr.obj_ptr);
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
        invoke(function_buffer& function_obj_ptr BOOST_FUNCTION_COMMA
               BOOST_FUNCTION_PARMS)

        {
          FunctionObj* f;
          if (function_allows_small_object_optimization<FunctionObj>::value)
            f = reinterpret_cast<FunctionObj*>(&function_obj_ptr.data);
          else
            f = reinterpret_cast<FunctionObj*>(function_obj_ptr.obj_ptr);
          BOOST_FUNCTION_RETURN((*f)(BOOST_FUNCTION_ARGS));
        }
      };

      template<
        typename FunctionObj,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
      >
      struct BOOST_FUNCTION_FUNCTION_REF_INVOKER
      {
        static R invoke(function_buffer& function_obj_ptr BOOST_FUNCTION_COMMA
                        BOOST_FUNCTION_PARMS)

        {
          FunctionObj* f = 
            reinterpret_cast<FunctionObj*>(function_obj_ptr.obj_ptr);
          return (*f)(BOOST_FUNCTION_ARGS);
        }
      };

      template<
        typename FunctionObj,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
      >
      struct BOOST_FUNCTION_VOID_FUNCTION_REF_INVOKER
      {
        static BOOST_FUNCTION_VOID_RETURN_TYPE
        invoke(function_buffer& function_obj_ptr BOOST_FUNCTION_COMMA
               BOOST_FUNCTION_PARMS)

        {
          FunctionObj* f = 
            reinterpret_cast<FunctionObj*>(function_obj_ptr.obj_ptr);
          BOOST_FUNCTION_RETURN((*f)(BOOST_FUNCTION_ARGS));
        }
      };

#if BOOST_FUNCTION_NUM_ARGS > 0
      /* Handle invocation of member pointers. */
      template<
        typename MemberPtr,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
      >
      struct BOOST_FUNCTION_MEMBER_INVOKER
      {
        static R invoke(function_buffer& function_obj_ptr BOOST_FUNCTION_COMMA
                        BOOST_FUNCTION_PARMS)

        {
          MemberPtr* f = 
            reinterpret_cast<MemberPtr*>(&function_obj_ptr.data);
          return boost::mem_fn(*f)(BOOST_FUNCTION_ARGS);
        }
      };

      template<
        typename MemberPtr,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
      >
      struct BOOST_FUNCTION_VOID_MEMBER_INVOKER
      {
        static BOOST_FUNCTION_VOID_RETURN_TYPE
        invoke(function_buffer& function_obj_ptr BOOST_FUNCTION_COMMA
               BOOST_FUNCTION_PARMS)

        {
          MemberPtr* f = 
            reinterpret_cast<MemberPtr*>(&function_obj_ptr.data);
          BOOST_FUNCTION_RETURN(boost::mem_fn(*f)(BOOST_FUNCTION_ARGS));
        }
      };
#endif

      template<
        typename FunctionPtr,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
      >
      struct BOOST_FUNCTION_GET_FUNCTION_INVOKER
      {
        typedef typename mpl::if_c<(is_void<R>::value),
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
        typedef typename mpl::if_c<(is_void<R>::value),
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
      struct BOOST_FUNCTION_GET_FUNCTION_REF_INVOKER
      {
        typedef typename mpl::if_c<(is_void<R>::value),
                            BOOST_FUNCTION_VOID_FUNCTION_REF_INVOKER<
                            FunctionObj,
                            R BOOST_FUNCTION_COMMA
                            BOOST_FUNCTION_TEMPLATE_ARGS
                          >,
                          BOOST_FUNCTION_FUNCTION_REF_INVOKER<
                            FunctionObj,
                            R BOOST_FUNCTION_COMMA
                            BOOST_FUNCTION_TEMPLATE_ARGS
                          >
                       >::type type;
      };

#if BOOST_FUNCTION_NUM_ARGS > 0
      /* Retrieve the appropriate invoker for a member pointer.  */
      template<
        typename MemberPtr,
        typename R BOOST_FUNCTION_COMMA
        BOOST_FUNCTION_TEMPLATE_PARMS
       >
      struct BOOST_FUNCTION_GET_MEMBER_INVOKER
      {
        typedef typename mpl::if_c<(is_void<R>::value),
                            BOOST_FUNCTION_VOID_MEMBER_INVOKER<
                            MemberPtr,
                            R BOOST_FUNCTION_COMMA
                            BOOST_FUNCTION_TEMPLATE_ARGS
                          >,
                          BOOST_FUNCTION_MEMBER_INVOKER<
                            MemberPtr,
                            R BOOST_FUNCTION_COMMA
                            BOOST_FUNCTION_TEMPLATE_ARGS
                          >
                       >::type type;
      };
#endif

      /* Given the tag returned by get_function_tag, retrieve the
         actual invoker that will be used for the given function
         object. 

         Each specialization contains an "apply" nested class template
         that accepts the function object, return type, function
         argument types, and allocator. The resulting "apply" class
         contains two typedefs, "invoker_type" and "manager_type",
         which correspond to the invoker and manager types. */
      template<typename Tag>
      struct BOOST_FUNCTION_GET_INVOKER { };

      /* Retrieve the invoker for a function pointer. */
      template<>
      struct BOOST_FUNCTION_GET_INVOKER<function_ptr_tag>
      {
        template<typename FunctionPtr,
                 typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS>
        struct apply
        {
          typedef typename BOOST_FUNCTION_GET_FUNCTION_INVOKER<
                             FunctionPtr,
                             R BOOST_FUNCTION_COMMA
                             BOOST_FUNCTION_TEMPLATE_ARGS
                           >::type
            invoker_type;

          typedef functor_manager<FunctionPtr> manager_type;
        };

        template<typename FunctionPtr,
                 typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS,
                 typename Allocator>
        struct apply_a
        {
          typedef typename BOOST_FUNCTION_GET_FUNCTION_INVOKER<
                             FunctionPtr,
                             R BOOST_FUNCTION_COMMA
                             BOOST_FUNCTION_TEMPLATE_ARGS
                           >::type
            invoker_type;

          typedef functor_manager<FunctionPtr> manager_type;
        };
      };

#if BOOST_FUNCTION_NUM_ARGS > 0
      /* Retrieve the invoker for a member pointer. */
      template<>
      struct BOOST_FUNCTION_GET_INVOKER<member_ptr_tag>
      {
        template<typename MemberPtr,
                 typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS>
        struct apply
        {
          typedef typename BOOST_FUNCTION_GET_MEMBER_INVOKER<
                             MemberPtr,
                             R BOOST_FUNCTION_COMMA
                             BOOST_FUNCTION_TEMPLATE_ARGS
                           >::type
            invoker_type;

          typedef functor_manager<MemberPtr> manager_type;
        };

        template<typename MemberPtr,
                 typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS,
                 typename Allocator>
        struct apply_a
        {
          typedef typename BOOST_FUNCTION_GET_MEMBER_INVOKER<
                             MemberPtr,
                             R BOOST_FUNCTION_COMMA
                             BOOST_FUNCTION_TEMPLATE_ARGS
                           >::type
            invoker_type;

          typedef functor_manager<MemberPtr> manager_type;
        };
      };
#endif

      /* Retrieve the invoker for a function object. */
      template<>
      struct BOOST_FUNCTION_GET_INVOKER<function_obj_tag>
      {
        template<typename FunctionObj,
                 typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS>
        struct apply
        {
          typedef typename BOOST_FUNCTION_GET_FUNCTION_OBJ_INVOKER<
                             FunctionObj,
                             R BOOST_FUNCTION_COMMA
                             BOOST_FUNCTION_TEMPLATE_ARGS
                           >::type
            invoker_type;

          typedef functor_manager<FunctionObj> manager_type;
        };

        template<typename FunctionObj,
                 typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS,
                 typename Allocator>
        struct apply_a
        {
          typedef typename BOOST_FUNCTION_GET_FUNCTION_OBJ_INVOKER<
                             FunctionObj,
                             R BOOST_FUNCTION_COMMA
                             BOOST_FUNCTION_TEMPLATE_ARGS
                           >::type
            invoker_type;

          typedef functor_manager_a<FunctionObj, Allocator> manager_type;
        };
      };

      /* Retrieve the invoker for a reference to a function object. */
      template<>
      struct BOOST_FUNCTION_GET_INVOKER<function_obj_ref_tag>
      {
        template<typename RefWrapper,
                 typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS>
        struct apply
        {
          typedef typename BOOST_FUNCTION_GET_FUNCTION_REF_INVOKER<
                             typename RefWrapper::type,
                             R BOOST_FUNCTION_COMMA
                             BOOST_FUNCTION_TEMPLATE_ARGS
                           >::type
            invoker_type;

          typedef reference_manager<typename RefWrapper::type> manager_type;
        };

        template<typename RefWrapper,
                 typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS,
                 typename Allocator>
        struct apply_a
        {
          typedef typename BOOST_FUNCTION_GET_FUNCTION_REF_INVOKER<
                             typename RefWrapper::type,
                             R BOOST_FUNCTION_COMMA
                             BOOST_FUNCTION_TEMPLATE_ARGS
                           >::type
            invoker_type;

          typedef reference_manager<typename RefWrapper::type> manager_type;
        };
      };


      /**
       * vtable for a specific boost::function instance. This
       * structure must be an aggregate so that we can use static
       * initialization in boost::function's assign_to and assign_to_a
       * members. It therefore cannot have any constructors,
       * destructors, base classes, etc.
       */
      template<typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS>
      struct BOOST_FUNCTION_VTABLE
      {
#ifndef BOOST_NO_VOID_RETURNS
        typedef R         result_type;
#else
        typedef typename function_return_type<R>::type result_type;
#endif // BOOST_NO_VOID_RETURNS

        typedef result_type (*invoker_type)(function_buffer&
                                            BOOST_FUNCTION_COMMA
                                            BOOST_FUNCTION_TEMPLATE_ARGS);

        template<typename F>
        bool assign_to(F f, function_buffer& functor)
        {
          typedef typename get_function_tag<F>::type tag;
          return assign_to(f, functor, tag());
        }
        template<typename F,typename Allocator>
        bool assign_to_a(F f, function_buffer& functor, Allocator a)
        {
          typedef typename get_function_tag<F>::type tag;
          return assign_to_a(f, functor, a, tag());
        }

        void clear(function_buffer& functor)
        {
          if (base.manager)
            base.manager(functor, functor, destroy_functor_tag);
        }

      private:
        // Function pointers
        template<typename FunctionPtr>
        bool 
        assign_to(FunctionPtr f, function_buffer& functor, function_ptr_tag)
        {
          this->clear(functor);
          if (f) {
            // should be a reinterpret cast, but some compilers insist
            // on giving cv-qualifiers to free functions
            functor.func_ptr = (void (*)())(f);
            return true;
          } else {
            return false;
          }
        }
        template<typename FunctionPtr,typename Allocator>
        bool 
        assign_to_a(FunctionPtr f, function_buffer& functor, Allocator, function_ptr_tag)
        {
          return assign_to(f,functor,function_ptr_tag());
        }

        // Member pointers
#if BOOST_FUNCTION_NUM_ARGS > 0
        template<typename MemberPtr>
        bool assign_to(MemberPtr f, function_buffer& functor, member_ptr_tag)
        {
          // DPG TBD: Add explicit support for member function
          // objects, so we invoke through mem_fn() but we retain the
          // right target_type() values.
          if (f) {
            this->assign_to(mem_fn(f), functor);
            return true;
          } else {
            return false;
          }
        }
        template<typename MemberPtr,typename Allocator>
        bool assign_to_a(MemberPtr f, function_buffer& functor, Allocator a, member_ptr_tag)
        {
          // DPG TBD: Add explicit support for member function
          // objects, so we invoke through mem_fn() but we retain the
          // right target_type() values.
          if (f) {
            this->assign_to_a(mem_fn(f), functor, a);
            return true;
          } else {
            return false;
          }
        }
#endif // BOOST_FUNCTION_NUM_ARGS > 0

        // Function objects
        // Assign to a function object using the small object optimization
        template<typename FunctionObj>
        void 
        assign_functor(FunctionObj f, function_buffer& functor, mpl::true_)
        {
          new ((void*)&functor.data) FunctionObj(f);
        }
        template<typename FunctionObj,typename Allocator>
        void 
        assign_functor_a(FunctionObj f, function_buffer& functor, Allocator, mpl::true_)
        {
          assign_functor(f,functor,mpl::true_());
        }

        // Assign to a function object allocated on the heap.
        template<typename FunctionObj>
        void 
        assign_functor(FunctionObj f, function_buffer& functor, mpl::false_)
        {
          functor.obj_ptr = new FunctionObj(f);
        }
        template<typename FunctionObj,typename Allocator>
        void 
        assign_functor_a(FunctionObj f, function_buffer& functor, Allocator a, mpl::false_)
        {
          typedef functor_wrapper<FunctionObj,Allocator> functor_wrapper_type;
          typedef typename Allocator::template rebind<functor_wrapper_type>::other
            wrapper_allocator_type;
          typedef typename wrapper_allocator_type::pointer wrapper_allocator_pointer_type;
          wrapper_allocator_type wrapper_allocator(a);
          wrapper_allocator_pointer_type copy = wrapper_allocator.allocate(1);
          wrapper_allocator.construct(copy, functor_wrapper_type(f,a));
          functor_wrapper_type* new_f = static_cast<functor_wrapper_type*>(copy);
          functor.obj_ptr = new_f;
        }

        template<typename FunctionObj>
        bool 
        assign_to(FunctionObj f, function_buffer& functor, function_obj_tag)
        {
          if (!boost::detail::function::has_empty_target(boost::addressof(f))) {
            assign_functor(f, functor, 
                           mpl::bool_<(function_allows_small_object_optimization<FunctionObj>::value)>());
            return true;
          } else {
            return false;
          }
        }
        template<typename FunctionObj,typename Allocator>
        bool 
        assign_to_a(FunctionObj f, function_buffer& functor, Allocator a, function_obj_tag)
        {
          if (!boost::detail::function::has_empty_target(boost::addressof(f))) {
            assign_functor_a(f, functor, a,
                           mpl::bool_<(function_allows_small_object_optimization<FunctionObj>::value)>());
            return true;
          } else {
            return false;
          }
        }

        // Reference to a function object
        template<typename FunctionObj>
        bool 
        assign_to(const reference_wrapper<FunctionObj>& f, 
                  function_buffer& functor, function_obj_ref_tag)
        {
          if (!boost::detail::function::has_empty_target(f.get_pointer())) {
            functor.obj_ref.obj_ptr = (void *)f.get_pointer();
            functor.obj_ref.is_const_qualified = is_const<FunctionObj>::value;
            functor.obj_ref.is_volatile_qualified = is_volatile<FunctionObj>::value;
            return true;
          } else {
            return false;
          }
        }
        template<typename FunctionObj,typename Allocator>
        bool 
        assign_to_a(const reference_wrapper<FunctionObj>& f, 
                  function_buffer& functor, Allocator, function_obj_ref_tag)
        {
          return assign_to(f,functor,function_obj_ref_tag());
        }

      public:
        vtable_base base;
        invoker_type invoker;
      };
    } // end namespace function
  } // end namespace detail

  template<
    typename R BOOST_FUNCTION_COMMA
    BOOST_FUNCTION_TEMPLATE_PARMS
  >
  class BOOST_FUNCTION_FUNCTION : public function_base

#if BOOST_FUNCTION_NUM_ARGS == 1

    , public std::unary_function<T0,R>

#elif BOOST_FUNCTION_NUM_ARGS == 2

    , public std::binary_function<T0,T1,R>

#endif

  {
  public:
#ifndef BOOST_NO_VOID_RETURNS
    typedef R         result_type;
#else
    typedef  typename boost::detail::function::function_return_type<R>::type
      result_type;
#endif // BOOST_NO_VOID_RETURNS

  private:
    typedef boost::detail::function::BOOST_FUNCTION_VTABLE<
              R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_ARGS>
      vtable_type;

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

    typedef BOOST_FUNCTION_FUNCTION self_type;

    BOOST_FUNCTION_FUNCTION() : function_base() { }

    // MSVC chokes if the following two constructors are collapsed into
    // one with a default parameter.
    template<typename Functor>
    BOOST_FUNCTION_FUNCTION(Functor BOOST_FUNCTION_TARGET_FIX(const &) f
#ifndef BOOST_NO_SFINAE
                            ,typename enable_if_c<
                            (boost::type_traits::ice_not<
                             (is_integral<Functor>::value)>::value),
                                        int>::type = 0
#endif // BOOST_NO_SFINAE
                            ) :
      function_base()
    {
      this->assign_to(f);
    }
    template<typename Functor,typename Allocator>
    BOOST_FUNCTION_FUNCTION(Functor BOOST_FUNCTION_TARGET_FIX(const &) f, Allocator a
#ifndef BOOST_NO_SFINAE
                            ,typename enable_if_c<
                            (boost::type_traits::ice_not<
                             (is_integral<Functor>::value)>::value),
                                        int>::type = 0
#endif // BOOST_NO_SFINAE
                            ) :
      function_base()
    {
      this->assign_to_a(f,a);
    }

#ifndef BOOST_NO_SFINAE
    BOOST_FUNCTION_FUNCTION(clear_type*) : function_base() { }
#else
    BOOST_FUNCTION_FUNCTION(int zero) : function_base()
    {
      BOOST_ASSERT(zero == 0);
    }
#endif

    BOOST_FUNCTION_FUNCTION(const BOOST_FUNCTION_FUNCTION& f) : function_base()
    {
      this->assign_to_own(f);
    }

    ~BOOST_FUNCTION_FUNCTION() { clear(); }

#if BOOST_WORKAROUND(BOOST_MSVC, < 1300)
    // MSVC 6.0 and prior require all definitions to be inline, but
    // these definitions can become very costly.
    result_type operator()(BOOST_FUNCTION_PARMS) const
    {
      if (this->empty())
        boost::throw_exception(bad_function_call());

      return static_cast<vtable_type*>(vtable)->invoker
               (this->functor BOOST_FUNCTION_COMMA BOOST_FUNCTION_ARGS);
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
               (boost::type_traits::ice_not<
                 (is_integral<Functor>::value)>::value),
               BOOST_FUNCTION_FUNCTION&>::type
#else
    BOOST_FUNCTION_FUNCTION&
#endif
    operator=(Functor BOOST_FUNCTION_TARGET_FIX(const &) f)
    {
      this->clear();
      try {
        this->assign_to(f);
      } catch (...) {
        vtable = 0;
        throw;
      }
      return *this;
    }
    template<typename Functor,typename Allocator>
    void assign(Functor BOOST_FUNCTION_TARGET_FIX(const &) f, Allocator a)
    {
      this->clear();
      try {
        this->assign_to_a(f,a);
      } catch (...) {
        vtable = 0;
        throw;
      }
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

      this->clear();
      try {
        this->assign_to_own(f);
      } catch (...) {
        vtable = 0;
        throw;
      }
      return *this;
    }

    void swap(BOOST_FUNCTION_FUNCTION& other)
    {
      if (&other == this)
        return;

      BOOST_FUNCTION_FUNCTION tmp;
      tmp.move_assign(*this);
      this->move_assign(other);
      other.move_assign(tmp);
    }

    // Clear out a target, if there is one
    void clear()
    {
      if (vtable) {
        reinterpret_cast<vtable_type*>(vtable)->clear(this->functor);
        vtable = 0;
      }
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
        this->vtable = f.vtable;
        f.vtable->manager(f.functor, this->functor,
                          boost::detail::function::clone_functor_tag);
      }
    }

    template<typename Functor>
    void assign_to(Functor f)
    {
      using detail::function::vtable_base;

      typedef typename detail::function::get_function_tag<Functor>::type tag;
      typedef detail::function::BOOST_FUNCTION_GET_INVOKER<tag> get_invoker;
      typedef typename get_invoker::
                         template apply<Functor, R BOOST_FUNCTION_COMMA 
                        BOOST_FUNCTION_TEMPLATE_ARGS>
        handler_type;
      
      typedef typename handler_type::invoker_type invoker_type;
      typedef typename handler_type::manager_type manager_type;

      // Note: it is extremely important that this initialization use
      // static initialization. Otherwise, we will have a race
      // condition here in multi-threaded code. See
      // http://thread.gmane.org/gmane.comp.lib.boost.devel/164902/.
      static vtable_type stored_vtable = 
        { { &manager_type::manage }, &invoker_type::invoke };

      if (stored_vtable.assign_to(f, functor)) vtable = &stored_vtable.base;
      else vtable = 0;
    }

    template<typename Functor,typename Allocator>
    void assign_to_a(Functor f,Allocator a)
    {
      using detail::function::vtable_base;

      typedef typename detail::function::get_function_tag<Functor>::type tag;
      typedef detail::function::BOOST_FUNCTION_GET_INVOKER<tag> get_invoker;
      typedef typename get_invoker::
                         template apply_a<Functor, R BOOST_FUNCTION_COMMA 
                         BOOST_FUNCTION_TEMPLATE_ARGS,
                         Allocator>
        handler_type;
      
      typedef typename handler_type::invoker_type invoker_type;
      typedef typename handler_type::manager_type manager_type;

      // Note: it is extremely important that this initialization use
      // static initialization. Otherwise, we will have a race
      // condition here in multi-threaded code. See
      // http://thread.gmane.org/gmane.comp.lib.boost.devel/164902/.
      static vtable_type stored_vtable =
        { { &manager_type::manage }, &invoker_type::invoke };

      if (stored_vtable.assign_to_a(f, functor, a)) vtable = &stored_vtable.base;
      else vtable = 0;
    }

    // Moves the value from the specified argument to *this. If the argument 
    // has its function object allocated on the heap, move_assign will pass 
    // its buffer to *this, and set the argument's buffer pointer to NULL. 
    void move_assign(BOOST_FUNCTION_FUNCTION& f) 
    { 
      if (&f == this)
        return;

#if !defined(BOOST_NO_EXCEPTIONS)      
      try {
#endif
        if (!f.empty()) {
          this->vtable = f.vtable;
          f.vtable->manager(f.functor, this->functor,
                            boost::detail::function::move_functor_tag);
		  f.vtable = 0;
#if !defined(BOOST_NO_EXCEPTIONS)      
        } else {
          clear();
        }
      } catch (...) {
        vtable = 0;
        throw;
      }
#endif
    }
  };

  template<typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS>
  inline void swap(BOOST_FUNCTION_FUNCTION<
                     R BOOST_FUNCTION_COMMA
                     BOOST_FUNCTION_TEMPLATE_ARGS
                   >& f1,
                   BOOST_FUNCTION_FUNCTION<
                     R BOOST_FUNCTION_COMMA
                     BOOST_FUNCTION_TEMPLATE_ARGS
                   >& f2)
  {
    f1.swap(f2);
  }

#if !BOOST_WORKAROUND(BOOST_MSVC, < 1300)
  template<typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS>
  typename BOOST_FUNCTION_FUNCTION<
      R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_ARGS>::result_type
   BOOST_FUNCTION_FUNCTION<R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_ARGS>
  ::operator()(BOOST_FUNCTION_PARMS) const
  {
    if (this->empty())
      boost::throw_exception(bad_function_call());

    return reinterpret_cast<const vtable_type*>(vtable)->invoker
             (this->functor BOOST_FUNCTION_COMMA BOOST_FUNCTION_ARGS);
  }
#endif

// Poison comparisons between boost::function objects of the same type.
template<typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS>
  void operator==(const BOOST_FUNCTION_FUNCTION<
                          R BOOST_FUNCTION_COMMA
                          BOOST_FUNCTION_TEMPLATE_ARGS>&,
                  const BOOST_FUNCTION_FUNCTION<
                          R BOOST_FUNCTION_COMMA
                          BOOST_FUNCTION_TEMPLATE_ARGS>&);
template<typename R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_PARMS>
  void operator!=(const BOOST_FUNCTION_FUNCTION<
                          R BOOST_FUNCTION_COMMA
                          BOOST_FUNCTION_TEMPLATE_ARGS>&,
                  const BOOST_FUNCTION_FUNCTION<
                          R BOOST_FUNCTION_COMMA
                          BOOST_FUNCTION_TEMPLATE_ARGS>& );

#if !defined(BOOST_FUNCTION_NO_FUNCTION_TYPE_SYNTAX)

#if BOOST_FUNCTION_NUM_ARGS == 0
#define BOOST_FUNCTION_PARTIAL_SPEC R (void)
#else
#define BOOST_FUNCTION_PARTIAL_SPEC R (BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,T))
#endif

template<typename R BOOST_FUNCTION_COMMA
         BOOST_FUNCTION_TEMPLATE_PARMS>
class function<BOOST_FUNCTION_PARTIAL_SPEC>
  : public BOOST_FUNCTION_FUNCTION<R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_ARGS>
{
  typedef BOOST_FUNCTION_FUNCTION<R BOOST_FUNCTION_COMMA BOOST_FUNCTION_TEMPLATE_ARGS> base_type;
  typedef function self_type;

  struct clear_type {};

public:

  function() : base_type() {}

  template<typename Functor>
  function(Functor f
#ifndef BOOST_NO_SFINAE
           ,typename enable_if_c<
                            (boost::type_traits::ice_not<
                          (is_integral<Functor>::value)>::value),
                       int>::type = 0
#endif
           ) :
    base_type(f)
  {
  }
  template<typename Functor,typename Allocator>
  function(Functor f, Allocator a
#ifndef BOOST_NO_SFINAE
           ,typename enable_if_c<
                            (boost::type_traits::ice_not<
                          (is_integral<Functor>::value)>::value),
                       int>::type = 0
#endif
           ) :
    base_type(f,a)
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
                            (boost::type_traits::ice_not<
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
#undef BOOST_FUNCTION_VTABLE
#undef BOOST_FUNCTION_COMMA
#undef BOOST_FUNCTION_FUNCTION
#undef BOOST_FUNCTION_FUNCTION_INVOKER
#undef BOOST_FUNCTION_VOID_FUNCTION_INVOKER
#undef BOOST_FUNCTION_FUNCTION_OBJ_INVOKER
#undef BOOST_FUNCTION_VOID_FUNCTION_OBJ_INVOKER
#undef BOOST_FUNCTION_FUNCTION_REF_INVOKER
#undef BOOST_FUNCTION_VOID_FUNCTION_REF_INVOKER
#undef BOOST_FUNCTION_MEMBER_INVOKER
#undef BOOST_FUNCTION_VOID_MEMBER_INVOKER
#undef BOOST_FUNCTION_GET_FUNCTION_INVOKER
#undef BOOST_FUNCTION_GET_FUNCTION_OBJ_INVOKER
#undef BOOST_FUNCTION_GET_FUNCTION_REF_INVOKER
#undef BOOST_FUNCTION_GET_MEM_FUNCTION_INVOKER
#undef BOOST_FUNCTION_GET_INVOKER
#undef BOOST_FUNCTION_TEMPLATE_PARMS
#undef BOOST_FUNCTION_TEMPLATE_ARGS
#undef BOOST_FUNCTION_PARMS
#undef BOOST_FUNCTION_PARM
#undef BOOST_FUNCTION_ARGS
#undef BOOST_FUNCTION_ARG_TYPE
#undef BOOST_FUNCTION_ARG_TYPES
#undef BOOST_FUNCTION_VOID_RETURN_TYPE
#undef BOOST_FUNCTION_RETURN

#if defined(BOOST_MSVC)
#   pragma warning( pop )
#endif       

#undef BOOST_FUNCTION_NUM_ARGS
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
namespace RBX {
class worker_thread {
public:
    enum work_result { more, done };
    struct data;
};
}
typedef boost::shared_ptr<RBX::worker_thread::data> roc_data_ptr;
typedef boost::function0<RBX::worker_thread::work_result> roc_work_fn;
template boost::_bi::bind_t<void, void (*)(roc_data_ptr, const roc_work_fn&), boost::_bi::list_av_2<roc_data_ptr, roc_work_fn>::type>
    boost::bind(void (*)(roc_data_ptr, const roc_work_fn&), roc_data_ptr, roc_work_fn);
