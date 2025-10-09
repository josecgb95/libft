/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:00:00 by jose-car          #+#    #+#             */
/*   Updated: 2025/10/09 15:01:28 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

int g_test_count = 0;
int g_test_passed = 0;
int g_test_failed = 0;

void print_header(const char *func_name)
{
    printf("\n%s=== Testing %s ===%s\n", BLUE, func_name, RESET);
}

void test_result(int condition, const char *test_name)
{
    g_test_count++;
    if (condition)
    {
        printf("%s[✓]%s %s\n", GREEN, RESET, test_name);
        g_test_passed++;
    }
    else
    {
        printf("%s[✗]%s %s\n", RED, RESET, test_name);
        g_test_failed++;
    }
}

/* ======================== PART I ======================== */

void test_ft_isalpha(void)
{
    print_header("ft_isalpha");
    test_result(ft_isalpha('a') == isalpha('a'), "Lowercase a");
    test_result(ft_isalpha('Z') == isalpha('Z'), "Uppercase Z");
    test_result(ft_isalpha('0') == isalpha('0'), "Digit 0");
}

void test_ft_isdigit(void)
{
    print_header("ft_isdigit");
    test_result(ft_isdigit('0') == isdigit('0'), "Digit 0");
    test_result(ft_isdigit('9') == isdigit('9'), "Digit 9");
    test_result(ft_isdigit('a') == isdigit('a'), "Letter a");
}

void test_ft_isalnum(void)
{
    print_header("ft_isalnum");
    test_result(ft_isalnum('a') == isalnum('a'), "Letter a");
    test_result(ft_isalnum('5') == isalnum('5'), "Digit 5");
    test_result(ft_isalnum('!') == isalnum('!'), "Special char !");
}

void test_ft_isascii(void)
{
    print_header("ft_isascii");
    test_result(ft_isascii(0) == isascii(0), "ASCII 0");
    test_result(ft_isascii(127) == isascii(127), "ASCII 127");
}

void test_ft_isprint(void)
{
    print_header("ft_isprint");
    test_result(ft_isprint(' ') == isprint(' '), "Space");
    test_result(ft_isprint('A') == isprint('A'), "Letter A");
}

void test_ft_strlen(void)
{
    print_header("ft_strlen");
    test_result(ft_strlen("Hello") == strlen("Hello"), "String 'Hello'");
    test_result(ft_strlen("") == strlen(""), "Empty string");
}

void test_ft_memset(void)
{
    print_header("ft_memset");
    char a[5];
    char b[5];
    ft_memset(a, 'x', 5);
    memset(b, 'x', 5);
    test_result(memcmp(a, b, 5) == 0, "Fill 5 bytes with 'x'");
}

void test_ft_bzero(void)
{
    print_header("ft_bzero");
    char a[5] = "abcde";
    char b[5] = "abcde";
    ft_bzero(a, 5);
    bzero(b, 5);
    test_result(memcmp(a, b, 5) == 0, "Zero 5 bytes");
}

void test_ft_memcpy(void)
{
    print_header("ft_memcpy");
    char src[5] = "1234";
    char dst1[5];
    char dst2[5];
    ft_memcpy(dst1, src, 5);
    memcpy(dst2, src, 5);
    test_result(memcmp(dst1, dst2, 5) == 0, "Copy 5 bytes");
}

void test_ft_memmove(void)
{
    print_header("ft_memmove");
    char str1[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    ft_memmove(str1 + 2, str1, 5);
    memmove(str2 + 2, str2, 5);
    test_result(memcmp(str1, str2, 10) == 0, "Overlapping copy");
}

void test_ft_strlcpy(void)
{
    print_header("ft_strlcpy");
    char dst1[10];
    char dst2[10];
    size_t r1 = ft_strlcpy(dst1, "Hello", 10);
    size_t r2 = ft_strlcpy(dst2, "Hello", 10);
    test_result(r1 == r2 && strcmp(dst1, dst2) == 0, "Copy 'Hello'");
}

void test_ft_strlcat(void)
{
    print_header("ft_strlcat");
    char dst1[20] = "Hello";
    char dst2[20] = "Hello";
    size_t r1 = ft_strlcat(dst1, " World", 20);
    size_t r2 = ft_strlcat(dst2, " World", 20);
    test_result(r1 == r2 && strcmp(dst1, dst2) == 0, "Concat ' World'");
}

void test_ft_toupper(void)
{
    print_header("ft_toupper");
    test_result(ft_toupper('a') == toupper('a'), "a -> A");
    test_result(ft_toupper('Z') == toupper('Z'), "Z -> Z");
}

void test_ft_tolower(void)
{
    print_header("ft_tolower");
    test_result(ft_tolower('A') == tolower('A'), "A -> a");
    test_result(ft_tolower('z') == tolower('z'), "z -> z");
}

void test_ft_strchr(void)
{
    print_header("ft_strchr");
    test_result(ft_strchr("Hello", 'e') == strchr("Hello", 'e'), "Find 'e'");
}

void test_ft_strrchr(void)
{
    print_header("ft_strrchr");
    test_result(ft_strrchr("Hello", 'l') == strrchr("Hello", 'l'), "Last 'l'");
}

void test_ft_strncmp(void)
{
    print_header("ft_strncmp");
    test_result(ft_strncmp("Hello", "Hello", 5) == strncmp("Hello", "Hello", 5), "Equal strings");
    test_result(ft_strncmp("Hello", "World", 5) == strncmp("Hello", "World", 5), "Different strings");
}

void test_ft_memchr(void)
{
    print_header("ft_memchr");
    char s[] = "abcde";
    test_result(ft_memchr(s, 'c', 5) == memchr(s, 'c', 5), "Find 'c'");
}

void test_ft_memcmp(void)
{
    print_header("ft_memcmp");
    char s1[] = "abcde";
    char s2[] = "abcdf";
    test_result(ft_memcmp(s1, s2, 5) == memcmp(s1, s2, 5), "Compare memory");
}

void test_ft_strnstr(void)
{
    print_header("ft_strnstr");
    test_result(ft_strnstr("Hello World", "World", 11) == strstr("Hello World", "World"), "Find 'World'");
    test_result(ft_strnstr("Hello", "xyz", 5) == NULL, "Not found");
}

void test_ft_atoi(void)
{
    print_header("ft_atoi");
    test_result(ft_atoi("42") == atoi("42"), "Simple number 42");
    test_result(ft_atoi("-42") == atoi("-42"), "Negative -42");
}

void test_ft_calloc(void)
{
    print_header("ft_calloc");
    int *arr1 = ft_calloc(5, sizeof(int));
    int *arr2 = calloc(5, sizeof(int));
    test_result(memcmp(arr1, arr2, 5 * sizeof(int)) == 0, "Calloc 5 ints");
    free(arr1);
    free(arr2);
}

void test_ft_strdup(void)
{
    print_header("ft_strdup");
    char *dup1 = ft_strdup("Hello");
    char *dup2 = strdup("Hello");
    test_result(strcmp(dup1, dup2) == 0, "Duplicate 'Hello'");
    free(dup1);
    free(dup2);
}

/* ======================== PART II ======================== */

void test_ft_substr(void)
{
    print_header("ft_substr");
    char *sub = ft_substr("Hello World", 6, 5);
    test_result(strcmp(sub, "World") == 0, "Substring 'World'");
    free(sub);
}

void test_ft_strjoin(void)
{
    print_header("ft_strjoin");
    char *join = ft_strjoin("Hello", "World");
    test_result(strcmp(join, "HelloWorld") == 0, "Join 'HelloWorld'");
    free(join);
}

void test_ft_strtrim(void)
{
    print_header("ft_strtrim");
    char *trim = ft_strtrim("   Hello   ", " ");
    test_result(strcmp(trim, "Hello") == 0, "Trim spaces");
    free(trim);
}

void test_ft_split(void)
{
    print_header("ft_split");
    char **split = ft_split("a,b,c", ',');
    test_result(strcmp(split[0], "a") == 0 && strcmp(split[1], "b") == 0 && strcmp(split[2], "c") == 0, "Split 'a,b,c'");
    for (int i = 0; split[i]; i++)
        free(split[i]);
    free(split);
}

void test_ft_itoa(void)
{
    print_header("ft_itoa");
    char *s = ft_itoa(12345);
    test_result(strcmp(s, "12345") == 0, "Integer to string 12345");
    free(s);
}

char ft_mapi_fun(unsigned int i, char c)
{
    (void)i;
    return c + 1;
}

void test_ft_strmapi(void)
{
    print_header("ft_strmapi");
    char *res = ft_strmapi("abc", ft_mapi_fun);
    test_result(strcmp(res, "bcd") == 0, "Map a->b, b->c, c->d");
    free(res);
}

void ft_iteri_fun(unsigned int i, char *c)
{
    (void)i;
    *c = *c + 1;
}

void test_ft_striteri(void)
{
    print_header("ft_striteri");
    char s[4] = "abc";
    ft_striteri(s, ft_iteri_fun);
    test_result(strcmp(s, "bcd") == 0, "Striteri a->b, b->c, c->d");
}

void test_ft_putchar_fd(void)
{
    print_header("ft_putchar_fd");
    printf("Output: "); ft_putchar_fd('A', 1); printf(" <- should see 'A'\n");
}

void test_ft_putstr_fd(void)
{
    print_header("ft_putstr_fd");
    printf("Output: "); ft_putstr_fd("Hello", 1); printf(" <- should see 'Hello'\n");
}

void test_ft_putendl_fd(void)
{
    print_header("ft_putendl_fd");
    printf("Output: "); ft_putendl_fd("Hello", 1); printf("<- should see 'Hello' with newline\n");
}

void test_ft_putnbr_fd(void)
{
    print_header("ft_putnbr_fd");
    printf("Output: "); ft_putnbr_fd(12345, 1); printf(" <- should see 12345\n");
}

/* ======================== BONUS ======================== */

void del(void *c)
	{
		free(c);
	}

void test_bonus_list(void)
{
    print_header("Bonus t_list");
    t_list *lst = ft_lstnew(strdup("one"));
    ft_lstadd_back(&lst, ft_lstnew(strdup("two")));
    ft_lstadd_back(&lst, ft_lstnew(strdup("three")));

    test_result(ft_lstsize(lst) == 3, "List size == 3");
    test_result(strcmp(ft_lstlast(lst)->content, "three") == 0, "Last element == 'three'");

    ft_lstclear(&lst, del);
    test_result(lst == NULL, "List cleared");
}

/* ======================== MAIN ======================== */

int main(void)
{
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    test_ft_isascii();
    test_ft_isprint();
    test_ft_strlen();
    test_ft_memset();
    test_ft_bzero();
    test_ft_memcpy();
    test_ft_memmove();
    test_ft_strlcpy();
    test_ft_strlcat();
    test_ft_toupper();
    test_ft_tolower();
    test_ft_strchr();
    test_ft_strrchr();
    test_ft_strncmp();
    test_ft_memchr();
    test_ft_memcmp();
    test_ft_strnstr();
    test_ft_atoi();
    test_ft_calloc();
    test_ft_strdup();
    test_ft_substr();
    test_ft_strjoin();
    test_ft_strtrim();
    test_ft_split();
    test_ft_itoa();
    test_ft_strmapi();
    test_ft_striteri();
    test_ft_putchar_fd();
    test_ft_putstr_fd();
    test_ft_putendl_fd();
    test_ft_putnbr_fd();
    test_bonus_list();

    printf("\n%sTests run: %d, Passed: %d, Failed: %d%s\n", YELLOW, g_test_count, g_test_passed, g_test_failed, RESET);
    return 0;
}
