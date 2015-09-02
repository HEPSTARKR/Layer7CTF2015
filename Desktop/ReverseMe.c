#include <stdio.h>
#include <stdlib.h>
#include <string.h>

u_long hostlong = 0x72650000;
u_long hostlong2 = 0x640000;

int sub_401060()
{
	int result; // eax@2
	u_long v1; // edi@3
	u_long v2; // ebx@3
	signed int v3; // esi@3
	u_long v4; // edi@3
	int v5; // eax@5
	u_long v6; // eax@10

	if (strlen((const char *)&hostlong) == 8)
	{
		v1 = hostlong2 ; // 브루트 포싱 변수가 들어가면 되는 부분
		v2 = htonl(hostlong);
		v3 = 0;
		v4 = htonl(v1);
		do
		{
			switch (v3)
			{
			case 0:
				v5 = sub_401110(v4);
				goto LABEL_9;
			case 1:
				v5 = sub_401160(v4);
				goto LABEL_9;
			case 2:
				v5 = sub_4011B0(v4);
				goto LABEL_9;
			case 4:
				v5 = sub_401200(v4);
			LABEL_9:
				v2 ^= v5;
				break;
			default:
				break;
			}
			v6 = v2;
			++v3;
			v2 = v4;
			v4 = v6;
		} while (v3 < 4);
		result = v6 == 1919260720 && v2 == 1690536768;
	}
	else
	{
		result = 0;
	}
	//if(result)
	//printf("v6 = %lX\nv2 = %lx\n",v6,v2);
	return result;
}

int sub_401110(int a1)
{
	int v1; // edi@1
	int v2; // esi@1
	signed int v3; // ecx@1
	signed int v4; // edx@2
	int v5; // eax@2
	int v6; // eax@3

	v1 = a1;
	v2 = a1 & 0xFFFFFF00;
	v3 = 0;
	do
	{
		v4 = 3 << v3;
		v5 = (v1 & (3 << v3)) >> v3;
		if (!v5)
		{
			v4 = 1 << v3;
		LABEL_7:
			v2 |= v4;
			goto LABEL_8;
		}
		v6 = v5 - 2;
		if (!v6)
			goto LABEL_7;
		if (v6 == 1)
			v2 |= 2 << v3;
	LABEL_8:
		v3 += 2;
	} while (v3 < 8);
	return v2;
}

int sub_401160(int a1)
{
	int v1; // edi@1
	signed int v2; // ecx@1
	int v3; // edx@1
	int v4; // eax@2
	int v5; // eax@3

	v1 = a1;
	v2 = 8;
	v3 = v1 & 0xFFFF00FF;
	do
	{
		v4 = (v1 & (3 << v2)) >> v2;
		if (v4)
		{
			v5 = v4 - 1;
			if (v5)
			{
				if (v5 == 1)
					v3 |= 1 << v2;
			}
			else
			{
				v3 |= 2 << v2;
			}
		}
		else
		{
			v3 |= 3 << v2;
		}
		v2 += 2;
	} while (v2 < 16);
	return v3;
}

int sub_4011B0(int a1)
{
	int v1; // edi@1
	signed int v2; // ecx@1
	int v3; // esi@1
	signed int v4; // edx@2
	int v5; // eax@2
	int v6; // eax@3

	v1 = a1;
	v2 = 16;
	v3 = v1 & 0xFF00FFFF;
	do
	{
		v4 = 3 << v2;
		v5 = (v1 & (3 << v2)) >> v2;
		if (!v5)
		{
			v4 = 2 << v2;
		LABEL_7:
			v3 |= v4;
			goto LABEL_8;
		}
		v6 = v5 - 1;
		if (!v6)
			goto LABEL_7;
		if (v6 == 2)
			v3 |= 1 << v2;
	LABEL_8:
		v2 += 2;
	} while (v2 < 24);
	return v3;
}

int sub_401200(int a1)
{
	int v1; // edi@1
	signed int v2; // ecx@1
	int v3; // esi@1
	int v4; // esi@1
	signed int v5; // edx@2
	int v6; // eax@2
	int v7; // eax@3

	v1 = a1;
	v2 = 24;
	v3 = v1;
	v4 = v3 & 0xFFFFFF;
	do
	{
		v5 = 3 << v2;
		v6 = (v1 & (3 << v2)) >> v2;
		if (v6)
		{
			v7 = v6 - 1;
			if (!v7)
			{
				v4 |= 2 << v2;
				goto LABEL_9;
			}
			if (v7 != 1)
				goto LABEL_9;
		}
		else
		{
			v5 = 1 << v2;
		}
		v4 |= v5;
	LABEL_9:
		v2 += 2;
	} while (v2 < 32);
	return v4;
}


int main(void)
{
	int result, aa, i;

	//printf("input : %s",hostlong);
	//scanf("%s", &hostlong);
for(i = 0x4141; i <= 0x7a7a; i++)
{
for(aa = 0x4141; aa <= 0x7a7a; aa++)
{
hostlong = 0x65670000 + aa;
hostlong2 = (( 0x400000 + i )*0x100)+0x64;
	if (sub_401060())
	{
		printf("Correct !\n");
		printf("flag is %s\n", &hostlong);
		result = 0;
	}
}
}

	return 0;
}
