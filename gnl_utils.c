size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i++] = s2[j];
	res[i] = '\0';
	free(s1);
	return (res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;
	size_t			n;

	n = size * nmemb;
	p = malloc(n);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *) s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

#include <stdio.h>
#include <string.h>

// Prototipos de tus funciones
size_t ft_strlen(const char *str);
char *ft_strjoin(char *s1, char *s2);
void *ft_calloc(size_t nmemb, size_t size);
char *ft_strchr(const char *s, int c);

int main(void)
{
    printf("=== TEST ft_strlen ===\n");
    char *test_str = "Hello World";
    printf("'%s' length: %zu (expected: %lu)\n", 
           test_str, ft_strlen(test_str), strlen(test_str));
    printf("NULL length: %zu (expected: 0)\n", ft_strlen(NULL));

    printf("\n=== TEST ft_strjoin ===\n");
    char *s1 = strdup("Hello");
    char *s2 = strdup(" World");
    char *joined = ft_strjoin(s1, s2);
    printf("'%s' + '%s' = '%s' (expected: 'Hello World')\n", s1, s2, joined);
    free(joined);

    s1 = NULL;
    joined = ft_strjoin(s1, s2);
    printf("NULL + '%s' = '%s' (expected: ' World')\n", s2, joined);
    free(joined);
    free(s2);

    s1 = strdup("Hello");
    s2 = NULL;
    joined = ft_strjoin(s1, s2);
    printf("'%s' + NULL = '%s' (expected: 'Hello')\n", s1, joined);
    free(joined);
    free(s1);

    printf("\n=== TEST ft_calloc ===\n");
    int *arr = ft_calloc(5, sizeof(int));
    printf("Allocated array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);  // Should all be 0
    }
    printf("(expected: 0 0 0 0 0)\n");
    free(arr);

    printf("\n=== TEST ft_strchr ===\n");
    test_str = "Hello World";
    char *found = ft_strchr(test_str, 'W');
    printf("'W' in '%s': %s (expected: 'World')\n", 
           test_str, found ? found : "NULL");
    
    found = ft_strchr(test_str, 'z');
    printf("'z' in '%s': %s (expected: NULL)\n", 
           test_str, found ? found : "NULL");
    
    found = ft_strchr(test_str, '\0');
    printf("'\\0' in '%s': %s (expected: empty string)\n", 
           test_str, found ? found : "NULL");
    
    found = ft_strchr(NULL, 'H');
    printf("'H' in NULL: %s (expected: NULL)\n", 
           found ? found : "NULL");

    return 0;
}
