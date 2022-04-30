#include <stdio.h>
#include <cs50.h>
#include <math.h>

void finalCheck(string type, int evenList[], int len, int odd);
void CheckSum(long n, string type);
void checkType(long n, int length);
void checkCardLength(long n);

int main(void)
{
    long input;
    do 
    {
        input = get_long("Number: ");
    }
    while (input < 0);
    
    
    checkCardLength(input);
}


void checkCardLength(long n)
{
    
    int length = log10(n) + 1;
    
    switch (length)
    {
        case 16:
            checkType(n, length);
            break;
        case 15:
            checkType(n, length);
            break;
        case 13:
            checkType(n, length);
            break;
        default:
            printf("INVALID\n");
    }
}

void checkType(long n, int length)
{
    if (length == 13)
    {
        int visa = n / pow(10, length - 1);
        (visa == 4) ? CheckSum(n, "VISA") : printf("INVALID\n");
    }
    else if (length == 16)
    {
        int visa = n / pow(10, length - 1);
        int v = n / pow(10, length - 1);
        int mast = n / pow(10, (length - 2));
        
        if (visa != 4)
        {
            (mast == 51 || mast == 52 || mast == 53 || mast == 54 || mast == 55) ? CheckSum(n, "MASTERCARD") : printf("INVALID\n");
        }
        else
        {
            CheckSum(n, "VISA");
        }
    }
    else
    {
        int amex = n / pow(10, length - 2);
        (amex == 34 || amex == 37) ? CheckSum(n, "AMEX") : printf("INVALID\n");
    }
}


void CheckSum(long n, string type)
{
    long newValue = 0;
    int length = log10(n) + 1, evenList[length / 2], odd = 0;
    
    for (int i = 0, j = (length / 2) + 1; j >= 1; i++, j--)
    {
        if (j == 1)
        {
            if (length == 16)
            {
                finalCheck(type, evenList, length, odd);
            }
            else
            {

                odd += n % 10;
                finalCheck(type, evenList, length, odd);
            }
            
        }
        else
        {

            odd += n % 10;

            newValue = n / 10;

            evenList[i] = (newValue % 10) * 2;

            n /= 100;
        }
        
    }
}

void finalCheck(string type, int array[], int len, int odd)
{
    int sum = 0;
    for (int i = 0; i < (int) len / 2; i++)
    {
        if (array[i] > 9)
        {
            for (int j = 0; j < 2; j++)
            {
                sum += array[i] % 10;
                array[i] /= 10;
            }
        }
        else
        {
            sum += array[i] % 10;
        }
    }
    int finalSum = sum + odd;
    if (finalSum % 10 == 0)
    {
        printf("%s\n", type);
    }
    else
    {
        printf("INVALID\n");
    }
}
