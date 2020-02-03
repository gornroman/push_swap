#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_stack
{
	int				val;
	int				i;
	int				sort;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
//	int 			ind_max_sort;
	int 			flag_print;
	int				cmd_counter;
	t_stack			*tmp_b;
	int				len_a;
	int				len_b;
	int 			ind_b;
	int				ind_a;
	int 			comb;
	int 			tmp_ind_b;
	int 			tmp_ind_a;
	int 			tmp_comb;
	int				visualisation;
	int				max_int_len;
	int				sort_from_start;
	int				firstlen;
}					t_stacks;

int			ft_is_not_dub(t_stack *s, int value);
void		ft_stack_free(t_stack **s);
int			ft_stacks_free(t_stacks **s);
void		ft_put_error(t_stacks **s);
t_stack		*ft_create_new_n(int val);
t_stack 	*ft_last_node(t_stack *s);
t_stack		*ft_stack_push_back(t_stack **stack, int val);
void		ft_free_array(char **array);
int			ft_check_int(int val_i, char *val_c);
void		ft_create_stack_a3(int argc, char **argv, t_stacks *s);
t_stacks	*ft_create_stack(int argc, char **argv);
int			ft_is_sorted(t_stacks *s);
int 		ft_cmd_s(t_stack **s);
t_stack 	*ft_pop_first(t_stack **s);
void		ft_push_first(t_stack **s, t_stack *new);
int 		ft_cmd_p(t_stack **from, t_stack **to);
t_stack 	*ft_get_last(t_stack *s);
void		ft_push_last(t_stack **s, t_stack *new);
int 		ft_cmd_r(t_stack **s);
t_stack 	*ft_pop_last(t_stack **s);
int 		ft_cmd_rr(t_stack **s);
int 		ft_do_cmd(char *cmd, t_stacks *s);
void		ft_prnt_cmd(char	*cmd);
void		ft_do_cmd_0(char *com, int rpt, t_stacks *s);
void		ft_visualisation(t_stacks *s);

void		ft_index(t_stack *s);
int			ft_get_slen(t_stack *s);
void		ft_print_stack3(t_stacks *s);
void		ft_print_stack4(t_stacks *s);
int 		ft_find_i_max_sort(t_stack *s);
void		ft_move_unsort(t_stacks *s);
int 		ft_find_i_after_sort2(t_stack *s);
void		ft_move_unsort_2(t_stacks *s);
void		ft_sort_3(t_stacks *s);
int			ft_is_sorted_1(t_stack *s);
int 		ft_find_a_place(t_stacks *s);
int 		ft_find_comb(t_stacks *s, int a_ind);
int 		ft_find_route1(t_stacks *s, int a_ind);
int 		ft_find_route2(t_stacks *s, int a_ind);
int 		ft_find_route3(t_stacks *s, int a_ind);
int 		ft_find_route4(t_stacks *s, int a_ind);
int 		ft_find_route(t_stacks *s, int comb, int a_ind);
int 		ft_swap(t_stacks *s);
void		ft_do_route1(t_stacks *s);
void		ft_do_route2(t_stacks *s);
void 		ft_do_route3(t_stacks *s);
void 		ft_do_route4(t_stacks *s);
void 		ft_move_to_a(t_stacks *s);
void 		ft_start_swaping(t_stacks *s);
int			ft_find_turn(t_stacks *s);
void		ft_start_pushing(t_stacks *s);


#endif //PUSH_SWAP_PUSH_SWAP_H
