#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    uint8_t bsize1 = 8, bsize2 = 64;
    uint8_t presentTag = 0;
    for (uint8_t ofst = 0; ofst < bsize2; ofst += bsize1)
    {
        uint8_t bitPos = ofst / bsize1;
        printf("bitPos = %u\n", bitPos);
        uint8_t bitMask = ((uint8_t)1 << bitPos);
        printf("bitMask = %u\n", bitMask);
        presentTag = presentTag | bitMask;
        printf("presentTag = %u\n", presentTag);
    }

    for (uint8_t ofst = 0; ofst < bsize2; ofst += bsize1)
    {
        uint8_t bitPos = ofst / bsize1;
        printf("bitPos = %u\n", bitPos);
        uint8_t bitMask = ~((uint8_t)1 << bitPos);
        printf("bitMask = %u\n", bitMask);
        presentTag = presentTag & bitMask;
        printf("presentTag = %u\n", presentTag);
    }
    return 0;
}
