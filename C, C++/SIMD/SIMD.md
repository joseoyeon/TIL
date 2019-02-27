# SIMD

Single Instruction Multiple Data

1개의 어셈블리 명령어로 다수의 데이터를 처리함.

AVX를 이용한 사칙연산 예제이다.

immintrin.h를 이용하고 벡터?를 이용해서 구현되었다.

__asm을 통해 직접 어셈블리어로 코딩도 가능한 것 같음.

이게 쫌 헷갈리는게 10,20,30이런식으로 변수를 넣으면 값이 역순으로 출력된다.

디스어셈블링해서 메모리주소 따라가보니 상수 매개변수 자체가 값이 역순으로 메모리에 기록되어있었음.~~왜그런지는 모르겠음.~~

xmm레지스터에 값을 담을 때 한번에 128/256비트를 읽어오기 때문에 128/256 자료형으로 생각해서 그렇게 저장되니까 리틀엔디언으로 적용되어 int단위로 찍어보면 역순으로 나오는 것 같다.

<immintrin.h> 인클루드하면 SIMD 명령어 사용 가능하다. 각 명령어는 SIMD연산 명령어와 거의 1:1로 매칭되어 어셈블리어로 코딩하는 것 보다 사용이 편리하다.

```C++
#include <immintrin.h>

int main()
{
	int i;
	/* Little Endian, High Indexes are first written at register */
	__m256i first = _mm256_set_epi32(10, 20, 30, 40, 50, 60, 70, 0x7FFFFFFF);
	__m256i second = _mm256_set_epi32(1, 2, 3, 4, 5, 6, 7, 0x7FFFFFFF);
	__m256i result;
	int* values = (int*)&result;

	/* Add */
	result = _mm256_add_epi32(first, second);
	printf("Add\n");
	for (i = 0; i < 8; i ++)
		printf("%d ", values[i]);
	printf("\n\n");

	/* Sub */
	printf("Sub\n");
	result = _mm256_sub_epi32(first, second);
	for (i = 0; i < 8; i ++)
		printf("%d ", values[i]);
	printf("\n\n");

	/* Mul
	Note	 :  first[1] * second [1] = result[7],[6]
				first[3] * second [3] = result[4],[5]
				...
				even number index ignored
	*/
	printf("Mul\n");
	result = _mm256_mul_epi32(first, second);
	long long res[4] = { 0 };
	res[0] = values[1];
	res[0] <<= 32;
	res[0] ^= values[0];
	res[1] = values[3];
	res[1] <<= 32;
	res[1] ^= values[2];
	res[2] = values[5];
	res[2] <<= 32;
	res[2] ^= values[4];
	res[3] = values[7];
	res[3] <<= 32;
	res[3] ^= values[6];
	for (i = 0; i < 4; i++)
		printf("%lld ", res[i]);
	printf("\n\n");

	/* Div */
	printf("Div\n");
	__m256d d1 = _mm256_setr_pd(120.0, 1234.5, 12312.123124, 9999.9999);
	__m256d d2 = _mm256_setr_pd(5, 0.5, 12, 34);
	__m256d r = _mm256_div_pd(d1, d2);
	double* v = (int*)&r;
	for (i = 0; i < 4; i++)
		printf("%f ", v[i]);
	printf("\n\n");

	return 0;
}
```

사칙연산 예제이다.

명령어가 매우 다양해서 뭐가 있는지 찾아보는 것도 재미있을 것 같다.