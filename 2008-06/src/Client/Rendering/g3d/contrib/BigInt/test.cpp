
#include <G3DAll.h>
#include "BigInt.h"

using namespace G3D;

void testParser() {
    // Test hex parsing
    {
        BigInt a("0xFF");
        debugAssert(a == 255);
    }
    {
        BigInt a("0x0F");
        debugAssert(a == 15);
    }
    {
        BigInt a("0xdEaDBeEf");
        debugAssert(a == 0xdeadbeef);
    }
}


void testCompare() {
    {
        BigInt a(10);
        BigInt b(11);
        debugAssert(a < b);
    }

    {
        BigInt a(0);
        debugAssert(a == 0);
        debugAssert(a != 1);
    }

    {
        BigInt a(500);
        BigInt b(200);
        debugAssert(a > b);
        debugAssert(b < a);
    }

    {
        BigInt a(-5000000);
        BigInt b(-2000000);
        debugAssert(a < b);
        debugAssert(b > a);
    }

    {
        BigInt a(-5000000);
        BigInt b(-2000000);
        debugAssert(a <= b);
        debugAssert(b >= a);
    }

    {
        BigInt a(10000);
        BigInt b(10000);
        debugAssert(a <= b);
        debugAssert(b >= a);
    }
}


void testAdd() {
    // Two positives
    {
        BigInt a(1);
        debugAssert(a == 1);
        debugAssert(a != 0);
        debugAssert(a != 11);
        a += 10;
        debugAssert(a == 11);
        debugAssert(a != 1);

        a = 834245;
        a += 1023123;
        debugAssert(a == (834245 + 1023123));

    }

    // Pos neg
    {
        BigInt a(1);
        BigInt b(-1);
        BigInt c = a + b;
        debugAssert(c == 0);
    }

    // Neg pos
    {
        BigInt a(-5);
        BigInt b(1);
        BigInt c = a + b;
        debugAssert(c == -4);
    }

    // Neg neg
    {
        BigInt a(-5);
        BigInt b(-3);
        BigInt c = a + b;
        debugAssert(c == -8);
    }

    // Subtraction
    {
        BigInt a = 0xFFFF;
        BigInt b = 0x0047;
        BigInt c = a - b;
        debugAssert(c == (int)0xFFFF - (int)0x0047);
    }

    // Case requiring carry
    {
        BigInt a = 1024;
        BigInt b = 600;
        BigInt c = a - b;

        debugAssert(c == 1024 - 600);
    }

}


void testMul() {
    {
        BigInt a(1);
        BigInt b(10);
        BigInt c = a * b;
        debugAssert(c == 10);
    }

    {
        BigInt a(2);
        BigInt b(10);
        BigInt c = a * b;
        debugAssert(c == 20);
    }

    {
        BigInt a(-5135);
        BigInt b(1243);
        BigInt c = a * b;
        debugAssert(c == (-5135 * 1243));
    }
}


void testPow() {
    {
        BigInt a = 10;
        BigInt c = a.pow(8);
        debugAssert(c == (int)pow(10, 8));
    }

    {
        BigInt a = 2;
        BigInt c = a.pow(40);
        int64 x = (int64)pow(2.0, 40.0);
        debugAssert(c == x);
    }

    {
        BigInt a = 15;
        BigInt c = a.pow(3);
        int64 x = (int64)pow(15, 3);
        debugAssert(c == x);
    }
}


void testConvert() {
    {
        BigInt a(-72137);
        int32 x = a.int32();
        debugAssert(x == -72137);
    }

    {
        int64 y = 12345678901L;
        BigInt a(y);
        int64 x = a.int64();
        debugAssert(x == y);
    }
}


int main(int argc, const char* argv) {

	for (int i = 0; i < 20; ++i) {
		BigInt x = BigInt::random(0, 255);
		debugPrintf("%d\n", x.int32());
	}

	/*
    testParser();
    testCompare();
    testAdd();
    testMul();
    testPow();
    testConvert();
*/

/*
    BigInt x = 1024;
    BigInt y = 16;

    BigInt c = x / y;

    debugPrintf("%d\n", c.int32());
*/
    return 0;
}


