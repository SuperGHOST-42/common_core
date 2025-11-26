# include <stdlib.h>
# include <stdio.h>

static int count_words(char *str, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i]) 
	{
		while (str[i] == c) // Ariclenes Alexandre
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	*ft_substr(char *str, int start, int len)
{
	char *dup;
	int i;

	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
		i = 0;
	while (i < len)
	{
		dup[i] = str[start + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char **split(char *str, char c)
{
	int i;
	int len;
	int j;
	char **splitted;

	i = 0;
	j = 0;
	splitted = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!splitted)
		return (NULL);
	while (str[i])
	{
		len = 0;
		while (str[i] == c) // Ariclenes Alexandre
			i++;
		if (str[i] != '\0')
		{
			while (str[i + len] != '\0' && str[i + len] != c)
				len++;
			splitted[j++] = ft_substr(str, i, len);
			i += len;
		}
	}
	splitted[j] = NULL;
	return (splitted);
}

int main(void)
{
	char **str = split(" Ariclenes   Alexandre.   ", ' ');

	for (int i = 0; i < 2; i++)
	{
		printf("%s\n", str[i]);
	}
}