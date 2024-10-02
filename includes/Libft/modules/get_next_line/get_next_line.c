/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:41:30 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/02 13:36:39 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#include <time.h>

char	*ft_update_fd(char *str, int i, int j)
{
	char	*aux;

	if (ft_strchr_gnl(str, '\n') == NULL)
	{
		if (str)
			free(str);
		return (NULL);
	}
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	i = i + 1;
	if (str[i - 1] == '\0')
	{
		return (str);
	}
	aux = malloc((ft_strlen_gnl(str) - i) + 1);
	if (!aux)
		return (NULL);
	while (str[i] != 0)
		aux[j++] = str[i++];
	aux[j] = '\0';
	free(str);
	return (aux);
}

char	*ft_find_end_of_line(char *str)
{
	int		i;
	char	*aux;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	aux = malloc(i + 2);
	if (!aux)
		return (NULL);
	aux[i + 1] = '\0';
	while (i >= 0)
	{
		aux[i] = str[i];
		i--;
	}
	return (aux);
}

char	*ft_strdup_gnl(char *s1)
{
	char	*s2;
	int		s1len;
	int		i;

	s1len = ft_strlen_gnl(s1);
	s2 = (char *)malloc(sizeof(char) * (s1len + 1));
	if (*s2 == '\0')
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static int	read_into_buffer(int fd, char **buffer_fd)
{
	char	temp[BUFFER_SIZE + 1];
	int		nbr;

	nbr = read(fd, temp, BUFFER_SIZE);
	if (nbr > 0)
	{
		temp[nbr] = '\0';
		*buffer_fd = ft_strjoin_gnl(*buffer_fd, temp);
	}
	return (nbr);
}

char	*get_next_line(int fd)
{
	static char	*buffer_fd;
	char		*line;
	int			nbr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer_fd)
		buffer_fd = ft_strdup_gnl("");
	nbr = 1;
	while (nbr > 0 && !ft_strchr_gnl(buffer_fd, '\n'))
		nbr = read_into_buffer(fd, &buffer_fd);
	if (nbr < 0)
	{
		free(buffer_fd);
		buffer_fd = NULL;
		return (NULL);
	}
	line = ft_find_end_of_line(buffer_fd);
	buffer_fd = ft_update_fd(buffer_fd, 0, 0);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/* int	main(void)
{
	int fd;

	fd = open("41 no_nl.txt", O_RDONLY);
	char *s;
	//clock_t start = clock();
	while ((s = get_next_line(fd)))
	{
		printf("===================================\n");
		printf("RETURN ----> %s", s);
		printf("===================================\n");
		free(s);
	}
	printf("RETURN ----> %s", s);
	//float seconds = (float)(clock() - start) / CLOCKS_PER_SEC;
	//printf ("%.2f ds\n", seconds);
	//system("leaks a.out");
	return (0);
 } */
