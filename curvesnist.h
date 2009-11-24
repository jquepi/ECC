/*
 * curvenist.h
 *
 *  Created on: Nov 15, 2009
 *      Author: bhess
 *
 * Defines the Elliptic Curves over prime fields
 * recommended by NIST: FIPS 186-3 Appendix D
 *
 * http://csrc.nist.gov/publications/fips/fips186-3/fips_186-3.pdf
 *
 * - P192, P224, P256, P384, P521
 *
 * The implementations inherit from the interface from
 * ellipticcurve.h
 *
 */

#ifndef CURVESNIST_H_
#define CURVESNIST_H_

#include "ecprime.h"
#include "ecbinary.h"

#define P192_MOD_FIELD "6277101735386680763835789423207666416083908700390324961279"
#define P192_ORDER "6277101735386680763835789423176059013767194773182842284081"
#define P192_ECC_A "-3"
#define P192_ECC_B "64210519 e59c80e7 0fa7e9ab 72243049 feb8deec c146b9b1"
#define P192_POINT_X "188da80e b03090f6 7cbf20eb 43a18800 f4ff0afd 82ff1012"
#define P192_POINT_Y "07192b95 ffc8da78 631011ed 6b24cdd5 73f977a1 1e794811"

#define P224_MOD_FIELD "26959946667150639794667015087019630673557916260026308143510066298881"
#define P224_ORDER "26959946667150639794667015087019625940457807714424391721682722368061"
#define P224_ECC_A "-3"
#define P224_ECC_B "b4050a85 0c04b3ab f5413256 5044b0b7 d7bfd8ba 270b3943 2355ffb4"
#define P224_POINT_X "b70e0cbd 6bb4bf7f 321390b9 4a03c1d3 56c21122 343280d6 115c1d21"
#define P224_POINT_Y "bd376388 b5f723fb 4c22dfe6 cd4375a0 5a074764 44d58199 85007e34"

#define P256_MOD_FIELD "115792089210356248762697446949407573530086143415290314195533631308867097853951"
#define P256_ORDER "115792089210356248762697446949407573529996955224135760342422259061068512044369"
#define P256_ECC_A "-3"
#define P256_ECC_B "5ac635d8 aa3a93e7 b3ebbd55 769886bc 651d06b0 cc53b0f6 3bce3c3e 27d2604b"
#define P256_POINT_X "6b17d1f2 e12c4247 f8bce6e5 63a440f2 77037d81 2deb33a0 f4a13945 d898c296"
#define P256_POINT_Y "4fe342e2 fe1a7f9b 8ee7eb4a 7c0f9e16 2bce3357 6b315ece cbb64068 37bf51f5"

#define P384_MOD_FIELD "39402006196394479212279040100143613805079739270465446667948293404245721771496870329047266088258938001861606973112319"
#define P384_ORDER "39402006196394479212279040100143613805079739270465446667946905279627659399113263569398956308152294913554433653942643"
#define P384_ECC_A "-3"
#define P384_ECC_B "b3312fa7 e23ee7e4 988e056b e3f82d19 181d9c6e fe814112 0314088f 5013875a c656398d 8a2ed19d 2a85c8ed d3ec2aef"
#define P384_POINT_X "aa87ca22 be8b0537 8eb1c71e f320ad74 6e1d3b62 8ba79b98 59f741e0 82542a38 5502f25d bf55296c 3a545e38 72760ab7"
#define P384_POINT_Y "3617de4a 96262c6f 5d9e98bf 9292dc29 f8f41dbd 289a147c e9da3113 b5f0b8c0 0a60b1ce 1d7e819d 7a431d7c 90ea0e5f"

#define P521_MOD_FIELD "6864797660130609714981900799081393217269435300143305409394463459185543183397656052122559640661454554977296311391480858037121987999716643812574028291115057151"
#define P521_ORDER "6864797660130609714981900799081393217269435300143305409394463459185543183397655394245057746333217197532963996371363321113864768612440380340372808892707005449"
#define P521_ECC_A "-3"
#define P521_ECC_B "051 953eb961 8e1c9a1f 929a21a0 b68540ee a2da725b 99b315f3 b8b48991 8ef109e1 56193951 ec7e937b 1652c0bd 3bb1bf07 3573df88 3d2c34f1 ef451fd4 6b503f00"
#define P521_POINT_X "c6 858e06b7 0404e9cd 9e3ecb66 2395b442 9c648139 053fb521 f828af60 6b4d3dba a14b5e77 efe75928 fe1dc127 a2ffa8de 3348b3c1 856a429b f97e7e31 c2e5bd66"
#define P521_POINT_Y "118 39296a78 9a3bc004 5c8a5fb4 2c7d1bd9 98f54449 579b4468 17afbd17 273e662c 97ee7299 5ef42640 c550b901 3fad0761 353c7086 a272c240 88be9476 9fd16650"

#define B163_POLY "8 00000000 00000000 00000000 00000000 000000c9"
#define B163_ORDER "5846006549323611672814742442876390689256843201587"
#define B163_ECC_A "1"
#define B163_ECC_B "2 0a601907 b8c953ca 1481eb10 512f7874 4a3205fd"
#define B163_POINT_X_POLYBASIS "3 f0eba162 86a2d57e a0991168 d4994637 e8343e36"
#define B163_POINT_Y_POLYBASIS "0 d51fbc6c 71a0094f a2cdd545 b11c5c0c 797324f1"

class CurveNISTp192 : public ECPrime {
public:
	CurveNISTp192(): ECPrime(P192_MOD_FIELD, 10,
			P192_ORDER, 10,
			P192_ECC_A, 16,
			P192_ECC_B, 16,
			P192_POINT_X, 16,
			P192_POINT_Y, 16) {}

	mpz_class getOrder() {
		return order;
	}
};

class CurveNISTp224 : public ECPrime {
public:
	CurveNISTp224(): ECPrime(P224_MOD_FIELD, 10,
			P224_ORDER, 10,
			P224_ECC_A, 16,
			P224_ECC_B, 16,
			P224_POINT_X, 16,
			P224_POINT_Y, 16) {}

	mpz_class getOrder() {
		return order;
	}
};

class CurveNISTp256 : public ECPrime {
public:
	CurveNISTp256(): ECPrime(P256_MOD_FIELD, 10,
			P256_ORDER, 10,
			P256_ECC_A, 16,
			P256_ECC_B, 16,
			P256_POINT_X, 16,
			P256_POINT_Y, 16) {}

	mpz_class getOrder() {
		return order;
	}
};

class CurveNISTp384 : public ECPrime {
public:
	CurveNISTp384(): ECPrime(P384_MOD_FIELD, 10,
			P384_ORDER, 10,
			P384_ECC_A, 16,
			P384_ECC_B, 16,
			P384_POINT_X, 16,
			P384_POINT_Y, 16) {}

	mpz_class getOrder() {
		return order;
	}
};

class CurveNISTp521 : public ECPrime {
public:
	CurveNISTp521(): ECPrime(P521_MOD_FIELD, 10,
			P521_ORDER, 10,
			P521_ECC_A, 16,
			P521_ECC_B, 16,
			P521_POINT_X, 16,
			P521_POINT_Y, 16) {}

	mpz_class getOrder() {
		return order;
	}
};

class CurveNISTb163 : public ECBinary {
public:
	CurveNISTb163(): ECBinary(B163_POLY, 16,
			B163_ORDER, 10,
			B163_ECC_A, 10,
			B163_ECC_B, 16,
			B163_POINT_X_POLYBASIS, 16,
			B163_POINT_Y_POLYBASIS, 16) {}

	mpz_class getOrder() {
		return order;
	}

};

#endif /* CURVESNIST_H_ */
