/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:28:54 by msingh            #+#    #+#             */
/*   Updated: 2026/01/28 09:14:21 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char sep)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == sep)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	word_size(const char *str, char sep)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	return (len);
}

static char	**free_words(char **words, int n)
{
	while (n >= 0)
	{
		free(words[n]);
		n--;
	}
	free(words);
	return (0);
}

static char	**fill_words(const char *str, char sep, char **words)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (str[pos])
	{
		if (str[pos] != sep)
		{
			j = 0;
			words[i] = malloc(word_size(str + pos, sep) + 1);
			if (!words[i])
				return (free_words(words, i));
			while (str[pos] && str[pos] != sep)
				words[i][j++] = str[pos++];
			words[i][j] = '\0';
			i++;
		}
		else
			pos++;
	}
	words[i] = 0;
	return (words);
}

char	**ft_split(const char *str, char sep)
{
	char	**words;

	words = malloc((count_words(str, sep) + 1) * sizeof(char *));
	if (!words)
		return (0);
	words = fill_words(str, sep, words);
	return (words);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	**str;
// 	int		i;

// 	i = 0;
// 	str = ft_split("hello i a toi", ' ');
// 	while (str[i])
// 	{
// 		printf("%s\n", str[i]);
// 		i++;
// 	}
// }
