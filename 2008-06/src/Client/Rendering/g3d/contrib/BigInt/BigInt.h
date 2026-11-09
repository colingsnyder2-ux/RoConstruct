/**
 @file BigInt.h
 
 
 @maintainer Morgan McGuire, matrix@graphics3d.com
 
 @created 2006-04-06
 @edited  2006-04-06

 Copyright 2000-2006, Morgan McGuire.
 All rights reserved.
 */
#ifndef G3D_BIGINT_H
#define G3D_BIGINT_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"

namespace G3D {

class MD5Hash;

/** 
  Representation of arbitrary length integers.
  The implementation is not optimized for performance; it
  favors convenience and simplicity of implementation.

  Bitwise operations all return positive results.

  The following operations have not be implemented in this 
  version:

  operator/
  operator%
  toString()
  random
  randomNumBits
 */
class BigInt {
private:

    // Can't use Array in here or we would not be able to create
    // arrays of BigInts.  We use System::malloc instead of std::vector;
    // it leads to fas allocation and copying and we don't often need
    // to grow the array anyway.

    // As a future optimization we could maintain a fixed size array (say, int64)
    // and only allocate when exceeding that size.

    /** Big endian, unsigned. Always contains the minimum number 
        of bytes needed to represent the current number.*/
    uint8*      byte;

    /** Length of byte */
    int         numBytes;

    /** 0, 1, or -1.  Always zero for the number zero */
    int         sgn;

	/** n is the number of bytes */
    void setSize(int n);

    /** Parses the hex or decimal representation and 
        modifies this.*/
    void parse(const char*);

    /** Assumes the sign is already read and that the number begins with "0x" */
    void parseHex(const char*);

    /** Assumes the sign is already read. */
    void parseDec(const char*);

    /** Uses setSize to remove any extra leading zeros after
        an operation.*/
    void stripLeadingZeros();

    inline bool nonZero() const {
        return sgn != 0;
    }

    inline bool isZero() const {
        return sgn == 0;
    }

    /** Called from the int constructors */
    void setUnsignedInt32(G3D::uint32 x);
    void setUnsignedInt64(G3D::uint64 a);

    /** Shifts to the left(positive) or right(negative) the specified number of digits.*/
    void shift255(int count);

    /** Performs x < y, or x <= y if ifEqual is true.*/
    static bool compare(const BigInt& x, const BigInt& y, bool ifEqual);


    /** 
      Solves for x/y, where y is smaller than x and both are within 2^9
      of each other, and both are positive.

      Used inside operator/
     */
    static uint64 closeDiv(const BigInt& x, const BigInt& y, BigInt& remainder);

public:

    /** Zero */
    BigInt();

    BigInt(uint32 x);

    BigInt(int32 x);

    BigInt(uint64 x);

    BigInt(int64 x);

    /** Creates a big-endian signed number */
    BigInt(const uint8* bytes, size_t numBytes, int sign = 1);

    BigInt(const BigInt&);

    BigInt(const MD5Hash&);

    explicit BigInt(class BinaryInput&);

    ~BigInt();

    /** Returns the largest non-zero byte index in unsigned big-endian
        representation.  Returns 0 for the number 0.*/
    inline int size() const {
        return numBytes;
    }

    /** Returns 1, 0, or -1 */
    inline int sign() const {
        return sgn;
    }

    /** If the string begins with "0x", "+0x", or "-0x" it is parsed as hex, 
        otherwise it is parsed as decimal.*/
    BigInt(const std::string& s);

    BigInt(const char* s);

    /** Uniform pseudorandom number, inclusive of the bounds. */
    static BigInt random(const BigInt& low, const BigInt& high);

    /** Generates a random number between 0 and (2^numBits)-1 using BigInt::random() */
    static BigInt randomNumBits(int numBits);

    /** 
      Returns byte i, starting from the low-order end, assuming an unsigned
      big endian representation.
      Returns zero for out of range values.
      */
    uint8 operator[](int i) const;
    BigInt& operator=(const BigInt&);
    BigInt operator-() const;
    BigInt operator+(const BigInt& x) const;
    BigInt operator-(const BigInt& x) const;
    BigInt operator&(const BigInt& x) const;
    BigInt operator|(const BigInt& x) const;
    BigInt operator^(const BigInt& x) const;
    bool operator>(const BigInt& x) const;
    bool operator<(const BigInt& x) const;
    bool operator>=(const BigInt& x) const;
    bool operator<=(const BigInt& x) const;
    bool operator==(const BigInt& x) const;
    bool operator!=(const BigInt& x) const;
    BigInt operator%(const BigInt& x) const;
    /** Integer division */
    BigInt operator/(const BigInt& x) const;
    BigInt operator*(const BigInt& x) const;

    BigInt& operator*=(const BigInt& x);
    BigInt& operator/=(const BigInt& x);
    BigInt& operator+=(const BigInt& x);
    BigInt& operator-=(const BigInt& x);

    void serialize(class BinaryOutput&) const;
    void deserialize(class BinaryInput&);

    /** Assertion fails if out of range. */
    int32 int32() const;

    /** Assertion fails if out of range. */
    int64 int64() const;

    /** Assertion fails if out of range. */
    uint32 uint32() const;

    /** Assertion fails if out of range. */
    uint64 uint64() const;

    /** 
      Returns this positive, <= 512 bit number as an MD5Hash.  Does <b>not</b> return the
      hash of this BigInt!
    */
    MD5Hash MD5Hash() const;

    /** Decimal representation */
    std::string toString() const;

    std::string toHexString() const;

    BigInt abs() const;

    BigInt pow(int) const;

	BigInt max(const BigInt& other) const;

	BigInt min(const BigInt& other) const;

    /** Computes this^p % m without huge intermediate results.
      */
    BigInt powMod(const int p, BigInt& m) const;
};

BigInt abs(const BigInt&);

} // namespace G3D

#endif
