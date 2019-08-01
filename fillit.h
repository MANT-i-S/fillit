/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:55:03 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/03 17:00:06 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# define I id[0]
# define D id[1]

int			g_tetriminos;
int			g_square;
char		**get_array(int fd, int k);
void		print_arr(char **s);
int			print_answer(char *s);
void		finish_him(int l, int fd, char **arr, char *lol);
int			main(int arc, char **arv);
int			is(char c);
int			valid_square(int fd);
int			count_hash(char *s);
int			face_hash(char *s);
int			valid_file(char **s);
int			dial(int i);
int			back(char *lol);
char		*iden(char *dub);
char		*resize(char *s, int j);
char		*getsmaller(char *s, int k, int j);
char		*getbigger(char *s, int k, int j);
void		finishthework(char **arr, char *lol);
char		*build(char l, char *s);
char		*kicker(int i, char *c, char *s);
char		*filler(char *yes, int i);
int			match(char **c, char *s, int lol, int t);
char		*news(char c, char *s);
int			check_this(char *c, char *s, int t, int j);
int			hash_counter(char *c, int d);
int			changer(char *c, char *s, int t, int j);
char		*smaller(char *c, char *s, char **arr);
char		*tworabbit(int f, int i, char **arr, char *s);
int			shapechecker(char **arr, char *c);
#endif
