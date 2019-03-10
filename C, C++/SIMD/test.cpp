	XAR3_AVX2(x3, x2, tmp, key->rk[4], key->rk[5]);
mov         eax,4  
imul        ecx,eax,5  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x3]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
shl         eax,2  
mov         ecx,dword ptr [key]  
vmovd       xmm1,dword ptr [ecx+eax]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x2]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Dh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,3  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x3],ymm0  
	XAR5_AVX2(x2, x1, tmp, key->rk[2], key->rk[3]);
mov         eax,4  
imul        ecx,eax,3  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x2]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
shl         eax,1  
mov         ecx,dword ptr [key]  
vmovd       xmm1,dword ptr [ecx+eax]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x1]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Bh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,5  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x2],ymm0  
	XAR9_AVX2(x1, x0, tmp, key->rk[0], key->rk[1]);
mov         eax,4  
shl         eax,0  
mov         ecx,dword ptr [key]  
vmovd       xmm0,dword ptr [ecx+eax]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x1]  
vpxor       ymm0,ymm1,ymm0  
mov         edx,4  
imul        eax,edx,0  
mov         ecx,dword ptr [key]  
vmovd       xmm1,dword ptr [ecx+eax]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x0]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,9  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,17h  
	XAR9_AVX2(x1, x0, tmp, key->rk[0], key->rk[1]);
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x1],ymm0  
	XAR3_AVX2(x0, x3, tmp, key->rk[10], key->rk[11]);
mov         eax,4  
imul        ecx,eax,0Bh  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x0]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,0Ah  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x3]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Dh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,3  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x0],ymm0  
	XAR5_AVX2(x3, x2, tmp, key->rk[8], key->rk[9]);
mov         eax,4  
imul        ecx,eax,9  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x3]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
shl         eax,3  
mov         ecx,dword ptr [key]  
vmovd       xmm1,dword ptr [ecx+eax]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x2]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Bh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,5  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x3],ymm0  
	XAR9_AVX2(x2, x1, tmp, key->rk[6], key->rk[7]);
mov         eax,4  
imul        ecx,eax,7  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x2]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,6  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x1]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,9  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,17h  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x2],ymm0  
	XAR3_AVX2(x1, x0, tmp, key->rk[16], key->rk[17]);
mov         eax,4  
imul        ecx,eax,11h  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x1]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
shl         eax,4  
mov         ecx,dword ptr [key]  
vmovd       xmm1,dword ptr [ecx+eax]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x0]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Dh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,3  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x1],ymm0  
	XAR5_AVX2(x0, x3, tmp, key->rk[14], key->rk[15]);
mov         eax,4  
imul        ecx,eax,0Fh  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x0]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,0Eh  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x3]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Bh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,5  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x0],ymm0  
	XAR9_AVX2(x3, x2, tmp, key->rk[12], key->rk[13]);
mov         eax,4  
imul        ecx,eax,0Dh  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x3]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,0Ch  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x2]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,9  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,17h  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x3],ymm0  
	XAR3_AVX2(x2, x1, tmp, key->rk[22], key->rk[23]);
mov         eax,4  
imul        ecx,eax,17h  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x2]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,16h  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x1]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Dh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,3  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x2],ymm0  
	XAR5_AVX2(x1, x0, tmp, key->rk[20], key->rk[21]);
mov         eax,4  
imul        ecx,eax,15h  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x1]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,14h  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x0]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Bh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,5  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x1],ymm0  
	XAR9_AVX2(x0, x3, tmp, key->rk[18], key->rk[19]);
mov         eax,4  
imul        ecx,eax,13h  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x0]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,12h  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x3]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,9  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,17h  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x0],ymm0  

	XAR3_AVX2(x3, x2, tmp, key->rk[28], key->rk[29]);
mov         eax,4  
imul        ecx,eax,1Dh  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x3]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,1Ch  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x2]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Dh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,3  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x3],ymm0  
	XAR5_AVX2(x2, x1, tmp, key->rk[26], key->rk[27]);
mov         eax,4  
imul        ecx,eax,1Bh  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x2]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,1Ah  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x1]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Bh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,5  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x2],ymm0  
	XAR9_AVX2(x1, x0, tmp, key->rk[24], key->rk[25]);
mov         eax,4  
imul        ecx,eax,19h  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x1]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,18h  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x0]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,9  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,17h  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x1],ymm0  
	XAR3_AVX2(x0, x3, tmp, key->rk[34], key->rk[35]);
mov         eax,4  
imul        ecx,eax,23h  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x0]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,22h  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x3]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Dh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,3  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x0],ymm0  
	XAR5_AVX2(x3, x2, tmp, key->rk[32], key->rk[33]);
mov         eax,4  
imul        ecx,eax,21h  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x3]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
shl         eax,5  
mov         ecx,dword ptr [key]  
vmovd       xmm1,dword ptr [ecx+eax]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x2]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Bh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,5  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x3],ymm0  
	XAR9_AVX2(x2, x1, tmp, key->rk[30], key->rk[31]);
mov         eax,4  
imul        ecx,eax,1Fh  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x2]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,1Eh  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x1]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,9  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,17h  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x2],ymm0  
	XAR3_AVX2(x1, x0, tmp, key->rk[40], key->rk[41]);
mov         eax,4  
imul        ecx,eax,29h  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x1]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,28h  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x0]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Dh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,3  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x1],ymm0  
	XAR5_AVX2(x0, x3, tmp, key->rk[38], key->rk[39]);
mov         eax,4  
imul        ecx,eax,27h  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x0]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,26h  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x3]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Bh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,5  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x0],ymm0  
	XAR9_AVX2(x3, x2, tmp, key->rk[36], key->rk[37]);
mov         eax,4  
imul        ecx,eax,25h  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x3]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,24h  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x2]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,9  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,17h  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x3],ymm0  
	XAR3_AVX2(x2, x1, tmp, key->rk[46], key->rk[47]);
mov         eax,4  
imul        ecx,eax,2Fh  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x2]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,2Eh  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x1]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Dh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,3  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x2],ymm0  
	XAR5_AVX2(x1, x0, tmp, key->rk[44], key->rk[45]);
mov         eax,4  
imul        ecx,eax,2Dh  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x1]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,2Ch  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x0]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,1Bh  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,5  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x1],ymm0  
	XAR9_AVX2(x0, x3, tmp, key->rk[42], key->rk[43]);
mov         eax,4  
imul        ecx,eax,2Bh  
mov         edx,dword ptr [key]  
vmovd       xmm0,dword ptr [edx+ecx]  
vpshufd     xmm0,xmm0,0  
vinsertf128 ymm0,ymm0,xmm0,1  
vmovdqu     ymm1,ymmword ptr [x0]  
vpxor       ymm0,ymm1,ymm0  
mov         eax,4  
imul        ecx,eax,2Ah  
mov         edx,dword ptr [key]  
vmovd       xmm1,dword ptr [edx+ecx]  
vpshufd     xmm1,xmm1,0  
vinsertf128 ymm1,ymm1,xmm1,1  
vmovdqu     ymm2,ymmword ptr [x3]  
vpxor       ymm1,ymm2,ymm1  
vpaddd      ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [tmp],ymm0  
vmovdqu     ymm0,ymmword ptr [tmp]  
vpslld      ymm0,ymm0,9  
vmovdqu     ymm1,ymmword ptr [tmp]  
vpsrld      ymm1,ymm1,17h  
vpxor       ymm0,ymm1,ymm0  
vmovdqu     ymmword ptr [x0],ymm0  