/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:27:36 by scartage          #+#    #+#             */
/*   Updated: 2022/10/26 20:07:22 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Con esta funcion lo que hacemos es poner en 0 la poscion actual donde estoy
 * para sumarle o restarte una pos segun a donde quiero ir.
 * una vez tengo la nueva "direccion" la defino como pos incial, asi cuando print_map
 * vuelva a hacer el recorrido muestre al personaje en la nueva posicion.
 * Hay que definir player, para que cuando el printf ponga las imagenes sea acorde a la
 * direccion a donde se quiere mover.*/
void now_move_up_down(t_vars *vars)
{
	if (vars->n_pos == 'W')
	{
		vars->counter = vars->counter + 1;
		printf("moves counter: %i\n", vars->counter);	
		vars->map[vars->px][vars->py] = '0';
		vars->px =  vars->px - 1;
		vars->map[vars->px][vars->py] = 'P';
		vars->player = 'W';
	}
	else if (vars->n_pos == 'S')
	{
		vars->counter = vars->counter + 1;
		printf("moves counter: %i\n", vars->counter);
		vars->map[vars->px][vars->py] = '0';
		vars->px = vars->px + 1;
		vars->map[vars->px][vars->py] = 'P';
		vars->player = 'S';
	}
}

void now_move_iz_dr(t_vars *vars)
{
	if (vars->n_pos == 'A')
	{
		vars->counter = vars->counter +  1;
		printf("moves counter: %i\n", vars->counter);
		vars->map[vars->px][vars->py] = '0';
		vars->py =  vars->py - 1;
		vars->map[vars->px][vars->py] = 'P';
		vars->player = 'A';
	}
	else if (vars->n_pos == 'D')
	{
		vars->counter = vars->counter + 1;
		printf("moves counter: %i\n", vars->counter);
		vars->map[vars->px][vars->py] = '0';
		vars->py =  vars->py + 1;
		vars->map[vars->px][vars->py] = 'P';
		vars->player = 'D';
	}
}

int is_finished(t_vars *vars)
{
	if (vars->col == 0 && (vars->map[vars->px - 1][vars->py] == 'E'
			|| vars->map[vars->px + 1][vars->py] == 'E'
			|| vars->map[vars->px][vars->py - 1] == 'E'
			|| vars->map[vars->px][vars->py + 1] == 'E'))
		return (0);
	return (1);
}
/*en esta funcion identificamos segun el codigo la letra que es.
 * a la izquierda estan los "codigos numericos" para las letras (AWDS)
 * y a la derecha los "codigos numerico" de las flechas. 
 * Segun lo que se pulse se da un valor. 
 * En caso de ser pulsado el ESC devolvemos un -1 y nos sacar del programa de forma limpia*/
int which_key(int key_symbol)
{
	if (key_symbol == 13 || key_symbol == 126)
		return ('W');
	else if (key_symbol == 1 || key_symbol == 125)
		return ('S');
	else if (key_symbol == 0 || key_symbol == 123 )
		return ('A');
	else if (key_symbol == 2 || key_symbol == 124)
		return ('D');
	else if (key_symbol == 53)
		return (-1);
	return (0);
}

/*La funcion recibe un parametro (key_symbol) avisando se ha pulsado una letra.
 * ese parametro lo pasamos a la funcion which_key.
 * Si lo que devulve la funcion es un -1 salimos del programa de forma limpia.*/
int player_movs(int key_symbol, t_vars *vars)
{
	//printf("the key:%i", key_symbol);
	vars->n_pos = which_key(key_symbol);
	if (vars->n_pos < 0)
		free_memory(vars);
//	printf("tecla: %c coleccionables: %i\n", vars->n_pos, vars->col);
	if (must_not_move(vars) == -1)
	{
		//printf("han habido problemas\n");
		return (-1);
	}
	if (is_finished(vars) == 0)
	{
		mlx_string_put(vars->mlx, vars->win_ptr, vars->px, vars->py, 0x0000FF00 , "YOU WON!!!");	
		return (0);
	}
	//printf("col: %i\n", vars->col);
	now_move_up_down(vars);
	now_move_iz_dr(vars);
	print_game_map(vars);
	return (0);
}
