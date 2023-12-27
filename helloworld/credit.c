#include <stdio.h>
#include <cs50.h>

int lenCardNo(long cardNo)
{
    int count = 0;
    while (cardNo > 1)
    {
        cardNo = cardNo / 10;
        count++;
    }
    return count;
}

bool cardLenValidity(int cardLen)
{
    if (cardLen == 13)
    {
        return true;
    }
    else if (cardLen == 15)
    {
        return true;
    }
    else if (cardLen == 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void cardValidity(long cardNo)
{
    long cardNumbersArray[lenCardNo(cardNo)];
    printf("%i\n", lenCardNo(cardNo));

    for (int i = 0; i < lenCardNo(cardNo); i++)
    {
        cardNumbersArray[i] = cardNo % 10;
        cardNo = cardNo / 10;
    }
    for (int j = 0; j < lenCardNo(cardNo); j++)
    {
        printf("%li", cardNumbersArray[j]);
    }
    printf("\n");
    printf("%li", cardNumbersArray[10]);
}

int main(void)
{
    long cardNumber = get_long("Number: ");
    if (cardLenValidity(lenCardNo(cardNumber)))
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
    cardValidity(cardNumber);
}