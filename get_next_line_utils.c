/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:47:08 by araji-af          #+#    #+#             */
/*   Updated: 2022/11/05 00:46:38 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != (char)c)
	{	
		if (!*s)
		{
			return (NULL);
		}
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (s1 == NULL)
		return (ft_strdup(s2));
	(new = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	if (!s2)
		return (new[i] = '\0', new);
	while (s2[j])
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	return (new[i] = '\0', new);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	str = malloc(sizeof (char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char const		*subs;	
	char			*a;

	if (!s)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		subs = malloc((sizeof (char) * (ft_strlen(s) - start + 1)));
	else
		subs = malloc((sizeof (char) * (len + 2)));
	if (!subs)
		return (NULL);
	i = 0;
	a = (char *)subs;
	while (len-- && s[start])
		a[i++] = s[start++];
	a[i] = '\0';
	return ((char *)subs);
}
