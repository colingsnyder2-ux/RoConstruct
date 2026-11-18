// Boost.Any library - native header for boost::any::holder instantiation
// This header provides a dummy holder declaration for the twin lane index.
// Actual definition comes from <boost/any.hpp> in the toolchain.

#ifndef BOOST_ANY_NATIVE_HPP
#define BOOST_ANY_NATIVE_HPP

// Dummy holder for index scanning - not used in actual compilation
template<typename ValueType>
class holder
{
public:
    holder(const ValueType & value) : held(value) {}
    ValueType held;
};

#endif // BOOST_ANY_NATIVE_HPP