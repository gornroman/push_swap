/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:48:02 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 17:44:01 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_stack
{
	int				val;
	int				i;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
	int				flag_print;
	int				cmd_counter;
	t_stack			*tmp_b;
	int				len_a;
	int				len_b;
	int				ind_b;
	int				ind_a;
	int				comb;
	int				tmp_ind_b;
	int				tmp_ind_a;
	int				tmp_comb;
	int				visualisation;
	int				sort_from_start;
	int				firstlen;
}					t_stacks;

void				ft_prnt_cmd(char *cmd);
int					ft_last_elem(t_stack *a);
void				ft_index(t_stack *s);
void				ft_move_unsort(t_stacks *s);
int					ft_check_sort(t_stack *s);
int					ft_check_unsort(t_stacks *s);
int					ft_same_sort_in_end(t_stack *a, int i);
void				ft_move_unsort_3(t_stacks *s);
void				ft_sort_3(t_stacks *s);
int					ft_is_sorted_1(t_stack *s);
int					ft_swap(t_stacks *s);
void				ft_find_i_max_sort_help2(t_stack *s, int *new_max,
		int *max, int *ind);
void				ft_find_i_after_sort2_help(t_stack *s, int *ind,
		int *new_max, int *max);
void				ft_move_unsort_3_help(t_stacks *s, int i);
void				ft_do_route1_help(int *min, int *max, char **cmd,
		t_stacks *s);
void				ft_do_route2_help(int *len_min_m, int *len_max_m,
		char **cmd, t_stacks *s);
int					ft_find_i_max_sort(t_stack *s);
int					ft_find_i_after_sort2(t_stack *s);
int					ft_find_a_place(t_stacks *s);
int					ft_find_comb(t_stacks *s, int a_ind);
int					ft_find_comb_bigger5(t_stacks *s, int a_ind);
int					ft_find_route1(t_stacks *s, int a_ind);
int					ft_find_route2(t_stacks *s, int a_ind);
int					ft_find_route3(t_stacks *s, int a_ind);
int					ft_find_route4(t_stacks *s, int a_ind);
int					ft_find_route(t_stacks *s, int comb, int a_ind);
void				ft_do_route1(t_stacks *s);
void				ft_do_route2(t_stacks *s);
void				ft_do_route3(t_stacks *s);
void				ft_do_route4(t_stacks *s);
void				ft_move_to_a(t_stacks *s);
void				ft_start_swaping(t_stacks *s);
int					ft_find_turn(t_stacks *s);
void				ft_check_last(t_stacks *s);
void				ft_start_pushing(t_stacks *s);
int					ft_get_slen(t_stack *s);
int					ft_get_len_of_int(int nbr);
int					ft_is_not_dub(t_stack *s, int value);
void				ft_put_error(t_stacks **s);
void				ft_free_array(char **array);
int					ft_check_int(int val_i, char *val_c);
void				ft_stack_free(t_stack **s);
int					ft_stacks_free(t_stacks **s);
t_stack				*ft_create_new_n(int val);
t_stack				*ft_last_node(t_stack *s);
t_stack				*ft_stack_push_back(t_stack **stack, int val);
void				ft_print_header(t_stacks *s);
void				ft_print_stack(t_stack *a);
void				ft_print_bot(t_stacks *s);
void				ft_print_v(t_stacks *s);
void				ft_create_stack_a3_help(t_stacks *s, char **temp, int j,
		int cur_value);
void				ft_create_stack_a3(int argc, char **argv, t_stacks *s);
t_stacks			*ft_create_stack(int argc, char **argv);
int					ft_is_sorted(t_stacks *s);
int					ft_cmd_s(t_stack **s);
t_stack				*ft_pop_first(t_stack **s);
void				ft_push_first(t_stack **s, t_stack *new);
t_stack				*ft_get_last(t_stack *s);
void				ft_push_last(t_stack **s, t_stack *new);
t_stack				*ft_pop_last(t_stack **s);
int					ft_cmd_p(t_stack **from, t_stack **to);
int					ft_cmd_r(t_stack **s);
int					ft_cmd_rr(t_stack **s);
int					ft_do_cmd(char *cmd, t_stacks *s);
void				ft_do_cmd_0(char *com, int rpt, t_stacks *s);
void				ft_print_v_help(t_stack *temp_a, t_stack *temp_b);

#endif
