/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:55:22 by susivagn          #+#    #+#             */
/*   Updated: 2018/05/03 06:07:42 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

int		set_flags(t_sdl *sdlinfo)
{
	FPC = 0;
	FWRITE = 0;
	FNONE = 0;
	//PLAYER = 0; a GET//
	if (a_flags[CUR_X] == CWCF_NONE)
	{
		FNONE = 1;
		return (1);
	}
	DATA = ft_itoa_base(arena[CUR_X], "0123456789ABCDEF");
	FPC = (a_flags[CUR_X] == CWCF_PCNO(PLAYER)) ? 1 : 0;
	FWRITE = (a_flags[CUR_X] == CWCF_RWRITE) ? 1 : 0;
	//PLAYER = (a_flags[CUR_START] == CWCF_PNO(1)) ? 1 : 0;
	//PLAYER = (a_flags[CUR_START] == CWCF_PNO(2)) ? 1 : 0;
	//PLAYER = (a_flags[CUR_START] == CWCF_PNO(3)) ? 1 : 0;
	//PLAYER = (a_flags[CUR_START] == CWCF_PNO(4)) ? 1 : 0;
	return (1);
}
