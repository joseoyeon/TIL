# AES_NI

인텔 CPU에 내장된 AES연산 전용 명령어.

xmm레지스터를 사용하여 128비트단위 연산을 가능하게 한다.

```
xmm0 //plaintext
xmm1 ~ xmm11 //scheduled keys
pxor xmm0, xmm1 /∗ Round 0 (whitening) ∗/
aesenc xmm0, xmm2 /∗ Round 1 ∗/
aesenc xmm0, xmm3 /∗ Round 2 ∗/
aesenc xmm0, xmm4 /∗ Round 3 ∗/
aesenc xmm0, xmm5 /∗ Round 4 ∗/
aesenc xmm0, xmm6 /∗ Round 5 ∗/
aesenc xmm0, xmm7 /∗ Round 6 ∗/
aesenc xmm0, xmm8 /∗ Round 7 ∗/
aesenc xmm0, xmm9 /∗ Round 8 ∗/
aesenc xmm0, xmm10 /∗ Round 9 ∗/
aesenclast xmm0, xmm11
```

이런식으로 명령어 한번에 라운드 한번돌 수 있다.

키스케줄링은 128비트는 SIMD를 이용해 빠른 연산이 가능한데 192, 256은 힘들어보인다.

COSIC 문서를 참조하여 파이프라이닝을 고려한 AES-128 연산을 아래와 같이 구현해 보았다.

파일 입출력과 같이 진행해 속도가 빠르진 않지만 기존 코드에 비해 6배 이상의 속도가 나왔다.

1.5기가 파일 암호화 진행 시 i5-8250U에서 15초, i7-6700에서 11초 걸렸다. 기존 C로 코딩한 AES는 90초이상 걸렸으며 파이프라이닝 고려하지 않고 16바이트 단위로 읽었을 때 약 3~40초대 걸렸다.

```C++
void aes_encrypt_4(const UNBYTE *in, UNBYTE *out, const void *key)
{
	__asm
	{
		pushad
		mov eax, in
		movdqu xmm0, [eax]	//plain
		movdqu xmm1, [eax + 0x10]
		movdqu xmm2, [eax + 0x20]
		movdqu xmm3, [eax + 0x30]
		mov ebx, key
		mov ecx, nr;
		movdqu xmm4, [ebx]	//key

			pxor xmm0, xmm4
			pxor xmm1, xmm4
			pxor xmm2, xmm4
			pxor xmm3, xmm4
			movdqu xmm4, [ebx + 0x10]
			movdqu xmm5, [ebx + 0x20]
			movdqu xmm6, [ebx + 0x30]
			movdqu xmm7, [ebx + 0x40]
			aesenc xmm0, xmm4
			aesenc xmm1, xmm4
			aesenc xmm2, xmm4
			aesenc xmm3, xmm4
			aesenc xmm0, xmm5
			aesenc xmm1, xmm5
			aesenc xmm2, xmm5
			aesenc xmm3, xmm5
			aesenc xmm0, xmm6
			aesenc xmm1, xmm6
			aesenc xmm2, xmm6
			aesenc xmm3, xmm6
			aesenc xmm0, xmm7
			aesenc xmm1, xmm7
			aesenc xmm2, xmm7
			aesenc xmm3, xmm7
			movdqu xmm4, [ebx + 0x50]
			movdqu xmm5, [ebx + 0x60]
			movdqu xmm6, [ebx + 0x70]
			movdqu xmm7, [ebx + 0x80]
			aesenc xmm0, xmm4
			aesenc xmm1, xmm4
			aesenc xmm2, xmm4
			aesenc xmm3, xmm4
			aesenc xmm0, xmm5
			aesenc xmm1, xmm5
			aesenc xmm2, xmm5
			aesenc xmm3, xmm5
			aesenc xmm0, xmm6
			aesenc xmm1, xmm6
			aesenc xmm2, xmm6
			aesenc xmm3, xmm6
			aesenc xmm0, xmm7
			aesenc xmm1, xmm7
			aesenc xmm2, xmm7
			aesenc xmm3, xmm7

			movdqu xmm4, [ebx + 0x90]
			movdqu xmm5, [ebx + 0xa0]
			aesenc xmm0, xmm4
			aesenc xmm1, xmm4
			aesenc xmm2, xmm4
			aesenc xmm3, xmm4
			aesenclast xmm0, xmm5
			aesenclast xmm1, xmm5
			aesenclast xmm2, xmm5
			aesenclast xmm3, xmm5

			mov ecx, out
			movdqu[ecx], xmm0
			movdqu[ecx + 0x10], xmm1
			movdqu[ecx + 0x20], xmm2
			movdqu[ecx + 0x30], xmm3
			emms
			popad
	}
}
```

자세한 내용은 아래 링크 참조.

출처 : https://www.cosic.esat.kuleuven.be/ecrypt/AESday/slides/Use_of_the_AES_Instruction_Set.pdf

