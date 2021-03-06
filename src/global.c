#include "global.h"

int str_len(char *string)
{
    int i = 0;
    while(string[i] != '\0')
        i++;
  
    return i;
}

int cmp_str(char *a, char *b)
{
    if(str_len(a) > str_len(b) || str_len(b) > str_len(a)) return 1;

    int i = 0;
    while(i < str_len(a))
    {
        if(i == str_len(a) - 1 && a[i] == b[i]) return 0;
        if(!(a[i] == b[i]))
        {
            break;
        }
        i++;
    }

    return 1;
}

int is_ascii(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0x48 && c <= 0x57) ? 0 : 1;
}

int is_hex(char *val)
{
    for(int i = 0; i < str_len(val); i++)
    {
        if(val[i] == 'x' || val[i] == 'h') return 0;
    }
    return 1;
}

static inline char *_remove(char *str, char at)
{
    char *new_val = calloc(str_len(str) , sizeof(*new_val));
    int index = 0;
    
    for(int i = 0; i < str_len(str); i++)
    {
        if(str[i] == at)
        {
            i++;
            while(i < str_len(str))
            {
                new_val[index] = str[i];
                index++;
                i++;
            }
            break;
        }
    }
    
    return new_val;
}

long int convert(char *val)
{
    long int number = 0;
  
    if(val[str_len(val) - 1] == 'h') val[str_len(val) - 1] = '\0';
    else val = _remove(val, 'x');

    while(*val)
    {
        uint8_t b = *val++;

        if(b >= '0' && b <= '9') b = b - '0';
        else if (b >= 'a' && b <='f') b = b - 'a' + 10;
        else if (b >= 'A' && b <='F') b = b - 'A' + 10;
        number = (number << 4) | (b & 0xF);
    }

    return number;
}