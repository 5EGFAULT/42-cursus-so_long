/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:45:09 by asouinia          #+#    #+#             */
/*   Updated: 2022/03/13 21:36:44 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define BUFFER_SIZE 1

size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char const *s2, int len);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char *s, size_t len);
char	*get_next_line(int fd);

#endif