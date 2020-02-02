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
	int 			ind_max_sort;
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

	int				opt_a;
	int				opt_b;
	int				opt_pl;
	int				tmp_a;
//	int				tmp_b;
	int				tmp_pl;
	int				cmd_print;
	int				flag_v;
}					t_stacks;

int			ft_is_not_dub(t_stack *s, int value);
static void	ft_stack_free(t_stack **s);
int			ft_stacks_free(t_stacks **s);
void		ft_put_error(t_stacks **s);
t_stack		*ft_create_new_n(int val);
t_stack 	*ft_last_node(t_stack *s);
t_stack		*ft_stack_push_back(t_stack **stack, int val);
void		ft_free_array(char **array);
int			ft_check_int(int val_i, char *val_c);
void		ft_create_stack_a(int argc, char **argv, t_stacks *s);
void		ft_create_stack_a_argc2(char **argv, t_stacks *s);
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
void		ft_print_cmd(char	*cmd);
void		ft_do_cmd_0(char *com, int rpt, t_stacks *s);

#endif //PUSH_SWAP_PUSH_SWAP_H
