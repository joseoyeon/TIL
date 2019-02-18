#include <stdio.h>
#include <Windows.h>
int main()
{
    //Generate 16 Byte Key
    BYTE buf[16];
    HCRYPTPROV h; 
    CryptAcquireContext(&h, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
	CryptGenRandom(h, 16, buf);
}