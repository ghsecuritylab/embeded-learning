#include <stdio.h>

int transFloatToBytes(float f, unsigned char *bytes);
int transFloatToBinString(float f, char string[]);
int transFloatToHexString(float f, char string[]);

int main()
{
    float a = 0.12;
    unsigned char bytes[4];
    char string[33];

    transFloatToBytes(a, bytes);
    transFloatToHexString(a, string);

    printf("%s", string);

    return 0;
}

int transFloatToBytes(float f, unsigned char *bytes)
{
    unsigned int b = *((unsigned int *)(&f));

    int i = 0;
    for (i = 0; i < 4; i++)
    {
        bytes[i] = (unsigned char)((b >> i * 8) & 0xff);
    }

    return 4;
}

int transFloatToBinString(float f, char string[])
{
    unsigned int b = *((unsigned int *)(&f));
    for (int i = 0; i < 32; i++)
    {
        string[i] = ((b << (i)) & 0x80000000) == 0x00000000 ? '0' : '1';
    }

    string[32] = '\0';

    return 33;
}

int transFloatToHexString(float f, char string[])
{
    unsigned int b = *((unsigned int *)(&f));
    for (int i = 0; i < 8; i++)
    {
        int hexChar = ((b >> 32-((i+1) * 4)) & 0x0f);
        string[i] = (hexChar < 0x0a) ? hexChar + '0' : hexChar-0x0a + 'a';
    }

    string[8] = '\0';

    return 9;
}