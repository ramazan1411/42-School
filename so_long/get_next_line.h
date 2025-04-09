/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:42:33 by raktas            #+#    #+#             */
/*   Updated: 2025/02/26 04:09:57 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen_(char *str);
char	*ft_strchr_(char *s, int c);
char	*ft_strjoin_(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_set_line_(char *save);
char	*ft_save(char *save);
char	*ft_read_and_save(int fd, char *save);
#endif
