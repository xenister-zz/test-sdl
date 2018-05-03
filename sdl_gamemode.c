/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_gamemode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:34:10 by susivagn          #+#    #+#             */
/*   Updated: 2018/05/03 06:08:12 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

int		update_gamemode1(t_sdl *sdlinfo)
{
	printf("---- IN MEMORY UPDATE ----\n");
	FWRITE = 0;
	FNONE = 0;
	FPC = 0;
	if (GAMEMODE == 2)
	{
	//set_flags(sdlinfo);
		get_txt_color(sdlinfo);
		if (FNONE == 0)
			MEM_ZONE = TTF_RenderText_Shaded(sdlinfo->police_game, "01",
				sdlinfo->txt_color, sdlinfo->bg_color);
		else
			MEM_ZONE = TTF_RenderText_Solid(sdlinfo->police_game, "00",
				sdlinfo->grey);
		if (MEM_ZONE == NULL)
		{
			printf("ERROR: Game Mode 1 Memory TTF_Render\n");
			return (-1);
		}
	}
	else if ((update_gamemode2(sdlinfo)) == -1)
		return (-1);
	return (1);
}

int		update_gamemode2(t_sdl *sdlinfo)
{
//set_flags(sdlinfo);
	get_block_color(sdlinfo);
	if (FWRITE == 1)
		MEM_ZONE = TTF_RenderText_Shaded(sdlinfo->police_game, "  ",
			sdlinfo->bg_color, sdlinfo->black);
	else if (PLAYER > 0)
		MEM_ZONE = TTF_RenderText_Shaded(sdlinfo->police_game, "  ",
			sdlinfo->txt_color, sdlinfo->bg_color);
	else
		MEM_ZONE = TTF_RenderText_Shaded(sdlinfo->police_game, "  ",
			sdlinfo->txt_color, sdlinfo->grey);
	if (MEM_ZONE == NULL)
	{
		printf("ERROR: Game Mode 2 Memory TTF_Render\n");
		return (-1);
	}
	return (1);
}

void	get_block_color(t_sdl *sdlinfo)
{
	printf("++++ In Block Color ++++\n");
	if (FPC == 0 && FWRITE == 1)
	{
		if (PLAYER == 1)
			sdlinfo->bg_color = sdlinfo->red;
		else if (PLAYER == 2)
			sdlinfo->bg_color = sdlinfo->blue;
		else if (PLAYER == 3)
			sdlinfo->bg_color = sdlinfo->green;
		else if (PLAYER == 4)
			sdlinfo->bg_color = sdlinfo->yellow;
	}
	else
	{
		if (PLAYER == 1)
			sdlinfo->bg_color = sdlinfo->pc_red;
		else if (PLAYER == 2)
			sdlinfo->bg_color = sdlinfo->pc_blue;
		else if (PLAYER == 3)
			sdlinfo->bg_color = sdlinfo->pc_green;
		else if (PLAYER == 4)
			sdlinfo->bg_color = sdlinfo->pc_yellow;
	}
	printf("++++ END Block Color ++++\n");
}

void	get_txt_color(t_sdl *sdlinfo)
{
	printf("++++ In Get Texte Color ++++\n");
	if (FWRITE == 1)
		get_wrt_txt_color(sdlinfo);
	else if (FPC == 0)
	{
		sdlinfo->bg_color = sdlinfo->black;
		if (PLAYER == 1)
			sdlinfo->txt_color = sdlinfo->red;
		else if (PLAYER == 2)
			sdlinfo->txt_color = sdlinfo->blue;
		else if (PLAYER == 3)
			sdlinfo->txt_color = sdlinfo->green;
		else if (PLAYER == 4)
			sdlinfo->txt_color = sdlinfo->yellow;
	}
	else
	{
		sdlinfo->txt_color = sdlinfo->black;
		if (PLAYER == 1)
			sdlinfo->bg_color = sdlinfo->red;
		else if (PLAYER == 2)
			sdlinfo->bg_color = sdlinfo->blue;
		else if (PLAYER == 3)
			sdlinfo->bg_color = sdlinfo->green;
		else if (PLAYER == 4)
			sdlinfo->bg_color = sdlinfo->yellow;
	}
	printf("++++ END Texte Color ++++\n");
}

void	get_wrt_txt_color(t_sdl *sdlinfo)
{
	printf("++++ IN Write Color ++++\n");
	sdlinfo->bg_color = sdlinfo->black;
	if (PLAYER == 1)
		sdlinfo->txt_color = sdlinfo->pc_red;
	else if (PLAYER == 2)
		sdlinfo->txt_color = sdlinfo->pc_blue;
	else if (PLAYER == 3)
		sdlinfo->txt_color = sdlinfo->pc_green;
	else if (PLAYER == 4)
		sdlinfo->txt_color = sdlinfo->pc_yellow;
	printf("++++ END Write Color ++++\n");
}
