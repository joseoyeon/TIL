# AES_NI

인텔 CPU에 내장된 AES연산 전용 명령어.

xxm, ymm레지스터를 사용하여 128비트단위 연산을 가능하게 한다.

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

키스케줄링, 복호화 등 다른 내용은 아래 링크 참조.

_출처 : https://www.cosic.esat.kuleuven.be/ecrypt/AESday/slides/Use_of_the_AES_Instruction_Set.pdf_