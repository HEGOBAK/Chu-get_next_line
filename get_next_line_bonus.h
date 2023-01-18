/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:25:17 by jchu              #+#    #+#             */
/*   Updated: 2023/01/18 16:26:38 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(const int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2, int val);
char	*ft_strchr(const char *str, int c);
char	*pickup(char *str);
char	*left_over(char *str);
char	*ft_get_line(int fd, char *str);

#endif