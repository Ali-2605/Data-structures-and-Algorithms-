#include <stdio.h>
#include <stdlib.h>


int strlen1(char *x)
{
    int i; 
    for(i = 0; x[i] != '\0'; i++);
    return i;
}

void changeCase(char *x)
{
    for(int i = 0; x[i] != '\0'; i++)
    {
        if(x[i] >= 'A' && x[i] <= 'Z')
            x[i] = x[i] + (' ');
        
        else if(x[i] >= 'a' && x[i] <= 'z')
            x[i] = x[i] - (' ');
    }
}

int countCharacters(char *x)
{   
    int count = 0;
    for(int i = 0; x[i] != '\0'; i++)
    {
        if((x[i] >= 'A' && x[i] <= 'Z') || (x[i] >= 'a' && x[i] <= 'z'))
            count++;
    }
    return count;
}

int countVowels(char *x)
{
    int count = 0;
    for(int i = 0; x[i] != '\0'; i++)
    {
        if(x[i] == 'A' || x[i] == 'E' || x[i] == 'I' || x[i] == 'O' || x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o') 
            count++;
    }
    return count;
}

int countConsonants(char *x)
{
    int count = 0;
    for(int i = 0; x[i] != '\0'; i++)
    {
        if(((x[i] >= 'A' && x[i] <= 'Z') || (x[i] >= 'a' && x[i] <= 'z')) && (x[i] != 'A' && x[i] != 'E' && x[i] != 'I' && x[i] != 'O' && x[i] != 'a' && x[i] != 'e' && x[i] != 'i' && x[i] != 'o')) 
        {
            count++;
        }
    }
    return count;
}

int countWords(char *x)
{
    int count = 1;
    for(int i = 0; x[i] != '\0'; i++)
    {
        if(x[i] == ' ' && x[i - 1] != ' ') 
        {
            count++;
        }
    }
    return count;
}

int isValid(char *x)
{
    for(int i = 0; x[i] != '\0'; i++)
    {
        if((!(x[i] >= 'A' && x[i] <= 'Z') && !(x[i] >= 'a' && x[i] <= 'z')) && (!(x[i] >= '0' && x[i] <= '9'))) 
        {
            return 0;
        }
    }
    return 1;
}

void reverse(char *x)
{
    int j = strlen1(x) - 1;
    for(int i = 0; i < j; i++)
    {
        char temp = x[i];
        x[i] = x[j];
        x[j] = temp;
        j--;
    }
}

int isSame(char *x, char *y)
{
    for(int i = 0, j = 0; x[i] == '\0' &&  y[j] == '\0'; i++, j++)
    {
        if(x[i] != y[j]) 
        {
            return 0;
        }
    }
    return 1;
}

int isPaladrome(char *x)
{
    int j = strlen1(x) - 1;
    for(int i = 0; i <= j; i++, j--)
    {
        if(x[i] != x[j])
        {
            return 0;
        }
    }
    return 1;
}

int isUpperOrSmall(char *x)
{
    char status = '0';
    for(int i = 0; x[i] != '\0'; i++)
    {
        if((x[i] >= 'a' && x[i] <= 'z')) 
        {
            if(status == '0')
                status = 's';
            else if(status == 'u')
                status = 'm';
        }
        else if((x[i] >= 'A' && x[i] <= 'Z'))
        {
            if(status == '0')
                status = 'u';
            else if(status == 's')
                status = 'm';
        }
        else
        {
            status = 'i';
            return status;
        }
    }
    return status;
}

void dublicateH(char *x)
{
    int status = isUpperOrSmall(x);
    if(status == 's')
    {
        char h[26] = {0};
        for(int i = 0; x[i] != '\0'; i++)
        {
            h[x[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (h[i] > 1)
            {
                printf("There is a dublicate of %c and it is dublicated %d times\n", i + 'a', h[i]);
            }
        }
    }

    else if(status == 'u')
    {
        char h[26] = {0};
        for(int i = 0; x[i] != '\0'; i++)
        {
            h[x[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (h[i] > 1)
            {
                printf("There is a dublicate of %c and it is dublicated %d times\n", i + 'A', h[i]);
            }
        }
    }

    else if(status == 'm')
    {
        char h[52] = {0};
        for(int i = 0; x[i] != '\0'; i++)
        {
            if ((x[i] >= 'a' && x[i] <= 'z'))
            {
                h[x[i] - 'a']++;
            }

            else if ((x[i] >= 'A' && x[i] <= 'Z'))
            {
                h[(x[i] - 'A') + 26]++;
            }
        }

        for (int i = 0; i < 52; i++)
        {
            if (h[i] > 1 && i < 26)
            {
                printf("There is a dublicate of %c and it is dublicated %d times\n", i + 'a', h[i]);
            }

            else if (h[i] > 1 && i > 26)
            {
                printf("There is a dublicate of %c and it is dublicated %d times\n", (i - 26) + 'A', h[i]);
            }
        }
    }
    else
    {
        printf("Invalid string.\n");
        return;
    }
    return;
}

void dublicateB(char *x)
{
    int status = isUpperOrSmall(x);
    if(status == 's')
    {
        int h = 0;
        int n;

        for(int i = 0; x[i] != '\0'; i++)
        {
            n = 1;
            n = n << (x[i] - 'a');
            if((n & h) > 0)
            {
                printf("%c is dublicate\n", x[i]);
            }
            else
            {
                h = h | n;
            }
        }
    }

    else if(status == 'u')
    {
        int h = 0;
        int n;
        for(int i = 0; x[i] != '\0'; i++)
        {
            n = 1;
            n = n << (x[i] - 'A');
            if((n & h) > 0)
            {
                printf("%c is dublicate\n", x[i]);
            }
            else
            {
                h = h | n;
            }
        }
    }

    else if(status == 'm')
    {
        int h = 0;
        int n;
        for(int i = 0; x[i] != '\0'; i++)
        {
            n = 1;
            if(x[i] >= 'A' && x[i] <= 'Z')
                n = n << (x[i] - 'A');

            else
                n = n << (x[i] - 'a');
                
            if((n & h)> 0)
            {
                printf("%c is dublicate\n", x[i]);
            }
            else
            {
                h = h | n;
            }
        }
    }

    else
    {
        printf("Invalid string.\n");
        return;
    }
    return;   
}

//not case senstive and cna't handle special characters
int anagramB1(char *x, char *y) 
{
    if (strlen1(x) != strlen1(y)) {
        return 0;
    }

    int h = 0;
    int n = 1;

    for (int i = 0; x[i] != '\0'; i++) 
    {
        if (x[i] >= 'a' && x[i] <= 'z') 
            h ^= (n << (x[i] - 'a')); 
        
        else if (x[i] >= 'A' && x[i] <= 'Z') 
            h ^= (n << (x[i] - 'A'));

        if (y[i] >= 'a' && y[i] <= 'z') 
            h ^= (n << (y[i] - 'a')); 
        
        else if (y[i] >= 'A' && y[i] <= 'Z') 
            h ^= (n << (y[i] - 'A'));
        
    }

    return (h == 0);
}

//case senstive and can handle special characters
int anagramB2(char *x, char *y) 
{
    if (strlen1(x) != strlen1(y)) {
        return 0;
    }

    long long int h = 0;
    int n = 1; 

    for (int i = 0; x[i] != '\0'; i++) 
    {
        h ^= (n << (x[i])); 
        h ^= (n << (y[i])); 
    }

    return (h == 0);
}


void permutation1(char *x, int k)
{
    static int num[10] = {0};
    static char result[10];

    if(x[k] == '\0')
    {
        result[k] = '\0';
        printf("%s\n", result);
    }
    else
    {
        for(int i = 0; x[i] != '\0'; i++)
        {
            if(num[i] == 0)
            {
                result[k] = x[i];
                num[i] = 1;
                permutation1(x, k + 1);
                num[i] = 0;
            }
        }
    }
}

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permutation2(char *x, int low, int high)
{
    if (low == high)
        printf("%s\n", x);
        
    else
    {
        for (int i = low; i <= high; i++)
        {
            swap(&(x[low]), &(x[i]));
            permutation2(x, low + 1, high);
            swap(&(x[low]), &(x[i]));
        }
    }
}

int main(void)
{
    char x[] = "nito";
    printf("%d\n", strlen1(x));
    changeCase(x);
    printf("%i\n", countCharacters(x));
    printf("%i\n", countVowels(x));
    printf("%i\n", countConsonants(x));
    printf("%i\n", countWords(x));
    printf("is the string valid: %s\n", isValid(x) ? "yes" : "no");
    reverse(x);
    char y[] = "Hello worl";
    printf("%i\n", isSame(x, y));
    printf("%i\n", isPaladrome(x));

    char x[] = "What";
    char y[] = "Hello124";
    printf("Is it an anagram: %s\n", anagramB2(x, y)? "yes" : "no");
    int n = strlen1(x);
    permutation2(x, 0, n - 1);
    return 0;
}