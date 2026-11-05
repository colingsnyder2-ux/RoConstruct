/**
 @file BigInt.cpp

 @maintainer Morgan McGuire, matrix@graphics3d.com
 
 @created 2006-04-06
 @edited  2006-04-06

 Copyright 2000-2006, Morgan McGuire.
 All rights reserved.
 */

#include "G3D/platform.h"
#include "G3D/System.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/Crypto.h"

#ifdef G3D_WIN32
#	ifndef _WIN32_WINNT
// Required for Wincrypt
#		define _WIN32_WINNT 0x0400
#	endif
#	include "Wincrypt.h"
#endif
#include "BigInt.h"

namespace G3D {

BigInt::BigInt(const uint8* b, size_t n, int s) {

    setSize(n);
    System::memcpy(byte, b, n);

    sgn = s;

    stripLeadingZeros();

    debugAssertM((sgn != 0) || (numBytes == 0),
        "Cannot have a sign bit of zero on a non-zero number.");
}


void BigInt::setSize(int n) {
    if (n == numBytes) {
        return;
    }

    if (n == 0) {
        System::free(byte);
        byte = NULL;
        sgn = 0;
    } else {
        debugAssert(n >= 0);

        byte = (uint8*)System::realloc(byte, n);

        // Zero revealed bytes 
        for (int i = numBytes; i < n; ++i) {
            byte[i] = 0;
        }
    }
    numBytes = n;
}


void BigInt::shift255(int count) {

    if ((count == 0) || isZero()) {

        return;

    } else if (count < 0) {

        // Shift right
        uint8* old = byte;
        int oldCount = numBytes;
        numBytes = G3D::max(0, numBytes + count);

        if (numBytes == 0) {
            sgn = 0;
        } else {
            byte = (uint8*)System::malloc(numBytes);

            // Copy old data
            System::memcpy(byte, old + oldCount - numBytes, numBytes);
        }

        System::free(old);

    } else if (count > 0) {

        // Shift left
        uint8* old = byte;
        int oldCount = numBytes;
        numBytes += count;

        byte = (uint8*)System::calloc(numBytes, 1);

        // Copy old data
        System::memcpy(byte + numBytes - oldCount, old, oldCount);

        System::free(old);
    }
}


BigInt::BigInt() : byte(NULL), numBytes(0), sgn(0) {
}


BigInt::BigInt(const G3D::MD5Hash& h) : byte(NULL), numBytes(0), sgn(0) {
    setSize(16);
    
    for (int i = 0; i < 16; ++i) {
        byte[i] = h[i];
    }

    sgn = 1;

    stripLeadingZeros();
}


BigInt::~BigInt() {
    System::free(byte);
    byte = 0;
}


void BigInt::setUnsignedInt32(G3D::uint32 a) {
    // Efficiently find the number of bytes needed to represent a
    int n =
        ((a > 0) ? 1 : 0) +
        ((a > 0xFF) ? 1 : 0) +
        ((a > 0xFFFF) ? 1 : 0) +
        ((a > 0xFFFFFF) ? 1 : 0);

    setSize(n);

    // Read in from low to high
    for (int i = 0; i < n; ++i) {
        byte[i] = a & 0xFF;
        a = a >> 8;
    }
}


void BigInt::setUnsignedInt64(G3D::uint64 a) {
    // Efficiently find the number of bytes needed to represent a
    int n =
        ((a > 0) ? 1 : 0) +
        ((a > 0xFF) ? 1 : 0) +
        ((a > 0xFFFF) ? 1 : 0) +
        ((a > 0xFFFFFF) ? 1 : 0) +
        ((a > 0xFFFFFFFFL) ? 1 : 0) +
        ((a > 0xFFFFFFFFFFL) ? 1 : 0) +
        ((a > 0xFFFFFFFFFFFFL) ? 1 : 0) +
        ((a > 0xFFFFFFFFFFFFFFL) ? 1 : 0);

    setSize(n);

    // Read in from low to high
    for (int i = 0; i < n; ++i) {
        byte[i] = a & 0xFF;
        a = a >> 8;
    }
}


BigInt::BigInt(G3D::uint32 x) : byte(NULL), numBytes(0), sgn((x > 0) ? 1 : 0) {
    setUnsignedInt32(x);
}


BigInt::BigInt(G3D::int32 x) : byte(NULL), numBytes(0), sgn(G3D::iSign(x)) {
    // Make unsigned
    setUnsignedInt32((G3D::uint32)(x * sgn));
}


int iSign(G3D::int64 x) {
    if (x > 0) {
        return 1;
    } else if (x == 0) {
        return 0;
    } else {
        return -1;
    }
}


BigInt::BigInt(G3D::int64 x) : byte(NULL), numBytes(0), sgn(G3D::iSign(x)) {
    // Make unsigned
    setUnsignedInt64((G3D::uint64)(x * sgn));
}


BigInt::BigInt(G3D::uint64 x) : byte(NULL), numBytes(0), sgn((x > 0) ? 1 : 0) {
    setUnsignedInt64(x);
}


BigInt::BigInt(const BigInt& x) : byte(NULL), numBytes(0), sgn(0) {
    *this = x;
}



BigInt::BigInt(class BinaryInput& b) : byte(NULL), numBytes(0), sgn(0) {
    deserialize(b);
}



BigInt::BigInt(const std::string& s) : byte(NULL), numBytes(0), sgn(0) {
    parse(s.c_str());
}



BigInt::BigInt(const char* s) : byte(NULL), numBytes(0), sgn(0) {
    parse(s);
}


BigInt BigInt::random(const BigInt& low, const BigInt& high) {
	debugAssert(high >= low);

	BigInt range = high - low;

	BigInt result;
	result.setSize(range.numBytes);
	result.sgn = 1;

	// Fill the buffer with random bytes
#	ifdef _WIN32
		HCRYPTPROV hProv;

		BOOL success = CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
		debugAssert(success); 
		
		success = CryptGenRandom(hProv, result.numBytes, result.byte);
		debugAssert(success);

		success = CryptReleaseContext(hProv, 0);
		debugAssert(success);
#	else
#		error BigInt::random only implemented on Win32.  Use OpenSSL.
#	endif

	result.stripLeadingZeros();
	result = result + low;

    return result;
}


BigInt BigInt::max(const BigInt& other) const {
	if (*this > other) {
		return *this;
	} else {
		return other;
	}
}


BigInt BigInt::min(const BigInt& other) const {
	if (*this < other) {
		return *this;
	} else {
		return other;
	}
}


BigInt BigInt::randomNumBits(int numBits) {
    return random(0, BigInt(2).pow(numBits));
}


uint8 BigInt::operator[](int i) const {
    if ((i >= 0) && (i < numBytes)) {
        return byte[i];
    } else {
        return 0;
    }
}


BigInt& BigInt::operator=(const BigInt& x) {
    setSize(x.numBytes);
    System::memcpy(byte, x.byte, numBytes);
    sgn = x.sgn;
    return *this;
}


BigInt BigInt::operator-() const {
    // Unary minus; flip sign
    BigInt result(*this);
    result.sgn = -result.sgn;
    return result;
}


BigInt BigInt::operator+(const BigInt& y) const {
    BigInt result;
    const BigInt& x = *this;

    if (x.isZero()) {
        return y;
    } else if (y.isZero()) {
        return x;
    }


    if (y.sgn != x.sgn) {
        // This is expressible as a subtraction of two
        // positive numbers.
        if (y.sgn == 1) {
            // y is positive, so x is negative
            return y - x.abs();
        } else {
            // x is positive, so y is negative
            return x - y.abs();
        }
    }

    // Both signs must match at this point, so make the result
    // sign match as well.
    result.sgn = y.sgn;

    // At this point we only have to compute the sum of two positive numbers
    // (although the sign bits in x and y may be arbitrary).

    int n = G3D::max(x.numBytes, y.numBytes);
    int i = 0;
    int carry = 0;

    // Iterate until we've touched each digit and have no carry left
    while ((i < n) || (carry != 0)) {
        // Let operator[] take care of boundary cases
        int a = x[i];
        int b = y[i];

        int c = a + b + carry;
        
        // Track the overflow in the new carry
        carry = c >> 8;
        c &= 0xFF;

        // Write to the result
        result.setSize(result.numBytes + 1);
        result.byte[i] = c;
        ++i;
    }

    return result;
}


BigInt BigInt::operator-(const BigInt& y) const {
    const BigInt& x = *this;

    if (y.isZero()) {
        return x;
    } else if (x.isZero()) {
        return -y;
    } else if (x.sgn == 1) {
        if (y.sgn == -1) {
            // An addition of two positive numbers
            return x + y.abs();     
        }
    } else if (y.sgn == 1) {
        // negative of the addition of two positive numbers
        return -(x.abs() + y);
    } else {
        // Simplify to the difference of two positive numbers
        return y - x.abs();
    }

    // If we reached this point, both x and y should be positive
    debugAssert(x.sgn == 1);
    debugAssert(y.sgn == 1);

    if (x < y) {
        // Subtracting a large number from a small one.  Switch
        // the order and negate the result.
        return -(y - x);
    }

    // Now we only have to subtract a small positive number from a large
    // positive number.  The result should be positive.

    BigInt result;
    result.sgn = 1;
    // The result can be no bigger than x, the larger number
    result.setSize(numBytes);


    // Index that we borrowed from to increase this value.
    // Any zero before borrow index is really 255
    int borrowIndex = -1;

    for (int i = 0; i < numBytes; ++i) {
        int a = x.byte[i];

        if (i < borrowIndex) {
            // We must have borrowed past a
            debugAssert(a == 0);
            a = 255;
        } if (i == borrowIndex) {
            debugAssert(a > 0);
            // Borrowed from a
            --a;
        }

        int b = y[i];

        if (a < b) {
            // Need to borrow
            debugAssertM(borrowIndex < i,
                "Shouldn't have to borrow if we have already borrowed.");
            // Search for a non-zero
            borrowIndex = i + 1;
            while (x.byte[borrowIndex] == 0) {
                ++borrowIndex;
            }

            // We can now add the borrowed value to a
            a += 256;
        }


        debugAssertM(a >= b, "Borrow failed.");
        result.byte[i] = a - b;
    }

    // Due to borrowing, we might have have a leading zero
    result.stripLeadingZeros();
  
    return result;
}


uint64 BigInt::closeDiv(const BigInt& x, const BigInt& y, BigInt& remainder) {
    // Compare the top several digits (unless y only has one digit)
    int numDigits = G3D::min(6, y.size());

    debugAssert(x.size() <= y.size() + 1);

    // Extract the top digits.  Note that if x is longer than y
    // the operator[] takes care of inserting a zero into b for us.
    G3D::uint64 a = 0, b = 0;
    for (G3D::uint64 i = 0; i < numDigits; ++i) {
        a = (a << 8) + x[x.size() - 1 - i];
        b = (b << 8) + y[y.size() - 1 - i];
    }

    // Form our guess from the top digits
    G3D::uint64 c = a / b;

    // Compute the remainder
    BigInt z;
    
    do {
        z = y * c;
        printf("%d - %d\n", x.int32(), z.int32());
        remainder = x - z;

        if (remainder.sgn < 0) {
            // We guessed too big of a factor because we have a negative remainder
            debugPrintf("Warning: overshoot in division\n");
            debugAssert(c > 1);
            --c;
        }
    } while (remainder.sgn < 0);

    while (remainder > y) {
        ++c;
        z = y * c;
        remainder = x - z;
        debugPrintf("Warning: undershoot in division\n");
    }

    return c;
}


BigInt BigInt::operator/(const BigInt& _y) const {

	alwaysAssertM(false, "Division not implemented");

    const BigInt& _x = *this;

    if (_y.isZero()) {
        debugAssertM(_y.nonZero(), "Divide by zero");
        return BigInt();
    }

    if (_x.isZero()) {
        // 0 over anything is zero
        return BigInt();
    }

    if (_y.numBytes > _x.numBytes) {
        // The result has to be zero if y >> x
        return BigInt();
    }

    // Throw away the signs
    BigInt x = _x.abs();
    BigInt y = _y.abs();

    // Grab the first subset of x (from the major end) that is bigger than y
    //
    //     x5 x4 x3 x2 x1 x0
    //   end^       ^start
    //
    int subEnd   = x.numBytes - 1;
    int subStart = subEnd - y.numBytes + 1;

    debugAssert(subStart >= 0);
    
    if (x.byte[subStart] > y.byte[y.numBytes]) {
        // We need one more byte; y is still bigger than our subset
        if (subStart == 0) {
            // Y is larger than X; the result must be zero
            return BigInt();        
        } else {
            --subStart;
        }
    }

    // See (approximately) how many times
    // TODO: compute a subset of x from these numbers

    BigInt remainder;
    int c = closeDiv(x, y, remainder);

//    debugAssertM(false, "TODO");
    
    BigInt result = c;
    result.sgn = _x.sgn * _y.sgn;
    return result;
}


BigInt BigInt::operator*(const BigInt& y) const {
    const BigInt& x = *this;

    if (x.isZero() || y.isZero()) {
        // Result is zero
        return BigInt();
    }

    BigInt result;

    for (int j = 0; j < y.numBytes; ++j) {
        int b = y.byte[j];

        // Accumulates the result of multiplying b by all of x
        BigInt digitResult;

        for (int i = x.numBytes - 1; i >= 0; --i) {
            int a = x.byte[i];

            digitResult.shift255(1);
            digitResult += BigInt(a * b);
        }

        // Multiply by 255^j so that we can move to the next digit
        digitResult.shift255(j);
        result += digitResult;
    }


    // Result sign is the product of the signs
    result.sgn = x.sgn * y.sgn;
    
    return result;
}


BigInt& BigInt::operator*=(const BigInt& x) {
    *this = *this * x;
    return *this;
}


BigInt& BigInt::operator/=(const BigInt& x) {
    *this = *this / x;
    return *this;
}


BigInt& BigInt::operator+=(const BigInt& x) {
    *this = *this + x;
    return *this;
}


BigInt& BigInt::operator-=(const BigInt& x) {
    *this = *this - x;
    return *this;
}


BigInt BigInt::operator&(const BigInt& x) const {
    BigInt result;

    // The result can be no longer than the shortest value
    result.setSize(G3D::min(x.numBytes, numBytes));

    for (int i = 0; i < result.numBytes; ++i) {
        result.byte[i] = byte[i] & x.byte[i];
    }

    return result;
}


BigInt BigInt::operator|(const BigInt& x) const {
    BigInt result;

    // The result can be no shorter than the longest value
    result.setSize(G3D::max(x.numBytes, numBytes));

    for (int i = 0; i < result.numBytes; ++i) {
        // Let the operator[] do the boundary case work for us
        result.byte[i] = (*this)[i] | x[i];
    }

    return result;
}


BigInt BigInt::operator^(const BigInt& x) const {
    BigInt result;

    // The result size depends on values.  Conservatively go long
    result.setSize(G3D::max(x.numBytes, numBytes));

    for (int i = 0; i < result.numBytes; ++i) {
        // Let the operator[] do the boundary case work for us
        result.byte[i] = (*this)[i] ^ x[i];
    }

    result.stripLeadingZeros();
    return result;
}


bool BigInt::operator>(const BigInt& y) const {
    return compare(y, *this, false);
}


bool BigInt::operator<(const BigInt& y) const {
    return compare(*this, y, false);
}


bool BigInt::compare(const BigInt& x, const BigInt& y, bool ifEqual) {

    // See what we can determine from the signs
    if (x.sgn != y.sgn) {
        return x.sgn < y.sgn;
    }

    if (x.isZero() && y.isZero()) {
        // They are equal
        return ifEqual;
    }

    // At this point, we must have two positive or two negative numbers.
    // Use flip to reduce us to always comparing the positive case.
    int flip = x.sgn;

    if (x.numBytes * flip < y.numBytes * flip) {
        // x is trivially smaller (larger) than y
        return true;
    } else if (x.numBytes * flip > y.numBytes * flip) {
        // x is trivially larger (smaller) than y
        return false;
    }

    // On the same order; we have to walk the bytes
    for (int i = x.numBytes - 1; i >= 0; --i) {
        if (x.byte[i] * flip > y.byte[i] * flip) {
            // x is bigger (smaller) than y
            return false;
        } else if (x.byte[i] * flip < y.byte[i] * flip) {
            // x is smaller (larger) than y
            return true;
        }
    }

    // The numbers must have been exactly equal
    return ifEqual;
}


bool BigInt::operator>=(const BigInt& y) const {
    return compare(y, *this, true);
}


bool BigInt::operator<=(const BigInt& y) const {
    return compare(*this, y, true);
}


bool BigInt::operator==(const BigInt& y) const {
    if (numBytes == y.numBytes) {
        if (numBytes == 0) {
            // Both are zero
            return true;
        } else if (sgn != y.sgn) {
            // Signs don't match
            return false;
        } else {
            // Check every byte.
            for (int i = 0; i < numBytes; ++i) {
                if (y.byte[i] != byte[i]) {
                    return false;
                }
            }
            return true;
        }
    } else {
        return false;
    }
}


bool BigInt::operator!=(const BigInt& y) const {
    return !(*this == y);
}


BigInt BigInt::operator%(const BigInt& y) const {
    debugAssertM(false, "TODO");
    return BigInt();
}


void BigInt::serialize(class BinaryOutput& b) const {
    b.writeInt8(sgn);
    b.writeUInt32(numBytes);
    b.writeBytes(byte, numBytes);
}


void BigInt::deserialize(class BinaryInput& b) {
    sgn = b.readInt8();
    setSize(b.readUInt32());
    b.readBytes(byte, numBytes);
}


void BigInt::stripLeadingZeros() {

    int newSize = numBytes;

    while ((newSize > 0) && (byte[newSize - 1] == 0)) {
        --newSize;
    }

    if (newSize != numBytes) {
        setSize(newSize);
    }
}


std::string BigInt::toString() const {

    // Have only one representation for 0
    if (numBytes == 0) {
        return "0";
    }

    std::string s;

    if (sgn == -1) {
        s += "-";
    }

    // We repeatedly DECIMAL shift and mask value to read out the string digits.
    BigInt value = *this;
    bool first = true;

    while (value.nonZero()) {
        // Being used to find the current digit
        BigInt current = value;
        BigInt shiftBack(1);

        while (current > 9) {
            // Shift one decimal place to the right and
            // keep track of the total number of shifts
            current /= 10;
            shiftBack *= 10;
        }

        // Don't append leading zeros
        if (current.nonZero()) {
            s += '0' + current.byte[0];
        } else {
            // Don't append leading zeros
            if (! first) {
                s += '0';
            }
        }

        // Now mask off the top decimal digit
        value -= shiftBack * current;
    }

    return s;
}


/** Converts a number less than 16 to a hex character. */
inline static char nibbleToHex(int x) {
    static const char *h = "0123456789ABCDEF";
    return h[x];
}


std::string BigInt::toHexString() const {
    // Have only one representation for 0
    if (numBytes == 0) {
        return "0";
    }

    std::string s;
    int signChar = (sgn == -1) ? 1 : 0;

    // Each byte turns into two hex characters
    s.resize(numBytes * 2 + signChar);

    if (signChar) {
        s[0] = '-';
    }

    for (int i = 0; i < numBytes; ++i) {
        unsigned char b = byte[numBytes - i - 1];
        // High nibble
        char c1 = nibbleToHex(b >> 4);
        // Low nibble
        char c0 = nibbleToHex(b && 0x0F);

        int j = signChar + i * 2;
        s[j] = c1;
        s[j + 1] = c0;
    }

    return s;
}


BigInt BigInt::abs() const {
    if (sgn == -1) {
        BigInt result(*this);
        result.sgn = 1;
        return result;
    } else {
        return *this;
    }
}


BigInt BigInt::powMod(int x, BigInt& y) const {
    debugAssertM(x >= 0, "Exponent must be non-negative");

    switch (x) {
    case 0:
        return BigInt();

    case 1:
        return *this;

    case 2:
        return ((*this) * (*this)) % y;

    case 3:
        return ((((*this) * (*this)) % y) * (*this)) % y;

    case 4:
        {
            BigInt tmp = ((*this) * (*this)) % y;
            return (tmp * tmp) % y;
        }

    default:
        {
            // For large powers, factor the operation
            // perform only a log number of multiplications
            int a = 2;
            BigInt tmp = ((*this) * (*this)) % y;
            while (a < x / 2) {
                tmp = (tmp * tmp) % y;
                a *= 2;
            }

            if (a == x) {
                return tmp;
            } else {
                return (tmp * powMod(x - a, y)) % y;
            }
        }    
    }
}


BigInt BigInt::pow(int x) const {
    debugAssertM(x >= 0, "Exponent must be non-negative");

    switch (x) {
    case 0:
        return BigInt();

    case 1:
        return *this;

    case 2:
        return (*this) * (*this);

    case 3:
        return (*this) * (*this) * (*this);

    case 4:
        {
            BigInt tmp = (*this) * (*this);
            return tmp * tmp;
        }

    default:
        {
            // For large powers, factor the operation
            // perform only a log number of multiplications
            int a = 2;
            BigInt tmp = (*this) * (*this);
            while (a < x / 2) {
                tmp *= tmp;
                a *= 2;
            }

            if (a == x) {
                return tmp;
            } else {
                return tmp * pow(x - a);
            }
        }
    }
}


void BigInt::parse(const char* str) {
    sgn = 0;

    if ((str == NULL) || (str[0] == '\0')) {
        // Zero length string
        return;
    }


    // Parse sign
    if (str[0] == '-') {

        debugAssertM(str[1] == '\0', 
            "BigInt could not parse \"-\".");

        if (str[1] == '\0') {
            // In release mode, return 0 for a single minus
            return;
        }

        sgn = -1;
        ++str;
    }

    if ((str[0] == '0') &&
        ((str[1] == 'x') ||
        (str[1] == 'X'))) {
        parseHex(str);
    } else {
        parseDec(str);
    }
}


static int hex2dec(char c) {
    if ((c >= '0') && (c <= '9')) {
        return c - '0';
    } else if ((c >= 'a') && (c <= 'f')) {
        return 10 + c - 'a';
    } else if ((c >= 'A') && (c <= 'F')) {
        return 10 + c - 'A';
    } else {
        debugAssertM(false, 
            "Illegal character in BigInt string during parse.");
        return 0;
    }
}


void BigInt::parseHex(const char* str) {
    // Skip over "0x"
    str += 2;

    // Read until the first non-zero
    while (str[0] == '0') {
        ++str;
    }

    if (str[0] == '\0') {
        return;
    } else {
        sgn = 1;
    }

    // The BigInt will have half as many places as there are
    // characters.
    int n = strlen(str);   
    setSize((n / 2) + (n & 1));

    // Handle the first byte specially since we may start on an odd position
    if ((n & 1) == 1) {
        // Odd, so we'll have to start on the first nibble
        byte[numBytes - 1] = hex2dec(str[0]);
        ++str;
    } else {
        // Even, so read two characters
        byte[numBytes - 1] = (hex2dec(str[0]) << 4) + hex2dec(str[1]);
        str += 2;
    }

    // Process two bytes at a time
    for (int i = numBytes - 2; i >= 0; --i, str += 2) {
        byte[i] = (hex2dec(str[0]) << 4) + hex2dec(str[1]);
    }
}


void BigInt::parseDec(const char* str) {
    int i = 0;

    // Read until the first non-zero
    while (str[0] == '0') {
        ++str;
    }

    if (str[0] == '\0') {
        return;
    } else {
        sgn = 1;
    }

    while (str[i] != '\0') {
        char c = str[i];
        debugAssert(c >= '0' && c <= '9');
        *this = (*this) * 10 + (c - '0');
        ++i;
    }
}


int32 BigInt::int32() const {
    debugAssertM(numBytes <= 4, "BigInt is too large to convert to int32.");

    if (numBytes == 4) {
        uint8 highByte = byte[4];
        if (sgn == 1) {           
            debugAssertM(highByte <= 0x7F,
                "BigInt is too large to convert to int32.");
        } else {
            debugAssertM(highByte <= 0x80,
                "BigInt is too (negatively) large to convert to int32.");
        }
    }

    G3D::int32 x = 0;

    for (int i = numBytes - 1; i >= 0; --i) {
        x = (x << 8) + byte[i];
    }

    return x * sgn;
}


uint32 BigInt::uint32() const {
    debugAssertM(numBytes <= 4, "BigInt is too large to convert to uint32.");
    debugAssertM(sgn < 1, "Cannot convert a negative BigInt to uint32.");

    G3D::uint32 x = 0;

    for (int i = numBytes - 1; i >= 0; --i) {
        x = (x << 8) + byte[i];
    }

    return x;
}


uint64 BigInt::uint64() const {
    debugAssertM(numBytes <= 8, "BigInt is too large to convert to uint64.");
    debugAssertM(sgn < 1, "Cannot convert a negative BigInt to uint64.");

    G3D::uint64 x = 0;

    for (int i = numBytes - 1; i >= 0; --i) {
        x = (x << 8) + byte[i];
    }

    return x;
}


int64 BigInt::int64() const {
    debugAssertM(numBytes <= 8, "BigInt is too large to convert to int64.");

    if (numBytes == 8) {
        uint8 highByte = byte[8];
        if (sgn == 1) {           
            debugAssertM(highByte <= 0x7F,
                "BigInt is too large to convert to int64.");
        } else {
            debugAssertM(highByte <= 0x80,
                "BigInt is too (negatively) large to convert to int64.");
        }
    }

    G3D::int64 x = 0;

    for (int i = numBytes - 1; i >= 0; --i) {
        x = (x << 8) + byte[i];
    }

    return x * sgn;
}


MD5Hash BigInt::MD5Hash() const {
    G3D::MD5Hash h;

    debugAssertM(sgn > -1, "Cannot convert a negative BigInt to a MD5Hash.");
    debugAssertM(numBytes <= 16, "BigInt is too large to convert to MD5Hash.");

    for (int i = 0; i < 16; ++i) {
        h[i] = (*this)[i];
    }

    return h;
}


BigInt abs(const BigInt& x) {
    return x.abs();
}

} // namespace G3D

