// from server: 100% by EspClaude
// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_3e040f0c42933ad7.cpp

// Candidate translation unit (score above; library headers required).
#ifndef BOOST_SHARED_PTR_HPP_INCLUDED
#define BOOST_SHARED_PTR_HPP_INCLUDED

//
//  shared_ptr.hpp
//
//  (C) Copyright Greg Colvin and Beman Dawes 1998, 1999.
//  Copyright (c) 2001-2006 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  See http://www.boost.org/libs/smart_ptr/shared_ptr.htm for documentation.
//

#include <boost/config.hpp>   // for broken compiler workarounds

#if defined(BOOST_NO_MEMBER_TEMPLATES) && !defined(BOOST_MSVC6_MEMBER_TEMPLATES)
#include <boost/detail/shared_ptr_nmt.hpp>
#else

#include <memory>               // for std::auto_ptr

#include <boost/assert.hpp>
#include <boost/checked_delete.hpp>
#include <boost/throw_exception.hpp>
#include <boost/detail/shared_count.hpp>
#include <boost/detail/workaround.hpp>

#include <algorithm>            // for std::swap
#include <functional>           // for std::less
#include <typeinfo>             // for std::bad_cast
#include <iosfwd>               // for std::basic_ostream

#ifdef BOOST_MSVC  // moved here to work around VC++ compiler crash
# pragma warning(push)
# pragma warning(disable:4284) // odd return type for operator->
#endif

namespace boost
{
namespace detail { struct sp_empty {}; }

template<class T> class weak_ptr;
template<class T> class enable_shared_from_this;

namespace detail
{

struct static_cast_tag {};
struct const_cast_tag {};
struct dynamic_cast_tag {};
struct polymorphic_cast_tag {};

template<class T> struct shared_ptr_traits
{
    typedef T & reference;
};

template<> struct shared_ptr_traits<void>
{
    typedef void reference;
};

#if !defined(BOOST_NO_CV_VOID_SPECIALIZATIONS)

template<> struct shared_ptr_traits<void const>
{
    typedef void reference;
};

template<> struct shared_ptr_traits<void volatile>
{
    typedef void reference;
};

template<> struct shared_ptr_traits<void const volatile>
{
    typedef void reference;
};

#endif

// enable_shared_from_this support

template<class T, class Y> void sp_enable_shared_from_this( shared_count const & pn, boost::enable_shared_from_this<T> const * pe, Y const * px )
{
    if(pe != 0) pe->_internal_weak_this._internal_assign(const_cast<Y*>(px), pn);
}

#ifdef sgi
// Turn off: the last argument of the varargs function "sp_enable_shared_from_this" is unnamed
# pragma set woff 3506
#endif

inline void sp_enable_shared_from_this( shared_count const & /*pn*/, ... )
{
}

#ifdef sgi
# pragma reset woff 3506
#endif

#if !defined( BOOST_NO_SFINAE ) && !defined( BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION ) && !defined( BOOST_NO_AUTO_PTR )

// rvalue auto_ptr support based on a technique by Dave Abrahams

template< class T, class R > struct sp_enable_if_auto_ptr
{
};

template< class T, class R > struct sp_enable_if_auto_ptr< std::auto_ptr< T >, R >
{
    typedef R type;
}; 

#endif

} // namespace detail


//
//  shared_ptr
//
//  An enhanced relative of scoped_ptr with reference counted copy semantics.
//  The object pointed to is deleted when the last shared_ptr pointing to it
//  is destroyed or reset.
//

template<class T> class shared_ptr
{
private:

    // Borland 5.5.1 specific workaround
    typedef shared_ptr<T> this_type;

public:

    typedef T element_type;
    typedef T value_type;
    typedef T * pointer;
    typedef typename boost::detail::shared_ptr_traits<T>::reference reference;

    shared_ptr(): px(0), pn() // never throws in 1.30+
    {
    }

    template<class Y>
    explicit shared_ptr( Y * p ): px( p ), pn( p ) // Y must be complete
    {
        boost::detail::sp_enable_shared_from_this( pn, p, p );
    }

    //
    // Requirements: D's copy constructor must not throw
    //
    // shared_ptr will release p by calling d(p)
    //

    template<class Y, class D> shared_ptr(Y * p, D d): px(p), pn(p, d)
    {
        boost::detail::sp_enable_shared_from_this( pn, p, p );
    }

    // As above, but with allocator. A's copy constructor shall not throw.

    template<class Y, class D, class A> shared_ptr( Y * p, D d, A a ): px( p ), pn( p, d, a )
    {
        boost::detail::sp_enable_shared_from_this( pn, p, p );
    }

//  generated copy constructor, assignment, destructor are fine...

//  except that Borland C++ has a bug, and g++ with -Wsynth warns
#if defined(__BORLANDC__) || defined(__GNUC__)

    shared_ptr & operator=(shared_ptr const & r) // never throws
    {
        px = r.px;
        pn = r.pn; // shared_count::op= doesn't throw
        return *this;
    }

#endif

    template<class Y>
    explicit shared_ptr(weak_ptr<Y> const & r): pn(r.pn) // may throw
    {
        // it is now safe to copy r.px, as pn(r.pn) did not throw
        px = r.px;
    }

    template<class Y>
    shared_ptr(shared_ptr<Y> const & r, boost::detail::sp_empty = boost::detail::sp_empty()): px(r.px), pn(r.pn) // never throws
    {
    }

    template<class Y>
    shared_ptr(shared_ptr<Y> const & r, boost::detail::static_cast_tag): px(static_cast<element_type *>(r.px)), pn(r.pn)
    {
    }

    template<class Y>
    shared_ptr(shared_ptr<Y> const & r, boost::detail::const_cast_tag): px(const_cast<element_type *>(r.px)), pn(r.pn)
    {
    }

    template<class Y>
    shared_ptr(shared_ptr<Y> const & r, boost::detail::dynamic_cast_tag): px(dynamic_cast<element_type *>(r.px)), pn(r.pn)
    {
        if(px == 0) // need to allocate new counter -- the cast failed
        {
            pn = boost::detail::shared_count();
        }
    }

    template<class Y>
    shared_ptr(shared_ptr<Y> const & r, boost::detail::polymorphic_cast_tag): px(dynamic_cast<element_type *>(r.px)), pn(r.pn)
    {
        if(px == 0)
        {
            boost::throw_exception(std::bad_cast());
        }
    }

#ifndef BOOST_NO_AUTO_PTR

    template<class Y>
    explicit shared_ptr(std::auto_ptr<Y> & r): px(r.get()), pn()
    {
        Y * tmp = r.get();
        pn = boost::detail::shared_count(r);
        boost::detail::sp_enable_shared_from_this( pn, tmp, tmp );
    }

#if !defined( BOOST_NO_SFINAE ) && !defined( BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION )

    template<class Ap>
    explicit shared_ptr( Ap r, typename boost::detail::sp_enable_if_auto_ptr<Ap, int>::type = 0 ): px( r.get() ), pn()
    {
        typename Ap::element_type * tmp = r.get();
        pn = boost::detail::shared_count( r );
        boost::detail::sp_enable_shared_from_this( pn, tmp, tmp );
    }


#endif // BOOST_NO_SFINAE, BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#endif // BOOST_NO_AUTO_PTR

#if !defined(BOOST_MSVC) || (BOOST_MSVC >= 1300)

    template<class Y>
    shared_ptr & operator=(shared_ptr<Y> const & r) // never throws
    {
        px = r.px;
        pn = r.pn; // shared_count::op= doesn't throw
        return *this;
    }

#endif

#ifndef BOOST_NO_AUTO_PTR

    template<class Y>
    shared_ptr & operator=( std::auto_ptr<Y> & r )
    {
        this_type(r).swap(*this);
        return *this;
    }

#if !defined( BOOST_NO_SFINAE ) && !defined( BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION )

    template<class Ap>
    typename boost::detail::sp_enable_if_auto_ptr< Ap, shared_ptr & >::type operator=( Ap r )
    {
        this_type( r ).swap( *this );
        return *this;
    }


#endif // BOOST_NO_SFINAE, BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#endif // BOOST_NO_AUTO_PTR

    void reset() // never throws in 1.30+
    {
        this_type().swap(*this);
    }

    template<class Y> void reset(Y * p) // Y must be complete
    {
        BOOST_ASSERT(p == 0 || p != px); // catch self-reset errors
        this_type(p).swap(*this);
    }

    template<class Y, class D> void reset( Y * p, D d )
    {
        this_type( p, d ).swap( *this );
    }

    template<class Y, class D, class A> void reset( Y * p, D d, A a )
    {
        this_type( p, d, a ).swap( *this );
    }

    reference operator* () const // never throws
    {
        BOOST_ASSERT(px != 0);
        return *px;
    }

    T * operator-> () const // never throws
    {
        BOOST_ASSERT(px != 0);
        return px;
    }
    
    T * get() const // never throws
    {
        return px;
    }

    // implicit conversion to "bool"

#if defined(__SUNPRO_CC) && BOOST_WORKAROUND(__SUNPRO_CC, <= 0x580)

    operator bool () const
    {
        return px != 0;
    }

#elif defined( _MANAGED )

    static void unspecified_bool( this_type*** )
    {
    }

    typedef void (*unspecified_bool_type)( this_type*** );

    operator unspecified_bool_type() const // never throws
    {
        return px == 0? 0: unspecified_bool;
    }

#elif \
    ( defined(__MWERKS__) && BOOST_WORKAROUND(__MWERKS__, < 0x3200) ) || \
    ( defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ < 304) )

    typedef T * (this_type::*unspecified_bool_type)() const;
    
    operator unspecified_bool_type() const // never throws
    {
        return px == 0? 0: &this_type::get;
    }

#else 

    typedef T * this_type::*unspecified_bool_type;

    operator unspecified_bool_type() const // never throws
    {
        return px == 0? 0: &this_type::px;
    }

#endif

    // operator! is redundant, but some compilers need it

    bool operator! () const // never throws
    {
        return px == 0;
    }

    bool unique() const // never throws
    {
        return pn.unique();
    }

    long use_count() const // never throws
    {
        return pn.use_count();
    }

    void swap(shared_ptr<T> & other) // never throws
    {
        std::swap(px, other.px);
        pn.swap(other.pn);
    }

    template<class Y> bool _internal_less(shared_ptr<Y> const & rhs) const
    {
        return pn < rhs.pn;
    }

    void * _internal_get_deleter(std::type_info const & ti) const
    {
        return pn.get_deleter(ti);
    }

// Tasteless as this may seem, making all members public allows member templates
// to work in the absence of member template friends. (Matthew Langston)

#ifndef BOOST_NO_MEMBER_TEMPLATE_FRIENDS

private:

    template<class Y> friend class shared_ptr;
    template<class Y> friend class weak_ptr;


#endif

    T * px;                     // contained pointer
    boost::detail::shared_count pn;    // reference counter

};  // shared_ptr

template<class T, class U> inline bool operator==(shared_ptr<T> const & a, shared_ptr<U> const & b)
{
    return a.get() == b.get();
}

template<class T, class U> inline bool operator!=(shared_ptr<T> const & a, shared_ptr<U> const & b)
{
    return a.get() != b.get();
}

#if __GNUC__ == 2 && __GNUC_MINOR__ <= 96

// Resolve the ambiguity between our op!= and the one in rel_ops

template<class T> inline bool operator!=(shared_ptr<T> const & a, shared_ptr<T> const & b)
{
    return a.get() != b.get();
}

#endif

template<class T, class U> inline bool operator<(shared_ptr<T> const & a, shared_ptr<U> const & b)
{
    return a._internal_less(b);
}

template<class T> inline void swap(shared_ptr<T> & a, shared_ptr<T> & b)
{
    a.swap(b);
}

template<class T, class U> shared_ptr<T> static_pointer_cast(shared_ptr<U> const & r)
{
    return shared_ptr<T>(r, boost::detail::static_cast_tag());
}

template<class T, class U> shared_ptr<T> const_pointer_cast(shared_ptr<U> const & r)
{
    return shared_ptr<T>(r, boost::detail::const_cast_tag());
}

template<class T, class U> shared_ptr<T> dynamic_pointer_cast(shared_ptr<U> const & r)
{
    return shared_ptr<T>(r, boost::detail::dynamic_cast_tag());
}

// shared_*_cast names are deprecated. Use *_pointer_cast instead.

template<class T, class U> shared_ptr<T> shared_static_cast(shared_ptr<U> const & r)
{
    return shared_ptr<T>(r, boost::detail::static_cast_tag());
}

template<class T, class U> shared_ptr<T> shared_dynamic_cast(shared_ptr<U> const & r)
{
    return shared_ptr<T>(r, boost::detail::dynamic_cast_tag());
}

template<class T, class U> shared_ptr<T> shared_polymorphic_cast(shared_ptr<U> const & r)
{
    return shared_ptr<T>(r, boost::detail::polymorphic_cast_tag());
}

template<class T, class U> shared_ptr<T> shared_polymorphic_downcast(shared_ptr<U> const & r)
{
    BOOST_ASSERT(dynamic_cast<T *>(r.get()) == r.get());
    return shared_static_cast<T>(r);
}

// get_pointer() enables boost::mem_fn to recognize shared_ptr

template<class T> inline T * get_pointer(shared_ptr<T> const & p)
{
    return p.get();
}

// operator<<

#if defined(__GNUC__) &&  (__GNUC__ < 3)

template<class Y> std::ostream & operator<< (std::ostream & os, shared_ptr<Y> const & p)
{
    os << p.get();
    return os;
}

#else

// in STLport's no-iostreams mode no iostream symbols can be used
#ifndef _STLP_NO_IOSTREAMS

# if defined(BOOST_MSVC) && BOOST_WORKAROUND(BOOST_MSVC, < 1300 && __SGI_STL_PORT)
// MSVC6 has problems finding std::basic_ostream through the using declaration in namespace _STL
using std::basic_ostream;
template<class E, class T, class Y> basic_ostream<E, T> & operator<< (basic_ostream<E, T> & os, shared_ptr<Y> const & p)
# else
template<class E, class T, class Y> std::basic_ostream<E, T> & operator<< (std::basic_ostream<E, T> & os, shared_ptr<Y> const & p)
# endif 
{
    os << p.get();
    return os;
}

#endif // _STLP_NO_IOSTREAMS

#endif // __GNUC__ < 3

// get_deleter (experimental)

#if ( defined(__GNUC__) && BOOST_WORKAROUND(__GNUC__, < 3) ) || \
    ( defined(__EDG_VERSION__) && BOOST_WORKAROUND(__EDG_VERSION__, <= 238) ) || \
    ( defined(__HP_aCC) && BOOST_WORKAROUND(__HP_aCC, <= 33500) )

// g++ 2.9x doesn't allow static_cast<X const *>(void *)
// apparently EDG 2.38 and HP aCC A.03.35 also don't accept it

template<class D, class T> D * get_deleter(shared_ptr<T> const & p)
{
    void const * q = p._internal_get_deleter(typeid(D));
    return const_cast<D *>(static_cast<D const *>(q));
}

#else

template<class D, class T> D * get_deleter(shared_ptr<T> const & p)
{
    return static_cast<D *>(p._internal_get_deleter(typeid(D)));
}

#endif

} // namespace boost

#ifdef BOOST_MSVC
# pragma warning(pop)
#endif    

#endif  // #if defined(BOOST_NO_MEMBER_TEMPLATES) && !defined(BOOST_MSVC6_MEMBER_TEMPLATES)

#endif  // #ifndef BOOST_SHARED_PTR_HPP_INCLUDED


#include "reflection/reflection.h"
#include "script/ThreadRef.h"
#include "script/LuaAtomicClasses.h"
#include "script/LuaInstanceBridge.h"
#include "lua.h"

#include "G3D/Vector2.h"
namespace RBX { namespace Reflection {
struct ExeType2009 { void* vptr; const void* name; const void* type; const void* tag; bool isEnum; bool isNumber; };
struct Tuple {
    ValueCollection values;
    Tuple() {}
    Tuple(size_t count):values(count) {}
    Tuple(const Tuple& other):values(other.values) {}
    Value& at(size_t i) { return values[i]; }
    const Value& at(size_t i) const { return values[i]; }
};
} }
namespace RBX
{
    namespace Lua
    {
        class LuaArguments : public Reflection::FunctionDescriptor::Arguments 
        {
        private:
            const int offset;
            lua_State* L;
  
        public:
            LuaArguments(lua_State* L, int offset)
                : offset(offset),
                  L(L)
            {
            }
            virtual size_t size() const
            {
                // TODO: check match
                return lua_gettop(L)-1;
            }
            virtual void get(int index, Reflection::Value& value) const
            {
                // TODO: check match
                int pos = index + offset;
                RBXASSERT(pos > 0);
                get(L, pos, value);
            }
            int push(const Reflection::Value& value) const
            {
                return push(value, L);
            }
            int pushReturnValue() const
            {
                return push(returnValue);
            }

        public:
            // TODO: 97.00%
            static void get(lua_State* L, int luaIndex, Reflection::Value& value)
            {
                // (018310)  S_BPREL32: [FFFFFF80], Type:             0x11DC, n ; const int
                // (018320)  S_BPREL32: [FFFFFF84], Type:             0x928D, values ; *std::vector<RBX::Reflection::Value> / *ValueCollection

                if (luaIndex <= lua_gettop(L))
                {
                    switch (lua_type(L, luaIndex))
                    {
                    case LUA_TNUMBER:
                    {
                        float rhs = lua_tonumber(L, luaIndex);
                        value = rhs;
                        return;
                    }

                    case LUA_TBOOLEAN:
                    {
                        bool rhs = lua_toboolean(L, luaIndex) != 0;
                        value = rhs;
                        return;
                    }

                    case LUA_TSTRING:
                    {
                        const char* str = lua_tostring(L, luaIndex);
                        value = std::string(str);
                        return;
                    }

                    case LUA_TTABLE:
                    {
                        const int n = static_cast<const int>(lua_objlen(L, luaIndex));
                        value = Reflection::ValueCollection(n);
                        Reflection::ValueCollection& values = value.cast<Reflection::ValueCollection&>();

                        if (n >= 1)
                        {
                            int i = 1;
                            do
                            {
                                Reflection::Value& ival = values[i-1];
                                lua_rawgeti(L, luaIndex, i);
                                LuaArguments::get(L, -1, ival);
                                lua_pop(L, 1);
                                i++;
                            } while (i <= n);
                        }

                        return;
                    }

                    case LUA_TNIL:
                        value = Reflection::Value();
                        break;

                    case LUA_TFUNCTION:
                        value = lua_tofunction(L, luaIndex);
                        return;

                    case LUA_TUSERDATA:
                        if (CoordinateFrameBridge::getValue(L, luaIndex, value)
                            || Vector3Bridge::getValue(L, luaIndex, value)
                            || Color3Bridge::getValue(L, luaIndex, value)
                            || BrickColorBridge::getValue(L, luaIndex, value)
                            || ObjectBridge::getPtr(L, luaIndex, value))
                            return;

                        value = Reflection::Value();
                        break;

                    default:
                        value = Reflection::Value();
                        break;
                    }
                }
            }

            static int push(const Reflection::Value& value, lua_State* const L);
        public:
            template <typename T>
            static int pushTable(T _First, T _Last, lua_State* const L)
            {
                lua_createtable(L, _Last-_First, 0);

                int i = 0;
                for (; _First != _Last; _First++)
                {
                    push(*_First, L);
                    lua_rawseti(L, -2, ++i);
                }

                return 1;
            }
        };
    }
}

int RBX::Lua::LuaArguments::push(const Reflection::Value& value, lua_State* const L)
{
                if (value.isType<void>())
                    return 0;

                if (value.isType<bool>())
                {
                    lua_pushboolean(L, value.cast<const bool&>());
                    return 1;
                }

                bool isNumber = reinterpret_cast<const Reflection::ExeType2009&>(value.type()).isNumber;
                if (isNumber)
                {
                    lua_pushnumber(L, value.get<double>());
                    return 1;
                }

                if (value.isType<FunctionRef>())
                {
                    lua_pushfunction(L, value.cast<const FunctionRef&>());
                    return 1;
                }

                if (value.isType<std::string>())
                {
                    lua_pushstring(L, value.cast<const std::string&>().c_str());
                    return 1;
                }

                if (value.isType<G3D::Vector3>())
                {
                    Vector3Bridge::pushVector3(L, value.cast<const G3D::Vector3&>());
                    return 1;
                }

                if (value.isType<G3D::Vector2>())
                {
                    Bridge<G3D::Vector2, true>::pushNewObject(L, value.cast<const G3D::Vector2&>());
                    return 1;
                }

                if (value.isType<G3D::CoordinateFrame>())
                {
                    CoordinateFrameBridge::pushCoordinateFrame(L, value.cast<const G3D::CoordinateFrame&>());
                    return 1;
                }

                if (value.isType<G3D::Color3>())
                {
                    Color3Bridge::pushColor3(L, value.cast<const G3D::Color3&>());
                    return 1;
                }

                if (value.isType<BrickColor>())
                {
                    BrickColorBridge::pushNewObject(L, value.cast<const BrickColor&>());
                    return 1;
                }

                if (value.isType<ContentId>())
                {
                    lua_pushstring(L, value.cast<const ContentId&>().c_str());
                    return 1;
                }

                if (value.isType<boost::shared_ptr<Instance>>())
                {
                    ObjectBridge::push(L, value.cast<const boost::shared_ptr<Instance>&>());
                    return 1;
                }

                if (value.isType<boost::shared_ptr<Reflection::DescribedBase>>())
                {
                    ObjectBridge::push(L, value.cast<const boost::shared_ptr<Reflection::DescribedBase>&>());
                    return 1;
                }

                if (value.isType<Reflection::ValueCollection>())
                {
                    const Reflection::ValueCollection& collection = value.cast<const Reflection::ValueCollection&>();
                    return pushTable(collection.begin(), collection.end(), L);
                }

                if (value.isType<Reflection::Tuple>())
                {
                    const Reflection::Tuple& tuple = value.cast<const Reflection::Tuple&>();
                    int count = 0;
                    Reflection::ValueCollection::const_iterator iter = tuple.values.begin();
                    Reflection::ValueCollection::const_iterator end = tuple.values.end();
                    while (iter != end) {
                        count += push(*iter, L);
                        ++iter;
                    }
                    return count;
                }

                if (value.isType<boost::shared_ptr<const Instances>>())
                {
                    boost::shared_ptr<const Instances> values = value.cast<boost::shared_ptr<const Instances>>();

                    if (values)
                    {
                        return pushTable(values->begin(), values->end(), L);
                    }
                    else
                    {
                        lua_newtable(L);
                        return 1;
                    }
                }

                return 0;
            }

